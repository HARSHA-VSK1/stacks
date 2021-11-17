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
    private:
        node* top = NULL;
};