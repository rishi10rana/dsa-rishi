**Approach to Solve

1. leftSum = 0 and rightSum = sum of all elements
2. then traverse in array using for loop 0 -> n
3. pick an index element and subtract it from rightSum
4.check leftSum == rightSum if true return i
5. each time then add this index element to left Sum