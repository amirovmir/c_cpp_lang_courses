#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    template<typename T>
    struct Node {
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

public:
    List() {
        size = 0;
        head = nullptr;
    }

    ~List() {
        removeNode();
    }

    void pushNode(T data);
    void removeNode();
    void deleteFront();
    void printList();
    int getSize() {
        return size;
    }

    int size;
    Node<T>* head;
};

template<typename T>
void List<T>::deleteFront() {
    Node<T>* temp = head;
    if (head->pNext != nullptr) {
        head = head->pNext;
        delete temp;
        size--;
    }
}

template<typename T>
void List<T>::removeNode() {
    while (size) {
        deleteFront();
    }
}

template <typename T>
void List<T>::pushNode(T data) {
    Node<T>* nd = new Node<T>();
    nd->data = data;
    nd->pNext = head;
    head = nd;
}

template <typename T>
void List<T>::printList() {
    Node<T>* current = head;

    while (current) {
        cout << current->data << " ";
        current = current->pNext;
    }
    cout << endl;
}

int main() {
    List<int> lst;
    cout << "Enter size" << endl;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
        lst.pushNode(rand() % 30);
    lst.printList();
    lst.deleteFront();
    lst.printList();
}
