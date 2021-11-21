#include <iostream>
using namespace std;
#include "stack1.h"
#include <math.h>

int main(){
    string inp;
    cout << "Enter string: ";
    cin >> inp;
    node <char> *top;
    for(int i=0;i<inp.length();i++){
        char c = inp[i];
        if(isdigit(c)){
            top = top->push(top,c);
        }
        else{
            int a = top->pop(top) - '0';
            int b = top->pop(top) - '0';
            cout << b << " "  << a << endl;
            switch (c)
            {
            case '*':
                top = top->push(top, b*a + '0');

                break;
            case '/':
                top = top->push(top, b/a + '0');
                break;
            case '+':
                top = top->push(top, b+a + '0');
                break;
            case '-':
                top = top->push(top, b-a + '0');
                break;
            case '^':
                top = top->push(top, pow(b,a)+ '0');
                break;
            case '%':
                top = top->push(top,b%a+'0');
                break;
            default:
                break;
            }
        }
    }

    cout << top->peek(top) - '0' << endl;
    return 0;
}