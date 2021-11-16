#include <iostream>
using namespace std;

class Stack{
    public:
        int num;
        int *stack;
       
        Stack(int s){
            num = s;
            stack = new int[s];
        };
       
        void push(int val){
            if(top==num-1){
                cout << "Stack overflow" << endl;
            }
            else{
                stack[++top] = val;
            }
        }
       
        int pop(){
            if(top==-1){
                cout << "Stack is empty" << endl;
                return 0;
            }
            else{
                return stack[top--];
            }
        }
       
        int peak(){
            if(top==-1){
                cout << "Stack is empty" << endl;
                return 0;
            }
            else{
                return stack[top];
            }
        }
       
        void Display(){
            if(top==-1)
                cout << "Stack is empty" << endl;
            else{
                int x = top;
                while(x>=0){
                    cout << stack[x] << " ";
                    x--;
                }
                cout << endl;
            }
        }
    private:
        int top = -1;
       
};


int main()
{
    int size;
    cout << "Enter size of the stack: ";
    cin >> size;
    Stack s(size);
    int val,choice;
    cout << "1.Push 2. Pop 3.Peak 4.Display" << endl;
    while(1){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                val = s.peak();
                cout << "peak value=" << val << endl;
                break;
            case 4:
                s.Display();
                break;
            default:
                break;
        }
    }
    return 0;
}