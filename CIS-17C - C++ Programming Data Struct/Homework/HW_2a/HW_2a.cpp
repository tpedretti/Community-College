//========================================
// File: HW_2
// =======================================
// Programmer: Taylor Pedretti
// Date: 8/18/2012
// Class: CIS 17C
// =======================================
//Main.cpp
#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	list myList;

	char option = NULL;
	int value = NULL;

	while(option != 'q') {
		cout << "Please enter an option:" << endl;
		cout << "quit(q), insert(i), insert in order(o), find(f), remove(r), print(p), sort(s)" << endl;
		cout << "Option: ";
		cin >> option;

		if(option != 'p' && option != 'q' && option != 's') {
			cout << "Plese enter the value for option " << option << ": ";
			cin >> value;
		}

		if(option == 'q') {
			cout << "Exiting the Program..\n";
			break;
		}

		switch(option) {
		case 'q':
			cout << "\nExiting the Program..\n";
			break;
		case 'i':
			myList.insert(value);
			break;
		case 'o':
			/* ~`Insert Sort `~ */
			myList.insertSort(value);
			break;
		case 'f':
			myList.find(value);
			break;
		case 'r':
			/* ~`REMOVE`~ */
			myList.remove(value);
			break;
		case 'p':
			myList.print();
			system("PAUSE");
			break;
		case 's':
			/* ~`SORT`~*/
			myList.sort();
			break;
		default:
			cout << "ERROR: Command not recognized!" << endl;
		}
		option = NULL;
		system("CLS");
	}
	return 0;
}
//Node.h
#include <iostream>

using namespace std;

#ifndef _NODE_H_
#define _NODE_H_

struct Node
{
	Node() {
		next = NULL;
	}
	~Node() {
		if(next!= NULL)
			delete next;
	}
	int data;
	Node* next;
};

#endif

//list.h
#include "node.h"

#ifndef _LIST_H_
#define _LIST_H_

class list
{
private:
	Node* head;
	int _length;

protected:	

public:
	list();
	list(int lenght) {
		_length = lenght;
	}
	~list();

	void insert(int);
	void insertSort(int, int);
	Node* find(int);
	void remove(int);
	void sort();
	void print();

};

#endif

//list.cpp
#include "list.h"	

list::list()	{
	head = NULL;
}
list::~list() { }

void list::insert(int num)	{
	if(head == NULL) {
		head = new Node;
		head->data = num;
		return;
	}
	//general case
	Node* i;
	for(i = head; i->next != NULL; i = i->next);
	i->next = new Node;
	i->next->data = num;
}
void list::insertSort(int num, int target)	{
	Node* i;
	Node* temp = NULL;
	Node* prev;

	//intitial case
	if(head == NULL) {
		head = new Node;
		head->data = num;
		return;
	}

	//head case
	if(num < head->data) {
		Node* victim = head;
		head = victim->next;
		victim->next = NULL;
		return;
	}

	//general Case
	temp->next = prev->next;
	prev->next = temp;

}

Node* list::find(int query)	{
	Node* results;
	for(results = head; results != NULL; results = results->next) {
		if(results->data = query)
			return results;
	}
}
void list::remove(int target)	{
	//initial case
	if(head == NULL)
		return;

	//head of the list case
	if(head->data == target) {
		Node* victim = head;
		head = victim->next;
		victim->next = NULL;
		delete victim;
		return;
	}
	for(Node* prev = head; prev != NULL; prev = prev->next) {
		if(prev->next->data == target) {
			Node* victim = prev->next; // locate victim
			prev->next = victim->next; //reroute list
			victim->next = NULL;	//isolate victim
			delete victim;			//... MUDER VICTIM
			return;		//profit
		}
	}
}
void list::print()
{
	for(Node* ptr = head; ptr != NULL; ptr = ptr->next) {
		cout << ptr->data << endl;
	}
}
void list::sort()
{
	Node* tmpPtr = head;
	Node* tmpNxt = head->next;

	int tmp;

	while(tmpNxt != NULL) {
		while(tmpNxt != tmpPtr) {
			if(tmpNxt->data < tmpPtr->data) {
				tmp = tmpPtr->data;
				tmpPtr->data = tmpNxt->data;
				tmpNxt->data = tmp;
			}
			tmpPtr = tmpPtr->next;
		}
		tmpPtr = head;
		tmpNxt = tmpNxt->next;
	}
}

//OUTPUT
/*
Please enter an option:
quit(q), insert(i), insert in order(o), find(f), remove(r), print(p), sort(s)
Option: p
0
1
4
5
7
Press any key to continue . . .
*/