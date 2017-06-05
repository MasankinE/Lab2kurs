#pragma once
#include <iostream>

using namespace std;
#include <fstream>
const int DefSize = 100;

class List
{
public:
	int Data; 
	int Key; 
	
	List* Next;
	List (int k, int d)
		{
		this->Data = d;
		this->Key = k;
		this->Next = NULL;
		}
};

class HashTable
{

private:
	List ** htable;

public:
	HashTable()
		
	{
		htable = new List*[DefSize];
		for (int i = 0; i < DefSize; i++)
		htable[i] = NULL;
	}
	
	~HashTable()
		
	{
		for (int i = 0; i < DefSize; i++)
			{
			List* tmp = htable[i];
			while (tmp != NULL)
				{
				List* prev = tmp;
				tmp = tmp->Next;
				delete prev;
				}
			}
		delete[] htable;
	}

	void resize()
	{
		for (int i = 0; i < DefSize; i++)
		{
			List* tmp = htable[i];
			while (tmp != NULL)
			{
				List* prev = tmp;
				tmp = tmp->Next;
				delete prev;
			}
		}
		delete[] htable;
	}



	void Add(int k, int d)
	
	{
		List* tmp2 = new List(k,d);
		List* tmp = htable[Function(k)];
		if (tmp == NULL)
		
		{
				htable[Function(k)] = tmp2;
				return;

		}
		while (tmp->Next != NULL)
		{
			tmp = tmp->Next;
		}

		tmp->Next=tmp2;
		

	}

	void Delete(int k)
	
	{
		List* tmp = htable[Function(k)];
		List* prev = NULL;
		if (tmp == NULL)
		
		{
			cout << "no key" << endl;
			return;
		}

		else
		{
			if (tmp->Key != k)
			{
				cout << "no key" << endl;
				return;
			}
		}

		while (tmp->Next != NULL)
		{
			prev = tmp;
			tmp = tmp->Next;
		}

		if (prev != NULL)
		{
			prev->Next = tmp->Next;
		}

		delete tmp;
		cout << "key deleted";
		htable[Function(k)] = NULL;
	}
	
	int Print(int k)

	{
		
		bool flag = false;
		List* tmp = htable[Function(k)];
		while (tmp != NULL)
		{
			
			if (tmp->Key == k)
			{
				cout <<k<<" "<<tmp->Data << " "<<endl;
				fout <<k << " " << tmp->Data << " " << endl;
				flag = true;
			}
			tmp = tmp->Next;
		}

		if (!flag)
		{
			cout << "no key" ;
			return -1;

		}
	}

		int Function(int k) 
	{
		//return k % DefSize;
		return k % 5;
	}

	
	
};
