/*
  TABLE OF CONTENTS:
  1. Learning Summary (Linked List Mechanics)
  2. Competitive Programming & HFT Insights
  3. Stack Implementation (Linked List)
*/

/*
  LEARNING SUMMARY:

  1. CP & HFT (High Frequency Trading) Context:
     - Competitive Programming: Linked lists are used when you need 
       O(1) insertions/deletions at the head and don't know the size 
       beforehand. However, arrays are often preferred because they are 
       "Cache Friendly" (data is stored together in memory).
     - HFT: In HFT, "Latency is King." Linked lists are often AVOIDED in 
       hot paths because they cause "Cache Misses." Every time you follow 
       `next`, the CPU has to look up a new, far-away memory address. 
       Fixed-size ring buffers or pre-allocated pools are used instead.

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    public:
        Node* top;

        Stack(){
            top = NULL;
        }

        ~Stack() {
            while (top != NULL) {
                pop();
            }
        }

        void push(int data){
            Node* newNode = new Node(data);
            newNode -> next = top;
            top = newNode;
        }
        void pop(){
            if(top == NULL){
                cout << "Stack Underflow" << endl;
                return;
            }
            Node* temp = top;
            top = top -> next;
            delete temp;
        }
        int peek(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top -> data;
        }
        bool isEmpty(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return true;
            }
            cout << "Stack is not empty" << endl;
            return false;
        }
        int size(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return 0;
            }
            Node* temp = top;
            int count = 0;
            while(temp != NULL){
                count++;
                temp = temp -> next;
            }
            return count;
        }
};

int main() {
    Stack st;

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped top element" << endl;
    st.pop();

    // checking top element
    cout << "Top element: " << st.peek() << endl;

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    // checking current size
    cout << "Current size: " << st.size() << endl;

    return 0;
}
