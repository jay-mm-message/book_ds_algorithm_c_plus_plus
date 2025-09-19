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
			cout << "free node.\n" << endl;
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

	cout << "The linked list has been created and all elements have been stored.\n" << endl;
}

void print_circle_linked_list(list head) {

	if (head == nullptr) return;

	list cur = head;
	list start = head;

	do {
		cur->get_st_info();
		cur = cur->next;
	} while(cur != start);

	cout << "Display all elements in the linked list.\n" << endl;
}

void invert(list &head) {

	if (head == nullptr) return;
	
	list prev = nullptr, next = nullptr;
	list cur = head, start = head;

	do {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	} while(cur != start);

	head->next = prev;
	head = prev;

	cout << "After inverting all elements in listed list.\n" << endl;
}


int main() {
	const int size = 5;
	string st_a_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_a_score[size] = {98, 58, 68, 77, 59};
	int st_a_id[size] = {1, 2, 3, 4, 5};

	list head = nullptr;
	create_circle_linked_list(head, st_a_id, st_a_score, st_a_name, size);
	
	print_circle_linked_list(head);
	invert(head);
	print_circle_linked_list(head);

	return 0;
}