#pragma once
#include "Elem.h"
#include "Stack_on_List.h"

template <class T>
class TTreeTable
{
protected:
	static TTreeElem<T> st;
	TTreeElem<T>* node;
	int count;
public:
	TTreeTable();
	TTreeTable(const TTreeTable<T>& table);
	~TTreeTable();
	int GetCount() const;
	TTreeElem<T>* GetNode() const;
	TTreeElem<T>* Add(TTreeElem<T>& elem);
	void Del(TTreeElem<T>& elem);
	bool Del(const String& key);
	TTreeElem<T>& Search(const String& key) const;
	T& operator[](const String& key) const;
	friend std::ostream& operator<<(std::ostream& out, const TTreeTable<T>& table)
	{
		TStackList<TTreeElem<T>*> stack1;
		stack1.Put(table.GetNode());
		while (stack1.IsEmpty() != true)
		{
			TTreeElem<T>* tmp = stack1.Get();
			if (tmp->GetRight() != NULL)
				stack1.Put(tmp->GetRight());
			if (tmp->GetLeft() != NULL)
				stack1.Put(tmp->GetLeft());
			out << *tmp << endl;
		}
		return out;
	}
};

template <class T>
TTreeElem<T> TTreeTable<T>::st;

template <class T>
TTreeTable<T>::TTreeTable()
{
	node = NULL;
	count = 0;
}

template <class T>
TTreeTable<T>::TTreeTable(const TTreeTable<T>& table)
{
	count = table.count;
	node = new TTreeElem<T>(*(table.node));
	TStackList<TTreeElem<T>*> stack1;
	TStackList<TTreeElem<T>*> stack2;
	stack1.Put(node);
	stack2.Put(table.node);
	while (stack2.IsEmpty() != true)
	{
		TTreeElem<T>* tmp1 = stack1.Get();
		TTreeElem<T>* tmp2 = stack2.Get();
		if (tmp2->GetLeft() != NULL)
		{
			tmp1->SetLeft(new TTreeElem<T>(*(tmp2->GetLeft())));
			stack1.Put(tmp1->GetLeft());
			stack2.Put(tmp2->GetLeft());
			tmp1->GetLeft()->SetParent(tmp1);
		}
		if (tmp2->GetRight() != NULL)
		{
			tmp1->SetRight(new TTreeElem<T>(*(tmp2->GetRight())));
			stack1.Put(tmp1->GetRight());
			stack2.Put(tmp2->GetRight());
			tmp1->GetRight()->SetParent(tmp1);
		}
	}
}

template <class T>
TTreeTable<T>::~TTreeTable()
{
	TStackList<TTreeElem<T>*> stack1;
	stack1.Put(node);
	while (stack1.IsEmpty() != true)
	{
		TTreeElem<T>* tmp = stack1.Get();
		if (tmp != NULL)
		{
			if (tmp->GetLeft() != NULL)
				stack1.Put(tmp->GetLeft());
			if (tmp->GetRight() != NULL)
				stack1.Put(tmp->GetRight());
			delete tmp;
		}
	}
}

template <class T>
int TTreeTable<T>::GetCount() const
{
	return count;
}

template <class T>
TTreeElem<T>* TTreeTable<T>::GetNode() const
{
	return node;
}

template <class T>
TTreeElem<T>* TTreeTable<T>::Add(TTreeElem<T>& elem)
{

	if (count == 0)
	{
		node = new TTreeElem<T>(elem);
		count++;
		return node;
	}
	else
	{	
		TTreeElem<T>* par;
		TTreeElem<T>* curr = node;
		while (curr != NULL)
		{
			par = curr;
			if (elem.GetKey() > curr->GetKey())
				curr = curr->GetRight();
			else if (elem.GetKey() < curr->GetKey())
				curr = curr->GetLeft();
			else
				throw 1;
		}
		count++;
		if (elem.GetKey() > par->GetKey())
		{
			par->SetRight(new TTreeElem<T>(elem));
			//par->SetRight(&elem);
			par->GetRight()->SetParent(par);
			curr = par->GetRight();
		}
		else
		{
			par->SetLeft(new TTreeElem<T>(elem));
			//par->SetLeft(&elem);
			par->GetLeft()->SetParent(par);
			curr = par->GetLeft();
		}
		return curr;
	}
}

template <class T>
void TTreeTable<T>::Del(TTreeElem<T>& elem)
{
	TTreeElem<T>* par = elem.GetParent();
	TTreeElem<T>* nl = NULL;
	if (elem.GetLeft() != NULL && elem.GetRight() != NULL)
	{
		if (par->GetLeft() == &elem)
		{
			nl = par->GetLeft();
			par->SetLeft(elem.GetRight());
			elem.GetRight()->SetParent(par);
		}
		else
		{
			nl = par->GetRight();
			par->SetRight(elem.GetRight());
			elem.GetRight()->SetParent(par);
		}
		//nl = elem.GetRight();
		TTreeElem<T>* i = elem.GetRight();
		while (i->GetLeft() != NULL)
			i = i->GetLeft();
		i->SetLeft(elem.GetLeft());
		//nl->SetParent(par);
		i->GetLeft()->SetParent(i);
	}
	else if (elem.GetLeft() == NULL && elem.GetRight() != NULL)
	{
		if (par->GetLeft() == &elem)
		{
			par->SetLeft(elem.GetRight());
			nl = elem.GetRight();
			nl->SetParent(par);
		}
		else
		{
			par->SetRight(elem.GetRight());
			nl = elem.GetRight();
			nl->SetParent(par);
		}
	}
	else if (elem.GetLeft() != NULL && elem.GetRight() == NULL)
	{
		if (par->GetLeft() == &elem)
		{
			par->SetLeft(elem.GetLeft());
			nl = elem.GetLeft();
			nl->SetParent(par);
		}
		else
		{
			par->SetRight(elem.GetLeft());
			nl = elem.GetLeft();
			nl->SetParent(par);
		}
	}
	else
		nl = NULL;
	delete &elem;
	count--;
	//return true;
}

template <class T>
bool TTreeTable<T>::Del(const String& key)
{
	bool flag = false;
	TTreeElem<T>* par;
	TTreeElem<T>* curr = node;
	while (curr != NULL)
	{
		if (key > curr->GetKey())
		{
			par = curr;
			curr = curr->GetRight();
		}
		else if (key < curr->GetKey())
		{
			par = curr;
			curr = curr->GetLeft();
		}
		else
		{
			flag = true;
			break;
		}
	}
	if (curr == node && flag == true)
	{
		node = node->GetRight();
		TTreeElem<T>* i = curr->GetRight();
		if (i != NULL)
		{
			while (i->GetLeft() != NULL)
				i = i->GetLeft();
			i->SetLeft(curr->GetLeft());
			if (i->GetLeft() != NULL)
				i->GetLeft()->SetParent(i);
		}
	}
	else if (flag == true && key == par->GetLeft()->GetKey())
	{
		par->SetLeft(curr->GetRight());
		TTreeElem<T>* i = curr->GetRight();
		if (i != NULL)
		{
			while (i->GetLeft() != NULL)
				i = i->GetLeft();
			i->SetLeft(curr->GetLeft());
			if (i->GetLeft() != NULL)
				i->GetLeft()->SetParent(i);
		}
	}
	else if (flag == true && key == par->GetRight()->GetKey())
	{
		par->SetRight(curr->GetRight());
		TTreeElem<T>* i = curr->GetRight();
		if (i != NULL)
		{
			while (i->GetLeft() != NULL)
				i = i->GetLeft();
			i->SetLeft(curr->GetLeft());
			if (i->GetLeft() != NULL)
				i->GetLeft()->SetParent(i);
		}
	}
	if (flag == true)
	{
		delete curr;
		count--;
	}
	return flag;
}

template <class T>
TTreeElem<T>& TTreeTable<T>::Search(const String& key) const
{
	if (count == 0)
		return st;
	TTreeElem<T>* tmp = node;
	while (tmp != NULL)
	{
		if (tmp->GetKey() < key)
			tmp = tmp->GetRight();
		else if (tmp->GetKey() > key)
			tmp = tmp->GetLeft();
		else
			return *tmp;
	}
	return st;
}

template <class T>
T& TTreeTable<T>::operator[](const String& key) const
{
	return Search(key).GetData();
}