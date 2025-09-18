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
			cout << "After freeing st_information of id: " << this->id << endl;
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

void print_st_info(list orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		ptr->get_st_info();
		ptr = ptr->next;
	}
	cout << "Display all elements in st_information list.\n" << endl;
}

void free_st_info(list &orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list tmp = ptr;
		ptr = ptr->next;
		delete ptr;
	}
	orig = nullptr;
	cout << "After freeing all elements in st_information list.\n" << endl;
}

void insert_tail(list new_node, list &orig) {
	if (orig == nullptr) {
		orig = new_node;
		return;
	}

	list ptr = orig;
	while(ptr->next != nullptr) {
		ptr = ptr->next;
	}
	ptr->next = new_node;
	return;
}

void insert_specified_position(list new_node, int index, list &orig) {
	if (orig == nullptr) {
		orig = new_node;
		return;
	}

	list ptr = orig;
	while(ptr != nullptr) {
		if (ptr->next->id == index) {
			break;
		}
		ptr = ptr->next;
	}

	new_node->next = ptr->next;
	ptr->next = new_node;
	
	ptr = new_node->next;
	while(ptr != nullptr) {
		ptr->id += 1;
		ptr = ptr->next;
	}

	cout << "After inserting at the specified position 3.\n" << endl;
}

int main() {

	const int size = 5;
	int st_no[size] = {1, 2, 3, 4 , 5};
	int st_score[size] = {85, 95, 68, 72, 79};
	string st_name[size] = {"andy", "michael", "may", "tom", "daniel"};

	list head = nullptr, ptr = head;
	for(size_t i = 0 ; i < size ; ++i) {
		list new_node = new node(st_no[i], st_score[i], st_name[i]);
		if (head != nullptr) {
			ptr->next = new_node;
			ptr = ptr->next;
		} else {
			head = new_node;
			ptr = head;
		}
	}

	print_st_info(head);
	insert_tail(new node(6, 100, "Jay"), head);
	print_st_info(head);
	int insert_position = 3;
	insert_specified_position(new node(insert_position, 88, "Ellen"), insert_position, head);
	print_st_info(head);

	return 0;
}