## there are some tricks for competitive programming
from: https://www.geeksforgeeks.org/c-tricks-competitive-programming-c-11/

1) Checking if the number is even or odd without using the % operator:
```cpp
    if (num & 1)
        cout << "ODD";
    else
        cout << "EVEN";
```

2) Fast Multiplication or Division by 2
```c++
    n = n << 1;   // Multiply n with 2
    n = n >> 1;   // Divide n by 2
```

3) Swapping of 2 numbers using XOR:
```c++
    // A quick way to swap a and b
    a ^= b;
    b ^= a;
    a ^= b;
```

4) Avoiding use of strlen():
```c++
    //  Use of strlen() can be avoided by:
    for (i=0; s[i]; i++)
    {
    }
    // loop breaks when the character array ends.
```

5)
...

9) Calculating the most significant digit: To calculate the most significant digit of any number log can be directly used to calculate it.
```seudocode
    Suppose the number is N then
    Let double K = log10(N);
    now K = K - floor(K);
    int X = pow(10, K);
    X will be the most significant digit.
```

10) Calculating the number of digits directly: To calculate number of digits in a number, instead of looping you can efficiently use log :
Number of digits in N =floor(log10(N)) + 1;

11) Efficient trick to know if a number is a power of 2 sing the normal technique of division the complexity comes out to be O(logN), but it can be solved using O(v) where v are the number of digits of number in binary form.
```c++
    // !! so cool
    /* Function to check if x is power of 2*/
    bool isPowerOfTwo (int x)
    {
        /* First x in the below expression is
        for the case when x is 0 */
        return x && (!(x&(x-1)));
    }
```

12) C++11 has in built algorithms for following:
```c++
    // are all of the elements positive?
    all_of(first, first+n, ispositive());

    // is there at least one positive element?
    any_of(first, first+n, ispositive());

    // are none of the elements positive?
    none_of(first, first+n, ispositive());
```
Please refer Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and itoa) for details.

14) The Iota Algorithm The algorithm iota() creates a range of sequentially increasing values, as if by assigning an initial value to *first, then incrementing that value using prefix ++. In the following listing, iota() assigns the consecutive values {10, 11, 12, 13, 14} to the array arr, and {‘a’, ‘b’, ‘c’} to the char array c[].
```c++
    int a[5] = {0};
    char c[3] = {0};

    // changes a to {10, 11, 12, 13, 14}
    iota(a, a+5, 10);
    iota(c, c+3, 'a'); // {'a', 'b', 'c'}
```
Please refer Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and itoa) for details.

15) Initialization in Binary form: In C++ 11 assignments can also be made in binary form.
```c++
    // C++ code to demonstrate working of
    // "binary" numbers
    #include<iostream>
    using namespace std;
    int main()
    {
        auto number = 0b011;
        cout << number;
        return 0;
    }
```

# scanf tricks
from https://www.cprogramming.com/tips/tip/the-power-of-scanf
```cpp
char a[100]
scanf("%[^\n]\n", a);
// it means read until you meet '\n', then trash that '\n'

canf("%[^,]", a);
// this one doesn't trash the coma

scanf("%[^,],",a);
// this one trashes the coma

scanf("%s %s", temp, last_name);
// typical answer, using 1 temporary variable

scanf("%s", last_name);
scanf("%s", last_name);
// another answer, only use 1 variable, but calls scanf twice

scanf("%*s %s", last);
// best answer, because you don't need extra temporary variable nor calling scanf twice
```
consider using fgets and sscanf rather than just scanf itself