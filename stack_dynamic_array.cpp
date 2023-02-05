/**
 *author:xyz_123
 *created:31-01-2023(22:18:51)
 **/
#include <bits/stdc++.h>
using namespace std;
template <class T>
class My_stack
{
public:
    int stack_size;
    T *a;
    int array_cap;
    My_stack()
    {
        a = new T[1];
        array_cap = 1;
        stack_size = 0;
    }
    // increase array size dynamically
    void increase_size()
    {
        T *temp;
        temp = new T[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            temp[i] = a[i];
        }
        swap(temp, a);
        delete[] temp;
        array_cap = array_cap * 2;
    }
    // stack push
    void push(T val)
    {
        if (stack_size + 1 > array_cap)
            increase_size();
        stack_size = stack_size + 1;
        a[stack_size - 1] = val;
    }
    // stack pop
    void pop()
    {
        if (stack_size == 0)
        {
            cout << "stack is empty!\n";
            return;
        }
        stack_size = stack_size - 1;
    }
    // return top element
    void top()
    {
        if (stack_size == 0)
        {
            cout << "stack is empty!\n";
            return;
        }
        cout << a[stack_size - 1] << "\n";
    }
};
int main()
{
    My_stack<double> st;
    st.push(10.8);
    st.top();
    st.push(20.44);
    st.top();
    st.push(30.22);
    st.top();
    cout << "pop start\n";
    st.pop();
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
    cout << "push start\n";
    st.push(10.88);
    st.top();
    return 0;
}