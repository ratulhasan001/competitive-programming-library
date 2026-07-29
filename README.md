# Competitive Programming Templates & Snippets

A personal collection of C++ templates, algorithm implementations, and VS Code snippets used for competitive programming (Codeforces, CSES, UVa, etc.). Everything here is written for quick reuse during contests — clarity and speed of adaptation over production-grade polish.

## Structure

```
├── Template/     Contest boilerplate, debug macros, and VS Code snippets
├── DP/           Dynamic programming problems and patterns
├── Graph/        Graph algorithms and data structures
├── Backtracking/ Backtracking / recursion examples
└── contest.docx  Contest notes
```

## Template/

| File | Description |
|---|---|
| [template1.cpp](Template/template1.cpp) | Minimal contest starter: fast I/O, common typedefs (`ll`, `pii`), `debug()` macro (disabled on `ONLINE_JUDGE`), multi-test-case loop. |
| [template2.cpp](Template/template2.cpp) | Extended starter with `#pragma GCC optimization`, `pb_ds` ordered set (order-statistics tree), and `deBUG.h` include. |
| [deBUG.h](Template/deBUG.h) | Standalone debug-printing header — pretty-prints containers, pairs, tuples, stacks, queues, and priority queues via a variadic `debug(...)` macro. |
| [cpp.json](Template/cpp.json) | VS Code C++ snippet definitions (see below). |

### VS Code snippets (`Template/cpp.json`)

| Prefix | Purpose |
|---|---|
| `snippet` | Bundle of number-theory helpers: primality test, `isPowerof`, `powmod`, `binpow`, palindrome check |
| `cpp` | Full contest template (fast I/O + typedefs + macros) |
| `basic` | Minimal `main()` skeleton |
| `debug` | Debug-printer macro block |
| `isPrime` | Trial-division primality check |
| `bitwiseSieve` | Sieve of Eratosthenes using bitwise tricks |
| `bitsetSieve` | Sieve of Eratosthenes using `bitset` |
| `divisor` | Divisor enumeration |
| `powmod` | Modular exponentiation |
| `binpow` | Binary exponentiation |
| `customHash` | Anti-hash-collision custom hash for `unordered_map`/`set` |
| `isSubstring` | Substring check |
| `execution` | Execution timer |
| `onlyDebug` | Debug-only code block guard |
| `orderedSet` | PBDS ordered set (order-statistics) |
| `MillerRabin` | Miller-Rabin primality test |
| `dfs` | DFS traversal skeleton |
| `prime_factor` | Prime factorization |

To use: copy the relevant entries into your VS Code user snippets for C++ (`cpp.json`).

## DP/

| File | Problem / Pattern |
|---|---|
| [0-1_knapsack.cpp](DP/0-1_knapsack.cpp) | 0/1 Knapsack |
| [unbounded_knapsack.cpp](DP/unbounded_knapsack.cpp) | Unbounded knapsack (memoized) |
| [rod_cutting.cpp](DP/rod_cutting.cpp) | Rod cutting (unbounded knapsack variant) |
| [subset_sum.cpp](DP/subset_sum.cpp) | Subset sum (existence check) |
| [equal_sum_array_partition.cpp](DP/equal_sum_array_partition.cpp) | Partition array into two equal-sum subsets |
| [minimum_subset_sum_difference.cpp](DP/minimum_subset_sum_difference.cpp) | Minimize the difference between two subset sums |
| [coin_change1.cpp](DP/coin_change1.cpp) | Coin change — count number of ways |
| [coin_change_2.cpp](DP/coin_change_2.cpp) | Coin change — minimum number of coins |
| [lcs.cpp](DP/lcs.cpp) | Longest Common Subsequence (with reconstruction) |
| [lcs_subtring.cpp](DP/lcs_subtring.cpp) | Longest Common Substring |
| [lps.cpp](DP/lps.cpp) | Longest Palindromic Subsequence |
| [shortest_common_supersequence.cpp](DP/shortest_common_supersequence.cpp) | Shortest Common Supersequence (with reconstruction) |
| [check_if_string_is_a_subseq.cpp](DP/check_if_string_is_a_subseq.cpp) | Check if one string is a subsequence of another (O(N) two-pointer and O(N·M) LCS approach) |
| [undirected_cycle_detect_using_dsu.cpp](DP/undirected_cycle_detect_using_dsu.cpp) | Cycle detection in an undirected graph using DSU (union by size / by rank) |

## Graph/

| File | Algorithm |
|---|---|
| [shortest_path_bfs.cpp](Graph/shortest_path_bfs.cpp) | BFS shortest path with path reconstruction |
| [bfs_2D.cpp](Graph/bfs_2D.cpp) | BFS on a 2D grid |
| [dfs_depth_height.cpp](Graph/dfs_depth_height.cpp) | DFS computing node depth and subtree height |
| [cycle_detection_using_dfs.cpp](Graph/cycle_detection_using_dfs.cpp) | Cycle detection in an undirected graph using DFS |
| [dijkstra.cpp](Graph/dijkstra.cpp) | Dijkstra's shortest path with path reconstruction |
| [bellman_ford.cpp](Graph/bellman_ford.cpp) | Bellman-Ford shortest path |
| [negative_cycle_detection_bellman_ford.cpp](Graph/negative_cycle_detection_bellman_ford.cpp) | Bellman-Ford with negative-cycle detection and per-query output |
| [floyd_warshall.cpp](Graph/floyd_warshall.cpp) | Floyd-Warshall all-pairs shortest path |
| [kruskal.cpp](Graph/kruskal.cpp) | Kruskal's MST using DSU |
| [prims.cpp](Graph/prims.cpp) | Prim's MST using a priority queue |
| [segment_tree.cpp](Graph/segment_tree.cpp) | Segment tree (range min query + point update) |

## Backtracking/

| File | Description |
|---|---|
| [backtrack.cpp](Backtracking/backtrack.cpp) | Generates all permutations of `1..n` via backtracking |

## Usage

These are meant to be copy-pasted (or referenced) into contest solutions rather than compiled as a library. Most files read input directly from `stdin` and print to `stdout`, matching typical competitive-programming judge I/O.

To compile and test any file locally:

```bash
g++ -std=c++17 -O2 -o sol DP/lcs.cpp
./sol
```

## Notes

- `deBUG.h` / the `debug(...)` macro is compiled out when `ONLINE_JUDGE` is defined, so it's safe to leave in submissions.
- Some files include commented-out alternate approaches or complexity notes inline (e.g. `subset_sum.cpp`, `coin_change1.cpp`) — kept for quick reference during contests.
