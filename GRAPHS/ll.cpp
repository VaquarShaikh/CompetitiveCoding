#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node* takeInput(){
	int data;
	cin>>data;
	Node* head = NULL;
	Node* tail = NULL;
	while(data != -1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}

void printList(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node* revIter(Node* head){
	Node *cur = head , *prev = NULL , *next = NULL;
	while(cur){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

Node* revRecursive(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* smallAns = revRecursive(head->next);
	Node* tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallAns;
}

Node* middleElement(Node* head){
	 Node *a = head , *b = head;
	 while(b != NULL && b->next != NULL){
	 	a = a->next;
	 	b = b->next->next;
	 }
	 return a;
}

int main(){
	Node* head = takeInput();
	printList(head);
	cout<<endl;
	// Node* temp = head;
	// Node* tt = revRecursive(temp);
	// printList(tt);
	// cout<<endl;
	Node* m = middleElement(head);
	cout<<m->data<<endl;
}