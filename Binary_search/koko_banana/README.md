
# Koko Eating Bananas: Minimum Speed Calculation

## Intuition

You have piles of bananas, and Koko wants to eat all of them within $h$ hours. You need to figure out the **minimum eating speed** (bananas per hour) so that she can finish on time.

---

## Approach

We know the minimum speed can’t be less than **1** (she has to eat at least 1 banana per hour).

The maximum speed can be as big as the **largest pile** (if she eats that fast, she finishes that pile in 1 hour).

We use **binary search** between these two speeds to find the smallest speed that lets her finish on time.

### How do we check if a speed works?

1.  For each pile, calculate how many hours it takes to finish at that speed.
2.  Add these hours up for all piles.
3.  If **total hours is less than or equal to $h$**, the speed works.
4.  Otherwise, she’s too slow.

---

## Example: $[3, 6, 7, 11]$ and $h = 8$

* Minimum speed = **1** banana/hour (can’t be zero)
* Maximum speed = **11** bananas/hour (largest pile)

**Step 1:** Binary search starts.

**Step 2:** Try middle speed: $(1 + 11) / 2 = 6$.

**Step 3: Check if speed 6 works**
* Hours for pile 3: $3 / 6 = 0.5 \rightarrow$ round up to **1 hour**
* Hours for pile 6: $6 / 6 = 1$ hour
* Hours for pile 7: $7 / 6 \approx 1.16 \rightarrow$ round up to **2 hours**
* Hours for pile 11: $11 / 6 \approx 1.83 \rightarrow$ round up to **2 hours**
* Total hours $= 1 + 1 + 2 + 2 = 6$ hours (**less than 8**)

**Step 4: Try to find slower speed**
* New search range: 1 to 5.
* Middle speed: $(1 + 5) / 2 = 3$.

**Step 5: Check speed 3**
* Hours for 3: $3 / 3 = 1$ hour
* Hours for 6: $6 / 3 = 2$ hours
* Hours for 7: $7 / 3 \approx 2.33 \rightarrow$ **3 hours**
* Hours for 11: $11 / 3 \approx 3.67 \rightarrow$ **4 hours**
* Total $= 1 + 2 + 3 + 4 = 10$ hours (**too slow**)

**Step 6: Try faster speed**
* New range: 4 to 5.
* Middle: $(4 + 5) / 2 = 4$.

**Step 7: Check speed 4**
* Hours for 3: **1**
* Hours for 6: **2**
* Hours for 7: **2**
* Hours for 11: **3**
* Total $= 8$ hours (**just right**)

**Step 8: Try slower than 4?**
* New range: 4 to 3 $\rightarrow$ stops because left $>$ right.

**Answer: 4**

We keep guessing speeds and check hours needed. If guess works, try slower speed. If it doesn’t, try faster. Finally, we find the slowest speed that finishes on time. In this example, it’s 4 bananas/hour.

---

## Complexity

### Time complexity:
$O(N \times \log M)$

### Space complexity:
$O(1)$

