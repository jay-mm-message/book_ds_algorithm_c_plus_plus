#include <iostream>
using namespace std;

class st_info {
	public:
		st_info *next;
		int id;
		int score;
		string name;

	public:
		st_info(int id, int score, string name) {
			this->next = nullptr;
			this->id = id;
			this->score = score;
			this->name = name;
		}
		~st_info() {
			cout << "Free the st_info of id: " << this->id << endl;
		}
		void get_st_info() {
			cout << "id : " << this->id;
			cout << ", score: " << this->score;
			cout << ", name: " << this->name << endl;
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
	cout << "Display all element in st_info_list.\n" << endl;
}

void free_st_info(list &orig) {
	if (orig == nullptr) return;

	list ptr = orig;
	while(ptr != nullptr) {
		list tmp = ptr;
		ptr = ptr->next;
		//cout << "After freeing st_info of id: " << tmp->id << endl;
		delete tmp;
	}
	cout << "After freeing the st_information.\n" << endl;
}

void sort_st_info(list &orig) {
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
	return;
}

int main() {
	
	const int size = 5;
	int st_no[size] = {1, 2, 3, 4 , 5};
	int st_score[size] = {85, 95, 68, 72, 79};
	string st_name[size] = {"andy", "michael", "may", "tom", "daniel"};

	list head = nullptr, ptr = head;
	for(int i = 0 ; i < 5 ; ++i) {
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
	sort_st_info(head);
	print_st_info(head);
	free_st_info(head);
	
	return 0;
}