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
};

// implement Deque
template <class T>
class Deque
{
public:
    Doubly_linked_list<T> dl;
    Deque(){

    };
    // front
    T front()
    {
        if (dl.get_size() == 0)
        {
            cout << "Deque is empty !\n";
            T a;
            return a;
        }
        return dl.head->data;
    };
    // back
    T back()
    {
        if (dl.get_size() == 0)
        {
            cout << "Deque is empty !\n";
            T a;
            return a;
        }
        return dl.tail->data;
    };
    // push_front
    void push_front(T val)
    {
        dl.inseart_at_head(val);
    };
    // pop_front
    void pop_front()
    {
        if (dl.get_size() == 0)
        {
            cout << "Deque is empty !\n";
            return;
        }
        dl.delete_at_head();
    };
    // push_back
    void push_back(T val)
    {
        dl.insert_at_tail(val);
    };
    // pop_back
    void pop_back()
    {
        if (dl.get_size() == 0)
        {
            cout << "Deque is empty !\n";
            return;
        }
        dl.delete_at_tail();
    }
    // get size
    int get_size()
    {
        return dl.get_size();
    }
};
int main()
{
    Deque<int> dq;
    dq.push_back(30);
    dq.push_back(70);
    dq.push_front(310);
    dq.push_front(130);
    dq.pop_front();
    dq.pop_back();

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.get_size()<<endl;
    return 0;
}
