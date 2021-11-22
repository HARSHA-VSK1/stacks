#include <iostream>
using namespace std;
#include "stack_header.h"

int main(){
    stack <int> s;
    s.push(12);
    s.push(22);
    s.push(13);
    s.push(14);
    s.Display();
    s.pop();
    s.Display();
    return 0;
}
