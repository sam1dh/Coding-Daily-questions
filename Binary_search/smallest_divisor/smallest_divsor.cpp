#include<bits/stdc++.h>
using namespace std;   
int smallest_divisor(vector<int>&nums,int mid,int threshold)
{
    long long sum = 0;
    for(auto i : nums)
    {
        sum =  sum + i/mid;
        if(i%mid!=0)
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
        vector<int> nums={1,2,5,9};
        int threshold=6;
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;
        while(left<=right)
        {
            int mid  = left+(right-left)/2;
            int val = smallest_divisor(nums,mid,threshold);
            if(val<=threshold)
            {
                ans = mid;
                right = mid-1;

            }
           else
           {
                left = mid+1;
           }
        }
        cout<<ans<<endl;
        return 0;
}