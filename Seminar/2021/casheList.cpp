#include <iostream>
#include <exception>
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
		while (head != nullptr) {
			Node<T>* cur = head;
			head = head->next;
			delete cur;
		}
	}

	void node_swap(Node<T>* n1, Node<T>* n2) {
		Node<T>* tmp;
		tmp = n1;
		n1 = n2;
		n1->next = tmp->next;
		tmp->next = n2->next;
		n2->prev = n1->prev;
		n1->prev = tmp->prev;
		n2 = tmp;
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
			throw std::out_of_range("Setter error!");
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
			throw std::out_of_range("Getter error!");
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
};


int main() {
	try {
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
	catch (exception& e) {
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	};
}
