
#include <iostream>
#include <chrono> // for timing the execution of the program
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {} // constructor for creating a new node with a given value
};

class Stack {
private:
    Node* top; // pointer to the top of the stack

public:
    Stack() : top(nullptr) {} // constructor for creating a new empty stack

    bool isEmpty() {
        return top == nullptr; // returns true if the stack is empty, false otherwise
    }

    void Push(int value) {
        Node* newNode = new Node(value); // create a new node with the given value
        newNode->next = top; // set the new node's next pointer to the current top of the stack
        top = newNode; // set the new node as the new top of the stack
    }

    void Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n"; // if the stack is empty, print an error message and return
            return;
        } else {
            Node* temp = top; // create a temporary pointer to the current top of the stack
            top = top->next; // set the new top of the stack to the next node in the list
            delete temp; // delete the old top of the stack
        }
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Error: stack is empty\n"; // if the stack is empty, print an error message and return -1
            return -1;
        } else {
            return top->data; // return the value of the top node in the stack
        }
    }

    void Display(Stack s) {
        if (isEmpty()) {
            cout << "Stack is empty\n"; // if the stack is empty, print a message and return
            return;
        } else {
            cout << "Stack: ";
            Node* curr = top; // create a pointer to the top of the stack
            while (curr != nullptr) { // iterate through the stack until the end is reached
                cout << curr->data << " "; // print the value of the current node
                curr = curr->next; // move to the next node in the stack
            }
            cout << endl;
        }
    }
};

int main() {
     
    auto start_time = chrono::high_resolution_clock::now(); // start timing the execution of the program
    
    Stack s;
    for(int i=0; i<10; i++){
        s.Push(rand() % 100); // push random numbers to the stack
    }
    s.Display(s); // display the stack contents
    for(int i=0; i<5; i++){
        s.Pop(); // remove 5 elements from the stack
    }
    s.Display(s); // display the updated stack contents
    for(int i=0; i<4; i++){
        s.Push(rand() % 100); // push 4 more random numbers to the stack
    }
    s.Display(s); // display the updated stack contents
    
    auto end_time = chrono::high_resolution_clock::now(); // stop timing the execution of the program

    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time); // calculate the elapsed time in microseconds

    cout << "Execution time(using Linked list): " << elapsed_time.count() << " microseconds\n"; // print the execution time

    return 0;
}

