// solve the coin problem
// use as few coins as possible to form a sum S
#include<iostream>
#include<set>
#include<ctime>

#define N 101
static const std::set<int > coins{1,2,5,10};  // , 50, 100, 200};
static int* records = (int *)malloc(N*sizeof(int));

int min(int i, int j){
    return (i<j) ? i : j;
}
/* exponet time
 * need 1.59e9 recurise call
 * consume time 121 seconds on 2.2GHZ machine
 * then this block of code is around 120 circles to excute, if not count time of sub-call
 **/
int solve1(int sum){
    if(sum == 0 ) return 0;
    int best{INT_MAX};
    for(auto i: coins){
        if(sum-i >=0){
            best = min(solve1(sum-i)+1, best);
        }
    }
    return best;
}

int main(){

    memset(records, 0, N*sizeof(int));
    int n = 40;
    time_t time1, time2;
    time(&time1);
    std::cout<<solve1(n)<<"\n";
    time(&time2);
    std::cout<<"time consume: "<<difftime(time2, time1)<<"\n";
    for(int i{0}; i<n+1; ++i){
        std::cout<<i<<" "<<records[i] <<"\n";
    }
    /*
    std::cout<<solve(100)<<"\n";
    std::cout<<solve(14)<<"\n";
    std::cout<<solve(16)<<"\n";
    */
}
