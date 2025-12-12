#include<bits/stdc++.h>
using namespace std;
int main()
{
        int counter = 0;
        string s = "((()())(())(()(())))";
        string ans = "";
        for(auto i : s)
        {
            if(i=='(')
            {
                counter++;
                 if(counter>1)
                 {
                ans.push_back('(');
                 }
            }
            if(i==')')
            {
                counter--;
                 if(counter>0)
                 {
                ans.push_back(')');
                 }
            }
           
        }
        cout<<ans;
}