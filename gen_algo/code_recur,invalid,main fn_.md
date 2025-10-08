# 🧠 GRID DYNAMIC PROGRAMMING CHEAT SHEET — with concise C++ templates

This cheat sheet includes **25 common DP-on-Grid patterns** (table) plus a **short, copy-pasteable C++ template** for each pattern. Templates are **concise** and meant to show the DP state, base/invalid checks, and the recurrence (top-down memo form).

---

## 🧩 Table of Patterns (quick reference)

| No | Problem Type | State Definition | ✅ Base | 🚫 Invalid | 🔁 Recurrence |
|----|---------------|------------------|--------:|-----------:|--------------|
| 1 | Count paths (Right + Down) | `f(i,j)`: ways to end | `(m-1,n-1)->1` | out -> 0 | `f(i+1,j)+f(i,j+1)` |
| 2 | Count paths w/ obstacles | same | end->1 | out / blocked ->0 | `f(i+1,j)+f(i,j+1)` |
| 3 | Min cost path | `f(i,j)`: min sum to end | end->grid | out->INF | `grid+min(down,right)` |
| 4 | Max cost path | `f(i,j)`: max sum to end | end->grid | out->-INF | `grid+max(down,right)` |
| 5 | Count paths (Bottom->Top) | `f(i,j)`: ways to (0,0) | (0,0)->1 | out->0 | `f(i-1,j)+f(i,j-1)` |
| 6 | Count paths with diagonal | same | end->1 | out->0 | `f(i+1,j)+f(i,j+1)+f(i+1,j+1)` |
| 7 | Min cost with obstacles | same | end->grid | out/blocked->INF | `grid+min(down,right)` |
| 8 | Restricted parity moves | same | end->1 | out->0 | conditional moves |
| 9 | Min steps (each move cost=1) | same | end->0 | out->INF | `1+min(down,right)` |
|10 | Variable jumps (1..K) | same | end->1 | out->0 | sum over jump lengths |
|11 | Restricted zones | same | end->1 | out/forbidden->0 | right+down |
|12 | Min cost with diagonal | same | end->grid | out->INF | `grid+min(R,D,Diag)` |
|13 | Count paths (3-dir) | same | end->1 | out->0 | right+down+diag |
|14 | Count paths on cells==1 | same | end->1 | out/ cell==0 ->0 | right+down |
|15 | Max coins collect | `f(i,j)`: max coins | end->grid | out->-INF | `grid+max(D,R)` |
|16 | Min effort / energy | `f(i,j)`: min total diff | end->0 | out->INF | `min(|a-b|+next)` |
|17 | Paths w/ turn limit | `f(i,j,dir,t)` | end->1 | out/t>k->0 | move/turn transitions |
|18 | Count paths with exact sum | `f(i,j,target)` | end & target==0 ->1 | out/target<0 ->0 | subtract current val |
|19 | Max product path | `f(i,j)`: max product | end->grid | out->1 | `grid * max(next)` |
|20 | Min path (Top->Bottom) | `f(i,j)`: min downward sum | bottom->grid | out->INF | min over 3 downward dirs |
|21 | Knight paths (chess) | `f(i,j)`: ways to end | start==end->1 | out->0 | sum of knight moves |
|22 | Avoid diagonal blocked | same | end->1 | out/blocked diagonal ->0 | right+down |
|23 | Longest increasing path | `f(i,j)`: max length | start->1 | out / next<=cur ->0 | `1+max(inc neighbours)` |
|24 | Any corner -> any corner | same | end->1 | out->0 | same recurrence (multi-source) |
|25 | Min time grid | `f(i,j)`: min time to end | end->grid | out->INF | `grid+min(D,R)` |

---

## 🧭 How to use the templates
- Each snippet is **top-down memoized** (easy to adapt to bottom-up).  
- `m`, `n` are grid dimensions. `grid` is `vector<vector<int>>`.  
- `dp` comment shows required type; adjust for `long long` for large sums.  
- Small and focused — paste into your solution and adapt edge checks.

---

## ✅ Concise C++ Templates (copy-paste ready)

### Pattern 1 — Count paths (Right + Down)
```cpp
int m,n;
vector<vector<int>> dp; // -1 = unvisited
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &res = dp[i][j];
  if(res!=-1) return res;
  return res = (dfs(i+1,j,grid) + dfs(i,j+1,grid));
}
```

### Pattern 2 — Count paths with obstacles (0 = free, 1 = blocked)
```cpp
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n || grid[i][j]==1) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j,grid) + dfs(i,j+1,grid);
}
```

### Pattern 3 — Minimum cost path
```cpp
const int INF = 1e9;
vector<vector<int>> memo; // init with INF
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n) return INF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &res = memo[i][j];
  if(res!=INF) return res;
  int a = dfs(i+1,j,grid), b = dfs(i,j+1,grid);
  return res = grid[i][j] + min(a,b);
}
```

### Pattern 4 — Maximum cost path
```cpp
const int NINF = INT_MIN/4;
vector<vector<int>> memo; // init with NINF
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n) return NINF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &res = memo[i][j]; if(res!=NINF) return res;
  int a = dfs(i+1,j,grid), b = dfs(i,j+1,grid);
  return res = grid[i][j] + max(a,b);
}
```

### Pattern 5 — Count paths (Bottom → Top) to (0,0)
```cpp
int dfs(int i,int j){
  if(i<0||j<0) return 0;
  if(i==0 && j==0) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i-1,j) + dfs(i,j-1);
}
```

### Pattern 6 — Count paths with diagonal
```cpp
int dfs(int i,int j){
  if(i>=m||j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j) + dfs(i,j+1) + dfs(i+1,j+1);
}
```

### Pattern 7 — Min cost w/ obstacles
```cpp
const int INF = 1e9;
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n || grid[i][j]==1) return INF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &r = memo[i][j]; if(r!=INF) return r;
  return r = grid[i][j] + min(dfs(i+1,j,grid), dfs(i,j+1,grid));
}
```

### Pattern 8 — Restricted moves (even → right, odd → down)
```cpp
int dfs(int i,int j){
  if(i>=m||j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  if((i+j)%2==0) return r = dfs(i,j+1); // right
  else return r = dfs(i+1,j); // down
}
```

### Pattern 9 — Min steps (cost = 1 per move)
```cpp
const int INF = 1e9;
int dfs(int i,int j){
  if(i>=m||j>=n) return INF;
  if(i==m-1 && j==n-1) return 0;
  int &r = memo[i][j]; if(r!=INF) return r;
  return r = 1 + min(dfs(i+1,j), dfs(i,j+1));
}
```

### Pattern 10 — Variable jumps (1..K)
```cpp
int dfs(int i,int j, int K){
  if(i>=m||j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  int ways = 0;
  for(int step=1; step<=K; ++step){
    ways += dfs(i+step, j, K) + dfs(i, j+step, K);
  }
  return r = ways;
}
```

### Pattern 11 — Restricted / forbidden zones (-1 = forbidden)
```cpp
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n || grid[i][j]==-1) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j,grid) + dfs(i,j+1,grid);
}
```

### Pattern 12 — Min cost with diagonal
```cpp
const int INF = 1e9;
int dfs(int i,int j){
  if(i>=m||j>=n) return INF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &r = memo[i][j]; if(r!=INF) return r;
  int a = dfs(i+1,j), b = dfs(i,j+1), c = dfs(i+1,j+1);
  return r = grid[i][j] + min(a, min(b,c));
}
```

### Pattern 13 — Count paths (3 directions)
```cpp
int dfs(int i,int j){
  if(i>=m||j>=n) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j) + dfs(i,j+1) + dfs(i+1,j+1);
}
```

### Pattern 14 — Count only on `1` cells (cell==1 allowed)
```cpp
int dfs(int i,int j, vector<vector<int>>& grid){
  if(i>=m||j>=n || grid[i][j]==0) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j,grid) + dfs(i,j+1,grid);
}
```

### Pattern 15 — Max coins collected
```cpp
const int NINF = INT_MIN/4;
int dfs(int i,int j){
  if(i>=m||j>=n) return NINF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &r = memo[i][j]; if(r!=NINF) return r;
  return r = grid[i][j] + max(dfs(i+1,j), dfs(i,j+1));
}
```

### Pattern 16 — Min effort (sum of diffs)
```cpp
const int INF = 1e9;
int dfs(int i,int j){
  if(i>=m||j>=n) return INF;
  if(i==m-1 && j==n-1) return 0;
  int &r = memo[i][j]; if(r!=INF) return r;
  int down = abs(grid[i][j]-grid[i+1][j]) + dfs(i+1,j);
  int right = abs(grid[i][j]-grid[i][j+1]) + dfs(i,j+1);
  return r = min(down, right);
}
```

### Pattern 17 — Paths with turn limit (dir:0=down,1=right)
```cpp
int dfs(int i,int j,int dir,int turns){
  if(i>=m||j>=n || turns>k) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp3[i][j][dir][turns]; if(r!=-1) return r;
  int ways = 0;
  // continue same dir
  if(dir==0) ways += dfs(i+1,j,0,turns);
  else ways += dfs(i,j+1,1,turns);
  // turn (if possible)
  if(dir==0) ways += dfs(i,j+1,1,turns+1);
  else ways += dfs(i+1,j,0,turns+1);
  return r = ways;
}
```

### Pattern 18 — Count paths with exact sum (target)
```cpp
int dfs(int i,int j,int target){
  if(i>=m||j>=n || target<0) return 0;
  if(i==m-1 && j==n-1) return (grid[i][j]==target);
  int &r = dp3[i][j][target]; if(r!=-1) return r;
  return r = dfs(i+1,j,target-grid[i][j]) + dfs(i,j+1,target-grid[i][j]);
}
```

### Pattern 19 — Max product path
```cpp
long long dfs(int i,int j){
  if(i>=m||j>=n) return 1; // neutral for product (or -inf for invalid)
  if(i==m-1 && j==n-1) return grid[i][j];
  long long &r = memo[i][j]; if(r!=-1) return r;
  return r = grid[i][j] * max(dfs(i+1,j), dfs(i,j+1));
}
```

### Pattern 20 — Min path (Top → Bottom) with 3 downward moves
```cpp
const int INF = 1e9;
int dfs(int i,int j){
  if(i<0||j<0||j>=n) return INF;
  if(i==m-1) return grid[i][j]; // bottom row
  int &r = memo[i][j]; if(r!=INF) return r;
  int a = dfs(i+1,j), b = dfs(i+1,j-1), c = dfs(i+1,j+1);
  return r = grid[i][j] + min(a, min(b,c));
}
```

### Pattern 21 — Knight paths (8 moves)
```cpp
int dr[8] = {2,2,-2,-2,1,1,-1,-1}, dc[8]={1,-1,1,-1,2,-2,2,-2};
int dfs(int i,int j){
  if(i<0||j<0||i>=m||j>=n) return 0;
  if(i==tg_r && j==tg_c) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  int ways=0;
  for(int k=0;k<8;++k) ways += dfs(i+dr[k], j+dc[k]);
  return r=ways;
}
```

### Pattern 22 — Avoid blocked diagonal cell(s)
```cpp
int dfs(int i,int j){
  if(i>=m||j>=n) return 0;
  if(i==j && blocked) return 0;
  if(i==m-1 && j==n-1) return 1;
  int &r = dp[i][j]; if(r!=-1) return r;
  return r = dfs(i+1,j) + dfs(i,j+1);
}
```

### Pattern 23 — Longest increasing path (4 dirs)
```cpp
int dfs(int i,int j){
  if(vis[i][j]) return memo[i][j];
  int best = 1;
  for(auto [di,dj] : vector<pair<int,int>>{{1,0},{-1,0},{0,1},{0,-1}}){
    int ni=i+di, nj=j+dj;
    if(inside && grid[ni][nj]>grid[i][j]) best = max(best, 1 + dfs(ni,nj));
  }
  return memo[i][j]=best;
}
```

### Pattern 24 — Any corner → any corner (multi-source)
```cpp
// initialize dp for all 4 corners as starting points and run DFS/BFS memoized accordingly
// same recurrence as counting paths; just seed multiple sources.
```

### Pattern 25 — Min time grid (weighted cost)
```cpp
const int INF = 1e9;
int dfs(int i,int j){
  if(i>=m||j>=n) return INF;
  if(i==m-1 && j==n-1) return grid[i][j];
  int &r = memo[i][j]; if(r!=INF) return r;
  return r = grid[i][j] + min(dfs(i+1,j), dfs(i,j+1));
}
```

---

## 🔚 Notes & Tips
- These templates are intentionally **concise** — adapt types (`int`, `long long`) and initialization (`-1`, `INF`) where needed.  
- For **counting with large answers**, use `long long` / mod arithmetic.  
- When converting to bottom-up, iterate rows/columns in the correct order to respect dependencies.

---

### Suggested filename for GitHub
`Grid_DP_CheatSheet_with_Templates.md`

