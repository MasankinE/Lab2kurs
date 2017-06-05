#include "HashTable.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

//#include "stdafx.h"
#include <fstream>
using namespace std;


int main() 
{



	setlocale(LC_ALL, "Russian");
	HashTable t;

	for (int i = 0; i < 20; i++)
		t.Add(0 + rand() % 10, 0+rand() %10);

	for (int i = 0; i < 10; i++)
		t.Print(i);

	system("pause");
	return 0;
}