// https://leetcode.com/contest/weekly-contest-106/problems/sort-array-by-parity-ii/
#include<vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> index1, index2;
    for(int i{0}; i<(int)A.size(); ++i){
        if((i&1)==0 && (A[i]&1)==1) index1.push_back(i);
        if((i&1)==1 && (A[i]&1)==0) index2.push_back(i);
    }
    while(index1.size()!=0){
        int j=index1.back();
        int i=index2.back();
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        index1.pop_back();
        index2.pop_back();
    }
    return A;
}
