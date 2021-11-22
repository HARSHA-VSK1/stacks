#include <iostream>
using namespace std;
#include "stack_header.h"
#include <math.h>

int pref_eval(string inp){
    stack <char> s;
    for(int i = inp.length()-1;i>=0;i--){
        char c = inp[i];
        if(isalnum(c)){
            s.push(c);
        }
        else{
            int a = s.pop() - '0';
            int b = s.pop() - '0';
            switch (c)
            {
            case '*':
                s.push(a*b + '0');
                break;
            
            case '/':
                s.push(a/b + '0');
                break;

            case '+':
                s.push(a+b + '0');
                break;
            
            case '-':
                s.push(a-b + '0');
                break;
            
            case '^':
                s.push(pow(a,b) + '0');
                break;
            
            case '%':
                s.push(a%b + '0');
                break;

            default:
                break;
            }
        }
    }
    int res = s.peek() - '0';
    return res;
}

int main(){
    string inp;
    cout << "Enter prefix string: ";
    cin >> inp;
    int op = pref_eval(inp);
    cout << op;
    return 0;
}