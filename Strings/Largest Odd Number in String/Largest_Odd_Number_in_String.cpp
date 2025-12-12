#include<bits/stdc++.h>
using namespace std;
int main()
{
        string num ="52";
        for(int i= num.size()-1 ; i>=0 ; i--)
      {
        if((num[i]-'0')%2!=0)
        {
            cout<<num.substr(0,i+1) ;
        }
      }
        cout<<" ";
}