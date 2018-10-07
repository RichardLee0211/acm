// solve the coin problem
// use as few coins as possible to form a sum S
#include<iostream>
#include<set>

static const std::set<int > coins{1,2,5,10, 50, 100, 200};

int min(int i, int j){
    return (i<j) ? i : j;
}
int solve(int sum){
    if(sum <= 0 ) return 0;
    int best{INT_MAX};
    for(auto i: coins){
        best = min(solve(sum-i)+1, best);
    }
    return best;
}

int main(){
    std::cout<<solve(100)<<"\n";
    std::cout<<solve(14)<<"\n";
    std::cout<<solve(16)<<"\n";
}
