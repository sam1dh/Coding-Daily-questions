## Problem Statement (LeetCode 1021 - Remove Outermost Parentheses)

Given a valid parentheses string `s`, consider its primitive decomposition: `s = P1 + P2 + ... + Pk`, where each `Pi` is a valid primitive parentheses string.

A primitive parentheses string is one that:
- Cannot be split into multiple valid parentheses strings
- Is non-empty and properly balanced

Return `s` after removing the **outermost parentheses** of every primitive string in its decomposition.

### Example 1:
```
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
"(()())" -> "()()"   (remove outer)
"(())"   -> "()"     (remove outer)
Combined: "()()()"
```

### Example 2:
```
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
```

### Example 3:
```
Input: s = "()()"
Output: ""
Explanation: Each "()" is a primitive, so removing outer parentheses leaves nothing.
```

## Intuition & Algorithm

We use a simple **level counter** (also called depth) to track nesting:

- Every time we see `'('`, we increase the level.
- Every time we see `')'`, we decrease the level.
- We only add a parenthesis to the result **if it is not part of the outermost layer** of a primitive.

Key Insight:
- The first `'('` in any primitive starts at `level = 1` → this is the outermost, **skip it**
- The matching last `')'` brings level back to `0` → this is also outermost, **skip it**
- All parentheses between `level >= 2` (for opening) and `level > 0` (for closing) belong to inner valid parts → **include them**

### Algorithm Steps:
1. Initialize an empty result string
2. Initialize `level = 0`
3. Traverse each character in the string:
   - If `'('` and `level > 0` → add `'('` and increment level
   - If `'('` and `level == 0` → just increment level (skip outermost)
   - If `')'` and `level > 1` → decrement level first, then add `')'`
   - If `')'` and `level == 1` → just decrement level (skip outermost)
4. Return the result

## Solution Code (Python)

```c++
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
```

## Complexity Analysis

- **Time Complexity:** O(n) — single pass through the string
- **Space Complexity:** O(n) — for the output string (required)
