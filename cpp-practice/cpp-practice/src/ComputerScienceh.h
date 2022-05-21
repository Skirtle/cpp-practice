/* TO ADD
 Trees
 Heap
 Graph
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <bitset>

template <typename T>
class Node {
public:
	T data;
	Node* next;

	Node<T>() {
		data = nullptr;
		next = nullptr;
	}
	Node<T>(T d) {
		data = d;
		next = nullptr;
	}
	Node<T>(T d, Node<T>* n) {
		data = d;
		next = n;
	}
};

template <typename T>
class SinglyLinkedList {
public:
	Node<T>* head;

	SinglyLinkedList<T>() {
		head = new Node<T>();
	}
	SinglyLinkedList<T>(T data) {
		head = new Node<T>(data);
	}

	void add(T data) {
		if (head->data == NULL) {
			head->data = data;
			return;
		}

		Node<T>* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new Node<T>(data);
	}
	bool search(T data) {
		Node<T>* curr = head;
		while (curr->next != nullptr) {
			if (curr->data == data) return true;
			curr = curr->next;
		}
		return curr->data == data;
	}
	bool remove(T data) {
		if (head->data == data) {
			head = head->next;
			return true;
		}

		Node<T>* curr = head;
		bool found = false;
		while (curr->next != nullptr) {
			if (curr->next->data == data) {
				found = true;
				break;
			}
			curr = curr->next;
		}

		if (!found) return false;

		Node<T>* newNext = curr->next->next;
		curr->next = newNext;
		return true;
	}
	void print() {
		Node<T>* curr = head;
		std::cout << "[";

		if (curr == nullptr) {
			std::cout << "]\n";
			return;
		}

		do {
			std::cout << curr->data;
			curr = curr->next;
			if (curr == nullptr) {
				std::cout << "]\n";
				return;
			}

			std::cout << ", ";
		} while (curr->next != nullptr);

		std::cout << curr->data << "]\n";
	}
};

template <typename T>
class Stack {
private:
	T* stack;
public:
	int maxSize;
	int top;

	Stack<T>() {
		maxSize = 8;
		top = -1;
		stack = (T*) malloc(sizeof(T) * 8);
	}
	Stack<T>(int size) {
		maxSize = size;
		top = -1;
		stack = (T*) malloc(sizeof(T) * size);
	}
	~Stack<T>() {
		free(stack);
	}

	void print() {
		std::cout << "[";
		for (int i = 0; i < top; i++) {
			std::cout << stack[i] << ", ";
		}
		if (top == -1) {
			std::cout << "]\n";
			return;
		}
		std::cout << stack[top] << "]\n";
	}
	bool push(T data) {
		if (top >= maxSize - 1) return false;
		top++;
		stack[top] = data;
	}
	T pop() {
		if (top < 0) return NULL;
		return stack[top--];
	}
	T peek() {
		if (top < 0) return NULL;
		return stack[top];
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == maxSize - 1;
	}
};

template <typename T>
class Queue {
private:
	T* queue;
public:
	int maxSize;
	int size;

	Queue<T>() {
		maxSize = 8;
		size = 0;
		queue = (T*)malloc(sizeof(T) * 8);
	}
	Queue<T>(int length) {
		maxSize = length;
		size = 0;
		queue = (T*)malloc(sizeof(T) * length);
	}
	~Queue<T>() {
		free(queue);
	}

	void print() {
		if (size == 0) {
			std::cout << "[]\n";
			return;
		}

		std::cout << "[";
		for (int i = 0; i < size - 1; i++) {
			std::cout << queue[i] << ", ";
		}

		std::cout << queue[size - 1] << "]\n";
	}
	void enqueue(T data) {
		if (size >= maxSize) return;
		queue[size++] = data;
	}
	T dequeue() {
		if (size < 0) return NULL;
		return queue[--size];
	}
	T peek() {
		if (size == 0) return NULL;
		return queue[0];
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == maxSize;
	}

};

int _8bitToInt(std::bitset<8> bits) {
	int num = 0;
	for (int i = 0; i < 8; i++) {
		num += bits[i] * (int) (pow(2, i));
	}

	return num;
}

int _23bitToInt(std::bitset<23> bits) {
	int num = 0;
	for (int i = 0; i < 23; i++) {
		num += bits[i] * (int)(pow(2, i));
	}

	return num;
}

/*std::bitset<8> int_to_8bit(int decimal) {
	if ()
}*/

float IEEE754_to_decimal(std::bitset<32> num) {
	const int floatSize = 32;
	const int exponentSize = 8;
	const int mantissaSize = 23;
	const int bias = 127;

	std::bitset<floatSize> number = num;
	std::bitset<1> sign;
	std::bitset<exponentSize> exponent;
	std::bitset<mantissaSize> mantissa;
	float fraction = 0;

	sign.set(0, number[floatSize-1]);
	for (int i = mantissaSize, j = 0; i < floatSize - 1; i++, j++) {
		exponent.set(j, number[i]);
	}

	for (int i = 0; i < mantissaSize; i++) {
		mantissa.set(i, number[i]);
	}

	int expo = _8bitToInt(exponent) - bias;
	for (int i = mantissaSize - 1; i >= 0; i--) {
		fraction += mantissa[i] * pow(2, -(mantissaSize -i));
	}
	return (1 + fraction) * pow(2, _8bitToInt(exponent) - bias) * ((sign[0] == 1) ? -1 : 1);
}

std::bitset<32> decimal_to_IEEE754(float decimal) {
	int whole;
	float frac;

	return std::bitset<32>();
}

