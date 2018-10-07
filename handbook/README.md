here: https://cses.fi/book/book.pdf
luck to find this book, when check C-style IO, and this book contain all the methods I get from internet
good, let's start

## ch4 data structures
### dynamic array
!! std::string is also dynamic array

### set structures
std::set self-balance-tree, base operation in &\theta(logn)&
std::unordered_set hashing function, basic operation in $\theta(1)$

### map structures
wait, for looking for repeat value in a array,
I could use map<value_t, int> to map from value to the number of value, great could solve in $\theta(n)$
I also could use std::set or std::unorder_setto find values...
this is like

### iterators and ranges

### other structures
bitset, interesting
queue
deque, two sides
priority queue, interesting
stack
policy-based data structures

### comparsion to sorting

## ch05 complete search
### generating subsets
### generating permutation
#include<algorithm>
std::is_permutation
std::next_permutation
std::prev_permutaion
about permutation in std
0, 1, 2, 3, 4 permutation
```txt
    01234  10234  20134  30124  40123
    01243  10243  20143  30142  40132
    01324  10324  20314  30214  40213
    01342  10342  20341  30241  40231
    01423  10423  20413  30412  40312
    01432  10432  20431  30421  40321

    02134  12034  21034  31024  41023
    02143  12043  21043  31042  41032
    02314  12304  21304  31204  41203
    02341  12340  21340  31240  41230
    02413  12403  21403  31402  41302
    02431  12430  21430  31420  41320

    03124  13024  23014  32014  42013
    03142  13042  23041  32041  42031
    03214  13204  23104  32104  42103
    03241  13240  23140  32140  42130
    03412  13402  23401  32401  42301
    03421  13420  23410  32410  42310

    04123  14023  24013  34012  43012
    04132  14032  24031  34021  43021
    04213  14203  24103  34102  43102
    04231  14230  24130  34120  43120
    04312  14302  24301  34201  43201
    04321  14320  24310  34210  43210
```
algorithm of wenchen::next_permutation_helper
```Pseudo code
    next_permutation_helper(A, l, r)
        IF A[l] is biggest in A[l]~A[r]
            return next_permutation_helper(A, l-1, r)
        swap(A[l], A[k]) // A[k] is min(A[i] | A[i] > A[l])
        std::sort(&A[l+1], &A[r+1])
```

### backtracking
8-queen question
recurrence function,
way1, recurrence by parameter
way2, recurrence by static data

### prunting the search
recap: function pointer and lambda function in std::qsort
here: https://www.geeksforgeeks.org/lambda-expression-in-c/
some good std functions to use lambda: std::sort, std::find_if, std::count

fancy output:
only printf fprintf sprintf
when output to terminal, could make use of terminal codes(ANSI/VT100), some useful code show here: http://wiki.bash-hackers.org/scripting/terminalcodes
\a terminal bell
\b backspace
\t horizontial tab
\n new line
\v vertical tab
\f new page
\r carriage return
\e[<X>;<Y>H home-position to X and Y coordinates
\e[0K  clear line from current cursor position to end of line
\e[1K  clear lien from beginning to current cursor
\e[2K  clear whole line
\e[<X>m text attributes and coloring

multithread, one to do calculation and one to indicate this process is still alive

### meet in the middle
it's the divide and conquer algorithm
sum of subset

## ch6 greedy algorithms

### coin problem
nice choice of euro coins,
for any sum x, the opitimal construction must contain largest coin that samller or equal to x
that's to say, for any coin C_i and C_{i+1}, 2*C_i <= C_{i+1}

### scheduling
in next possible events, choose the one ends as earliest as possible

### tasks and deadlines
finish shortest task

### minimizing sums
sum = \sum_{i=0}^N abs(a_i -x), x is the median
sum = \sum_{i=0}^N pow(a_i -x, 2), x is the mean

### data compression
huffman coding

coding: use huffman to code 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 in pi million bits
while, you never know it unless you code with it
recap: const_cast<>() static_cast<>() dynamic_cast<>() reinterpret_cast<>(), here: https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/
unbelieve it takes me 3 hours to finish this part, std::unordered_set<use-pointer> because of hash

this is like finish the rest of basic techniques

## ch07 Dynamic programming
TODO: to be continue, save for later,

## ch8 Amortized analysis
### two pointers method
- subarray sum
- two sum
- 3sum problem
here: https://en.wikipedia.org/wiki/3SUM
$\theta(n^2)$ method:
way1: for each i and j in array, find S-X[i]-X[j], using hash table so we can do search in $\thata(1) time$
so what using hash table means in c++ is to use std::unorderd_map<int, int> hash
way2: sort array, loop array with a; for each X[a], only need to find b and c in X[a+1 ~ n-1] such that X[b]+ X[c] = S - X[a]
- subset sum
here: https://en.wikipedia.org/wiki/Subset_sum_problem
there is a Pseudo-polynomial time dynamic programming solution in this wiki page

### mearst smaller elements
using stack to do work,
TODO: I need a application of this question ??
TODO: programming exercise

### sliding window minimum
using queue, this is increment queue

## Advanced topic
## ch21 number theory
### primes and factors
great, I wanna learn it
sum of factors: !!
TODO: how to improve that $p_i$ is prime number, then $\sum_i=1^n (p_i) + 1$ is also prime number. page.198
- basic algorithm
- sieve of eratosthenes
interesting series:
$ \sum_x=2^n (n/x) = n/2 + n/3 + ... + n/n = \bigoh(nlogn) $
this series: $ \sum_i=2^\infinte (1/i) $ is here: https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)

- Euclid's algorithm
    greatest common devisor(gcd)
    least common multiple(lcm)
    for i \in [2, n], p_i is prime numbers needed
    a = p_1^{\alpha_1} * p_2^{\alpha_2} * ... * p_n^{\alpha_n}
    b = p_1^{\beta_1} * p_2^{\beta_2} * ... * p_n^{\beta_n}
    gcd(a, b) = p_1^{min(\alpha_1, \beta_1)} * p_2^{min(\alpha_2, \beta_2)} * ... * p_n^{min(\alpha_n, \beta_n)}
    lcm(a, b) = p_1^{max(\alpha_1, \beta_1)} * p_2^{max(\alpha_2, \beta_2)} * ... * p_n^{max(\alpha_n, \beta_n)}

    crazy:
    prove of Euclid's algorithm ?: recall that c|a in number theory means c is a factor of a. here: https://courses.cs.washington.edu/courses/cse311/14au/slides/lecture13.pdf
    ```cpp
        int gcd(int a, int b){
            if(b==0) return a;
            return gcd(b, a%b);
        }
    ```
    what does it do with Fibonacci numbers ?: easy to solve

    somethind about mod
    n%m = ((double) (n/m) - (long)(n/m)) * m

- Euler's totient function

### modular arithmetic
- modular exponentiation, page.202
smart
```cpp
    int modpow(int x, int n, int m){
        if(n==0) return 1%m;
        int u = modpow(x, n/2, m);
        u = (u*u) % m;
        if(n/2 == 1) u=(u*x) % m;
        return u;
    }
```

- Fermat's theorem and Euler's theorem
TODO: how and for what??

- modular inverse
great, useful in cryptosystem

## solving equations
### Diophantine equations

### chinese remainder theorem
TODO: don't understand ??

## ch22 combinatorics
all right, let's keeping going
### binomial coefficients
!!counting the number of ways to represent an integer n as a sum of positive integer, page.207
!!OMG: sum of binomial coefficients is n^2, and why pascal's triangle is important. (a+b)^n
- boxes and balls
!!OMG, scenario 2 and 3 are smart
- multinomial coefficients

### catalan numbers
- parenthesis expressions
TODO: formula1: don't understand why ??
!!formula2: 66
- counting trees
kepa

### inclusion-exclusion
- inclusion-exclusion

- derangements
understand the formula is just the first step to solve this kind of question
TODO: don't real understand f(n-1)??

### Burnside's lemma
TODO: low power to understand

### cayley's formula
TODO: low power

## ch27 square root algorithm

## ch28 segment trees revisited

## ch29 geometry
very happy to algorithm assignment lead me to here, hack it
!!Heron's formula: area of triangle:$s(s-a)(s-b)(s-c)^(1/2)$ where a, b, c is side of triangle, s=(a+b+c)/2
!!page.266, the magic area formalu, TODO: but how it come??
### complex numbers
std::complex<double>
std::abs()
std::arg()
std::polar(length, angle)
std::conj(vector) // conjugate

### points and lines
- point location
- line segment intersection
- point distance from a line
I would like to review vector, here: https://en.wikipedia.org/wiki/Euclidean_vector
dot product: $a \dot b = a_1 \times b_1 + a_2 \times b_2 + a_3 \times b_3 $
cross product: $ ... $
- point inside a polygon

### polygon area
!! page.271, the formula: 66
- pick's theroem

### distance functions
- rotating coordinates

## ch30 sweep line algorithms
WTF, the closest pair problem is in here
continue
### intersection points
### closest pair problem
### convex hull problem

TODO: to be continue, finish chapters that you like, heading to assignment


# others
when convert markdown to latex,
add \begin{align*} \end{align*}
add \\
add \text{} or \inserttext{}
* => \times
min => \min
max => \max

using python as my computer
python math is just use math in C library
say \pi has random bits, 0,1,2,3,4,5,6,7,8,9 has the same possible to appear
this is true:
```
    ➜  ch05completeSearch git:(master) ✗ ./test3 pi.txt
    3.14159265358979311600
    count[0]: 10258
    count[1]: 10363
    count[2]: 10170
    count[3]: 10248
    count[4]: 10210
    count[5]: 10279
    count[6]: 10268
    count[7]: 10287
    count[8]: 10195
    count[9]: 10119
```
