/**
 *author:xyz_123
 *created:06-02-2023(13:17:21)
**/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<string>q;
    q.push("1");
    for (int i = 1; i <= n; i++)
    {
        cout<<"binary of "<<i<<" is :"<<q.front()<<"\n";
        q.push(q.front()+"0");
        q.push(q.front()+"1");
        q.pop();
    }
    
return 0;
}