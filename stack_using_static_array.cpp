/**
 *author:xyz_123
 *created:31-01-2023(12:50:26)
 **/
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
public:
    int max_size = 5;
    T a[5];
    int stack_size;
    Stack()
    {
        stack_size = 0;
    }
    // add element in the stack O(1)
    void push(T val)
    {
        if (stack_size + 1 > max_size)
        {
            cout << "stack is full !\n";
            return;
        }
        stack_size = stack_size + 1;
         a[stack_size - 1] = val;
    };
    // delete the top most element O(1)
    void pop()
    {
        if (stack_size == 0)
        {
            cout << "stack size empty!\n";
        }
        stack_size = stack_size - 1;
    };
    // return top element
    void top()
    {
        if (stack_size == 0)
        {
            cout << "stack size is empty!\n";
            return;
        }
        cout << a[stack_size - 1] << "\n";
    }
};
int main()
{
    Stack<string> st;
    st.push("my name is mamun");
    st.push("my");
    st.top();

    return 0;
}