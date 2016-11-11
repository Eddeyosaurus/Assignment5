#include "List.h"


List::List()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}

List::~List()
{
	current = tail;

	while(current){
		tail = tail->prev;
		delete current;
		current = tail;
	}
}

List::List(const List& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			tail = current;
			otherPtr = otherPtr->next;
		}
	}
	else{
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	
}

List& List::operator=(const List& other)
{
	if(other.head)
	{
		nodePtr otherPtr;
		otherPtr = other.head;
		head = new Node;
		current = head;

		current->data = otherPtr->data;
		otherPtr = otherPtr->next;
		
		while(otherPtr)
		{
			current->next = new Node;
			current = current->next;
			current->data = otherPtr->data;
			tail = current;
			otherPtr = otherPtr->next;
		}
	}
	else{
		head = NULL;
		tail = NULL;
		current = NULL;
	}
}

void List::Insert(int i)
{
	nodePtr temp = new Node;
	temp->data = i;

	current = head;

	if(!head)
		head = temp;
	else{
		while(current)
		{
			if(current->data < i){
				temp->next = current->next;
				current->next = temp;
				temp->prev = current;
				temp->next->prev = temp;

				return;
			}
		}
	}
}

void List::Print()
{
	current = head;

	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}
