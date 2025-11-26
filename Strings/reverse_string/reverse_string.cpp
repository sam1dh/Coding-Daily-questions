#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "a good   example";
    reverse(s.begin(),s.end());
    for(int i = 0; i<s.length();i++)
    {
        int j = i;
        while(j<s.length() && s[j]!=' ')
        {
            j++;
        }
        reverse(s.begin()+i,s.begin()+j);
        i = j;
    } 
    string result;
    for(int i = 0; i<s.length();i++)
    {
        if(s[i]!=' ' || (s[i]==' ' && !result.empty() && result.back()!=' '))
        {
            result.push_back(s[i]);
        }
    }
    if(!result.empty() && result.back()==' ')
    {
        result.pop_back();
    }
    cout<<result<<endl;
}