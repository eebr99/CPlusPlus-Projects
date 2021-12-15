//Eric Blanco
#include <iostream>
#include<random>

class SortedListInterface{
	public:
		
		virtual void insert(int val)=0;
		virtual void removeFirst()=0;
		virtual void display()=0;
};


class Node{
	public:
		int val;
		Node *next;
};


class LinkedSortedList: public SortedListInterface{
	Node *head;

	public:
		
		LinkedSortedList();
		void insert(int val);
		void display();
		void removeFirst();
};


LinkedSortedList::LinkedSortedList(){
	head=NULL;
}


void LinkedSortedList::insert(int val){

	Node *cur=head,*newNode;

	newNode=new Node;

	newNode->val=val;

	newNode->next=NULL;

	if(head==NULL)
		head=newNode;
	else{
		if(head->val > val){
			newNode->next=head;
			head=newNode;
		}
		else{
			while(cur->next!=NULL && cur->next->val < val)
			cur=cur->next;
			newNode->next=cur->next;
			cur->next=newNode;
		}

	}

}


void LinkedSortedList::display(){
	Node *cur=head;
	while(cur!=NULL){
		std::cout<<cur->val<<" ";
		cur=cur->next;
	}
	std::cout<<std::endl;
}


void LinkedSortedList::removeFirst(){
	Node *cur=head;
	head=head->next;
	delete cur;
}

//Main.cpp
int main(){
	SortedListInterface *list=new LinkedSortedList;
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> distribution_1_100(1, 100);

	for(int i = 0; i < 20; i++)
		list->insert(distribution_1_100(random_engine));

	std::cout<<"Sorted linked list is : ";
	list->display();
	//remove first
	list->removeFirst();
	std::cout<<"\nSorted linked list after removing first element is : ";
	list->display();

}
