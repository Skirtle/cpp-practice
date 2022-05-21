#pragma once

template <typename T>
class SinglyLinkedList {
	T data;
	Node* next;
public:
	SinglyLinkedList() {
		data = null;
		next = nullptr;
	}
};