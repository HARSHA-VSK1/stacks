#include <iostream>
using namespace std;

class node{
    public:
        char data;
        node* next;
};

class stack{
    public:
        void push(char val){
            node* n = new node();
            n->data = val;
            if(top==NULL){
                top = n;
            }
            else{
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
                char d = top->data;
                top = top->next;
                return d;
            }
        }

        node* peek(){
            return top;
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
    private:
        node* top = NULL;
};

string in_to_post(string inp){
    stack s;
    string op = "";
    for(int i=0;i<inp.length();i++){
        if((inp[i]>='a'&&inp[i]<='z')||(inp[i]>='A'&&inp[i]<='Z')){
            op = op+ inp[i];
        }
        else if(inp[i]=='{')
            s.push('{');
        
    }
}

int main(){
    string inp;
    cout << "Enter the string: " << endl;
    cin >> inp;

}
