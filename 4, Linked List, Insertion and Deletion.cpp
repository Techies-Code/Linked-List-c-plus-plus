// Linked List.cpp
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int d){
		data=d;
		next = NULL;
	}

	~Node(){
		// will be dissussed later
	}
};

void insertAtEnd(Node* &head,int data){
	Node*n = new Node(data);

	// case 1 list is empty
	if(head==nullptr){
		head = n;
		return;
	}

	Node*tail = head;

	while(tail->next != nullptr){
		tail = tail->next;
	}

	tail->next = n;
}

void insertAtBeg(Node* &head,int data){

	Node*n = new Node(data);

	n->next = head;
	head = n;
}

void insertAtK(Node* &head ,int data, int k){

	if(k==1){
		insertAtBeg(head,data);
		return;
	}


	Node*n = new Node(data);

	Node* temp = head;
	int cnt =0;
	while(temp->next){
		cnt++;
		if(cnt == k-1){
			break;
		}

		temp = temp->next;
	}

	Node* temp2 = temp->next;

	temp->next = n;

	n->next = temp2;
}

void DeleteAtBeg(Node* &head){

	if(head == nullptr)
		return;

	Node*temp = head;

	head = head ->next;

	delete temp;

}

void DeleteAtEnd(Node* &head){

	if(head->next==nullptr){
		delete head;
		head = nullptr;
		return;
	}

	Node*tail = head;

	while(tail->next!=nullptr && tail->next->next !=nullptr){
		tail = tail->next;
	}

	delete tail->next;

	tail->next = nullptr;
}

void DeleteAtK(Node*&head, int k){

	if(k==1){
		DeleteAtBeg(head);
		return;
	}

	// Step-1 go to k-1 th pos
	Node* temp = head;
	int cnt =0;
	while(temp->next){
		cnt++;
		if(cnt == k-1){
			break;
		}

		temp = temp->next;
	}

	if(temp->next == nullptr)
		return;

	// Delete temp->next
	Node * temp2 = temp->next;

	// connect to next node

	temp->next = temp->next->next;

	// delete temp2;

	delete temp2;

}

void Print(Node*head){

	while(head != nullptr){
		cout<<head->data<<" ";
		head = head ->next;
	}
	cout<<endl;
}

Node* Search(Node*curr,int Key){
	while(curr){
		if(curr->data == Key)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

int main(){

	Node* head = nullptr;

	// insertAtEnd(head,24);
	// insertAtEnd(head,25);
	// insertAtEnd(head,27);
	// insertAtEnd(head,28);
	// insertAtEnd(head,30);

	// Print(head);

	// insertAtBeg(head,10);
	// insertAtBeg(head,11);
	// insertAtBeg(head,12);
	// insertAtBeg(head,13);
	
	// Print(head);

	insertAtK(head,1,1);
	insertAtK(head,2,2);
	insertAtK(head,3,3);
	insertAtK(head,5,4);
	insertAtK(head,4,4);
	Print(head);

	DeleteAtK(head,4);
	Print(head);

	return 0;
}