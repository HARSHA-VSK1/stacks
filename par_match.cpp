#include <iostream>
using namespace std;

class node{
    public:
        char data;
        node* next;

        node* push(node* top, char val){
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
            node* ptr = top;
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }

        bool isempty(node* top){
            if(top==NULL)
                return true;
            else
                return false;
        }
};

bool ParMatching(string inp){
    node* top  = NULL;
    for(int i=0;i<inp.length();i++){
        if(inp[i]=='{'){
            top = top->push(top,inp[i]);
        }
        else if(inp[i]=='}'){
            if(top->isempty(top)){
                return false;
            }
            else{
                top = top->pop(top);
            }
        }
    }
    if(top->isempty(top)){
        return true;
    }
    else
        return false;
}

int main(){
    string inp;
    cout << "Enter the string: " << endl;
    cin >> inp;
    bool val = ParMatching(inp);
    cout << boolalpha << val << endl;
}
