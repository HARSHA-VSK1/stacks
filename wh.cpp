#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
        Node* InsStart(Node* head, int val){
            Node* n = new Node();
            n->data = val;
            n->next = head;
            head = n;
            return head;
        }

        void InsEnd(Node* head, int val){
            Node* n = new Node();
            n->data = val;
            if(head==NULL){
                head = n;
            }
            else{
                Node* ptr = head;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
        }

        void Print(Node* head){
            Node* ptr = head;
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }

        
};

Node* head = NULL;

Node* sort(){
            cout << "sort" << endl;
            Node* h1 = NULL;
            while(head!=NULL){
                cout << "while" << endl;
                if(head->data==0){
                    h1 = h1->InsStart(h1,0);
                }
                else if(head->data==2){
                    h1->InsEnd(h1,2);
                }
                head = head->next;
            }
    return h1;
}

int main(){
    int num, val;
    cout << "Enter number of elements: ";
    cin >> num;
    while(num>0){
        cout << "Enter: ";
        cin >> val;
        head = head->InsStart(head,val);
        num--;
    }
    head->Print(head);
    head = sort();
    head->Print(head);
    return 0;
}