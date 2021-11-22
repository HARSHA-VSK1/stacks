#include <iostream>
using namespace std;
#include "stack_header.h"

int pred(char v){
    if(v=='*'||v=='/')
        return 5;
    else if(v=='+'||v=='-')
        return 4;
    else
        return 3;
}

string in_topre(string inp){
    stack <char> s;
    string op = "";
    for(int i = inp.length()-1;i>=0;i--){
        char c = inp[i];
        if(isalnum(c)){
            op += c;
            //cout << op << endl;
        }
        else if(c==')'){
            s.push(')');
        }
        else if(c=='('){
            while(s.peek()!=')'){
                op += s.pop();
            }
            s.pop();
        }
        else{
            while(!s.isempty() && (pred(s.peek())>pred(c))){
                char p = s.pop();
                op += p;
            }
            s.push(c);
        }
    }
    while(!s.isempty()){
        op += s.pop();
    }
    string fin = "";
    for(int i =op.length()-1;i>=0;i--){
        if(op[i]=='(' || op[i]==')')
            return "invalid string";
        fin+=op[i];
    }
    return fin;
}

int main(){
    string inp;
    cout << "Enter: ";
    cin >> inp;
    string op = in_topre(inp);
    cout << op;
}
