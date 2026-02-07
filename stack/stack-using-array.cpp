#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
  TABLE OF CONTENTS:
  1. Stack Class Implementation (Array-based)
  2. Main Test Function (Usage Examples)
*/

/*
  LEARNING SUMMARY:
  1. this->member vs this.member: 
     - In C++, 'this' is a pointer to the current object. 
     - Use '->' to access members via a pointer. 
     - '.' is only for objects/references. 'this.size' is a compile error.

  2. Assignment Direction (this->size = size):
     - Always 'Target = Source;'.
     - We put the parameter 'size' into the class variable 'this->size'.
     - 'size = this->size' would incorrectly try to change the input parameter.

  3. Logical vs Physical Deletion:
     - pop() just does 'top--'. The value stays in memory (Physical), but is 
       ignored by the stack (Logical).
     - Why not set to 0 or NULL? Doing `arr[top] = 0;` requires an extra 'Write' 
       operation to RAM. Since `top--` already makes that index "inactive", 
       adding a write operation consumes unnecessary CPU cycles and memory 
       bandwidth for a value that will just be overwritten later.

  4. Class Essentials:
     - Constructor name must match Class name exactly.
     - Destructor (~Stack) is needed to free memory allocated with 'new' (prevents memory leaks).
     - Semicolon is mandatory after the closing brace of a class '};'.
*/



class Stack{
    private:
        int *arr;
        int top;
        int size;
    public:
        Stack(int size){
            this->size = size;
            this->top = -1;
            this->arr = new int[size];
        }
        ~Stack() {
            delete[] arr;
        }
        void push(int data){
            if(top == size-1){
                cout<<"Stack Overflow\n";
                return;
            }
            top++;
            arr[top] = data;
        }
        void pop(){
            if(top == -1){
                cout<<"Stack is empty\n";
                return;
            }
            top--;
        }
        int peek(){
            if(top == -1){
                cout<<"Stack is empty\n";
                return -1;
            }
            return arr[top];
        }
        bool isEmpty(){
            return top == -1;
        }
        bool isFull(){
            return top == size-1;
        }
        void display(){
            if(top == -1){
                cout<<"Stack is empty\n";
                return;
            }
            for(int i = top; i >= 0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main() {
    Stack s(3);

    cout << "Test: Pushing 1, 2, 3" << endl;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Stack structure: ";
    s.display();

    cout << "Peek top: " << s.peek() << endl;

    cout << "Popping all elements..." << endl;
    s.pop();
    s.pop();
    s.pop();

    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

/*
  =============================================================================
  PRODUCTION C++ KNOWLEDGE: .HPP FILES & PROJECT STRUCTURE
  =============================================================================

  1. What is an .hpp file?
     - It is a Header file (Header + Plus Plus).
     - Purpose: Separates the "Interface" (what the class does) from the 
       "Implementation" (how it does it).

  2. Why use .hpp in Production?
     - Compilation Efficiency: In large projects, you only recompile the .cpp 
       file that changed, not the entire codebase.
     - Avoiding Circular Dependencies: Using "Header Guards" (#pragma once) 
       ensures that if multiple files include the same header, the compiler 
       doesn't get confused by duplicate definitions.
     - API Design: You can ship the .hpp files to other developers so they can 
       use your library without ever seeing your private source code.

  3. Standard Production Layout:
     - stack.hpp: Contains the class definition, member variables, and 
                  function signatures.
     - stack.cpp: Contains the actual logic (e.g., void Stack::push(int d) { ... }).
     - main.cpp:  The entry point that #includes "stack.hpp" to use the tool.

  4. The Build Process in Infrastructure:
     - [Compiler] turns .cpp files into .obj (object) files.
     - [Linker] stitches all .obj files together into a single .exe.
     
  5. Pro Tip - Templates:
     - If you want this Stack to work for <string> or <float>, you would use 
       Templates. C++ Templates are usually written ENTIRELY in .hpp files 
       because the compiler needs the full logic to generate the specific 
       types at compile time.
  =============================================================================
*/


// Stack Implementation using Dynamic Array

class DynamicStack{
    private:
        vector<int> arr;
    public:
        DynamicStack(){
            arr = vector<int>();
        }
        ~DynamicStack(){
            arr.clear();
        }
        void push(int data){
            arr.push_back(data);
        }

        void pop(){
            if(arr.size() == 0){
                cout << "Stack Underflow" << endl;
                return;
            }
            arr.pop_back();
        }
        int peek(){
            if(arr.size() == 0){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[arr.size() - 1];
        }
        bool isEmpty(){
            return arr.size() == 0;
        }
        bool isFull(){
            return arr.size() == arr.capacity();
        }
        int size(){
            return arr.size();
        }
        void display(){
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

// int main() {
//     DynamicStack st;

//     // pushing elements
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     // popping one element
//     st.pop();

//     // checking top element
//     cout << "Top element: " << st.peek() << endl;

//     // checking if stack is empty
//     cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;
    
//     // checking current size
//     cout << "Current size: " << st.size() << endl;
// }