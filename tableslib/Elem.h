#pragma once
#include "TString.h"
#include <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
  T data;
  String key;
public:
  TElem();
  TElem(const T& _data, const String& _key);
	~TElem();
  TElem& operator=(const TElem<T>& elem);
	bool operator==(const TElem<T>& elem);
	bool operator!=(const TElem<T>& elem);
  T& GetData();
  void SetData(const T& _data);
  String& GetKey();
  void SetKey(const String& _key);
  friend std::ostream& operator<<(std::ofstream& out, TElem<T>& elem)
	{
		out << elem.GetKey().GetArrChar() << "\t";
		out << elem.GetData() << std::endl;
		return out;
	}
};

template <class T>
TElem<T>::TElem()
{
  data = NULL;
}

template <class T>
TElem<T>::TElem(const T& _data, const String& _key)
{
  data = _data;
  key = _key;
}

template <class T>
TElem<T>::~TElem()
{
}

template <class T>
TElem<T>& TElem<T>::operator=(const TElem<T>& elem)
{
	if (this != &elem)
	{
		data = elem.data;
		key = elem.key;
	}
	return *this;
}

template <class T>
bool TElem<T>::operator==(const TElem<T>& elem)
{
	if (data == elem.data && key == elem.key)
		return true;
	return false;
}

template <class T>
bool TElem<T>::operator!=(const TElem<T>& elem)
{
	if (data == elem.data && key == elem.key)
		return false;
	return true;
}

template <class T>
T& TElem<T>::GetData()
{
  return data;
}

template <class T>
void TElem<T>::SetData(const T& _date)
{
  data = _date;
}

template <class T>
String& TElem<T>::GetKey()
{
  return key;
}

template <class T>
void TElem<T>::SetKey(const String& _key)
{
  key = _key;
}

//////////////////////////////////////////////////

template <class T>
class TTreeElem
{
protected:
	TTreeElem<T>* left;
	TTreeElem<T>* right;
	TTreeElem<T>* parent;
	String key;
	T data;
public:
	TTreeElem();
	TTreeElem(const T& _data, const String& _key, TTreeElem<T>* _left = NULL, TTreeElem<T>* _right = NULL, TTreeElem<T>* _parent = NULL);
	TTreeElem(const TTreeElem<T>& elem);
	~TTreeElem();
	TTreeElem<T>& operator=(const TTreeElem<T>& elem);
	bool operator==(const TTreeElem<T>& elem) const;
	bool operator!=(const TTreeElem<T>& elem) const;
	T& GetData();
	void SetData(const T& _data);
	String& GetKey();
	void SetKey(const String& _key);
	TTreeElem<T>* GetLeft();
	TTreeElem<T>* GetRight();
	TTreeElem<T>* GetParent();
	void SetLeft(TTreeElem<T>* _left);
	void SetRight(TTreeElem<T>* _right);
	void SetParent(TTreeElem<T>* _parent);
	friend std::ostream& operator<<(std::ofstream& out, TTreeElem<T>& elem)
	{
		out << elem.GetKey().GetArrChar() << "\t";
		out << elem.GetData() << std::endl;
		return out;
	}
};

template <class T>
TTreeElem<T>::TTreeElem()
{
	left = right = parent = NULL;
	data = NULL;
}

template <class T>
TTreeElem<T>::TTreeElem(const T& _data, const String& _key, TTreeElem<T>* _left, TTreeElem<T>* _right, TTreeElem<T>* _parent)
{
	data = _data;
	key = _key;
	left = _left;
	right = _right;
	parent = _parent;
}

template <class T>
TTreeElem<T>::TTreeElem(const TTreeElem<T>& elem)
{
	data = elem.data;
	key = elem.key;
	left = right = parent = NULL;
}

template <class T>
TTreeElem<T>::~TTreeElem()
{
	left = right = parent = NULL;
}

template <class T>
TTreeElem<T>& TTreeElem<T>::operator=(const TTreeElem<T>& elem)
{
	if (this != &elem)
	{
		left = elem.left;
		right = elem.right;
		parent = elem.parent;
		key = elem.key;
		data = elem.data;
	}
	return *this;
}

template <class T>
bool TTreeElem<T>::operator==(const TTreeElem<T>& elem) const
{
	if (key == elem.key && data == elem.data)
		return true;
	else
		return false;
}

template <class T>
bool TTreeElem<T>::operator!=(const TTreeElem<T>& elem) const
{
	if (key == elem.key && data == elem.data)
		return false;
	else
		return true;
}

template <class T>
T& TTreeElem<T>::GetData()
{
	return data;
}

template <class T>
void TTreeElem<T>::SetData(const T& _data)
{
	data = _data;
}

template <class T>
String& TTreeElem<T>::GetKey()
{
	return key;
}

template <class T>
void TTreeElem<T>::SetKey(const String& _key)
{
	key = _key;
}

template <class T>
TTreeElem<T>* TTreeElem<T>::GetLeft()
{
	return left;
}

template <class T>
TTreeElem<T>* TTreeElem<T>::GetRight()
{
	return right;
}

template <class T>
TTreeElem<T>* TTreeElem<T>::GetParent()
{
	return parent;
}

template <class T>
void TTreeElem<T>::SetLeft(TTreeElem<T>* _left)
{
	left = _left;
}

template <class T>
void TTreeElem<T>::SetRight(TTreeElem<T>* _right)
{
	right = _right;
}

template <class T>
void TTreeElem<T>::SetParent(TTreeElem<T>* _parent)
{
	parent = _parent;
}