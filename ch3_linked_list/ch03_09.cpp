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
			cout << "free delete.\n" << endl;
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
	if (head == nullptr) return;

	list cur = head;
	list start = head;

	do {
		cur->get_st_info();
		cur = cur->next;
	} while (cur != start);

	cout << "Display all elements in circle linked list.\n" << endl;
}

void invert_circle_linked_list(list &head) {
	list prev = nullptr, next = nullptr;
	list cur = head;
	list start = head;

	do {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	} while(cur != start);

	head->next = prev;
	head = prev;
	
	cout << "After inverting all elements in circle linked list.\n" << endl;
}

void insert_specified_position(list &head, int id, list tmp_node) {

	list new_node = new node(tmp_node->id, tmp_node->score, tmp_node->name);
	
	list cur = head;
	list start = head;

	do {
		if (cur->next->id == id) {
			new_node->next = cur->next;
			cur->next = new_node;
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
	
	cout << "Insert specified position: " << id << endl;
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

int main() {
	const int size = 5;
	string st_a_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_a_score[size] = {98, 58, 68, 77, 59};
	int st_a_id[size] = {1, 2, 3, 4, 5};

	list head = nullptr;
	create_circle_linked_list(head, st_a_id, st_a_score, st_a_name, size);
	print_circle_linked_list(head);

	insert_specified_position(head, 2, new node(2, 98, "Amy"));
	print_circle_linked_list(head);

	invert_circle_linked_list(head);
	print_circle_linked_list(head);

	return 0;
}