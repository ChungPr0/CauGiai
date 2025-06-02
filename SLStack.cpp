#include <iostream>
 
using namespace std;
 
template <class E>
struct Node {
    E element;
    Node<E> *next;
    Node(E e = E(), Node<E> *n = 0) : element(e), next(n) {}
};
 
template <class E>
class SLStack {
protected:
    Node<E> *head;
    int size;
public:
    SLStack() {
        this->head = nullptr;
        this->size = 0;
    }
 
    void print() {
        while (!isEmpty()) {
            cout << this->top() << " ";
            this->pop();
        }
    }
 
    void push(const E & e) {
        Node<E> *temp = new Node<E> (e);
        temp->next = head;
        head = temp;
        this->size++;
    }
 
 
    void pop() {
        if (this->isEmpty()) return;
        Node<E> *tmp = head;
        head = head->next;
        this->size--;
        delete tmp;
    }
 
    E top() const {
        if (!isEmpty()) {
            return head->element;
        }
        return -1;
    }
 
    void clear() {
        while (!this->isEmpty()) {
            this->pop();
        }
    }
 
    virtual ~SLStack() {
        this->clear();
    }
 
    int getSize() const {
        return this->size;
    }
 
    bool isEmpty() const {
        return this->size == 0;
    }
 
    SLStack (const SLStack<E> &) {
 
    }
 
    const SLStack<E> & operator== (const SLStack<E> &) {
 
    }
};
 
int main() {
    SLStack<int> sl;
    for(int i = 1; i <= 10; i++){
        sl.push(i);
    }
    sl.pop();
    cout << sl.getSize() << endl;
    sl.print(); cout << endl; // 9 8 7 6 5 4 3 2 1
    cout << sl.getSize() << endl;
    cout << sl.top();
    return 0;
}
