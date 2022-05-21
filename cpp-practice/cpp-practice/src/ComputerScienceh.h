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
	bool is_empty() {
		return top == -1;
	}
	bool is_full() {
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
	bool is_empty() {
		return size == 0;
	}
	bool is_full() {
		return size == maxSize;
	}

};

int _8bit_to_int(std::bitset<8> bits) {
	int num = 0;
	for (int i = 0; i < 8; i++) {
		num += bits[i] * (int) (pow(2, i));
	}

	return num;
}

int _23bit_to_int(std::bitset<23> bits) {
	int num = 0;
	for (int i = 0; i < 23; i++) {
		num += bits[i] * (int)(pow(2, i));
	}

	return num;
}

std::bitset<8> uint_to_8bit(int decimal) {
	std::bitset<8> binary = std::bitset<8>(0);
	if (decimal < 0) return binary;

	int currDec = decimal;
	int index = 7;
	while (index >= 0) {
		int diff = currDec - (int)pow(2, index);
		if (diff >= 0) {
			binary.set(index, 1);
			currDec -= (int)pow(2, index);
		}

		index--;
	}

	return binary;
}

int largest_power_of_2(float x) {
	int power = 0;
	int curr = 1;

	while (curr < x) {
		curr *= 2;
		power++;
	}


	return power - 1;
}

float IEEE754_single_to_decimal(std::bitset<32> num) {
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

	int expo = _8bit_to_int(exponent) - bias;
	for (int i = mantissaSize - 1; i >= 0; i--) {
		fraction += mantissa[i] * pow(2, -(mantissaSize -i));
	}
	return (1 + fraction) * pow(2, _8bit_to_int(exponent) - bias) * ((sign[0] == 1) ? -1 : 1);
}

std::bitset<32> decimal_to_IEEE754_single(double decimal) {
	int sign = 0;
	if (decimal < 0) {
		sign = 1;
		decimal *= -1;
	}

	// Get exponent as binary
	int largestPower = largest_power_of_2(decimal);
	int decimalExponent = 127 + largestPower;
	std::bitset<8> binaryExponent = uint_to_8bit(decimalExponent);


	// Get mantissa as binary
	std::bitset<23> binaryMantissa = std::bitset<23>(0);
	if (largestPower < 0) largestPower = 0;
	double currDec = (decimal / (int)pow(2, largestPower));
	if (currDec >= 1) currDec--;
	// std::cout << "largestPower = " << largestPower << "\n";
	for (int i = 22; i >= 0; i--) {
		// std::cout << currDec << " * 2 = " << currDec * 2 << " -> " << ((currDec * 2 >= 1) ? 1 : 0) << "\n";
		currDec *= 2;
		if (currDec >= 1) {
			currDec -= 1;
			binaryMantissa.set(i, 1);
		}
		if (currDec == 0) break;
	}

	// Set bits
	std::bitset<32> binaryFloat = std::bitset<32>(0);
	binaryFloat.set(31, sign);
	for (int expoIndex = 7, floatIndex = 30; expoIndex >= 0; expoIndex--, floatIndex--) {
		binaryFloat.set(floatIndex, binaryExponent[expoIndex]); // FIX
	}
	for (int index = 22; index >= 0; index--) {
		binaryFloat.set(index, binaryMantissa[index]); // FIX
	}


	return binaryFloat;
}

