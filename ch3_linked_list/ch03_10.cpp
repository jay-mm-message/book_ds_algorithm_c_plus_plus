#include <iostream>
using namespace std;

class st_info {
	public:
		int id;
		int score;
		string name;
		st_info *next;
	public:
		st_info(int id, int score, string name) {
			this->id = id;
			this->score = score;
			this->name = name;
			this->next = nullptr;
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

void print_circle_linked_list(list head) {

	list cur = head, start = head;
	do {
		cur->get_st_info();
		cur = cur->next;
	} while(cur != start);
	cout << "Display all elements in circle linked list.\n" << endl;
}

void create_circle_linked_list(list &head, int *st_id, int *st_score, string *st_name, int leng) {

	list cur = head;
	for(size_t i = 0 ; i < leng ; ++i) {
		list new_node = new node(st_id[i], st_score[i], st_name[i]);
		if (head != nullptr) {
			cur->next = new_node;
			cur = cur->next;
		} else {
			head = new_node;
			cur = head;
		}
	}
	cur->next = head;
	cout << "The circle linked list has been created and all elements have been stored.\n" << endl;
}

void remove_id(list &head, int id) {

	list cur = head, start = head;
	
	do {
		if (cur->next->id == id) {
			list tmp = cur->next;
			cur->next = cur->next->next;
			cout << "remove id: " << tmp->id;
			cout << ", score: " << tmp->score;
			cout << ", name: " << tmp->name;
			cout << endl;
			delete tmp;
			break;
		}
		cur = cur->next;
	} while(cur != start);

	int i = 1;
	cur = head;
	do {
		cur->id = i++;
		cur = cur->next;
	} while(cur != start);
}

int main() {
	const int size = 5;
	string st_a_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_a_score[size] = {98, 58, 68, 77, 59};
	int st_a_id[size] = {1, 2, 3, 4, 5};

	list head = nullptr;
	create_circle_linked_list(head, st_a_id, st_a_score, st_a_name, size);
	print_circle_linked_list(head);
	remove_id(head, 2);
	print_circle_linked_list(head);


	return 0;
}