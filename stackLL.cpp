#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node* push(node* top, int val){
            if(top==NULL){
                top = new node();
                top->data = val;
                return top;
            }
            node* n = new node();
            n->data = val;
            n->next = top;
            return n;
        }

        node* pop(node* top){
            if(top==NULL){
                cout << "Stack underflow" << endl;
                return 0;
            }
            else{
                node* temp = top;
                top = top->next;
                delete temp;
                return top;
            }
        }

        int peek(node* top){
            return top->data;
        }

        void Display(node* top){
            if(top==NULL){
                cout << "stack underflow" << endl;
                return;
            }
            node* ptr = top;
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
};

int main(){
    node* top = NULL;
    int choice,val;
    cout << "1.Push 2. Pop 3.Peak 4.Display" << endl;
    while(1){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                top = top->push(top,val);
                break;
            case 2:
                top = top->pop(top);
                break;
            case 3:
                val = top->peek(top);
                cout << "peak value=" << val << endl;
                break;
            case 4:
                top->Display(top);
                break;
            default:
                break;
        }
    }
    return 0;
}
