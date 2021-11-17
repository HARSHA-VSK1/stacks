#include <iostream>
using namespace std;
#include <stack>
class node{
    public:
        char data;
        node* next = NULL;
};

node* top;

void push(char v){
    
    if(top==NULL){
        top = new node();
        top->data = v;
    }
    else{
        node* n = new node();
        n->data = v;
        n->next = top;
        top = n;
    }
}

char pop(){
    if(top==NULL){
        cout << "stack underflow" << endl;
        return 0;
    }
    else{
        char x = top->data;
        top = top->next;
        return x;
    }
}

char peek(){
    return top->data;
}

void Display(){
    if(top==NULL){
        cout << "stack underflow" << endl;
    }
    else{
        node* ptr = top;
        while(ptr!=NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

bool isempty(){
    if(top==NULL)
        return true;
    else
        return false;
}

int pred(char v){
    if(v=='*'||v=='/')
        return 5;
    else if(v=='+'||v=='-')
        return 4;
    else
        return 3;
}

int main(){
    string ip;
    cout << "Enter: ";
    cin >> ip;
    int n = ip.length();
    cout << ip.length() << endl;
    string o;
    for(int i=0;i<n;i++){
        char c = ip[i];
        if(isalnum(c)){
            o+=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(peek()!='('){
                o+=pop();
            }
            pop();
        }
        else{
            while(!isempty() && pred(peek())>=pred(c)){
                o+=pop();
            }
            push(c);
        }
    }
    while(!isempty()){
        o+=pop();
    }
    cout << o;
    return 0;
}
/*int main(){
    stack<char> st;
    string ip;
    cout << "Enter: ";
    cin >> ip;
    int n = ip.length();
    cout << ip.length();
    string o;
    for(int i=0;i<n;i++){
        cout << "in" << endl;
        char c = ip[i];
        if(isalnum(c)){
            o += c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                o += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(pred(st.top())>=pred(c)){
                o += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        o += st.top();
        st.pop();
    }
    cout << o;
    return 0;
}*/
