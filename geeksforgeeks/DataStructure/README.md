first finish this
www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/

some reference come from http://en.cppreference.com/

Must Do Coding Questions for Companies like Amazon, Microsoft, Adobe, …
As the placement season is back so are we to help you ace the interview. We have
selected some most commonly asked and must do practice problems for you. We
recommend to practice these and ace the coding round with confidence. Happy
Coding.

Topic :
## Arrays
## String
## Linked List
    std::list
    std::forward_list
    std::list is a container that supports constant time insertion and removal
    of elements from anywhere in the container. Fast random access is not
    supported. It is usually implemented as a doubly-linked list. Compared to
    std::forward_list this container provides bidirectional iteration capability
    while being less space efficient.
## Stack and Queue:
    std::stack<> FILO, top(), push(), pop()
    template<class T, class Container=std::deque<T>> class queue, FIFO, front(),
    back(), push(), pop()
    std::deque (double-ended queue) is an indexed sequence container that allows
    fast insertion and deletion at both its beginning and its end. In addition,
    insertion and deletion at either end of a deque never invalidates pointers
    or references to the rest of the elements.
## Tree and BST
    stdlib of C++ doesn't offer tree or binary search tree
## Heap
    std::is_heap(), max heap
    std::pop_heap()
    std::make_heap()
    std::push_heap()
    std::sort_heap()
## vector
    at(), access specified element with bounds checking
    operator[], access specified element
    ...
    so useful
## map
## Recursion
## Hashing
    A Hash is a function object for which the output depends only on the input
    and has a very low probability of yielding the same output given different
    input values.
## Graph
## Greedy
## Dynamic Programming
    In computer science, mathematics, management science, economics and
    bioinformatics, dynamic programming (also known as dynamic optimization) is
    a method for solving a complex problem by breaking it down into a collection
    of simpler subproblems, solving each of those subproblems just once, and
    storing their solutions.
    [from https://en.wikipedia.org/wiki/Dynamic_programming]
## Divide and Conquer
## Backtracking
## Bit Magic

content
----------
## Arrays :
    - [ ] Kadane’s Algorithm
    - [ ] Missing number in array
    - [ ] Subarray with given sum
    - [ ] Sort an array of 0s, 1s and 2s
    - [ ] Equilibrium point
    - [ ] Maximum sum increasing subsequence
    - [ ] Leaders in an array
    - [ ] Minimum Platforms
    - [ ] Maximum of all subarrays of size k
    - [ ] Reverse array in groups
    - [ ] K’th smallest element
    - [ ] Trapping Rain Water
    - [ ] Pythagorean Triplet
    - [ ] Chocolate Distribution Problem
    - [ ] Stock buy and sell
    - [ ] Element with left side smaller and right side greater
    - [ ] Convert array into Zig-Zag fashion
    - [ ] Find the element that appears once in sorted array
    - [ ] Kth largest element in a stream
    - [ ] Relative Sorting
    - [ ] Spirally traversing a matrix
    - [ ] Sorting Elements of an Array by Frequency
    - [ ] Largest Number formed from an Array

## String :
    - [ ] Parenthesis Checker
    - [ ] Reverse words in a given string
    - [ ] Permutations of a given string
    - [ ] Longest Palindrome in a String
    - [ ] Recursively remove all adjacent duplicates
    - [ ] Check if string is rotated by two places
    - [ ] Roman Number to Integer
    - [ ] Anagram
    - [ ] Longest Common Substring
    - [ ] Remove Duplicates
    - [ ] Form a Palindrome
    - [ ] Longest Distinct Characters in the string
    - [ ] Implement Atoi
    - [ ] Implement strstr
    - [ ] Longest Common Prefix

## Linked List :
    - [ ] Finding middle element in a linked list
    - [ ] Reverse a linked list
    - [ ] Rotate a Linked List
    - [ ] Reverse a Linked List in groups of given size
    - [ ] Detect Loop in linked list
    - [ ] Remove loop in Linked List
    - [ ] n’th node from end of linked list
    - [ ] Flattening a Linked List
    - [ ] Merge two sorted linked lists
    - [ ] Intersection point of two Linked Lists
    - [ ] Pairwise swap of a linked list
    - [ ] Add two numbers represented by linked lists
    - [ ] Check if Linked List is Palindrome
    - [ ] Implement Queue using Linked List
    - [ ] Implement Stack using Linked List
    - [ ] Given a linked list of 0s, 1s and 2s, sort it
    - [ ] Delete without head pointer

## Stack and Queue :
    - [ ] Next larger element
    - [ ] Queue using two Stacks
    - [ ] Stack using two queues
    - [ ] Get minimum element from stack
    - [ ] LRU Cache
    - [ ] Circular tour
    - [ ] First non-repeating character in a stream
    - [ ] Rotten Oranges

## Tree :
    - [ ] Print Left View of Binary Tree
    - [ ] Check for BST
    - [ ] Print Bottom View of Binary Tree
    - [ ] Print a Binary Tree in Vertical Order
    - [ ] Level order traversal in spiral form
    - [ ] Connect Nodes at Same Level
    - [ ] Lowest Common Ancestor in a BST
    - [ ] Convert a given Binary Tree to Doubly Linked List
    - [ ] Write Code to Determine if Two Trees are Identical or Not
    - [ ] Given a binary tree, check whether it is a mirror of itself
    - [ ] Height of Binary Tree
    - [ ] Maximum Path Sum
    - [ ] Diameter of a Binary Tree
    - [ ] Number of leaf nodes
    - [ ] Check if given Binary Tree is Height Balanced or Not
    - [ ] Serialize and Deserialize a Binary Tree

## Heap :
    - [ ] Find median in a stream
    - [ ] Heap Sort
    - [ ] Operations on Binary Min Heap
    - [ ] Rearrange characters
    - [ ] Kth largest element in a stream
    - [ ] Merge K sorted linked lists

## Recursion :
    - [ ] Flood fill Algorithm
    - [ ] Number of paths
    - [ ] Combination Sum – Part 2
    - [ ] Special Keyboard
    - [ ] Water Overflow
    - [ ] Josephus problem

## Hashing :
    - [ ] Largest subarray with 0 sum
    - [ ] Swapping pairs make sum equal
    - [ ] Count distinct elements in every window
    - [ ] Array Pair Sum Divisibility Problem
    - [ ] Longest consecutive subsequence
    - [ ] Array Subset of another array
    - [ ] Find all pairs with a given sum
    - [ ] Find first repeated character
    - [ ] Zero Sum Subarrays
    - [ ] Minimum indexed character
    - [ ] Check if two arrays are equal or not
    - [ ] Uncommon characters
    - [ ] Smallest window in a string containing all the characters of another string
    - [ ] First element to occur k times
    - [ ] Check if frequencies can be equal

## Graph :
    - [ ] Depth First Traversal
    - [ ] Breadth First Traversal
    - [ ] Detect cycle in a directed graph
    - [ ] Topological sort
    - [ ] Find the number of islands
    - [ ] Implementing Dijkstra
    - [ ] Minimum Swaps
    - [ ] Strongly Connected Components
    - [ ] Shortest Source to Destination Path
    - [ ] Find whether path exist
    - [ ] Minimum Cost Path
    - [ ] Circle of Strings
    - [ ] Floyd Warshall
    - [ ] Alien Dictionary
    - [ ] Snake and Ladder Problem

## Greedy :
    - [ ] Activity Selection
    - [ ] N meetings in one room
    - [ ] Coin Piles
    - [ ] Minimum number of Coins
    - [ ] Maximize Toys
    - [ ] Page Faults in LRU
    - [ ] Largest number possible
    - [ ] Minimize the heights
    - [ ] Minimize the sum of product
    - [ ] Huffman Decoding
    - [ ] Max length chain
    - [ ] Minimum Spanning Tree
    - [ ] Minimum Operations
    - [ ] Shop in Candy Store
    - [ ] Geek collects the balls

# Dynamic Programming :
    - [ ] Longest Increasing Subsequence
    - [ ] Longest Common Subsequence
    - [ ] 0 – 1 Knapsack Problem
    - [ ] Minimum number of jumps
    - [ ] Edit Distance
    - [ ] Coin Change Problem
    - [ ] Subset Sum Problem
    - [ ] Box Stacking
    - [ ] Rod Cutting
    - [ ] Path in Matrix
    - [ ] Minimum sum partition
    - [ ] Count number of ways to cover a distance
    - [ ] Egg Dropping Puzzle
    - [ ] Optimal Strategy for a Game
    - [ ] Shortest Common Supersequence

## Divide and Conquer :
    - [ ] Binary Search
    - [ ] Quick Sort
    - [ ] Merge Sort
    - [ ] Find the element that appears once in sorted array
    - [ ] K-th element of two sorted Arrays
    - [ ] Last index of One

## Backtracking :
    - [ ] N-Queen Problem
    - [ ] Solve the Sudoku
    - [ ] Rat in a Maze Problem
    - [ ] Word Boggle
    - [ ] Generate IP Addresses

## Bit Magic :
    - [ ] Find first set bit
    - [ ] Rightmost different bit
    - [ ] Check whether K-th bit is set or not
    - [ ] Toggle bits given range
    - [ ] Set kth bit
    - [ ] Power of 2
    - [ ] Bit Difference
    - [ ] Rotate Bits
    - [ ] Swap all odd and even bits
    - [ ] Count total set bits
    - [ ] Longest Consecutive 1’s
    - [ ] Sparse Number
    - [ ] Alone in a couple
    - [ ] Maximum subset XOR

## others
T&& t= <temportary>; C++1y new feature, rvalue reference, move operator
https://www.artima.com/cppsource/rvalue.html

my doc style:
put design and mathmatics formula in README(.md or .tex)
code is only about code

## TODO:
#include<cmath> // useful: http://www.cplusplus.com/reference/cmath/
#include<algorithm>
// http://www.cplusplus.com/reference/algorithm/?kw=algorithm
- [x] find a good way to redict text file to cin ?: ./exec < inputFile.txt > outputFile.txt
- [ ]
- [ ]
