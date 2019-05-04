#include "linkedlist.h"

linkedlist::linkedlist() {
head=NULL;
}

linkedlist::~linkedlist() {
    // RECURSIVE
		deleteNode(head);
}

void linkedlist::deleteNode(node * ptr){
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		delete ptr;
		deleteNode(ptr->next);
	}
}

int linkedlist::count() {
    // RECURSIVE
		node * temp=head;
		return(count(temp));
}

int linkedlist::count(node * ptr)
{
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		return(1+count(ptr->next));
	}
}

void linkedlist::addToFront(int n) {
	node * newNode = new node;
	newNode->data=n;
	newNode->next=head;
	head=newNode;
}

double linkedlist::average() {
    // uses sum and count functions
double avg=(double(sum())/double(count()));
		return(avg);
}

int linkedlist::sum() {
    // RECURSIVE
		node * temp=head;
		return(sum(temp));
}

int linkedlist::sum(node * ptr)
{
	if(ptr==NULL)
	{
		return 0;
	}
	else
	{
		return(ptr->data+sum(ptr->next));
	}
}

void linkedlist::writeInorder(ofstream & outData) {
node * temp=head;
while(temp!=NULL)
{
	outData<<temp->data<<" ";
	temp=temp->next;
}
outData<<endl;
}

void linkedlist::writeReversed(ofstream & outData) {
    // RECURSIVE
		node * temp=head;
		writeReversed(head, outData);
}

void linkedlist::writeReversed(node * ptr, ofstream & outData)
{
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		writeReversed(ptr->next, outData);
		outData<<ptr->data<<" ";
	}
}

void linkedlist::printList()
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void linkedlist::insertInOrder(int num)
{
	if(head==NULL)
	{	//If the linked list is empty just add to the front.
		addToFront(num);
		return;
	}
	node * curr=head;
	if(num<curr->data)
	{	//If the number is less than the first number in the list.
		node * newNode=new node;
		newNode->data=num;
		newNode->next=curr;
		head=newNode;
		return;
}
curr=head;
node * prev=NULL;
	while(curr!=NULL && num>curr->data)
	{
		prev=curr;
		curr=curr->next;
	}
	node * newNode = new node;
	newNode->data=num;
	newNode->next=curr;
	prev->next=newNode;
return;
}
