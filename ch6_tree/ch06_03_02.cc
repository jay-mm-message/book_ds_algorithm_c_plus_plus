#include <iostream>
using namespace std;

class Tree
{
	public:
		int data;
		class Tree *left, *right;

	public:
		Tree(int d) : data(d), left(nullptr), right(nullptr) {};
};

typedef Tree node;
typedef node *btree;



void preorder(btree root) {
	if (root == nullptr) { return; }
	if (root != nullptr) {
		cout << root->data << ' ';
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(btree ptr)
{
	if (ptr == nullptr) { return; }

	if (nullptr != ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}

void postorder(btree root) {
	if (root == nullptr) { return; }

	if (root != nullptr) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << ' ';
	}
}

/*

btree creat_tree(btree root, int val)
{
	btree newnode, current, backup;

	newnode = new Tree(val);

	if (root == nullptr) {
		return new Tree(val);
	}
	
	else {
		int count = 0;
		cout << "root:[" << count << "]: ";
		inorder(root);
		++count;
		cout << endl;
		for (current = root; current != nullptr ;)
		{
			cout << "current:[" << count << "]: ";
			inorder(current);
			++count;
			cout << endl;
			backup = current;
			if (current->data > val)
				current = current->left;
			else
				current = current->right;
		}

		if (backup->data > val)
			backup->left = newnode;
		else
			backup->right = newnode;

		cout << "backup:[" << count << "]: ";
		inorder(backup);
		++count;
		cout << endl;
	}
	return root;
}

*/

btree creat_tree(btree root, int data) {
	if (nullptr == root) { return new Tree(data);}
	else {
		btree backup = nullptr;
		btree current = nullptr;

		for(current = root ; current != nullptr ;) {
			backup = current;
			if (data > current->data) {
				current = current->right;
			} else {
				current = current->left;
			}
		}
		if (data > backup->data) {
			backup->right = new Tree(data);
		} else {
			backup->left = new Tree(data);
		}
	}
	return root;
}

int main()
{
	int i, data[] = {7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2};
	//int i, data[] = {5, 6, 24, 8, 12};
	btree ptr = nullptr;
	btree root = nullptr;

	for (i = 0; i < sizeof(data) / sizeof(int); ++i) {
		cout << data[i] << ' ';
	}
	cout << endl;
	
	for (i = 0; i < sizeof(data) / sizeof(int); i++)
		ptr = creat_tree(ptr, data[i]);

	cout << "====================\n";
	
	cout << "preorder: " << endl;
	preorder(ptr);
	cout << "\n" << endl;
	cout << "inorder: " << endl;
	inorder(ptr);
	cout << "\n" << endl;
	cout << "postorder: " << endl;
	postorder(ptr);
	cout << "\n" << endl;
	return 0;
}