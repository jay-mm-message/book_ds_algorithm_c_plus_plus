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

void print_st_info_list(list orig) {
	if (orig == nullptr) return;

	list p = orig;
	while(p != nullptr) {
		p->get_st_info();
		p = p->next;
	}
	cout << "Display all elements in st_information.\n" << endl;
}

void copy_st_info(list &head, int *st_id, int *st_score, string *st_name, int leng) {
	list p = head;
	for(size_t i = 0 ; i < leng ; ++i) {
		list new_node = new node(st_id[i], st_score[i], st_name[i]);
		if (head != nullptr) {
			p->next = new_node;
			p = p->next;
		} else {
			head = new_node;
			p = head;
		}
	}
}

void invert(list &orig) {
	if (orig == nullptr) return;

	list curr_ptr = nullptr, remainder_ptr = nullptr;
	list orig_ptr = orig;
	
	while(orig_ptr != nullptr) {
		remainder_ptr = curr_ptr;
		curr_ptr = orig_ptr;
		orig_ptr = orig_ptr->next;
		curr_ptr->next = remainder_ptr;
	}
	orig = curr_ptr;
	cout << "After inverting all elements in st_information.\n" << endl;
}

int main() {
	const int size = 5;

	string st_a_name[size] = {"Allen", "Scott", "Marry", "Jon", "Mark"};
	int st_a_score[size] = {98, 58, 68, 77, 59};
	int st_a_id[size] = {1, 2, 3, 4, 5};

	string st_b_name[size] = {"andy", "michael", "may", "tom", "daniel"};
	int st_b_score[size] = {85, 95, 68, 72, 79};
	int st_b_id[size] = {1, 2, 3, 4 , 5};

	list head_a = nullptr, p_a = head_a;
	// for(size_t i = 0 ; i < size ; ++i) {
	// 	list new_node = new node(st_a_id[i], st_a_score[i], st_a_name[i]);
	// 	if (head_a != nullptr) {
	// 		p_a->next = new_node;
	// 		p_a = p_a->next;
	// 	} else {
	// 		head_a = new_node;
	// 		p_a = head_a;
	// 	}
	// }
	copy_st_info(head_a, st_a_id, st_a_score, st_a_name, size);
	print_st_info_list(head_a);

	list head_b = nullptr, p_b = head_b;
	// for(size_t i = 0 ; i < size ; ++i) {
	// 	list new_node = new node(st_b_id[i], st_b_score[i], st_b_name[i]);
	// 	if (head_b != nullptr) {
	// 		p_b->next = new_node;
	// 		p_b = p_b->next;
	// 	} else {
	// 		head_b = new_node;
	// 		p_b = head_b;
	// 	}
	// }

	copy_st_info(head_b, st_b_id, st_b_score, st_b_name, size);
	print_st_info_list(head_b);

	list combine_head = head_a;
	list p_t = head_a;
	while(p_t->next != nullptr) {
		p_t = p_t->next;
	}
	p_t->next = head_b;

	//print_st_info_list(combine_head);
	p_t = combine_head;
	int i = 0;
	while(p_t != nullptr) {
		p_t->id = i;
		p_t = p_t->next;
		++i;
	}
	print_st_info_list(combine_head);

	invert(combine_head);
	print_st_info_list(combine_head);
	
	return 0;
}