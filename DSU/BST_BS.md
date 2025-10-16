# Tree Recursion Templates

Compact collection of recursive & iterative tree function templates (C++), with time/space complexity notes. Paste this `README.md` into your GitHub repo alongside `tree_recursion_templates.cpp`.

---

## What this file contains

- Common recursive and iterative templates for binary tree / BST problems:
  - insert, delete, balance, flatten, invert, merge, LCA, traversals, diameter, serialize/deserialize, path sum, kth smallest, validate BST, build from preorder+inorder, and utilities.
- One-line **Time / Space** annotations for each function.
- A short example `main()` demonstrating usage.

---

## Quick complexity rules (n = number of nodes, h = tree height)

- If function visits **every node** → **Time:** `O(n)`.
- If it walks a single root→leaf path → **Time:** `O(h)` (BST insert/delete/search typically).
- **Space:** usually recursion stack `O(h)` unless an explicit container (vector/queue/string) is used → `O(n)`.

---

## Source: `tree_recursion_templates.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* ------------------------------------------------------------------
   Quick complexity table (n = #nodes, h = tree height)

   - O(n) time: functions that must visit every node (traversals, serialize,
     flatten, diameter, validate, merge, etc.).
   - O(h) time: operations that walk a single root→leaf path (BST insert/delete/search)
   - Space: recursion stack O(h) unless an explicit container (vector/queue/string) is used -> O(n).
   ------------------------------------------------------------------ */

// 1) Recursive insert into BST
// Time: O(h) (worst O(n))   Space: O(h) recursion
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

// 1b) Iterative insert into BST
// Time: O(h) (worst O(n))   Space: O(1) extra
TreeNode* insertIterative(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left) cur = cur->left;
            else { cur->left = new TreeNode(val); break; }
        } else {
            if (cur->right) cur = cur->right;
            else { cur->right = new TreeNode(val); break; }
        }
    }
    return root;
}

// 2) Delete from BST
// Time: O(h) (worst O(n))   Space: O(h) recursion
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            TreeNode* r = root->right; delete root; return r;
        }
        if (!root->right) {
            TreeNode* l = root->left; delete root; return l;
        }
        TreeNode* succ = root->right;
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}

// 3) Balance (build balanced BST from inorder values)
// Time: O(n)   Space: O(n) extra for inorder + O(log n) recursion
TreeNode* buildBalancedBST(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBalancedBST(nums, l, mid - 1);
    root->right = buildBalancedBST(nums, mid + 1, r);
    return root;
}
TreeNode* balanceBST(TreeNode* root) {
    vector<int> inorder;
    function<void(TreeNode*)> dfs = [&](TreeNode* node){
        if (!node) return; dfs(node->left); inorder.push_back(node->val); dfs(node->right);
    };
    dfs(root);
    return buildBalancedBST(inorder, 0, (int)inorder.size() - 1);
}

// 4) Flatten binary tree to linked list (preorder -> right chain)
// Time: O(n)   Space: O(h) recursion
void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = NULL;
    root->right = left;
    TreeNode* cur = root;
    while (cur->right) cur = cur->right;
    cur->right = right;
}

// 5) Invert / mirror
// Time: O(n)   Space: O(h)
TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root->left = r; root->right = l;
    return root;
}

// 6) Merge two trees
// Time: O(min(n1,n2)) ~ O(n_visited)   Space: O(h)
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

// 7) Lowest Common Ancestor in BST
// Time: O(h)   Space: O(h)
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestorBST(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestorBST(root->right, p, q);
    return root;
}

// 8) Lowest Common Ancestor in Binary Tree (general)
// Time: O(n)   Space: O(h)
TreeNode* lcaBT(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    TreeNode* l = lcaBT(root->left, p, q);
    TreeNode* r = lcaBT(root->right, p, q);
    if (l && r) return root;
    return l ? l : r;
}

// 9) Max depth
// Time: O(n)   Space: O(h)
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 10) Check balanced
// Time: O(n)   Space: O(h)
int checkBalance(TreeNode* root) {
    if (!root) return 0;
    int l = checkBalance(root->left); if (l == -1) return -1;
    int r = checkBalance(root->right); if (r == -1) return -1;
    if (abs(l - r) > 1) return -1;
    return 1 + max(l, r);
}
bool isBalanced(TreeNode* root) { return checkBalance(root) != -1; }

// 11) Diameter of binary tree (returns diameter)
// Time: O(n)   Space: O(h)
pair<int,int> diamHelper(TreeNode* root) { // {height, diameter}
    if (!root) return {0, 0};
    auto L = diamHelper(root->left);
    auto R = diamHelper(root->right);
    int height = 1 + max(L.first, R.first);
    int dia = max({L.second, R.second, L.first + R.first});
    return {height, dia};
}
int diameterOfBinaryTree(TreeNode* root) { return diamHelper(root).second; }

// 12) Convert to Sum Tree (replace node value with sum of left & right subtree original values)
// Time: O(n)   Space: O(h)
int toSumTree(TreeNode* root) {
    if (!root) return 0;
    int old = root->val;
    int l = toSumTree(root->left);
    int r = toSumTree(root->right);
    root->val = l + r;
    return root->val + old; // return total original sum
}

// 13) Serialize / Deserialize (preorder with null marker)
// Time: O(n)   Space: O(n) for string + O(h) recursion
string serialize(TreeNode* root) {
    if (!root) return string();
    ostringstream out;
    function<void(TreeNode*)> dfs = [&](TreeNode* node){
        if (!node) { out << "# "; return; }
        out << node->val << ' ';
        dfs(node->left);
        dfs(node->right);
    };
    dfs(root);
    return out.str();
}

TreeNode* deserializeHelper(istringstream &in) {
    string s; if (!(in >> s)) return NULL;
    if (s == "#") return NULL;
    int v = stoi(s);
    TreeNode* node = new TreeNode(v);
    node->left = deserializeHelper(in);
    node->right = deserializeHelper(in);
    return node;
}

TreeNode* deserialize(const string &data) {
    if (data.empty()) return NULL;
    istringstream in(data);
    return deserializeHelper(in);
}

// 14) Path Sum (existence) and all root-to-leaf paths with given sum
// hasPathSum: Time O(n) Space O(h)
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

// pathSumAll: Time O(n + output_size) Space O(h + output_size)
void pathSumAll(TreeNode* root, int target, vector<int>& cur, vector<vector<int>>& out) {
    if (!root) return;
    cur.push_back(root->val);
    if (!root->left && !root->right && target == root->val) out.push_back(cur);
    pathSumAll(root->left, target - root->val, cur, out);
    pathSumAll(root->right, target - root->val, cur, out);
    cur.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>> out; vector<int> cur; pathSumAll(root, target, cur, out); return out;
}

// 15) Kth smallest in BST (inorder)
// Time: O(k + h) typical, worst O(n)   Space: O(h)
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    int ans = -1;
    function<void(TreeNode*)> dfs = [&](TreeNode* node){
        if (!node || cnt >= k) return;
        dfs(node->left);
        if (++cnt == k) { ans = node->val; return; }
        dfs(node->right);
    };
    dfs(root);
    return ans;
}

// 16) Validate BST
// Time: O(n)   Space: O(h)
bool validateBST(TreeNode* root, long long low = LLONG_MIN, long long high = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= low || root->val >= high) return false;
    return validateBST(root->left, low, root->val) && validateBST(root->right, root->val, high);
}

// 17) Level order traversal
// Time: O(n)   Space: O(n) (queue + result)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res; if (!root) return res;
    queue<TreeNode*>q; q.push(root);
    while (!q.empty()){
        int n = q.size(); vector<int> layer;
        while (n--) {
            TreeNode* t = q.front(); q.pop(); layer.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        res.push_back(layer);
    }
    return res;
}

// 18) Traversals (recursive)
// Time: O(n)   Space: O(h) (+ O(n) if storing result)
void inorder(TreeNode* root, vector<int>& out){ if (!root) return; inorder(root->left,out); out.push_back(root->val); inorder(root->right,out); }
void preorder(TreeNode* root, vector<int>& out){ if (!root) return; out.push_back(root->val); preorder(root->left,out); preorder(root->right,out); }
void postorder(TreeNode* root, vector<int>& out){ if (!root) return; postorder(root->left,out); postorder(root->right,out); out.push_back(root->val); }

// 19) Build tree from preorder + inorder (classic)
// Time: O(n)   Space: O(n) for map + O(h) recursion
TreeNode* buildFromPreIn(vector<int>& pre, int preL, int preR, vector<int>& in, int inL, int inR, unordered_map<int,int>& pos) {
    if (preL > preR) return NULL;
    int rootVal = pre[preL]; int idx = pos[rootVal];
    int leftSz = idx - inL;
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildFromPreIn(pre, preL+1, preL+leftSz, in, inL, idx-1, pos);
    root->right = buildFromPreIn(pre, preL+leftSz+1, preR, in, idx+1, inR, pos);
    return root;
}
TreeNode* buildTreeFromPreIn(vector<int>& pre, vector<int>& in) {
    unordered_map<int,int> pos;
    for (int i=0;i<in.size();++i) pos[in[i]] = i;
    return buildFromPreIn(pre, 0, (int)pre.size()-1, in, 0, (int)in.size()-1, pos);
}

/* ----------------------- Utilities / quick tests ----------------------- */
void printRightChain(TreeNode* root) {
    for (TreeNode* cur = root; cur; cur = cur->right) cout << cur->val << " ";
    cout << '\n';
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left); freeTree(root->right); delete root;
}

int main(){
    // small usage example — you can expand tests as needed
    TreeNode* root = NULL;
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 8);

    cout << "Inorder: "; vector<int> arr; inorder(root, arr); for (int v: arr) cout << v << ' '; cout << '\n';

    cout << "Kth(2): " << kthSmallest(root, 2) << '\n';
    cout << "Diameter: " << diameterOfBinaryTree(root) << '\n';

    string s = serialize(root);
    TreeNode* root2 = deserialize(s);
    cout << "Serialized and deserialized. Root2 inorder: "; arr.clear(); inorder(root2, arr); for (int v: arr) cout << v << ' '; cout << '\n';

    freeTree(root); freeTree(root2);
    return 0;
}
```

---

## How to use
1. Copy `tree_recursion_templates.cpp` into your repo and include this `README.md`.
2. Compile with `g++ -std=c++17 tree_recursion_templates.cpp -O2 -o tree_tests` and run `./tree_tests`.
3. Modify `main()` to add more test cases.

---

If you want, I can also:
- provide a standalone `README.md` with section-per-function (short signatures) — done here,
- create a header-only `.hpp` version with namespace wrapping,
- add unit tests (Google Test) or a CI workflow for GitHub Actions.

Which one next?