#include <iostream>
#include <vector>

using namespace std;

const int STACK_SIZE = 5;
vector<int> stackVector;

void push(int val) {
    stackVector.push_back(val);
}

void pop() { stackVector.pop_back(); }

int top() { return stackVector.back(); }

bool isEmpty() { return stackVector.size() == 0; }

int main() {
    for (int i = 0; i < STACK_SIZE; i++) {
        push(i);
    }
    
    cout << "Top of stack is: " << top() << endl;
    cout << "The correct answer is the last item pushed on which is 4.\n";
    
    pop();
    pop();
    
    cout << "Top of stack is: " << top() << endl;
    cout << "The correct answer is the last item pushed on which is 2.\n";
    
    while(!isEmpty()) {
        cout << "Stack: " << top() << endl;
        pop();
    }
}
