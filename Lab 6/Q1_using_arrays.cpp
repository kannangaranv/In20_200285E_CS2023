#include <iostream>
#include <chrono>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE]; // array to store stack elements
    int top; // index of the top element of the stack

public:
    Stack() {
        top = -1; // initialize the top index to -1
    }

    bool isEmpty() {
        return (top == -1); // check if the stack is empty
    }

    bool isFull() {
        return (top == MAX_SIZE - 1); // check if the stack is full
    }

    void Push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl; // print an error message if the stack is full
            return;
        } else {
            arr[++top] = x; // add the element to the top of the stack
        }
    }
    

    int Pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl; // print an error message if the stack is empty
            return 0;
        } else {
            return arr[top--]; // remove and return the top element of the stack
        }
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl; // print an error message if the stack is empty
            return -1;
        } else {
            return arr[top]; // return the top element of the stack
        }
    }
    
    void Display(Stack s) {
        while (!s.isEmpty()) {
            cout << s.Pop() << " "; // remove and print each element in the stack
        }
        cout << endl;
    }
};

int main() {
     
    auto start_time = std::chrono::high_resolution_clock::now();
    
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
    
    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Execution time(using Arrays): " << elapsed_time.count() << " microseconds\n"; // print the execution time

    return 0;
}
