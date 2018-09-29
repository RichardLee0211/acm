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

## ch8 Amortized analysis

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

# others
when convert markdown to latex,
add \begin{align*} \end{align*}
add \\
add \text{} or \inserttext{}
* => \times
min => \min
max => \max
