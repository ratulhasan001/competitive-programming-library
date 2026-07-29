import sys
input = sys.stdin.readline  # faster input

n = int(input())
arr = [int(x) for x in input().split()]
matrix = [list(map(int, input().split())) for _ in range(n)]

from collections import Counter
arr = [1, 2, 3, 4, 5, 5, 5, 5]
cnt = Counter(arr)
print(cnt[5])          # count of 5
x = 3.14159
print(f"{x:.4f}")      # fixed-precision float formatting

# sort by frequency, then by value
sorted(cnt.items(), key=lambda x: (-x[1], x[0]))

for i in reversed(range(n)):
    pass

a, b = map(int, input().split())

# enumerate for index + value
for i, val in enumerate(arr):
    print(i, val)

s = "first/second"
first, second = s.split("/")

s = input().strip()
s = s.lower()
s = s.upper()
s = s[::-1]  # reverse

parts = s.split()
list_of_strings = ["a", "b", "c"]
joined = "_".join(list_of_strings)

prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + arr[i]

# careful: use // for integer division in Python, / is float division
