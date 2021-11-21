#include <iostream>
using namespace std;

template <class T>
class node{
    private:
        T data;
        node* next;

    public:
        node* push(node* top,T val){
            node* n = new node();
            n->data = val;
            if(top==NULL){
                top = n;
            }
            else{
                n->next = top;
                top = n;
            }
            return top;
        }

        T pop(node* top){
            if(top==NULL){
                cout << "stack underflow" << endl;
                return 0;
            }
            else{
                T d = top->data;
                *top = *top->next;
                return d;
            }
        }

        T peek(node* top){
            return top->data;
        }

        void Display(node* top){
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

        bool isempty(node* top){
            if(top==NULL)
                return true;
            else
                return false;
        }
};

