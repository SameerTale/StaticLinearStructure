#include "LinearStructures.h"
#include <vector>

namespace LinearStructures {

	template <typename T>
	class ListNode {
	public:
		ListNode(T value, ListNode<T>* next) : value(value), next(next) {}
		ListNode(T value) : next(nullptr), value(value) {}
		ListNode() : next(nullptr) {}
		~ListNode() {}
		void deleteAllNexts() {
			next->deleteAllNexts();
			delete next;
		}
		ListNode<T>* next;
		T value;
	};

	template <typename T>
	class Stack {
	public:
		Stack() {
			_head = nullptr;
		}
		~Stack() {
			if (_head != nullptr)
				delete _head;
		}
		int push_back(T value) {
			if (_head == nullptr)
				_head = new ListNode<T>(value);
			else
				_head = new ListNode<T>(value, _head);
			return _size++;
		}

		bool pop_back() {
			if (_head == nullptr) return false;
			ListNode<T>* temp = _head;
			_head = _head->next;
			delete temp;
			_size--;
			return true;
		}

		T back() {
			return _head->value;
		}

		int size() { return _size; }

		bool pop_get(T& value) {
			if (_head == nullptr) return false;
			value = _head->value;
			return pop_back();
		}

		std::vector<T> getList() {
			std::vector<T> arr = std::vector<T>(_size);
			ListNode<T>* curr = _head;
			while (curr != nullptr)
			{
				arr.push_back(curr->value);
				curr = curr->next;
			}
			return arr;
		}

		void setList(std::vector<T> list) {
			for(T val : list)
			{
				push_back(val);
			}
		}

	protected:
		int _size = 0;
		ListNode<T>* _head;
	};

	template <typename T>
	class LinkedList : public Stack<T> {
	public:
		LinkedList() : Stack<T>() {}
		~LinkedList() {}
		bool Insert(int index, T value) {
			if (index < 0) return false;
			int backIndex = Stack<T>::_size - index;
			if (backIndex < 0) return false;
			if (backIndex == 0)
			{
				Stack<T>::push_back(value);
			}
			else
			{
				ListNode<T>* temp = Stack<T>::_head;
				for (int i = 0; i < backIndex - 1; i++)
				{
					temp = temp->next;
				}
				temp->next = new ListNode<T>(value, temp->next);
				Stack<T>::_size++;
			}
			return true;
		}

		bool Delete(int index) {
			if (index < 0) return false;
			int backIndex = Stack<T>::_size - index;
			if (backIndex < 1) return false;
			if (backIndex == 1) return Stack<T>::pop_back();
			ListNode<T>* temp = Stack<T>::_head;
			for (int i = 1; i < backIndex - 1; i++)
			{
				temp = temp->next;
			}
			ListNode<T>* todelete = temp->next;
			temp->next = temp->next->next;
			delete todelete;
			Stack<T>::_size--;
			return true;
		}
	};

	template <typename T>
	class Queue {
	public:
		Queue() {
			_head = nullptr;
			_tail = nullptr;
		}
		~Queue();
	private:
		T* _head;
		T* _tail;
	};


}