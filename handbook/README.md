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

### wenchen: review of containers of C++
from http://www.cplusplus.com/reference/queue/priority_queue/
TODO: go through it

#### array
std::array<T>
defines the fixed-size array container class
what's the advantage then ?: maybe could cooperate with algorithm header better

####  vector
std::vector<>
the one I use most
the various length array

#### deque
std::deque<T>
double ended queue

#### queue
- std::priority_queue
```c++
    namespace std{
        template <class T, class Container=vector<T>, class compare>
        class priority_queue;
    }
```
internal: max_heap
could only access the top
top of queue is the "back", is max element

- std::queue<T, Container>
FIFO queue

#### std::forward_list<>
internal: forward linked list
#### std::list<>
internal: double linked list

#### map
std::map<Key, T, Compare>
sorted
#### std::unordered_map<>

#### std::set<>
sorted
#### std::unordered_set<>
hash function

#### std::stack<>


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
TODO: read latter: https://thispointer.com/how-to-use-unordered_set-with-user-defined-classes-tutorial-example/
TODO: read latter: std::heap

this is like finish the rest of basic techniques

## ch07 Dynamic programming
### coin problem
### longest incresing subsequence
n^2 is easy to understand
!!: nlogn here: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
TODO: code this
this is like, every update make subsequence lower
    1. If A[i] is smallest among all end
    candidates of active lists, we will start
    new active list of length 1.
    2. If A[i] is largest among all end candidates of
    active lists, we will clone the largest active
    list, and extend it by A[i].
    3. If A[i] is in between, we will find a list with
    largest end element that is smaller than A[i].
    Clone and extend this list by A[i]. We will discard all
    other lists of same length as that of this modified list.


### path in grid
TODO: coding it, easy

### knapsack problem
TODO: coding it, easy
if there is a n elements, a_0~a_n, and the Sum could be S
by the recurrence formula, need to calculate n*S result

### edit distance
666

### counting tilings
TODO: need problems


## ch8 Amortized analysis
### two pointers method
- subarray sum
- two sum
- 3sum problem
here: https://en.wikipedia.org/wiki/3SUM
$\theta(n^2)$ method:
way1: for each i and j in array, find S-X[i]-X[j], using hash table so we can do search in $\theta(1) time$
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

## ch09 range queries
### static array queries
- sum queries
- minimum queries

### binary index tree
TODO: come back with application
this is a tree that I never see

### segment tree
TODO: come back with application

### addtional techniques

## ch10 Bit manipulation
### bit represent
the magic of design signed integer,
Two’s complement is used, which means that the opposite number of a number is calculated by first inverting all the bits in the number, and then increasing the number by one.
the signed number -x equals the unsigned number 2^n-x
seems that I never use (nor)~x in coding
~x = -x-1

### bit operation
x | (1<<k) set kth bit to 1
x & ~(1<<k) set kth bit to 0
x ^ (1<<k) invert kth bit

```cpp
    int x = 5328; // 00000000000000000001010011010000
    std::cout << __builtin_clz(x) << "\n"; // 19, the number of zeros in the begining of number
    std::cout << __builtin_ctz(x) << "\n"; // 4, the number of zeros in the end of number
    std::cout << __builtin_popcount(x) << "\n"; // 5, the number of ones
    std::cout << __builtin_parity(x) << "\n"; // 1, the parity (even or odd) of the number of ones
```

### representing sets
```c++
    for(int b{0}; b< (1<<n); b++){
        if(__builtin_popcount(b) == k){
            // process subset with exactly k elements
        }
    }

    int b=0;
    do{
        // process subsets of x
    }while(b=(b-x)&x);
    // 66, think of  it as -(x-b) & x, and -x = ~x+1
```

## bit optimizations
### hamming distances
it has significate disadvantage, k<32 and each character only have 2 values
better to use divide and conquer

### counting subgrids
66, it's cool because don't need to process them one element by one element, could do them 32 by 32 or 64 by 64
make 32 seconds to 1 seconds

## Dynamic programming
### optimal selection

### from permutations to subsets
6666
but limited to 64 bits, unless use std::bitset, like array of bool
subsets problem is 2^n
permutation problem is n!
they are bad for computer
TODO: code this using std::bitset

### counting subsets
wanna find subsets of S{0b1101 1100}
```cpp
    for(int p{0}; p<(1<<N); p++){
        if(p&S !=0 && p&~S ==0){
            // p is a subset of S
        }
    }
```
TODO: come back for subsets problem

# part 2 graph algorithm
## ch11 basic of graphs
### graph presentation
- adjacency list representation
- adjacency matrix representation
- edge list representation

## ch12 graph traversal
### DFS
### BFS
### application
- connectivity check
TODO: code it
- Find cycles
whether there is a cycle, how many circles ?: intro edge labeling in algorithm class, back edges
- bipartiteness check

ch13 shortest paths
--------------------------------------------------------------------------------

### bellman-Ford algorithm
question: find the shortest path from one the all others
assumption: graph doesn't contain a cycle with negetive length
The algorithm reduces the distances by finding edges that shorten the paths until it is not possible to reduce any distance.
O(mn)
in the implement, make use of tuple
```cpp
    for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[x] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
```
!! crazy, man, the preview application on MacOS support speaking PDF
- negative circle
- SPFA algorithm
don't exam every edge each time.
maintain a queue of nodes:
```pseudoCode
    for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[x] = 0;
    initially put starting node a into queue
    while(!queue.empty())
        loop edges attached to queue.head
            if edges[head][b].weight + distance[head]<distance[b]
                distance[b]=distance[head]+edges[head][b].weight
                queue.push_back(b)
        queue.pop()
```

### Dijkstra's algorithm
solve single-source-shortest-path problem
assume: no negetive path in graph
O(n+mlogm)
each time, select smallest distanced and unfinished note to update others
```cpp
    for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
```
TODO: review std::initializer_list: https://en.cppreference.com/w/cpp/language/list_initialization
TODO: code it

### Floyd-Warshall algorithm
solve shortest paths between all pair of nodes
assume: directed path
using two-dimensional array and reduces distance by using intermediate nodes in paths
```cpp
    // initial
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) distance[i][j] = 0;
            else if (adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = INF;
        }
    }
    // using each nodes as intermediate nodes
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j],
                        distance[i][k]+distance[k][j]);
            }
        }
    }
```

ch14 tree algorithm
--------------------------------------------------------------------------------
A tree is a connected, acyclic graph that consists of n nodes and n − 1 edges.
TODO: finish the graph part
### tree traversal
### Diameter
### All longest paths
### binary tree

ch15 spanning tree
--------------------------------------------------------------------------------
### kruskal's algorithm
description1: the initial spanning tree only contains the nodes of the graph and does not contain any edges. Then the algorithm goes through the edges ordered by their weights, and always adds an edge to the tree if it does not create a cycle.
description2: A MST can be grown from a forest of spanning trees by adding the smallest edge connecting two spanning trees.

### Union-find structure
In a union-find structure, one element in each set is the representative of the set, and there is a chain from any other element of the set to the representative.

### prim's algorithm

ch16 directed graphs
--------------------------------------------------------------------------------
### topological sorting
### Dynamic programming
### successor paths
### cycle detection

ch17 strong connectivity
--------------------------------------------------------------------------------
### korsaraju's algorithm
### 2SAT problem

ch18 tree queries
--------------------------------------------------------------------------------
### Finding ancestors
### subtrees and paths
### Lowest common ancestor
### offline algorithm


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

latex is great for building pdf file, but not for reading, hard to read the math so far

I may build up my input format, line by line, comment start with #, data to separate with space

#### about use std::set<Myclass> or std::priority_queue<Myclass>
[reference](http://www.cplusplus.com/reference/set/set/set/)
!! first, remember to include set or queue, or you get errors that confuse you
- way0, using operate< by default
- way1, create comp function and using function pointer to initial set
- way2, create comp struct and operator() in it.
    I don't like this idea, create a struct only for compare? but it has a clear code
```cpp
    struct Edge{
        uint start;
        uint end;
        int weight;
    };
    /* using operator< by default */
    bool operator<(const Edge& lhs, const Edge& rhs){
        return lhs.weight < rhs.weight;
    }
    std::set<Edge> set0;
    /* using edge_comp function for custom */
    bool edge_comp(const Edge& lhs, const Edge& rhs){
        return lhs.weight < rhs.weight;
    }
    std::set<Edge, bool (*)(const Edge&, const Edge&)> set1(edge_comp);
    /* using struct Edge_comp for custom, and it's clear code */
    struct Edge_comp{
        bool operator()(const Edge* lhs, const Edge* rhs){
            return lhs.weight < rhs.weight;
        }
    };
    std::set<Edge, Edge_comp> set2;
```
more:
- using friend operator<(const Edge& lhs, const Edge& rhs); in struct Edge to let operator< access private data
- std::priority_queue<Edge> pq;
- std::sort(data.begin(), data.end(), cmp); // cmp is a custom fn_pt

TODO: what's the meaning of std::priority_queue when we already have std::set??
TODO:
in process-oriented programming, I could use a bunch of global data, and allocate, initial, update and free them
but in objective-oriented programming, how do I organize data??

they are not so clearly separeted
- template
- classes defination(data defination, method)
- function
- data
- drive main function

where to put data:
- in template, for use of template method
- in class, for use of class methods
- in function, for use of one function
- in global, could be accessed by funcitons, methods, and main dirve

in object-oriented programming, we have file_parser class.
after parser method, we need to store data somewhere that could be accessed by process functions or process classes
these data are used to initial process classes and go through process
until they reach the final status or generate output data

input_file -> parser => data1 => process1 => data2 => process2 => output_data

some order of execution is influence the result(dependence), other's could be paraller
some behavior is trigger under some condition, this is why condition branch is so important

exe_name <flags> input_file output_file
input_file, input data or config file
flags(what client wanna do at the beginning of program)
stdout is used for client(tell client what's status of process right now)
stdin is used for manipulate(what's client wanna do dynamically, not every is judged by program)
output_file is used for result
stderr is used for errors(tell client what's wrong with process, say it cann't open files)
log_file is used for logs

e.g. PS program:
double click to open,
flags are default ones,
stdout is origin image,
stdin is manipulation,
stderr is the pop-up windows,
output_file is modified files, which often overwrite the original one
log_file is often ignored by artist

it makes the input -> process -> output more realistic
multiple_inputs -> process -> multiple_outputs
and in the process, we have stdout and stdin for UI porpuse

about getline
- in C++, [here](http://www.cplusplus.com/reference/string/string/getline/)
istream& getline(istream& is, string& str, char delim)
get to use std::cin and std::string
- in C, [here](https://en.cppreference.com/w/c/experimental/dynamic/getline)
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
I am worried it's not stdandard c, it's in GNU C
- used fgets, [here](https://en.cppreference.com/w/c/io/fgets)
char *fgets(char *str, int count, FILE *stream );

it seems that I known a lot of things after I have used them for a long time
int main(int argc, char* argv[])
argument count and argument value


    // Edge testedge{1, 2, 3}; // call constrocture
    // std::vector<Edge> vecEdges{{1,2,4}, {3, 4,5}}; // it's cool that you can do it
