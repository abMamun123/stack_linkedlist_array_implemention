/**
 *author:xyz_123
 *created:02-02-2023(13:38:32)
 **/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> a;
    for (int i = 0; i <s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            a.push(s[i]);
        }
        else
        {
            if (a.empty())
            {
                cout << "Invalid\n";
                return 0;
            }
            else if (a.top() == '(' and s[i] == ')')
                a.pop();
            else if (a.top() == '{' and s[i] == '}')
                a.pop();
            else if (a.top() == '[' and s[i] == ']')
                a.pop();
        }
    }
    if (a.empty())
        cout <<"valid\n";
    else
    cout<<"Invalid\n";
    return 0;
}