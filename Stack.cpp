#include <iostream>
using namespace std;

#define MAX 100  // Số phần tử tối đa của stack

class Stack {
private:
    int arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack day, khong the push.\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong, khong the pop.\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong, khong co phan tu top.\n";
            return -1; // hoặc throw exception
        }
        return arr[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack rong.\n";
            return;
        }
        cout << "Stack: ";
        for (int i = topIndex; i >= 0; --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    cout << "Top phan tu: " << st.top() << endl;

    st.pop();
    st.display();

    st.pop();
    st.pop();
    st.pop();  // thử pop khi rỗng

    return 0;
}
