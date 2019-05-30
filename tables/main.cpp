#include <iostream>
#include "SeeTable.h"
#include "SortTable.h"
#include "TreeTable.h"
#include "HashTable.h"

//#define SEETABLE
//#define SORTTABLE
#define TREETABLE
//#define HASHTABLE
//#define TESTINGSORTS

using namespace std;

int main()
{
#ifdef SEETABLE
	TTable<int> table;
	int count;
	cout << "Write count of elements in table: ";
	cin >> count;
	TElem<int> curr_elem;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		int data;
		cout << "Write key " << i + 1 << ": ";
		cin >> str;
		cout << "Write data " << i + 1 << ": ";
		cin >> data;
		String curr_key(str);
		curr_elem.SetData(data);
		curr_elem.SetKey(curr_key);
		table.Add(curr_elem);
	}
	cout << endl << table;
	cout << "Write count of elements in table that you want to delete: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Write key: ";
		cin >> str;
		String curr_key(str);
		table.Del(curr_key);
	}
	cout << endl << table;	
#endif 
#ifdef TESTINGSORTS
	TTable<int> testtable(6);
	String key1("key1");
	String key2("key2");
	String key3("key3");
	String key4("key4");
	String key5("key5");
	String key6("key6");
	String key7("key7");
	String key8("key8");
	String key9("key9");
	String key10("key10");
	String key11("key11");
	String key12("key12");
	String key13("key13");
	String key14("key14");
	String key15("key15");
	String key16("key16");
	String key17("key17");
	String key18("key18");
	TElem<int> elem1(10, key1);
	TElem<int> elem2(15, key2);
	TElem<int> elem3(20, key3);
	TElem<int> elem4(5, key4);
	TElem<int> elem5(25, key5);
	TElem<int> elem6(1, key6);
	TElem<int> elem7(10, key7);
	TElem<int> elem8(15, key8);
	TElem<int> elem9(20, key9);
	TElem<int> elem10(5, key10);
	TElem<int> elem11(25, key11);
	TElem<int> elem12(1, key12);
	TElem<int> elem13(10, key13);
	TElem<int> elem14(15, key14);
	TElem<int> elem15(20, key15);
	TElem<int> elem16(5, key16);
	TElem<int> elem17(25, key17);
	TElem<int> elem18(1, key18);
	testtable.Add(elem1);
	testtable.Add(elem18);
	testtable.Add(elem2);
	testtable.Add(elem17);
	testtable.Add(elem3);
	testtable.Add(elem16);
	testtable.Add(elem4);
	testtable.Add(elem15);
	testtable.Add(elem5);
	testtable.Add(elem14);
	testtable.Add(elem6);
	testtable.Add(elem13);
	testtable.Add(elem7);
	testtable.Add(elem12);
	testtable.Add(elem8);
	testtable.Add(elem11);
	testtable.Add(elem9);
	testtable.Add(elem10);
	int nomberSort;
	cin >> nomberSort;
	switch (nomberSort)
	{
	case 1:
		TSortTable<int>::InsertSort(testtable);
		break;
	case 2:
		TSortTable<int>::MergeSort(testtable, 18, 0);
		cout << compare_cout << endl;
		break;
	case 3:
		TSortTable<int>::QuickSort(testtable, 0, 17);
		cout << compare_cout << endl;
		break;
	}
	cout << testtable;
#endif 
#ifdef SORTTABLE
	TSortTable<int> table;
	int count;
	cout << "Write count of elements in table: ";
	cin >> count;
	TElem<int> curr_elem;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		int data;
		cout << "Write key " << i + 1 << ": ";
		cin >> str;
		cout << "Write data " << i + 1 << ": ";
		cin >> data;
		String curr_key(str);
		curr_elem.SetData(data);
		curr_elem.SetKey(curr_key);
		table.Add(curr_elem);
	}
	cout << endl << table;
	cout << "Write count of elements in table that you want to delete: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Write key: ";
		cin >> str;
		String curr_key(str);
		table.Del(curr_key);
	}
	cout << endl << table;
#endif 
#ifdef HASHTABLE
	THashTable<int> table;
	int count;
	cout << "Write count of elements in table: ";
	cin >> count;
	TElem<int> curr_elem;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		int data;
		cout << "Write key " << i + 1 << ": ";
		cin >> str;
		cout << "Write data " << i + 1 << ": ";
		cin >> data;
		String curr_key(str);
		curr_elem.SetData(data);
		curr_elem.SetKey(curr_key);
		table.Add(curr_elem);
	}
	cout << endl << table;
	cout << "Write count of elements in table that you want to delete: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Write key: ";
		cin >> str;
		String curr_key(str);
		table.Del(curr_key);
	}
	cout << endl << table;
#endif 
#ifdef TREETABLE
	TTreeTable<int> table;
	int count;
	cout << "Write count of elements in table: ";
	cin >> count;
	TTreeElem<int> curr_elem;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		int data;
		cout << "Write key " << i + 1 << ": ";
		cin >> str;
		cout << "Write data " << i + 1 << ": ";
		cin >> data;
		String curr_key(str);
		curr_elem.SetData(data);
		curr_elem.SetKey(curr_key);
		table.Add(curr_elem);
	}
	cout << endl << table;
	cout << "Write count of elements in table that you want to delete: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Write key: ";
		cin >> str;
		String curr_key(str);
		table.Del(curr_key);
	}
	cout << endl << table;
#endif // TREETABLE
  return 0;
}