# Math Formulas Reference

## Equations

Quadratic formula: for `ax^2 + bx + c = 0`

```
x = (-b ± sqrt(b^2 - 4ac)) / 2a
```

The extremum is given by `x = -b / 2a`.

## Sums

```
c^a + c^(a+1) + ... + c^b = (c^(b+1) - c^a) / (c - 1),  c != 1

1 + 2 + 3 + ... + n       = n(n+1) / 2
1^2 + 2^2 + ... + n^2     = n(n+1)(2n+1) / 6
1^3 + 2^3 + ... + n^3     = n^2(n+1)^2 / 4
1^4 + 2^4 + ... + n^4     = n(n+1)(2n+1)(3n^2+3n-1) / 30
```

## Series

```
e^x       = 1 + x + x^2/2! + x^3/3! + ...,             -inf < x < inf
ln(1+x)   = x - x^2/2 + x^3/3 - x^4/4 + ...,            -1 < x <= 1
sqrt(1+x) = 1 + x/2 - x^2/8 + 2x^3/32 - 5x^4/128 + ...,  -1 <= x <= 1
sin(x)    = x - x^3/3! + x^5/5! - x^7/7! + ...,          -inf < x < inf
cos(x)    = 1 - x^2/2! + x^4/4! - x^6/6! + ...,          -inf < x < inf
```

## Primes

`p = 962592769` is such that `2^21 | p - 1`, which may be useful.

For hashing use `970592641` (31-bit), `31443539979727` (45-bit), `3006703054056749` (52-bit).

There are 78498 primes less than 1,000,000.
