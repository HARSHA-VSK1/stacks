#include <iostream>
using namespace std;

#define max 5
class stack{
    public:
        int stack_arr[max];
        int top = -1;

        void Push(stack s, int val){
            if(s.top!=max-1){
                s.stack_arr[++s.top] = val;
                ++s.top;
                cout << s.top << endl;
            }
            else{
                cout << "Stack overflow" << endl;
            }
        }

        int Pop(stack s){
            if(s.top==-1){
                cout << "Stack is empty" << endl;
            }
            else{
                
                return s.stack_arr[s.top--];
            }
        }

        int peak(stack s){
            if(s.top==-1){
                cout << "Stack is empty" << endl;
            }
            else{
                return s.stack_arr[s.top];
            }
        }

        void display(stack s){
            if(s.top==-1){
                cout << "Stack is empty" << endl;
            }
            else{
                int x = s.top;
                while(x>=0){
                    cout << s.stack_arr[x] << " ";
                    x--;
                }
                cout << endl;
            }
        }

};
int main(){
    stack s;
    cout << "1.Push 2.Pop 3.Display 4.Peak" << endl;
    int val, choice;
    while(1){
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.Push(s,val);
            break;
        
        case 2:
            s.stack_arr[s.top] = s.Pop(s);
            break;
        
        case 3:
            s.display(s);
            break;
        
        case 4:
            val = s.peak(s);
            cout << "peak: " << val << endl;
            break;

        default:
            break;
        }
    }
}