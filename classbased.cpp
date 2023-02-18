#include <bits/stdc++.h>
using namespace std;

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
        if (ch >= '0' && ch <= '9')
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

int evaluate(string str)
{
    stack<int> stack;

    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            stack.push(str[i] - '0');
        }
        else
        {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            switch (str[i])
            {
            case '+':
                stack.push(a + b);
                break;
            case '-':
                stack.push(b - a);
                break;
            case '*':
                stack.push(a * b);
                break;
            case '/':
                stack.push(b / a);
                break;
            }
        }
    }
    return stack.top();
}

int main()
{
    string str;
    cin >> str;
    string s = infixToPostfix(str);
    cout << "result = " << evaluate(s) << endl;
    return 0;
}
