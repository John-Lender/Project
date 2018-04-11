#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


struct Tree {
	int key;
	Tree* left;
	Tree* right;
};

void print(Tree *&first)
{
	if (first != NULL){
		print(first->left);
		cout << first->key << " ";
		print(first->right);
}
}
void Del_all(Tree *&first) {
	if (first != NULL) {
		Del_all(first->left);
		Del_all(first->right);
		delete(first);
	}
}
//*Tree min()


Tree* Delete_el(Tree *&first, int key) 
{
	if (first == NULL) {
		return first;
	}
	else if (first->key > key) {
		first->left = Delete_el(first->left, key);
	}
	else if (first->key < key) {
		first->right = Delete_el(first->right, key);
	}
	else if (first->left != NULL && first->right != NULL);
}


	//Tree* del(Tree* Ptree, int key)
	//{
	//	if (Ptree == nullptr)
	//		return Ptree;
	//	if (key < Ptree->key)
	//		Ptree->left = del(Ptree->left, key);
	//	else if (key > Ptree->key)
	//		Ptree->right = del(Ptree->right, key);
	//	else if (Ptree->left != nullptr && Ptree->right != nullptr)
	//	{
	//		Ptree->key = min(Ptree->right)->key;
	//		Ptree->right = del(Ptree->right, Ptree->key);
	//	}
	//	else if (Ptree->left != nullptr)
	//		Ptree = Ptree->left;
	//	else
	//		Ptree = Ptree->right;
	//	return Ptree;
	//}

	//void Del_el(Tree *&first, int key) {
	//	if (first == NULL) {
	//		cout << "0" << endl;
	//	}
	//	if (first->key > key) {
	//		Del_el(first->left, key);
	//	}
	//	else if (first->key < key) {
	//		Del_el(first->right, key);
	//	}else if ()
	//}
int minimum(Tree *&first) {
	if (first->left = NULL) {
		delete(first);
		first = NULL;
		return first->key;
	}
		return minimum(first->left);
}

Tree* dele(Tree *&first, int key) {
	if (first == NULL) {
		return first;
	}
	if (key < first->key) {
		first->left = dele(first->left, key);
	}
	else if (key > first->key) {
		first->right = dele(first->right, key);
	}
	else if (first->left != NULL && first->right != NULL) {
		first->key = minimum(first->right);
		first->right = dele(first->right, first->key);
	}
	else if (first->left != NULL) {
			first = first->left;
		}
		else {
			first = first->right;
		}
		return first;
	}
		

void insert(Tree *&first, int key)
{
	if (first == NULL) {
		first = new Tree;
		first->key = key;
		first->left = NULL;
		first->right = NULL;
	}
	if (first->key > key) {
		if (first->left != NULL) insert(first->left, key);
		else {
			first->left = new Tree;
			first->left->left = NULL;
			first->left->right = NULL;
			first->left->key = key;
		}
	}

	if (first->key < key) {
		if (first->right != NULL) insert(first->right, key);
		else {
			first->right = new Tree;
			first->right->right = NULL;
			first->right->left = NULL;
			first->right->key = key;
		}
	};
}



int main() {

	bool y = false;
	Tree *begin = NULL;
	string com;
	int k;
	while (com != "exit") {
		cout << "Enter command " << endl << "1) add" << endl << "2) print" << endl << "3) delete" << endl << "4) exit" << endl;
		cout << "Command: ";
		cin >> com;
		cout << endl;
		if (com == "add") {
			cout << "Enter key!: " << endl;
			cin >> k;
			insert(begin, k);
			y = true;
			cout << endl << "--------------" << endl;
		}
		else if (com == "print") {
			cout << "TREE" << endl;
			print(begin);
			cout << endl << "--------------" << endl;
			y = true;
		}
		else if (com == "delete") {
			cout << "Enter key!: " << endl;
			cin >> k;
			if (begin->left == NULL && begin->right == NULL) {
				delete(begin);
				begin = NULL;
			}
			else if (begin != NULL) {
				dele(begin, k);
			}
			dele(begin,k);
			cout << endl << "--------------" << endl;
			y = true;
		}
		else if (y = false) {
			cout << "Error. Enter other command !";
			cout << endl << "--------------" << endl;
		}
		y = false;
	}


	system("pause");


	return 0;
}
