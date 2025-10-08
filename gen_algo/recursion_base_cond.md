# 🧠 GRID DYNAMIC PROGRAMMING CHEAT SHEET

A complete reference of **25+ common DP-on-Grid patterns**, including:
- Function definition meaning  
- ✅ Base condition  
- 🚫 Invalid condition  
- 🔁 Recurrence relation  
- 🎯 What it returns  
- 💡 Key reasoning / idea  

---

## 🧩 Table of Patterns

| No | Problem Type | State Definition | ✅ Base Condition | 🚫 Invalid Condition | 🔁 Recurrence | 🎯 Returns | 💡 Idea |
|----|---------------|------------------|------------------|----------------------|----------------|-------------|-----------|
| **1** | Count paths (Right + Down) | `f(i, j)`: ways to reach end | `i=m-1, j=n-1 → 1` | `i≥m or j≥n → 0` | `f(i+1, j) + f(i, j+1)` | #paths | Sum of right + down moves |
| **2** | Count paths with obstacles | Same | End → 1 | Out / `grid[i][j]==1` → 0 | `f(i+1, j) + f(i, j+1)` | #paths | Skip blocked cells |
| **3** | Minimum cost path | `f(i,j)`: min sum to reach end | End → `grid[i][j]` | Out → ∞ | `grid[i][j] + min(down, right)` | min sum | Add current cost + smaller next |
| **4** | Maximum cost path | Same | End → `grid[i][j]` | Out → -∞ | `grid[i][j] + max(down, right)` | max sum | Add cost + choose larger next |
| **5** | Count paths (Bottom → Top) | `f(i,j)`: ways to reach (0,0) | `(i,j)==(0,0) → 1` | `i<0 or j<0 → 0` | `f(i-1, j) + f(i, j-1)` | #paths | Reverse direction traversal |
| **6** | Count paths with diagonal | Same | End → 1 | Out → 0 | `f(i+1,j) + f(i,j+1) + f(i+1,j+1)` | #paths | Include diagonal move |
| **7** | Min cost with obstacles | Same | End → `grid[i][j]` | Out / blocked → ∞ | `grid[i][j] + min(down, right)` | min sum | Avoid obstacle cells |
| **8** | Restricted moves (even→R, odd→D) | Same | End → 1 | Out → 0 | Conditional next moves | #paths | Move depends on parity |
| **9** | Min steps (cost = 1 per move) | Same | End → 0 | Out → ∞ | `1 + min(down, right)` | min steps | Add one step each move |
| **10** | Variable jumps (1..K) | Same | End → 1 | Out → 0 | Σ over jumps | #paths | Try all possible jump lengths |
| **11** | Restricted zones | Same | End → 1 | Out / `grid[i][j]==-1` → 0 | Right + Down | #paths | Avoid forbidden zones |
| **12** | Min cost with diagonal | Same | End → `grid[i][j]` | Out → ∞ | `grid[i][j] + min(R, D, Diag)` | min sum | Add diagonal as third option |
| **13** | Count paths (3-direction) | Same | End → 1 | Out → 0 | Right + Down + Diag | #paths | 3 possible directions |
| **14** | Count paths on `grid[i][j]==1` | Same | End → 1 | Out / cell==0 → 0 | Right + Down | #paths | Step only on valid 1-cells |
| **15** | Max coins collection | `f(i,j)`: max coins | End → `grid[i][j]` | Out → -∞ | `grid[i][j] + max(D, R)` | max coins | Maximize collected values |
| **16** | Min effort / energy | `f(i,j)`: min total diff | End → 0 | Out → ∞ | `min(|a-b| + next)` | min effort | Pick smaller difference |
| **17** | Paths with turn limit | `f(i,j,dir,t)` | End → 1 | Out / `t>k` → 0 | Continue or turn | #paths | Add direction & turn count |
| **18** | Count paths with exact sum | `f(i,j,target)` | End & match → 1 | Out / `target<0` → 0 | `f(i+1,j,t-grid[i][j]) + f(i,j+1,t-grid[i][j])` | #paths | Subtract cell value each step |
| **19** | Max product path | `f(i,j)`: max product | End → `grid[i][j]` | Out → 1 | `grid[i][j] * max(D, R)` | max product | Multiply instead of add |
| **20** | Min path (Top → Bottom) | `f(i,j)`: min sum downward | Bottom → `grid[i][j]` | Out → ∞ | `grid[i][j] + min(3 dirs)` | min sum | Move down, down-left, down-right |
| **21** | Knight paths (chess) | `f(i,j)`: ways to end | Start==End → 1 | Out → 0 | Sum(8 knight moves) | #paths | Apply knight’s movement rules |
| **22** | Avoid diagonal blocked | Same | End → 1 | Out / `(i==j && blocked)` | R + D | #paths | Skip cells on blocked diagonal |
| **23** | Longest increasing path | `f(i,j)`: max length | Start → 1 | Out / `next≤cur` → 0 | `1 + max(4 dirs if inc.)` | max len | Move only if increasing |
| **24** | Any corner → any corner | Same | End → 1 | Out → 0 | Same recurrence | #paths | Multi-source version |
| **25** | Min time grid | `f(i,j)`: min time | End → `grid[i][j]` | Out → ∞ | `grid[i][j] + min(D, R)` | min time | Weighted traversal time |

---

## 🧭 DP Design Template

1️⃣ **Define State**  
→ What does `f(i, j)` represent?  
(e.g., number of ways, minimum cost, etc.)

2️⃣ **Base Case**  
→ Usually destination cell or condition (e.g., `f(end)=1` or `grid[i][j]`).  

3️⃣ **Invalid Condition**  
→ Out of bounds, obstacle, invalid target, etc.  

4️⃣ **Recurrence Relation**  
→ Pick transitions among valid moves (`R, D, Diagonal`).  
→ Use **sum**, **min**, or **max** depending on problem type.  

5️⃣ **Memoization / Tabulation**  
→ Cache results or fill table bottom-up.

---

## 🧮 Common Recurrence Forms

| Type | Formula |
|------|----------|
| **Counting** | `f = Σ(next moves)` |
| **Minimize** | `f = cost + min(next)` |
| **Maximize** | `f = cost + max(next)` |
| **Product** | `f = val × max(next)` |
| **Target Sum** | `f = Σ(f(next, target - val))` |
| **Variable Jump** | `f = Σ(f(i+step, j)) + f(i, j+step)` |

---

## 🧱 Constant Base Patterns

| Base Case | Meaning |
|------------|----------|
| Reached destination → 1 | For counting problems |
| Reached destination → `grid[i][j]` | For cost/coins |
| Out of grid → 0 | For counting |
| Out of grid → ∞ / -∞ | For min/max problems |
| `target < 0 → 0` | For target-sum type |

---

## 💡 Key Reminders

- Return **0** for invalid paths (counting problems).  
- Return **∞ / -∞** for impossible states (optimization problems).  
- Base case often = **destination cell** or **exact constraint**.  
- Use **recursive + memoized → then tabulate** to optimize.  

---

### 🗂️ Suggested File Structure (for practice)
```
📁 DP_on_Grid/
 ├── CountPaths.cpp
 ├── MinCostPath.cpp
 ├── PathsWithObstacles.cpp
 ├── MaxCoinCollect.cpp
 ├── LongestIncreasingPath.cpp
 └── ... (more variations)
```
