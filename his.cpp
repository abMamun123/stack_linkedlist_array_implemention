#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
public:
    T *a;
    int l, r, sz, array_cap;
    Queue()
    {
        a = new T[1];
        array_cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }
    void remove_circular() if (l > r)
    {
        T *temp = new T[array_cap];
        int idx = 0;
        for (int i = l; i < array_cap; i++)
        {
            temp[idx] = a[i];
            idx++;
        }
        for (int i = 0; i <= r; i++)
        {
            temp[idx] = a[i];
            idx++;
        }
        swap(temp, a);
        l = 0;
        r = array_cap - 1;
        delete[] temp;
    }

    void
    increase_size() // O(1)
    {
        remove_circular();
        T *temp = new T[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            temp[i] = a[i];
            swap(temp, a);
        }
        array_cap = array_cap * 2;
        delete[] temp;
    }

    void enqueue(T value) // O(1)
    {
        if (sz == array_cap)
        {
            increase_size();
        }
        r++;
        if (r == array_cap)
        {
            r = 0;
        }
        a[r] = value;
        sz++;
    }
    void dequeue()
    {
        if (sz == 0)
        {
            cout << "Queue is empty!\n";
            return;
        }
        l++;
        if (l == array_cap)
        {
            l = 0;
        }
        sz--;
    }
    int get_size() // O(1)
    {
        return sz;
    }
    T front_value() // O(1)
    {
        if (sz == 0)
        {
            cout << "Queue is empty!\n";
            T a;
            return a;
        }
        return a[l];
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front value is: " << q.front_value() << "\n";
    q.dequeue();
    q.dequeue();
    cout << "Front value is: " << q.front_value() << "\n";
    q.dequeue();
    cout << "Front value is: " << q.front_value() << "\n";
    return 0;
}