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
			cout << "After freeing id: " << this->id << endl;
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

void print_st_info_list(list orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		ptr->get_st_info();
		ptr = ptr->next;
	}
	cout << "Display all elements in st_information.\n" << endl;
}

void free_st_info_list(list &orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	cout << "After freeing all elements in st_information.\n" << endl;
}

void remove_specified_position(int index, list &orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		if (ptr->next->id == index) {
			break;
		}
		ptr = ptr->next;
	}

	list tmp = ptr->next;
	ptr->next = ptr->next->next;

	ptr = ptr->next;
	while(ptr != nullptr) {
		ptr->id -= 1;
		ptr = ptr->next;
	}

	cout << "Remove the specified position: " << tmp->id;
	cout << ", score: " << tmp->score;
	cout << ", name: " << tmp->name;
	cout << "\n" << endl;
	delete tmp;

	cout << "After deleting an the specified position: " << index << endl;
}

void free_st_information_list(list &orig) {

	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	orig = nullptr;
	cout << "After freeing all elements in st_information.\n" << endl;
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

	print_st_info_list(head);
	remove_specified_position(2, head);
	print_st_info_list(head);

	free_st_information_list(head);
	if (head != nullptr) {
		cout << "The st_information not freed.\n" << endl;
	} else {
		cout << "The st_information freed successfully.\n" << endl;
	}

	return 0;
}