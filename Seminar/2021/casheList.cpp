#include <iostream>
using namespace std;

template <class T>
struct Node {
	int uid;
	T data;

	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;

	int calls = 0;

	Node() = delete;

	Node(int id) {
		uid = id;
	}
};

template <class T>
class List {
private:
	int size = 0;
	Node<T>* head;

public:

	List() {
		head = new Node<T>(size);
	}

	~List() {
		delete[] head;
	}

	void set(int id, T val)	{
		Node<T>* cur = head;
		while (cur->uid != id && cur->next != nullptr)
			cur = cur->next;

		if (cur->uid == id) {
			cur->calls++;
			cur->data = val;

			sort(cur);
		}
		else {
			cout << "Setter error";
		}
	}

	T get(int id) {
		Node<T>* cur = head;
		while (cur->uid != id && cur->next != nullptr)
			cur = cur->next;

		if (cur->uid == id) {
			cur->calls++;
			sort(cur);
			return cur->data;
		}
		else {
			cout << "Getter error";
			cout << "Returned first element:" << endl;
			return head->data;
		}
	}

	void push_new(Node<T>* item) {
		size++;
		(item->next) = new Node<T>(size);
		(item->next)->prev = item;
	}

	void push_back(T val) {
		Node<T>* cur = head;
		while (cur->next != nullptr) 
			cur = cur->next;

		push_new(cur);
		cur->data = val;
	}

	void print() {
		Node<T>* cur = head;
		while (cur->next != nullptr) {
			cout << cur->uid << ' ';
			cout << cur->data << endl;
			cur = cur->next;
		}
	}

	void node_swap(Node<T>* u1, Node<T>* u2) {
		T pdata = u1->data;
		int id = u1->uid;
		int cls = u1->calls;

		u1->data = u2->data;
		u1->uid = u2->uid;
		u1->calls = u2->calls;

		u2->data = pdata;
		u2->uid = id;
		u2->calls = cls;
	}



	void sort(Node<T>* cur) {
		while (cur->prev != nullptr) {
			if (cur->prev->calls < cur->calls)
				node_swap(cur->prev, cur);
			else 
				break;

			cur = cur->prev;
		}
	}
};


int main()
{
	List<int>* list = new List<int>();

	list->push_back(0);
	list->push_back(1);
	list->push_back(2);
	list->push_back(3);
	list->push_back(4);
	list->push_back(5);
	list->push_back(6);
	list->push_back(7);
	list->push_back(8);
	list->push_back(9);

	list->get(1);
	list->get(2);
	list->get(1);

	list->get(4);
	list->get(5);

	list->get(2);

	list->print();
}
