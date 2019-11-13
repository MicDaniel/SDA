#include<iostream>
#include<vector>

using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node(int value = 0) {
		this->value = value;
		this->next = NULL;
	}
	void setValue(int v) {
		this->value = v;
	}
	void setNext(Node* node) {
		this->next = node;
	}
	int getValue() {
		return this->value;
	}
	Node* getNext() {
		return this->next;
	}
};

class Stack {
private:
	int maxSize;
	vector<int> stackVect;
	int top;
public:
	Stack(int max) :maxSize(max), top(-1) {
		stackVect.resize(maxSize);
	}
	void push(int item) {
		stackVect[++top] = item;
	}
	int pop() {
		return stackVect[top--];
	}
	int peek() {
		return stackVect[top - 1];
	}
	bool isEmpty() {
		return (top == -1);
	}
	bool isFull() {
		return top == maxSize - 1;
	}
};

class Pqueue {
private:
	int maxSize;
	vector<int> queVect;
	int nItems;
public:
	Pqueue(int s) : maxSize(s), nItems(0) {
		queVect.resize(maxSize);
	}
	void insert(int item) {
		int j;
		if (nItems == 0)
			queVect[nItems++] = item;
		else {
			for (j = nItems - 1; j >= 0; j--) {
				if (item > queVect[j])
					queVect[j + 1] = queVect[j];
				else
					break;
			}
			queVect[j + 1] = item;
			nItems++;
		}
	}
	int remove() {
		return queVect[--nItems];
	}
	int minim() {
		return queVect[nItems - 1];
	}
	bool isFull() {
		return (nItems == maxSize);
	}
	bool isEmpty() {
		return nItems == 0;
	}
	void print() {
		for (int i = 0; i < nItems; i++) {
			cout << queVect[i] << ' ';
		}
	}
};

Pqueue* convert(Stack* stack) {
	Pqueue* q;
	q = new Pqueue(10);
	while (!stack->isEmpty()) {
		int toInsert = stack->pop();
		q->insert(toInsert);
	}
	return q;
}

int main() {
	//prioritate 0 => reclame
	//prioritate 100 => facturi

	Stack stack(10);
	stack.push(100);
	stack.push(0);
	stack.push(0);
	stack.push(100);
	stack.push(0);
	stack.push(100);
	stack.push(100);
	stack.push(0);
	stack.push(0);
	stack.push(0);
	Pqueue* q;
	q = convert(&stack);
	q->print();
}