#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

/* brute force */
/*
int threeSumMulti_1(vector<int>& A, int target) {
    int count{0};
    for(int i{0}; i<(int)A.size(); ++i){
        for(int j{i+1}; j<(int)A.size();++j){
            for(int k{j+1}; k<(int)A.size(); ++k){
                if(A[i]+A[j]+A[k]==target){
                    count++;
                    count %= (long)pow(10,9)+7;
                }

            }
        }
    }
    return count;
}
*/

static long long my_count{0};
int recur(vector<int>& A, int l, int r, int target){
    if(r<=l)  return 0;
    if(A[l]+A[r] == target){
        if(A[l]==A[r]){ // handle repeat value A[l]==A[r]
            int factor = r-l+1;
            my_count += factor*(factor-1)/2;
            return 0;
        }

        int l_factor{1}, r_factor{1}; // to handle repeat value
        while(A[l]==A[l+1] ){
            l++; l_factor++;
        }
        while(A[r]==A[r-1] ){
            r--; r_factor++;
        }
        my_count += l_factor*r_factor;
        // std::cout<<A[l] <<" "<<A[r]<<"\n";
        return recur(A, l+1, r-1, target);
    }
    else if(A[l]+A[r] > target){
        return recur(A, l, r-1, target);
    }
    // else if(A[l]+A[r] < target){
        return recur(A, l+1, r, target);
    // }
}

int twoSum(vector<int>&A, int target, int k){
    int l{k+1}, r{(int)A.size()-1};
    recur(A, l, r, target);
}

int threeSumMulti(vector<int>& A, int target) {
    std::sort(A.begin(), A.end());
    for(int k{0}; k<(int)A.size()-2; ++k){
        if(target-A[k]<0) break;
        twoSum(A, target-A[k], k);
    }
    long long temp = my_count;
    my_count = 0;
    return temp % (long long)(pow(10, 9)+7);
}

int main(){
    vector<int> A{1,1,2,2,3,3,4,4,5,5};
    int target{8};
    std::cout<<threeSumMulti(A, target)<<"\n"; // 20
    vector<int> A_1{1,1,2,2,2,2};
    target=5;
    std::cout<<threeSumMulti(A_1, target)<<"\n"; // 12
}
