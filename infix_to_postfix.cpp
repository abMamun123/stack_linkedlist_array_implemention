#include <bits/stdc++.h>
using namespace std;
// return precedance of operator
int prec(char ch)
{
    if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
};
string infixToPostfix(string str)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z')
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(str[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
};
int main()
{
    string str;
    cin >> str;
    cout << infixToPostfix(str);
    return 0;
}