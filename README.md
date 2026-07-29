# Competitive Programming Templates & Snippets

A personal collection of C++ templates, algorithm implementations, and VS Code snippets used for competitive programming (Codeforces, CSES, UVa, etc.). Everything here is written for quick reuse during contests — clarity and speed of adaptation over production-grade polish.

## Structure

```
├── Template/        Contest boilerplate, debug macros, and VS Code snippets
├── NumberTheory/     Primality, factorization, combinatorics, modular arithmetic
├── Bitmasking/       Bit tricks, bitmask DP helpers, XOR basis
├── DP/               Dynamic programming problems and patterns
├── Graph/            Graph algorithms and data structures
├── DataStructures/   Fenwick tree, sparse table, lazy segment tree, trie, ordered set, Mo's algorithm
├── String/           Z-function, string hashing, Manacher's algorithm
├── Geometry/         Points, cross product, convex hull
├── Math/             Matrix exponentiation, FFT, formula reference
├── Backtracking/     Backtracking / recursion examples
├── Misc/             STL & Python cheatsheets, debugging checklist
└── contest.docx      Contest notes
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

## NumberTheory/

| File | Description |
|---|---|
| [sieve_normal.cpp](NumberTheory/sieve_normal.cpp) | Trial-division primality check |
| [sieve_bitwise.cpp](NumberTheory/sieve_bitwise.cpp) | Sieve of Eratosthenes packed into bits of an `int` array |
| [sieve_bitset.cpp](NumberTheory/sieve_bitset.cpp) | Sieve of Eratosthenes using `std::bitset` |
| [miller_rabin.cpp](NumberTheory/miller_rabin.cpp) | Deterministic Miller-Rabin primality test (64-bit safe) |
| [pollard_rho.cpp](NumberTheory/pollard_rho.cpp) | Pollard's Rho integer factorization (uses Miller-Rabin) |
| [divisors.cpp](NumberTheory/divisors.cpp) | Enumerate all divisors of `n` in O(√n) |
| [smallest_prime_factor.cpp](NumberTheory/smallest_prime_factor.cpp) | Smallest-prime-factor sieve + O(log n) factorization |
| [euler_totient.cpp](NumberTheory/euler_totient.cpp) | Euler's totient function for all values `1..n` |
| [factorial_ncr.cpp](NumberTheory/factorial_ncr.cpp) | Precomputed factorials/inverse factorials, `nCr`, `nPr` (mod and plain) |
| [gcd_lcm_power.cpp](NumberTheory/gcd_lcm_power.cpp) | `gcd`, `lcm`, `binpow`, `powmod`, `isPowerof`, power-of-two helpers |
| [extended_euclidean.cpp](NumberTheory/extended_euclidean.cpp) | Extended Euclidean algorithm (`ax + by = gcd(a,b)`) |
| [mod_inverse.cpp](NumberTheory/mod_inverse.cpp) | Modular inverse via extended Euclidean (works for non-prime modulus) |
| [crt.cpp](NumberTheory/crt.cpp) | Chinese Remainder Theorem — combine congruences, moduli need not be coprime |

## Bitmasking/

| File | Description |
|---|---|
| [bit_tricks.cpp](Bitmasking/bit_tricks.cpp) | Cheatsheet of bit operations: check/set/clear/toggle, popcount, lowbit, etc. |
| [subset_sum_bitmask.cpp](Bitmasking/subset_sum_bitmask.cpp) | Brute-force subset sum by enumerating all `2^n` masks |
| [binary_conversion.cpp](Bitmasking/binary_conversion.cpp) | Binary ↔ decimal conversion, including two's-complement negatives |
| [linear_basis_xor.cpp](Bitmasking/linear_basis_xor.cpp) | XOR linear basis for maximum-XOR-subset queries |
| [sos_dp.cpp](Bitmasking/sos_dp.cpp) | Sum over Subsets (SOS) DP — O(n·2^n) subset-sum aggregation |

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
| [bounded_knapsack_binary_lifting.cpp](DP/bounded_knapsack_binary_lifting.cpp) | Bounded coin change solved as 0/1 knapsack via binary lifting on item counts |
| [min_cost_to_reach_value.cpp](DP/min_cost_to_reach_value.cpp) | Minimum weight needed to reach each achievable value (dual of knapsack) |
| [lcs.cpp](DP/lcs.cpp) | Longest Common Subsequence (with reconstruction) |
| [lcs_subtring.cpp](DP/lcs_subtring.cpp) | Longest Common Substring |
| [lps.cpp](DP/lps.cpp) | Longest Palindromic Subsequence |
| [shortest_common_supersequence.cpp](DP/shortest_common_supersequence.cpp) | Shortest Common Supersequence (with reconstruction) |
| [check_if_string_is_a_subseq.cpp](DP/check_if_string_is_a_subseq.cpp) | Check if one string is a subsequence of another (O(N) two-pointer and O(N·M) LCS approach) |
| [undirected_cycle_detect_using_dsu.cpp](DP/undirected_cycle_detect_using_dsu.cpp) | Cycle detection in an undirected graph using DSU (union by size / by rank) |
| [fibonacci.cpp](DP/fibonacci.cpp) | Fibonacci — memoized recursion (+ iterative and mod variants inline) |
| [derangement.cpp](DP/derangement.cpp) | Count derangements (permutations with no fixed point) |
| [kadane_max_subarray.cpp](DP/kadane_max_subarray.cpp) | Kadane's algorithm — maximum subarray sum |
| [longest_increasing_subsequence.cpp](DP/longest_increasing_subsequence.cpp) | LIS in O(n log n), with reconstruction |
| [digit_dp.cpp](DP/digit_dp.cpp) | Digit DP template — count numbers in a range with a digit-based property |

## Graph/

| File | Algorithm |
|---|---|
| [shortest_path_bfs.cpp](Graph/shortest_path_bfs.cpp) | BFS shortest path with path reconstruction |
| [bfs_2D.cpp](Graph/bfs_2D.cpp) | BFS on a 2D grid |
| [bfs_01.cpp](Graph/bfs_01.cpp) | 0-1 BFS shortest path (deque-based) |
| [dfs_depth_height.cpp](Graph/dfs_depth_height.cpp) | DFS computing node depth and subtree height |
| [cycle_detection_using_dfs.cpp](Graph/cycle_detection_using_dfs.cpp) | Cycle detection in an undirected graph using DFS |
| [dijkstra.cpp](Graph/dijkstra.cpp) | Dijkstra's shortest path with path reconstruction |
| [bellman_ford.cpp](Graph/bellman_ford.cpp) | Bellman-Ford shortest path |
| [negative_cycle_detection_bellman_ford.cpp](Graph/negative_cycle_detection_bellman_ford.cpp) | Bellman-Ford with negative-cycle detection and per-query output |
| [floyd_warshall.cpp](Graph/floyd_warshall.cpp) | Floyd-Warshall all-pairs shortest path |
| [kruskal.cpp](Graph/kruskal.cpp) | Kruskal's MST using DSU |
| [prims.cpp](Graph/prims.cpp) | Prim's MST using a priority queue |
| [segment_tree.cpp](Graph/segment_tree.cpp) | Segment tree (range min query + point update) |
| [tarjan_scc.cpp](Graph/tarjan_scc.cpp) | Tarjan's algorithm — strongly connected components |
| [bridges_articulation_points.cpp](Graph/bridges_articulation_points.cpp) | Bridges and articulation points via DFS low-link |
| [topological_sort_dfs.cpp](Graph/topological_sort_dfs.cpp) | Topological sort — DFS-based |
| [topological_sort_kahn.cpp](Graph/topological_sort_kahn.cpp) | Topological sort — Kahn's algorithm (BFS-based, detects cycles) |
| [lca_binary_lifting.cpp](Graph/lca_binary_lifting.cpp) | Lowest Common Ancestor via binary lifting |
| [heavy_light_decomposition.cpp](Graph/heavy_light_decomposition.cpp) | Heavy-Light Decomposition for path queries on a tree |
| [centroid_decomposition.cpp](Graph/centroid_decomposition.cpp) | Centroid decomposition for divide-and-conquer on trees |
| [dinic_max_flow.cpp](Graph/dinic_max_flow.cpp) | Dinic's algorithm — maximum flow |
| [mcmf.cpp](Graph/mcmf.cpp) | Min-Cost Max-Flow via successive shortest augmenting paths (SPFA) |
| [tsp_bitmask.cpp](Graph/tsp_bitmask.cpp) | Travelling Salesman Problem — bitmask DP (Held-Karp) |
| [two_sat.cpp](Graph/two_sat.cpp) | 2-SAT solver via implication graph + Kosaraju's SCC |
| [bipartite_check.cpp](Graph/bipartite_check.cpp) | Bipartite check via 2-coloring (BFS) |
| [bipartite_matching.cpp](Graph/bipartite_matching.cpp) | Maximum bipartite matching — Kuhn's algorithm |

## DataStructures/

| File | Description |
|---|---|
| [fenwick_tree.cpp](DataStructures/fenwick_tree.cpp) | Fenwick / Binary Indexed Tree with range update + range query |
| [sparse_table.cpp](DataStructures/sparse_table.cpp) | Sparse table for O(1) range-maximum queries (static array) |
| [segment_tree_lazy.cpp](DataStructures/segment_tree_lazy.cpp) | Range-sum segment tree with lazy propagation (range add) |
| [trie.cpp](DataStructures/trie.cpp) | Trie (prefix tree) — insert and search |
| [ordered_set.cpp](DataStructures/ordered_set.cpp) | PBDS ordered set — `find_by_order` / `order_of_key` |
| [mo_algorithm.cpp](DataStructures/mo_algorithm.cpp) | Mo's algorithm for offline range queries (distinct-count example) |
| [dsu_path_compression.cpp](DataStructures/dsu_path_compression.cpp) | Disjoint Set Union with path compression + union by rank, as a reusable struct |

## String/

| File | Description |
|---|---|
| [z_function.cpp](String/z_function.cpp) | Z-function and its use for substring search |
| [string_hashing.cpp](String/string_hashing.cpp) | Single-mod string hash and a double-mod rolling hash (O(1) substring hash) |
| [manacher.cpp](String/manacher.cpp) | Manacher's algorithm — longest palindromic substring in O(n) |
| [kmp.cpp](String/kmp.cpp) | Knuth-Morris-Pratt prefix function + pattern search |
| [suffix_array.cpp](String/suffix_array.cpp) | Suffix array construction (O(n log² n)) + Kasai's LCP array |

## Geometry/

| File | Description |
|---|---|
| [point_basics.cpp](Geometry/point_basics.cpp) | `Point` struct with cross/dot product, orientation test |
| [convex_hull.cpp](Geometry/convex_hull.cpp) | Convex hull via Andrew's monotone chain |
| [segment_intersection.cpp](Geometry/segment_intersection.cpp) | Segment-segment intersection test (handles collinear touching cases) |
| [polygon_area.cpp](Geometry/polygon_area.cpp) | Polygon area (Shoelace formula) + point-in-polygon (ray casting) |

## Math/

| File | Description |
|---|---|
| [matrix_exponentiation.cpp](Math/matrix_exponentiation.cpp) | Matrix exponentiation (e.g. O(log n) Fibonacci) |
| [fft_polynomial_multiplication.cpp](Math/fft_polynomial_multiplication.cpp) | Fast Fourier Transform for polynomial multiplication |
| [formulas.md](Math/formulas.md) | Quadratic formula, sum/series identities, notable primes for hashing |

## Backtracking/

| File | Description |
|---|---|
| [backtrack.cpp](Backtracking/backtrack.cpp) | Generates all permutations of `1..n` via backtracking |
| [n_queens.cpp](Backtracking/n_queens.cpp) | N-Queens — all placements via column/diagonal tracking |

## Misc/

| File | Description |
|---|---|
| [stl_cheatsheet.cpp](Misc/stl_cheatsheet.cpp) | Common `vector`/`deque`/`string`/`set` insert & erase idioms |
| [python_cheatsheet.py](Misc/python_cheatsheet.py) | Fast I/O, `Counter`, sorting, slicing, and prefix-sum idioms for Python contests |
| [debug_checklist.md](Misc/debug_checklist.md) | Checklist for TLE / RE / WA / presentation-error debugging |

## Usage

These are meant to be copy-pasted (or referenced) into contest solutions rather than compiled as a library. Most files read input directly from `stdin` and print to `stdout`, matching typical competitive-programming judge I/O.

To compile and test any file locally:

```bash
g++ -std=c++17 -O2 -o sol DP/lcs.cpp
./sol
```

Files that use PBDS (`ordered_set.cpp`, `Template/template2.cpp`) rely on GCC's `<ext/pb_ds/...>` headers and won't compile with clang without extra flags.

## Notes

- `deBUG.h` / the `debug(...)` macro is compiled out when `ONLINE_JUDGE` is defined, so it's safe to leave in submissions.
- Some files include commented-out alternate approaches or complexity notes inline (e.g. `subset_sum.cpp`, `coin_change1.cpp`) — kept for quick reference during contests.
- `Math/formulas.md`, `Misc/python_cheatsheet.py`, and `Misc/debug_checklist.md` are reference notes rather than runnable code.
