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
typedef Tree<char> node;
typedef node *btree;

btree insert(btree root, char ch) {
	if (root == nullptr) return new Tree<char>(ch);
	if (ch > root->data) {
		root->r = insert(root->r, ch);
	}
	if (ch < root->data) {
		root->l = insert(root->l, ch);
	}
	return root;
}

void inorder(btree root) {
	if (root == nullptr) return;
	inorder(root->l);
	cout << root->data << ' ';
	inorder(root->r);
}

void dump_arr(char d[], int sz) {
	for(int i = 0 ; i < sz ; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;
}

int main() {
	char d[] = {'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
	int sz = sizeof(d) / sizeof(char);

	dump_arr(d, sz);

	btree root = nullptr;
	for(int i = 0 ; i < sz ; ++i) {
		root = insert(root, d[i]);
	}

	inorder(root);
	cout << endl;
	return 0;
}