// Reverse Linked List.cpp
#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node*next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

Node* CreateList() {
	int n; cin >> n;
	Node* head = nullptr;
	Node* tail = nullptr;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		Node*n = new Node(d);

		if (head == nullptr) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = tail->next;
		}
	}

	return head;
}

Node* ReverseList(Node* head) {
	// links Changed
	Node* curr = head;
	Node* prev = nullptr;

	while (curr) {
		Node*temp = curr->next;
		curr->next = prev;

		prev = curr;
		curr = temp;
	}

	return prev;
}


Node* ReverseData(Node* head, Node* curr){

	if(curr->next==nullptr){
		swap(curr->data,head->data);
		return head->next;
	}

	Node * ans = ReverseData(head,curr->next);

	if(ans == nullptr || ans == curr || curr->next == ans)
		return nullptr;

	swap(ans->data,curr->data);
	return ans->next;

}


Node* ReverseListRec(Node* curr, Node* prev){

	if(curr->next == nullptr){
		curr->next = prev;
		return curr;
	}

	Node* ans = ReverseListRec(curr->next,curr);
	curr->next = prev;
	return ans;
}

void Print(Node*head) {

	while (head != nullptr) {
		cout << head->data << " ";
		head = head ->next;
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);

	Node*head = CreateList();

	Print(head);

	head = ReverseListRec(head,nullptr);

	Print(head);

	// // head = ReverseList(head);

	// // Print(head);


	// ReverseData(head,head);

	// Print(head);

	return 0;
}