#include <iostream>
using namespace std;

class st_info{
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

void print_st_info_list(list orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		ptr->get_st_info();
		ptr = ptr->next;
	}
	cout << "Display all elements in st_information.\n" << endl;
	return;
}

void invert(list &orig) {
	if (orig == nullptr) return;

	list orig_ptr = orig;
	list new_head_ptr = nullptr, new_remainder_ptr = nullptr;
	
	while(orig_ptr != nullptr) {
		new_remainder_ptr = new_head_ptr;
		new_head_ptr = orig_ptr;
		orig_ptr = orig_ptr->next;
		new_head_ptr->next = new_remainder_ptr;
	}
	
	orig = new_head_ptr;
	cout << "After inverting all elements in st_information.\n" << endl;

	return;
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
	invert(head);
	print_st_info_list(head);
	return 0;
}