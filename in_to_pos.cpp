#include <iostream>
using namespace std;
#include "stack_header.h"

int pred(char c){
    if(c=='*'||c=='/')
        return 5;
    else if(c=='+'||c=='-')
        return 4;
    else
        return 3;
}

string in_to_post(string i){
    stack <char> s;
    char c;
    string fo;
    for(int j=0;j<i.length();j++){
        c = i[j];
        if(isalnum(c)){
            fo+=c;
        }
        else if(c=='(')
            s.push(c);
        else if(c==')'){
            while(s.peek()!='('){
                fo+=s.pop();
            }
            s.pop();
        }
        else{
            while(!s.isempty()&& (pred(s.peek())>=pred(c))){
                fo+=s.pop();
            }
            s.push(c);
        }
    }
    while(!s.isempty()){
        fo+=s.pop();
    }
    return fo;
}

int main(){
    string i;
    cout << "Enter string: ";
    cin >> i;
    string o = in_to_post(i);
    cout << "Postfix string: " << o;
    return 0;
}
