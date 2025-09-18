#include <iostream>
#include <cstring>
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
			cout << "free id: " << this->id << endl;
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

void print_st_list(list orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		ptr->get_st_info();
		ptr = ptr->next;
	}
	cout << "After display all the information in st_information.\n" << endl;
}

void free_st_list(list &orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	orig = nullptr;
	cout << "After freeing the st_information list using the delete method.\n" << endl;	
}

void sort_st_info(list orig) {

	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list curr = ptr->next;
		while(curr != nullptr) {
			if (ptr->score < curr->score) {
				int id = ptr->id;
				int score = ptr->score;
				string name = ptr->name;
				
				ptr->id = curr->id;
				ptr->score = curr->score;
				ptr->name = curr->name;

				curr->id = id;
				curr->score = score;
				curr->name = name;
			}
			curr = curr->next;
		}
		ptr = ptr->next;
	}
	cout << "After sorting the st_information list." << endl;
}

int main() {

	const int size = 5;
	int st_no[size] = {1, 2, 3, 4, 5};
	int st_score[size] = {85, 95, 68, 72, 79};
	string st_name[size] = {"andy", "michael", "may", "tom", "daniel"};

	list head = nullptr, ptr = head;
	for(size_t i = 0 ; i < size ; ++i) {
		// allocate st_info node
		list new_node = new node(st_no[i], st_score[i], st_name[i]);
		// storage st_info
		if (head != nullptr) {
			ptr->next = new_node;
			ptr = ptr->next;
		} else {
			head = new_node;
			ptr = head;
		}
	} 

	print_st_list(head);
	sort_st_info(head);
	print_st_list(head);
	free_st_list(head);

	if(head != nullptr) {
		cout << "The student information list isn't empty." << endl;
	} else {
		cout << "The student information list is clear." << endl;
	}
	
	return 0;
}