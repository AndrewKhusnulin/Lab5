#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int tabs = 0;
int value = 0;

template <class Type>
class BinarySearchTree
{
private:
	Type value, key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *parent;

public:
    BinarySearchTree(){};
	void insert(Type key, Type value, BinarySearchTree *&root_up)
	{
		if (!root_up)
		{
			root_up = new BinarySearchTree;
			root_up->value = value;
			root_up->key = key;
			root_up->parent = NULL;
			root_up->left = 0;
			root_up->right = 0;
			return;
		}
		else if (key > root_up->key)
		{
			insert(key, value, root_up->right); 
			root_up->right->parent = root_up;
		}
		else if (key < root_up->key) 
		{
			insert(key, value, root_up->left); 
			root_up->left->parent = root_up;
		}
		else return;
	}

	void find(Type value, BinarySearchTree *root)
	{
		if (!root)	return;
		if (root->value == value)
			cout << endl << "[+] The number " << value << " was found!" << endl;
		find(value, root->left);
		find(value, root->right);
	}
	void print(BinarySearchTree *root)
	{
		if (!root) return;
		tabs++;
		print(root->right);

		for (int i = 0; i < tabs; i++) cout << "- ";
		cout << root->value << endl;

		print(root->left);
		tabs--;
		return;
	}
	void printstream(BinarySearchTree *root)
	{

		if (!root) return;
		printstream(root->right);
		cout << root->value << " " << endl;
		printstream(root->left);
		return;
	}
	void remove(Type value, BinarySearchTree *root)
	{
		if (root == NULL) return;

		if (value > root->value) remove(value, root->right);
		else if (value < root->value) remove(value, root->left);
		else
		{
			if (!root->left && !root->right) // нет ни левого, ни правого
			{
				(root->parent->left == root) ? root->parent->left = NULL : root->parent->right = NULL;
				delete root;
				return;
			}
			else if (root->left && root->right) // есть и левый и правый
			{
				root->parent->left == root ? root->parent->left = root->left : root->parent->right = root->left;
				root->left->parent = root->parent;
				root->right->parent = NULL;
				insert(root->right->key, root->right->value, root->parent);
			}
			else if ((root->left && !root->right) || (!root->left && root->right))
			{
				BinarySearchTree *tmp;
				root->left ? tmp = root->left : tmp = root->right;
				root->parent->left == root ? root->parent->left = tmp : root->parent->right = tmp;
				delete root;
				return;
			}
		}
	}
	~BinarySearchTree(){};
};

int main()
{
	int choice;
	unsigned int key, value;

	BinarySearchTree <unsigned int> *root = 0;
	BinarySearchTree <unsigned int> *p;
	p = new BinarySearchTree <unsigned int>;
	while (1)
	{
		system("cls");
		cout << "  Binary Search Tree Operations  " << endl;
		cout << "  -----------------------------  " << endl;
		cout << "  1. Insert  ";
		cout << "  2. Print   ";
		cout << "  3. Delete  ";
		cout << "  4. Find    ";
		cout << "  5. Print stream  ";
		cout << "  0. Exit    " << endl;
		cout << "  Enter your choice :  ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "  Enter data to be inserted :  ";
			cin >> value;
			key = value; // key = f(value) ключ поиска
			p->insert(key, value, root);
			break;
		case 2: cout << endl;
			cout << "  Here is the tree  " << endl;
			cout << "  ------------------- " << endl;
			p->print(root);
			system("pause");
			break;
		case 3: cout << "  Enter data to be deleted :  ";
			cin >> value;
			p->remove(value, root);
			break;
		case 4: cout << "  Enter data to be searched :  ";
			cin >> value;
			p->find(value, root);
			system("pause");
			break;
		case 5: cout << endl;
			cout << "  Here is the stream  " << endl;
			cout << "  ------------------- " << endl;
			p->printstream(root);
			system("pause");
			break;
		case 0:
			return 0;
			break;
		}
	}
}
