# Prefix-Difference Problem Cheat Sheet (20–30 must-know problems)

A compact list of canonical problems that use the `pf[j] - pf[i] = const` pattern (prefix-sum / prefix-xor / prefix-mod), plus a one-line hint for how to attack each. Open the links and you’ll have immediate templates to apply.

> **How to use:** For each problem, identify the cumulative function (sum, xor, mod, transformed values) and apply the corresponding pattern: frequency map for counts, `first index` map for longest, ordered set / BIT for range/ordered queries, deque/trie for advanced XOR/maximum queries.

---

## 1. Subarray Sum Equals K
- **Link:** https://leetcode.com/problems/subarray-sum-equals-k/
- **Hint:** `cnt += freq[pref - K]` with `freq[0]=1`.

## 2. Maximum Size Subarray Sum Equals K
- **Link:** https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
- **Hint:** store **first index** of each prefix sum; answer `i - first[pref-K]`.

## 3. Binary Subarrays With Sum
- **Link:** https://leetcode.com/problems/binary-subarrays-with-sum/
- **Hint:** binary array; use prefix sum freq or `atMost(goal) - atMost(goal-1)` trick.

## 4. Contiguous Array (equal 0s and 1s)
- **Link:** https://leetcode.com/problems/contiguous-array/
- **Hint:** convert `0 → -1`, count equal prefix sums.

## 5. Subarrays with K Different Integers
- **Link:** https://leetcode.com/problems/subarrays-with-k-different-integers/
- **Hint:** `exactly(K) = atMost(K) - atMost(K-1)` using sliding window.

## 6. Subarray Sums Divisible by K
- **Link:** https://leetcode.com/problems/subarray-sums-divisible-by-k/
- **Hint:** store counts of `pref % K` (normalize negatives).

## 7. Count of Range Sum (number in [lower, upper])
- **Link:** https://leetcode.com/problems/count-of-range-sum/
- **Hint:** use prefix sums + merge sort / BIT / ordered set to count ranges.

## 8. Number of Submatrices That Sum to Target (2D)
- **Link:** https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
- **Hint:** fix top/bottom rows → collapse cols to 1D → use prefix-sum hashmap.

## 9. Max Sum Rectangle No Larger Than K (2D)
- **Link:** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
- **Hint:** compress rows, then use ordered set (`lower_bound`) on prefix sums to find best ≤ K.

## 10. Count Number of Nice Subarrays (exactly K odd numbers)
- **Link:** https://leetcode.com/problems/count-number-of-nice-subarrays/
- **Hint:** transform odd→1 even→0 then `atMost(K)-atMost(K-1)` or prefix freq on odd-count.

## 11. Continuous Subarray Sum (multiple of k)
- **Link:** https://leetcode.com/problems/continuous-subarray-sum/
- **Hint:** prefix % k repeated with index distance ≥ 2 (watch length constraint).

## 12. Shortest Subarray with Sum at Least K
- **Link:** https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
- **Hint:** prefix sums + monotonic deque to find minimal-length interval with sum ≥ K.

## 13. Number of Subarrays with Bounded Maximum
- **Link:** https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
- **Hint:** sliding-window counting (`max ≤ right`) minus (`max < left`).

## 14. Count Subarrays With Median K
- **Link:** https://leetcode.com/problems/count-subarrays-with-median-k/
- **Hint:** transform values to `>k → 1, <k → -1`, use prefix freq around the index of k.

## 15. Longest Subarray of 1's After Deleting One Element
- **Link:** https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
- **Hint:** sliding window / keep track of last zero index; O(n).

## 16. Number of Sub-arrays of Size K and Average ≥ Threshold
- **Link:** https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
- **Hint:** sliding window on sums (sum ≥ k*threshold).

## 17. Number of Subarrays with Given XOR (GfG)
- **Link:** https://www.geeksforgeeks.org/dsa/count-number-subarrays-given-xor/
- **Hint:** use prefix-XOR and map: `cnt += freq[prefXor ^ K]`.

## 18. Longest Subarray with Sum K (GfG)
- **Link:** https://www.geeksforgeeks.org/dsa/longest-sub-array-with-sum-k/
- **Hint:** store earliest index of each prefix sum to maximize length.

## 19. Count Subarrays with Sum Exactly K (GfG)
- **Link:** https://www.geeksforgeeks.org/dsa/number-subarrays-sum-exactly-equal-k/
- **Hint:** prefix freq map; base `freq[0]=1`.

## 20. Count Subarrays with Given Sum — Practice Variants
- **Link:** https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1
- **Hint:** variations include binary arrays, positives-only (sliding window), negatives allowed (prefix hash).

## 21. Number of Subarrays with Sum in [L, R]
- **Link:** https://leetcode.com/problems/count-of-range-sum/ (see #7)
- **Hint:** `count(≤R) - count(<L)` using ordered structures or BIT after compression.

## 22. Maximum Subarray Sum ≤ K (1D) — helper for 2D rectangle
- **Link:** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ (see #9)
- **Hint:** ordered set `lower_bound(pref - K)` to find best candidate.

## 23. Count Subarrays with Bounded Sum / At-most K (family)
- **Link:** Patterns appear across problems: 992, 1248, 930. (See respective links above.)
- **Hint:** convert `exactly K` → `atMost(K) - atMost(K-1)`.

## 24. Transform-for-Average Problems (convert `a[i] → a[i] - K`)
- **Link:** general technique — see GfG article for "longest subarray with given average".
- **Hint:** reduce average constraint to sum=0 problem and apply prefix-frequency method.

---

## Quick templates (copy-paste)

**Count subarrays with sum = K**
```cpp
unordered_map<int,int> freq; freq[0]=1;
int pref=0, ans=0;
for(int x: a){ pref += x; ans += freq[pref - K]; freq[pref]++; }
```

**Longest subarray with sum = K**
```cpp
unordered_map<int,int> first; int pref=0, best=0;
for(int i=0;i<n;i++){ pref+=a[i]; if(pref==K) best=max(best,i+1);
 if(first.count(pref-K)) best=max(best, i-first[pref-K]); if(!first.count(pref)) first[pref]=i; }
```

**Count subarrays with prefix-XOR = K**
```cpp
unordered_map<int,int> freq; freq[0]=1; int xr=0, ans=0;
for(int x: a){ xr ^= x; ans += freq[xr ^ K]; freq[xr]++; }
```

---

If you want this as a downloadable `.md` file or a printable PDF, or want me to **convert to flashcards** (title + 1-line hint), tell me which format and I’ll export it right away.

