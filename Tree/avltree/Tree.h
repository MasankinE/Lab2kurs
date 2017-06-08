#include <iostream>
using namespace std;

typedef int Type;

struct AVL
{
	AVL* right;
	AVL* left;
	Type key;
	int data;
	int height;
	AVL(Type k, int d)
	
	{ 
		height = 1;
		left = right = 0;
		data= d;
		key= k; 
		
	}
};

class AVLTree

{	
private:
AVL* root;

int AVLHeight(AVL* tree)
{
		return tree ? tree->height : 0;
	}

int GetBalance(AVL* tree)
{
		return AVLHeight(tree->right) - AVLHeight(tree->left);
	}


AVL* Balance(AVL* tree)
{
	HeightBalance(tree);
	if (GetBalance(tree) == 2)
	{

		if (GetBalance(tree->right) < 0)
			tree->right = RotateRight(tree->right);
		return RotateLeft(tree);

	}
	if (GetBalance(tree) == -2)
	{

		if (GetBalance(tree->left) > 0)
			tree->left = RotateLeft(tree->left);
		return RotateRight(tree);
	}
	return tree;
}


void HeightBalance(AVL* tree)
{
		int RHeight = AVLHeight(tree->right);
		int LHeight = AVLHeight(tree->left);
		tree->height = (LHeight>RHeight ? LHeight : RHeight) + 1;
}

AVL* AVLAdd(AVL* tree, Type k, int d)
{
	if (!tree) return new AVL(k,d);
	if (k<tree->key)
		tree->left = AVLAdd(tree->left, k,d);
	else
		tree->right = AVLAdd(tree->right, k,d);
	return Balance(tree);
}

AVL* RotateLeft(AVL* a)
{
	AVL* b = a->right;
	a->right = b->left;
	b->left = a;

	HeightBalance(a);
	HeightBalance(b);

	return b;
}


AVL* RotateRight (AVL* b)
{
	AVL* a = b->left;
	b->left = a->right;
	a->right = b;

	HeightBalance(b);
	HeightBalance(a);

	return a;
}



AVL* DeleteElem(AVL* tree, Type k)
{

	if (!tree) return 0;
	if (k < tree->key)
		tree->left = DeleteElem(tree->left, k);
	else if (k > tree->key)
		tree->right = DeleteElem(tree->right, k);
	else 
		{
			AVL* a = tree->left;
			AVL* b = tree->right;
			delete tree;
	if (!b) return a;
			AVL* min = Findmin(b);
			min->right = Deletemin(b);
			min->left = a;
		return Balance(min);
		}
	return Balance(tree);
}

AVL *find(AVL*tree, Type k)
{
	if (!tree)
		return NULL;
	else if (k == tree->key)
		return tree;
	else if (k<tree->key)
		tree->left = find(tree->left, k);
	else if (k > tree->key)
		tree->right = find(tree->right, k);
}

AVL* Findmin(AVL* tree)
{
	return tree->left ? Findmin(tree->left) : tree;
}

AVL* Deletemin(AVL* tree)
{
	if (tree->left == 0)
		return tree->right;
	tree->left = Deletemin(tree->left);
	return Balance(tree);
}


void  PrintAVL(AVL *tree, int level)
{
	if (tree->left)
		PrintAVL(tree->left, level + 1);

	for (int i = 0; i < level; i++) //shift
		cout << "       ";

	cout<<"("<<tree->key<<", "<<tree->data<<") "<<endl;
	if(tree->right)
		PrintAVL(tree->right, level + 1);
}

public:
	AVLTree() :root(0)
{
	}
	;

void AVLAdd(Type k, int d)
{
	root = AVLAdd(root, k,d);
}

Type findElem(Type key)
{
	AVL* tmp = find(root, key);
	return tmp ? tmp->data :NULL;
}

void del(Type key)
{
	if (key!=root->key) 
	DeleteElem(root, key);
	else cout << "error:root!"<< endl;
}

void print()
{
	PrintAVL(root, 0);
	cout << endl;
}

};
