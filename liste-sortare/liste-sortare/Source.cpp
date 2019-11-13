#include<iostream>
#include<conio.h>

using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node(int value = 0);
	~Node();
	void setValue(int value = 0);
	int getValue();
	void setNext(Node* pointer);
	Node* getNext();
};

class List {
private:
	Node* first;
	Node* last;
public:
	List(Node* first = NULL,Node* last = NULL);
	~List();
	void setFirst(Node* pointer);
	Node* getFirst();
	void setLast(Node* pointer);
	Node* getLast();
	Node* createNode(int value);

	void addNode(int value);
	void addNodes(int nrNodes);
	void addBeforeIndex(int index);
	void addAfterIndex(int index);
	void addBeforeValue(int value);
	void addAfterValue(int value);
	void deleteNodeByValue(int value);
	void deleteNodeByIndex(int index);
	void searchNodeByValue(int value);
	void searchNodeByIndex(int index);
	void separateEvenOdd(List* evenList, List* oddList);
	void insertAverage(List* average);

	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void shellSort();
	void quickSort();

	void printList();
};

int main() {
	List* list1;
	List* evenList;
	List* oddList;
	List* averageList;
	list1 = new List(NULL, NULL);
	evenList = new List(NULL, NULL);
	oddList = new List(NULL, NULL);;
	averageList = new List(NULL, NULL);
	list1->printList();
	list1->addNodes(5);
	list1->printList();
	list1->bubbleSort();
	list1->printList();
	
	List* list2;
	list2 = new List(nullptr, nullptr);
	list2->addNodes(7);
	list2->printList();
	list2->selectionSort();
	list2->printList();
	
	List* list3;
	list3 = new List(nullptr, nullptr);
	list3->addNodes(5);
	list3->printList();
	list3->insertionSort();
	list3->printList();

	_getch();
	return 0;
}

Node::Node(int value)
{
	this->value = value;
	this->next = NULL;
}

Node::~Node()
{
	delete this->next;
}

void Node::setValue(int value)
{
	this->value = value;
}

int Node::getValue()
{
	return this->value;
}

void Node::setNext(Node * pointer)
{
	this->next = pointer;
}

Node * Node::getNext()
{
	return this->next;
}

List::List(Node * first, Node * last)
{
	this->first = first;
	this->last = last;
}

List::~List()
{
	delete this->first;
	delete this->last;
}

void List::setFirst(Node * pointer)
{
	this->first = pointer;
}

Node * List::getFirst()
{
	return this->first;
}

void List::setLast(Node * pointer)
{
	this->last = pointer;
}

Node * List::getLast()
{
	return this->last;
}

Node * List::createNode(int value)
{
	Node* newNode;
	newNode = new Node;
	return newNode;
}

void List::addNode(int value)
{
	Node *newNode;
	newNode = new Node;
	newNode->setValue(value);

	if (!this->getLast()) {
		this->setLast(newNode);
		this->setFirst(newNode);
	}
	else {
		this->getLast()->setNext(newNode);
		this->setLast(newNode);
		newNode->setNext(NULL);
	}
}

void List::addNodes(int nrNodes)
{
	for (int i = 0; i < nrNodes; i++) {
		int value;
		cout << "Insert value: ";
		cin >> value;
		this->addNode(value);
		cout << ' ';
	}
	cout << '\n';
}

void List::addBeforeIndex(int index)
{
	Node *newNode;

	newNode = new Node;
	int value;
	cout << "Insert value: ";
	cin >> value;

	if (!this->getFirst()) {
		this->setLast(newNode);
		this->setFirst(newNode);
		newNode->setNext(NULL);
	}
	else {
		newNode = this->getFirst();
		for (int i = 0; i < index - 1; i++) {
			if (!newNode->getNext()) {
				break;
			}
			newNode = newNode->getNext();
		}
	}
	newNode->setValue(value);
	cout << '\n';
}

void List::addAfterIndex(int index)
{
	Node *newNode;

	newNode = new Node;
	int value;
	cout << "Insert value: ";
	cin >> value;
	if (!this->getFirst()) {
		this->setLast(newNode);
		this->setFirst(newNode);
		newNode->setNext(NULL);
	}
	else {
		newNode = this->getFirst();
		for (int i = 0; i < index; i++) {
			if (!newNode->getNext()) {
				break;
			}
			newNode = newNode->getNext();
		}
	}
	newNode->setValue(value);

	cout << '\n';
}

void List::addBeforeValue(int value)
{
	Node * newNode, * previousNode, * pointer;
	previousNode = NULL;

	newNode = new Node;
	int valueToInsert;
	cout << "Insert value: ";
	cin >> valueToInsert;
	newNode->setValue(valueToInsert);
	newNode->setNext(NULL);

	if (!this->getFirst()) {
		this->setLast(newNode);
		this->setFirst(newNode);
		newNode->setNext(NULL);
	}
	else {
		pointer = this->getFirst();
		while (pointer->getNext() != NULL && pointer->getValue() <= value) {
			previousNode = pointer;
			pointer = pointer->getNext();
		}

		if (previousNode == NULL) {
			newNode->setNext(pointer);
			this->setFirst(newNode);
		}
		else {
			previousNode->setNext(newNode);
			newNode->setNext(pointer);
		}
	}
}

void List::addAfterValue(int value)
{
	Node* newNode, * pointer;
	newNode = new Node;
	int valueToInsert;
	cout << "Insert value: ";
	cin >> valueToInsert;
	newNode->setValue(valueToInsert);
	newNode->setNext(NULL);

	if (!this->getFirst()) {
		this->setLast(newNode);
		this->setFirst(newNode);
		newNode->setNext(NULL);
	}
	else {
		pointer = this->getFirst();
		while (pointer->getNext() != NULL && pointer->getValue() <= value) {
			pointer = pointer->getNext();
		}

		newNode->setNext(pointer->getNext());
		pointer->setNext(newNode);
	}
}

void List::deleteNodeByValue(int value)
{
	Node* pointer, * previousNode = NULL;;

	if (!this->getFirst())
		return;

	if (this->getFirst()->getValue() == value) {
		pointer = this->getFirst()->getNext();
		delete this->getFirst();
		this->setFirst(pointer);
	}
	else {
		pointer = this->getFirst();

		while (pointer->getNext() != NULL && pointer->getValue() != value) {
			previousNode = pointer;
			pointer = pointer->getNext();
		}
		previousNode->setNext(pointer->getNext());
		delete pointer;

	}

}

void List::deleteNodeByIndex(int index)
{
	Node* pointer, *previousNode;
	previousNode = NULL;

	if (!this->getFirst())
		return;

	if (index == 0) {
		pointer = this->getFirst()->getNext();
		delete this->getFirst();
		this->setFirst(pointer);
	}
	else {
		pointer = this->getFirst();
		int idx = 0;

		while (pointer->getNext() != NULL && idx < index) {
			previousNode = pointer;
			pointer = pointer->getNext();
			idx++;
		}

		previousNode->setNext(pointer->getNext());
		delete pointer;
	}
}

void List::searchNodeByValue(int value)
{
	Node *pointer;

	if (!this->getFirst()) {
		cout << "The list is empty";
		return;
	}
	
	int idx = 0;
	pointer = this->getFirst();
	while (pointer->getNext() != NULL && pointer->getValue() != value) {
		pointer = pointer->getNext();
		idx++;
	}

	cout << "Nodul " << idx << "are valoarea: " << pointer->getValue();
}

void List::searchNodeByIndex(int index)
{
	Node* pointer;

	if (!this->getFirst()) {
		cout << "The list is empty";
		return;
	}

	int idx = 0;
	pointer = this->getFirst();
	while (pointer->getNext() != NULL && idx < index) {
		pointer = pointer->getNext();
		idx++;
	}

	cout << "Nodul " << idx << "are valoarea: " << pointer->getValue();
}

void List::separateEvenOdd(List* evenList, List* oddList)
{
	Node* pointer;

	if (!this->getFirst()) {
		cout << "The list is empty";
		return;
	}

	pointer = this->getFirst();
	while (pointer != NULL) {
		if (pointer->getValue() % 2 == 0) {
			evenList->addNode(pointer->getValue());
		}
		else {
			oddList->addNode(pointer->getValue());
		}
		pointer = pointer->getNext();
	}
	
	cout << "Even - ";
	evenList->printList();

	cout << "Odd - ";
	oddList->printList();
}

void List::insertAverage(List* average)
{
	Node* pointer, * previous;

	if (!this->getFirst()) {
		cout << "The list is empty";
		return;
	}

	pointer = this->getFirst()->getNext();
	previous = this->getFirst();

	while (pointer != NULL) {
		average->addNode(previous->getValue());
		average->addNode((previous->getValue() + pointer->getValue()) / 2);
		average->addNode(pointer->getValue());

		previous = pointer->getNext();
		pointer = previous->getNext();
	}

	cout << "Average - ";
	average->printList();
}

void List::printList()
{
	Node* pointer = this->getFirst();

	if (!this->getFirst()) {
		cout << "The list is empty";
		return;
	}

	cout << "The list is: \n";
	while (pointer != NULL) {
		cout << pointer->getValue() << ' ';
		pointer = pointer->getNext();
	}
	cout << '\n';
}

void List::bubbleSort() {
	Node* start = this->getFirst();
	Node* current = nullptr;
	Node* previous = nullptr;
	Node* temp = nullptr;

	int counter = 0;
	while (start != NULL) {
		counter++;
		start = start->getNext();
	}

	for (int i = 0; i < counter; i++) {
		current = previous = this->getFirst();
		
		while (current->getNext() != NULL) {
			if (current->getValue() > current->getNext()->getValue()) {
				temp = current->getNext();
				current->setNext(current->getNext()->getNext());
				temp->setNext(current);
				//swap next of current and current->next;
				
				if (current == this->getFirst()) {
					previous = temp;
					this->setFirst(temp);
				}
				else {
					previous->setNext(temp);
				}
				current = temp;
			}
			previous = current;
			current = current->getNext();
		}
	}
}

void List::selectionSort(){

	Node* previousI = NULL;
	for (Node* i = this->getFirst();i->getNext() != NULL; i = i->getNext()) {
		Node* min = i;
		Node* previousMin = NULL;

		for (Node* j = i; j->getNext() != NULL; j = j->getNext()) {
			if (j->getNext()->getValue() < min->getValue()) {
				previousMin = j;
				min = j->getNext();
			}
		}

		if (previousMin != NULL) {
			if (i == previousMin) {
				if (i == this->getFirst()) {
					i->setNext(min->getNext());
					min->setNext(i);
					this->setFirst(min);
				}
				else {
					i->setNext(min->getNext());
					min->setNext(i);
					previousI->setNext(min);
				}
			}
			else {
				if (i == this->getFirst()) {

					Node* temp = i->getNext();
					i->setNext(min->getNext());
					min->setNext(temp);
					previousMin->setNext(i);
					this->setFirst(min);
				}
				else {
					Node* temp = i->getNext();
					i->setNext(min->getNext());
					min->setNext(temp);
					temp = previousI;
					previousI = previousMin;
					previousMin = temp;
				}
			}
		}

		previousI = i;
	}
}

void List::insertionSort()
{
	if (this->getFirst() == nullptr) {
		cout << "Empty list";
		return;
	}
	if (this->getFirst()->getNext() == nullptr) {
		return;
	}

	Node* current = this->getFirst();
	Node* auxiliar = nullptr;
	Node* previousCurrent = nullptr;
	Node* previousAuxiliar = nullptr;
	Node* helper;

	while (current->getNext() != nullptr) {
		previousCurrent = current;
		current = current->getNext();
		previousAuxiliar = nullptr;
		auxiliar = this->getFirst();

		while (auxiliar != current) {

			if (auxiliar->getValue() > current->getValue()) {
				if (auxiliar != previousCurrent) {
					if (previousAuxiliar == nullptr) { // cazul 1. auxiliarul este primul element.
						helper = current->getNext();
						current->setNext(auxiliar->getNext());

						current = auxiliar;
						current->setNext(helper);
						
						auxiliar = previousCurrent->getNext();
						previousCurrent->setNext(current);
						this->setFirst(auxiliar);
					}
					else {
						helper = current->getNext();
						current->setNext(auxiliar->getNext());

						current = auxiliar;
						current->setNext(helper);

						auxiliar = previousCurrent->getNext();
						previousCurrent->setNext(current);
						previousAuxiliar->setNext(auxiliar);
					}
				}
				else {
					if (previousAuxiliar == nullptr) {
						helper = current->getNext();
						
						current->setNext(auxiliar);

						current = auxiliar;
						current->setNext(helper);

						
						this->setFirst(auxiliar);

					}
					else {
						helper = current;
						helper->setNext(auxiliar);

						auxiliar->setNext(current->getNext());
						current = auxiliar;

						previousAuxiliar->setNext(helper);
						auxiliar = helper;
					}
				}
			}

			previousAuxiliar = auxiliar;
			auxiliar = auxiliar->getNext();
		}

	}
}