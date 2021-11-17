#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    template<typename T>
    struct Node {
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

public:

    List();
    ~List();

    void InsertNode(T data);
    void RemoveNode();
    void DeleteFront();
    void PrintList();

    int size;
    Node<T>* head;
};

template<typename T>
void List<T>::DeleteFront() {
    Node<T>* temp = head;

    head = head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::RemoveNode() {
    while (size) {
        DeleteFront();
    }
}

template<typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    RemoveNode();
}

template <typename T>
void List<T>::InsertNode(T data) {
    Node<T>* nd = new Node<T>();
    nd->data = data;
    nd->pNext = head;
    head = nd;
}

template <typename T>
void List<T>::PrintList() {
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
    int numberCount = 0;
    cin >> numberCount;
    for (int i = 0; i < numberCount; i++)
        lst.InsertNode(rand() % 30);
    lst.PrintList();
}
