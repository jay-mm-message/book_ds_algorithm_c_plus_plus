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
			cout << ", score: " << this->id;
			cout << ", name: " << this->name;
			cout << endl;
 		}
};

typedef st_info node;
typedef node *list;

void create_circular_linked_list(list &head, int *st_id, int *st_score, string *st_name, int leng) {
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

	cout << "The circular linked list has been created.\n" << endl;
}

void print_circular_linked_list(list head) {
	list cur = head;
	list start = head;

	do {
		cur->get_st_info();
		cur = cur->next;
	} while(cur != start);

	cout << "Display all elements in circular linked list.\n" << endl;
}

void merge_two_circular_linked_list(list head_a, list head_b) {
	list head = nullptr;

	head = head_a->next;
	head_a->next = head_b->next;
	head_b->next = head;

	cout << "Successfully merge two circular linked list.\n" << endl;
}

int main() {

	const int size = 5;

	string st_a_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_a_score[size] = {98, 58, 68, 77, 59};
	int st_a_id[size] = {1, 2, 3, 4, 5};

	string st_b_name[size] = {"andy", "michael", "may", "tom", "daniel"};
	int st_b_score[size] = {85, 95, 68, 72, 79};
	int st_b_id[size] = {1, 2, 3, 4 , 5};

	list head_a = nullptr;
	create_circular_linked_list(head_a, st_a_id, st_a_score, st_a_name, size);
	print_circular_linked_list(head_a);

	list head_b = nullptr;
	create_circular_linked_list(head_b, st_b_id, st_b_score, st_b_name, size);
	print_circular_linked_list(head_b);

	merge_two_circular_linked_list(head_a, head_b);

	cout << "head_a: " << endl;
	print_circular_linked_list(head_a);

	cout << "head_b: " << endl;
	print_circular_linked_list(head_b);

	return 0;
}