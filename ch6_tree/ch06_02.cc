/*	int d[] = {0, 6, 3, 5, 9, 7, 8, 4, 2}; */
#include <iostream>
using namespace std;


template<class T>
class Tree {
	public:
		T data;
		Tree *r, *l;
	public:
		Tree(T d): data(d), r(nullptr), l(nullptr) {};
};
typedef Tree<int> node;
typedef node *btree;

btree insert(btree root, int d) {
	if (root == nullptr) return new Tree<int>(d);
	if (d > root->data) {
		root->r = insert(root->r, d);
	}
	if (d < root->data) {
		root->l = insert(root->l, d);
	}
	return root;
}

void inorder(btree root) {
	if (root == nullptr) return;
	inorder(root->l);
	cout << root->data << ' ';
	inorder(root->r);
}

void dump_arr(int d[], int sz) {
	for(int i = 1 ; i < sz ; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;
}

int main() {
	int d[] = {0, 6, 3, 5, 9, 7, 8, 4, 2};
	int sz = sizeof(d) / sizeof(int);

	dump_arr(d, sz);

	btree root = nullptr;
	for(int i = 1 ; i < sz ; ++i) {
		root = insert(root, d[i]);
	}

	inorder(root);
	cout << endl;
	return 0;
}