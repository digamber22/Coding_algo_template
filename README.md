# Coding_algo_template

## Disjoint Set Union (DSU) Algorithm

- **Purpose**: Efficiently manage a collection of disjoint sets, often used in **dynamic graphs** where edges/nodes change over time.
- **Time Complexity**: `O(α(N))` (Inverse Ackermann function) → practically constant.
- **Core Operations**:
  1. **findUPar** – Finds the ultimate parent of a node (with path compression).
  2. **union** – Merges two sets:
     - **unionByRank** – Attach smaller rank tree to larger rank tree.
     - **unionBySize** – Attach smaller-sized set to larger-sized set.
