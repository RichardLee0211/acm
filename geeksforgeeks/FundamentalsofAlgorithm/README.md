this is from here: https://www.geeksforgeeks.org/fundamentals-of-algorithms/#PatternSearching

## pattern research
### Naive Algorithm for Pattern Searching

### KMP algorithm for pattern searching
LPS, Longest prefix which is also proper suffix
base on the pattern could have some repeats, like pat[0~5] and pat[7~12] is the same. txt[i-1] txt[12]match, txt[i] and pat[13] don't match, then check out txt[i] and pat[6]
not easy to explain in plaintxt
666, TODO: code it

### Rabin-Karp Algorithm
easy to understand, if hash value equals, then check the internal structure
formula:
hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
hash( txt[s .. s+m-1] ) : Hash value at shift s.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet
q: A prime number
h: d^(m-1)

### Finite Automata algorithm for Pattern Searching
smart, make use of state machine
The idea is to get length of the longest prefix of the given pattern such that the prefix is also suffix of “pat[0..k-1]x”.

### boyer moore algorithm for pattern searching
bad character heuristic
and Good Suffix heuristic

TODO: latter
Ukkonen's suffix tree:
suffix array

###
