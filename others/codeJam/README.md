from
https://code.google.com/codejam/contest/3264486/dashboard

input:
3
---+-++- 3
+++++ 4
-+-+- 4

output:
Case #1: 3
Case #2: 0
Case #3: IMPOSSIBLE

this is from the Bits operation question, and using ^ operator between number
and mask

take input as 00010110
length is 8, mask length is 3
then masks 0x111<<OFFSET have (8-3+1)=6 possibility, OFFSET belengs to
{0,1,2,3,4,5}
and could apply
mask0, mask1, mask2, mask3...mask4
mask0+make1, mask0+mask2, mask0+mask3...
mask0+mask1+mask3, ...
...
the possibility space is C(6, 1)+C(6,2)+C(6,3)+C(6,4)+C(6,5)+C(6,6)

apply(XOR) all these mask to 0x11111111, that's all the possibility for imposible
solutions

implement:
can't using long long, need a class wrapper on vector<bool>, and override ^
operator
what about C(1,6) in Math
std::next_permutation

### Dance Battle Strategy
At begining, your dance team get E energy and H(starting with 0) Honor. You are facing a team of dancers with skills, S{S1, S2, S3..Si}. You can use following strategies to battle them one by one.

1. you can battle Si, when E-Si>=0. Then Si is remove from S, and H increase by one.

2. you can make excuse to delay the battle. Then Si is remove from head of S, and push back to end of S. Your E and H don't change.

3. you can refuse to battle Si. Then Si is remove from S, and your E and H don't change.

4. you can hire Si when H>0. Then Si is remove from S, and your E+= Si, and H decrease by one.

your goal is to gain max H when S is empty. Output the max H.
