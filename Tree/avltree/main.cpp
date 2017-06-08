#include "Tree.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main()
{
	AVLTree AVL;
	//rand
	for (int i=0; i<10; i++)
		AVL.AVLAdd(10 - i, 0 + rand() % 10);
	AVL.print();

	//find
	int f = 3;
	cout << "Key = " << f << "  Elem=" << AVL.findElem(f) << endl;
	AVL.print();

	//del elem
	cout << "try Del 5 :" << endl;
	AVL.del(5);
	AVL.print();
	//del root
	cout << "try Del 7 :" << endl; //root!
	AVL.del(7);
	AVL.print();

	//dopzadanie
	cout << "Vsego Elementov : "<< AVL.AVLHeight2() << endl;

	system("pause");
	return 0;
}