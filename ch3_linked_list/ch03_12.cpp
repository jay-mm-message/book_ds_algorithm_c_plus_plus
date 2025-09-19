#include <iostream>
using namespace std;

class st_info {
	public:
		int id;
		int score;
		string name;
		st_info *rlink;
		st_info *llink;
	public:
		st_info(int id, int score, string name) {
			this->id = id;
			this->score = score;
			this->name = name;
			this->rlink = nullptr;
			this->llink = nullptr;
		}
		~st_info() {
			cout << "free node" << endl;
		}
		void get_st_info() {
			cout << "id: " << this->id;
			cout << ", score: " << this->score;
			cout << ", name: " << this->name;
			cout << endl;
		}
};

typedef st_info node;
typedef node *list;

void print_from_R(list head) {
	cout << "Display all elements from Right.\n";
	list cur = head;
	while(cur != nullptr) {
		cur->get_st_info();
		cur = cur->rlink;
	}
}

void print_from_L(list head) {

	cout << "Display all elements from left.\n";
	list tail = head;
	while(tail->rlink != nullptr) {
		tail = tail->rlink;
	}
	while(tail != nullptr) {
		tail->get_st_info();
		tail = tail->llink;
	}
}

void create_a_double_linked_list(list &head, int size, int *st_id, int *st_score, string *st_name) {

	list cur = head;
	for(size_t i = 0 ; i < size ; ++i) {
		list new_node = new node(st_id[i], st_score[i], st_name[i]);
		if (head != nullptr) {
			cur->rlink = new_node;
			new_node->llink = cur;
			cur = cur->rlink;
		} else {
			head = new_node;
			cur = head;
		}
	}

	cout << "\nThe double linked list has been created and all elements have been stored.\n";
	print_from_R(head);
	print_from_L(head);
}

void remove_id(list head, int id) {
	list cur = head;
	while (cur != nullptr) {
		if (cur->rlink->id == id) {
			list tmp_node = cur->rlink;
			cur->rlink = cur->rlink->rlink;
			cur->rlink->llink = cur;
			tmp_node->llink = nullptr;

			cout << "\nAfter remove node: ";
			tmp_node->get_st_info();

			print_from_R(head);
			print_from_L(head);

			delete tmp_node;
			break;
		}
		cur = cur->rlink;
	} 
}

void insert_node(list head, list node) {
	list cur = head;
	while(cur != nullptr) {

		if (cur->rlink->id > node->id) {
			node->rlink = cur->rlink;
			cur->rlink->llink = node;
			cur->rlink = node;
			node->llink = cur;

			cout << "\nAfter inserting node: ";
			node->get_st_info();

			print_from_R(head);
			print_from_L(head);
			break;
		}
		cur = cur->rlink;
	}
}

int main() {

	const int size = 5;
	string st_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_score[size] = {98, 58, 68, 77, 59};
	int st_id[size] = {1, 2, 3, 4, 5};

	list head = nullptr;

	create_a_double_linked_list(head, size, st_id, st_score, st_name);
	remove_id(head, 2);
	insert_node(head, new node(2, 99, "Sandy"));

	return 0;
}