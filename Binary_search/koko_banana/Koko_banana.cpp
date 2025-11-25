#include<bits/stdc++.h>
using namespace std;
bool hours_count(vector<int>&piles,int speed,int h)
{
    int hours=0;
    for(int pile:piles)
    {
        hours+=pile/speed;
        if(pile%speed!=0)
        {
            hours++;
        }
        if(hours>h)
        {
            return false;
        }
    }
    return hours<=h;
}
int main()
{
    vector<int> piles={30,11,23,4,20};
    int h=6;
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;
    while(left<=right)
    {
        int mid = left + (right - left) / 2;
       if(hours_count(piles,mid,h))
       {
            ans = mid;
            right = mid-1;
       }
       else{
            left = mid + 1;
       }
    }
    cout<<ans<<endl;
    return 0;
}