/**
 *author:xyz_123
 *created:31-01-2023(23:13:49)
 **/
#include <bits/stdc++.h>
using namespace std;
template <class T>
class node
{
public:
    T data;
    node *prev;
    node *next;
};
template <class T>
class Doubly_linked_list
{
public:
    node<T> *head;
    node<T> *tail;
    int size;
    Doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // create new node
    node<T> *create_new_node(T val)
    {
        node<T> *new_node = new node<T>;
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;
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
            tail = head;
            return;
        }
        node<T> *a = head;
        new_node->next = a;
        a->prev = new_node;
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
        if (b != NULL)
            b->prev = NULL;
        head = b;
    };
    // insert at tail
    void insert_at_tail(T val)
    {
        size++;
        node<T> *new_node = create_new_node(val);
        if (tail == NULL)
        {
            tail = new_node;
            head = tail;
            return;
        }
        node<T> *a = tail;
        a->next = new_node;
        new_node->prev = a;
        tail = new_node;
    }
    // delete at tail
    void delete_at_tail()
    {
        size--;
        if (tail == NULL)
            return;
        node<T> *a = tail;
        node<T> *b = tail->prev;
        delete a;
        tail = b;
    }
    // traverse linked list
    void traverse()
    {
        if (head == NULL)
            return;
        node<T> *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    }
};

// implement stack
template <class T>
class Stack
{
public:
    Doubly_linked_list<T> dl;
    Stack(){

    };
    // stack top value
    int top()
    {
        if (dl.get_size() == 0)
        {
            cout << "Stack is empty !\n";
            return -1;
        }
        return dl.tail->data;
    };
    // iserat at top(push)
    void push(T val)
    {
        dl.insert_at_tail(val);
    };
    // delete at top(pop)
    void pop()
    {
        if (dl.get_size() == 0)
        {
            cout << "Stack is empty !\n";
            return;
        }
        dl.delete_at_tail();
    };
    // get size
    int get_size()
    {
        return dl.get_size();
    }
    // travers
    void travers()
    {
        return dl.traverse();
    }
};
/*int main()
{
    // Stack<int> a;
    // a.push(77);
    // a.push(23);
    // a.push(66);
    // a.push(54);
    // cout << a.top() << "\n";
    // a.travers();
    // Stack<int> temp;
    // while (a.get_size() > 0)
    // {
    //     temp.push(a.top());
    //     a.pop();
    // }
    // swap(a, temp);
    // a.travers();

    Stack<int> st;
    cout << st.get_size();
    st.push(77);
    st.push(23);
    st.push(66);
    st.push(54);

    Stack<int> temp;
    while (st.get_size > 0)
    {
        if (temp.get_size == 0)
        {
            temp.push(st.top());
            st.pop();
        }
        if(temp.top()>st.top()){
            
        }
    }

    return 0;
}*/
int main()
{
    stack <int> ds;
    ds.push(34);
    ds.push(35);
    ds.push(32);
    ds.push(33);
    stack <int> temp;
    while(ds.get_size()>0)
    {
        temp.push(ds.top());
        ds.pop();
    }
    swap(ds,temp);
    while(ds.get_size()>0)
    {
        cout<<ds.top()<<" ";
        ds.pop();
    }
    return 0;
}