#include<bits/stdc++.h>
using namespace std;
    bool check_possible(vector<int>& bloomDay, int mid, int k, int m) {
        int consecutive_bloomed = 0;
        int noofbouquets = 0;

        for (int day : bloomDay) {
            // Check 1: Has the flower bloomed by day 'mid'?
            if (day <= mid) {
                consecutive_bloomed++;
            } else {
                // If the sequence is broken, calculate how many bouquets could be formed
                noofbouquets += consecutive_bloomed / k;
                consecutive_bloomed = 0; // Reset the counter for the new sequence
            }
        }
        
        // Account for any remaining consecutive bloomed flowers at the end of the array
        noofbouquets += consecutive_bloomed / k;

        // Check 2: Can we make AT LEAST m bouquets?
        return noofbouquets >= m;
    }

int main()
{
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3; // number of bouquets
    int k = 1; // flowers per bouquet

    int left = 1; // minimum possible day
    int right = *max_element(bloomDay.begin(), bloomDay.end()); // maximum possible day
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check_possible(bloomDay, mid, k, m)) {
            result = mid; // Found a possible solution
            right = mid - 1; // Try to find a smaller day
        } else {
            left = mid + 1; // Increase the day
        }
    }

    cout << "Minimum number of days to make " << m << " bouquets: " << result << endl;
    return 0;   
}