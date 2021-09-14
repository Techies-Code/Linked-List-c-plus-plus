// FindMiddle_LL.cpp
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int d){
		data = d;
		next = nullptr;
	}
};

Node* createLinkedList(){
	Node*head = nullptr;
	Node*tail = nullptr;

	int n,d;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>d;
		Node*n = new Node(d);

		if(head == nullptr){
			head = n;
			tail = n;
		}else{
			tail->next = n;
			tail = n;
		}
	}
	return head;
}

void FindMiddle(Node*head){
	Node*slow,*fast;
	slow = head;
	fast = head;
	// for finding first middle element use this loop
	/*
	while(fast){
		fast = fast->next->next;
		if(fast->next && fast->next->next){
			break;
		}
		slow = slow->next;
	}
	*/

	// for finding second middle as disscused in video
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<slow->data<<" ";
}



void Print(Node* head){

	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	freopen("input.txt","r",stdin);
	Node* head = createLinkedList();
	
	Print(head);
	FindMiddle(head);


	return 0;
}

