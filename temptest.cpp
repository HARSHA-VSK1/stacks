#include <iostream>
using namespace std;
#include "stack1.h"

int main(){
    node <char> *top = NULL;
    top = top->push(top,'a');
    top = top->push(top,'b');
    top = top->push(top,'c');
    top->Display(top);
    char val = top->pop(top);
    cout << val << endl;
    top->Display(top);
}
