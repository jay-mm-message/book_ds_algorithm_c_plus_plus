#include <iostream>
#include <vector>
using namespace std;

class node {
	public:
		int data;
		node* next;
};

void create_head(node* head[8], int data[20][2]) {
	
	node* p = nullptr;
	for (int v = 1 ; v <= 8 ; ++v) {

		head[v] = new node;
		head[v]->data = v;
		head[v]->next = nullptr;

		for (int i = 0 ; i < 20 ; ++i) {
			if (data[i][0] == v) {
				node* newNode = new node;
				newNode->data = data[i][1];
				newNode->next = nullptr;

				p = head[v];
				while(p->next != nullptr) {
					p = p->next;
				}

				p->next = newNode;
			}
		}
	}
}

void print_head(node* head[8]) {
	
	node* p = nullptr;

	for (int v = 1 ; v <= 8 ; ++v) {
		cout << "[" << v << "] = ";
		p = head[v]->next;
		do {
			cout << p->data << " ";
			p = p->next;
		} while(p != nullptr);
		cout << endl;
	}
}

vector<bool> visited(9, false);

void dfs(node* head[8], int current) {
	visited[current] = true;
	node* p = head[current]->next;
	
	cout << current << ' ';

	while(p != nullptr) {
		if (visited[p->data] == false) {
			dfs(head, p->data);
		}
		p = p->next;
	}
}

int main(void) {

		int data[20][2]={	{1,2},{2,1},{1,3},{3,1},
							{2,4},{4,2},{2,5},{5,2},
							{3,6},{6,3},{3,7},{7,3},
							{4,5},{5,4},{6,7},{7,6},
							{5,8},{8,5},{6,8},{8,6}};

		node* head[8];
		create_head(head, data);
		print_head(head);
		cout << "dfs: ";
		dfs(head, 1);
		cout << endl;
		
	return 0;
}