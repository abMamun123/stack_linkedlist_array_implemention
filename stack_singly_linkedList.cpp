#include <bits/stdc++.h>
using namespace std;
template <class T>
class node
{
public:
    T data;
    node *next;
};
template <class T>
class Singly_linked_list
{
public:
    node<T> *head;
    int size;
    Singly_linked_list()
    {
        head = NULL;
        size = 0;
    }
    // create new node
    node<T> *create_new_node(T val)
    {
        node<T> *new_node = new node<T>;
        new_node->data = val;
        new_node->next = NULL;
        return new_node;
    }
    // get size of the linked list
    int get_size()
    {
        return size;
    }
    // inseart at head
    void inseart_at_head(T val)
    {
        size++;
        node<T> *new_node = create_new_node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        node<T> *a = head;
        new_node->next = a;
        head = new_node;
    };
    // delete at head
    void delete_at_head()
    {
        size--;
        if (head == NULL)
            return;
        node<T> *a = head;
        node<T> *b = a->next;
        delete a;
        head = b;
    }
};

// implement stack
template <class T>
class Stack
{
public:
    Singly_linked_list<T> l;
    Stack(){

    };
    // stack top value
    T top()
    {
        if (l.get_size() == 0)
        {
            cout << "Stack is empty !\n";
            T a;
            return a;
        }
        return l.head->data;
    };
    // iserat at top(push)
    void push(T val)
    {
        l.inseart_at_head(val);
    };
    // delete at top(pop)
    void pop()
    {
        if (l.get_size() == 0)
        {
            cout << "Stack is empty !\n";
            return;
        }
        l.delete_at_head();
    };
    // get size
    int get_size()
    {
        return l.get_size();
    }
};
int main()
{
    Stack<char> st;
    st.push('m');
    cout << st.top() << endl;
    st.pop();
    st.push('o');
    cout << st.top() << endl;
    st.push('a');
    cout << st.top() << endl;
    st.pop();
    return 0;
}
