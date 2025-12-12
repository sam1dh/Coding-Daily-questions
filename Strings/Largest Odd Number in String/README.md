# Largest Odd Number in String (LeetCode 1903)

**Problem Link**: [LeetCode 1903 - Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/)

You are given a string `num` representing a large integer.  
Return the **largest-valued odd integer** (as a string) that is a **substring** of `num`, or an empty string `""` if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

---

### Examples

**Example 1:**
```
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

**Example 2:**
```
Input: num = "4206"
Output: ""
Explanation: There are no odd digits.
```

**Example 3:**
```
Input: num = "35427"
Output: "35427"
Explanation: "35427" itself is odd.
```

---

### Solution (C++ - Clean & One-Pass)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // Start from the end (to get largest possible substring)
        for (int i = num.size() - 1; i >= 0; i--) {
            // Convert char digit to integer: num[i] - '0'
            if ((num[i] - '0') % 2 != 0) {
                // Return substring from index 0 to i (inclusive)
                return num.substr(0, i + 1);
            }
        }
        return ""; // No odd digit found
    }
};

int main() {
    Solution sol;
    cout << sol.largestOddNumber("52") << endl;     // "5"
    cout << sol.largestOddNumber("4206") << endl;   // ""
    cout << sol.largestOddNumber("35427") << endl;  // "35427"
}
```

---

### Key Concepts & Tricks Learned

| Concept                        | Explanation                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| `char` → `int` conversion     | `num[i] - '0'` → converts digit character `'5'` → integer `5`              |
| `int` → `char` (reverse)      | `'0' + 5` → converts integer `5` → character `'5'`                         |
| `num.substr(pos, len)`        | Extracts substring starting at `pos` with length `len`                      |
| `num.substr(0, i+1)`          | One-liner to get prefix from index 0 to i (inclusive)                      |
| Greedy from right             | To get **largest** number → check from rightmost digit first                |

**Pro Tip**: Always prefer `num.substr(0, len)` over `num.substr(0, i+1)` with manual calculation — it's clean and readable!

---

### Complexity Analysis

- **Time Complexity**: **O(n)** – single pass from right to left
- **Space Complexity**: **O(1)** – excluding the output string

---