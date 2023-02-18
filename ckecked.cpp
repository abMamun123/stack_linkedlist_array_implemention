#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
public:
    T *a;
    int array_cap;
    int l, r, size;
    Queue()
    {
        a = new T[1];
        array_cap = 1;
        l = 0;
        r = -1;
        size = 0;
    }
    void remove_circular()
    {
        if (l > r)
        {

            T* tmp = new T[array_cap];
            int idx = 0;
            for (int i = l; i < array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for (int i = 0; i < r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(a, tmp);
            l = 0;
            r = array_cap - 1;
            delete[] tmp;
        }
    }
    void increase_size()
    {
        remove_circular();
        T *tmp = new T[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            tmp[i] = a[i];
            swap(tmp, a);
        }
            array_cap = array_cap * 2;
            delete[] tmp;
    }
    // insert in queue.....
    void enqueue(T val)
    {
        if (size == array_cap)
            increase_size();
        r++;
        if (r == array_cap)
        {
            r = 0;
        }
        a[r] = val;
        size++;
    }
    // delete in queue.....
    void dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            return;
        }
        l++;
        if (l == array_cap)
            l = 0;
        size--;
    };
    // front element
    T front()
    {
        if (size == 0)
        {
            cout << "queue is empty!\n";
            T a;
            return a;
        }
        return a[l];
    }
    int getSize()
    {
        return size;
    }
};
int main()

{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(8);
    cout<<q.front()<<"\n";

    Queue<char> q1;
    q1.enqueue('a');
    q1.enqueue('c');
    cout<<q1.front()<<"\n";

    Queue<string> q2;
    q2.enqueue("i am");
    cout<<q2.front()<<"\n";
    return 0;
}