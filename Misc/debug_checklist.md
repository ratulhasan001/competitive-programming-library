# Contest Debugging Checklist

## Before submitting
- Divisible by 0? Check zero, min, max, prime, and same-digit edge cases.
- Array bounds, constraints, and any precalculation correct?
- Generate max and min test cases by hand, also check `0`.
- Check for TLE, overflow, and uninitialized variables.
- Check consecutive/duplicate-value cases.
- Check output format and whitespace.
- Check every case given in the problem statement.
- Check for overflow — do you need `long long`?

## TLE
- Re-check the constraints.
- How many times are you looping, and how deep is the nesting?
- If it's a math problem and you're getting TLE, a loop won't save you — look for a closed-form equation.

## Runtime Error
- Division by zero?
- Array (or string) index out of bounds?
- Loop running past your array/string limit?

## Wrong Answer
- Re-check the constraints — are you handling the highest and lowest bounds?
- Does this need `long long`?
- Any corner case you're not thinking about? Don't skip it, check it.
- Garbage values from an uninitialized variable?
- Which case are you silently skipping?

## Presentation Error
- Newline after output?
- Test the combination of same / same+1 / diff+1 / same+different inputs.
- Using Python? Make sure `//` (integer division) isn't accidentally `/`.

> When it's hard: switch to Python for quick prototyping.
