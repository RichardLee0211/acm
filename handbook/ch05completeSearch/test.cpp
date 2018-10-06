#include<iostream>
#include<vector>
#include<algorithm> // is_permutation
#include<set>
#include<unordered_set>
#include<ctime>

namespace wenchen{
    void swap(int *A, int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    int next_permutation_helper(int *A, int l, int r){
        std::unordered_set<int> biggerthanl;
        for(int i{l+1}; i<=r; ++i){
            if(A[i] > A[l])
                biggerthanl.insert(i);
        }

        if(biggerthanl.size() == 0)
            return next_permutation_helper(A, l-1, r);

        int min{INT_MAX};
        int theOne{INT_MAX};
        for(auto i: biggerthanl){
            if(A[i]<min){
                theOne = i;
                min = A[i];
            }
        }
        swap(A, l, theOne);
        std::sort(&A[l+1], &A[r+1]);
        return 0;
    }
    int next_permutation(int *A, int l, int r){
        if(r-l < 1) return -1;
        bool max_permutation{true};
        for(int i{l}; i<r; ++i){
            if(A[i]<A[i+1])
                max_permutation = false;
        }
        if(max_permutation) return -1;

        next_permutation_helper(A, r-1, r);
        return 0;
    }
}

    /*
     * very useful for recurrence function to use one data and update it
    static int count{0};
    if(n<0) {
        count = 0; // or free resource
        return 0;
    }
    std::cout<<count++;
    return search_queens(n-1);
    */
int search_queens(int n){
    // static bool isTopLevel{true};
    static bool *col {NULL};
    static bool *diag1{NULL};
    static bool *diag2{NULL};
    static long i{0}, count{0}; // current row in recurrence tree

    if(n<1) return -1;
    if(i>n-1) return -1;


    if(i==0){
        col = (bool*) malloc(n*sizeof(bool)); // 1 means it's ocupied
        diag1 = (bool*) malloc((2*n-1)*sizeof(bool)); // 1 means it's ocupied
        diag2 = (bool*) malloc((2*n-1)*sizeof(bool)); // 1 means it's ocupied
        memset(col, 0, n*sizeof(bool));
        memset(diag1, 0, n*sizeof(bool));
        memset(diag2, 0, n*sizeof(bool));
        count = 0;
    }

    for(int j{0}; j<n; ++j){
        if(col[j]==0 && diag1[j+i]==0 && diag2[n-1+i-j]==0){
            col[j] = diag1[i+j] = diag2[n-1+i-j] = 1;
            if(i == n-1){
                count++;
            }
            i++;
            search_queens(n);
            i--;
            col[j] = diag1[i+j] = diag2[n-1+i-j] = 0;
        }
    }
    if(i==0){
        free(col);
        free(diag1);
        free(diag2);
        return count;
    }
    return -1;
}

/*
 * next_permutation(permutation.begin(), permutation.end())
 *
 **/
int permutation(int n){
    std::vector<int> permutation;
    for(int i{0}; i<n; ++i){
        permutation.push_back(i);
    }
    do{
        int sum{0};
        for(int i{0}; i<n; i++){
            sum += 5*(n-i)*permutation[i];
            std::cout<<permutation[i];
        }
        printf(" sum=%d\n", sum);
    }while(std::next_permutation(permutation.begin(), permutation.end()));
    return 0;
}
/*
 * this is anti-human recurrence to find permutations
 **/
int search_permutation(int *A, int n, std::vector<int> &permutation, bool *choosen){
    if((int)permutation.size() == n){
        for(auto &i: permutation)
            std::cout<<i;
        printf("\n");
        return 0;
    }

    for(int i{0}; i<n; ++i){
        if(choosen[i] == true) continue;
        choosen[i] = true;
        permutation.push_back(A[i]);
        search_permutation(A, n, permutation, choosen);
        choosen[i] = false;
        permutation.pop_back();
    }

    return 0;
}

/*
 * make use of bits
 **/
int getSubset(int *A, int n, std::vector<int> &subset){
    for(int b{0}; b<(1<<n); ++b){
        for(int i{0}; i<n; ++i){
            if((1<<i) & b) subset.push_back(A[i]);
        }
        for(auto i: subset)
            std::cout<<i;
        printf("\n");
        subset.clear();
    }
    return 0;
}
/*
 * recurence, such a stupid way to find all subsets
 * A, array of elements
 * i, the A[i] to search
 * n, the total number of A
 **/
int search(int *A, std::vector<int> &subset, int i, int n){
    if(i == n){
        for(auto i: subset)
            std::cout<<i;
        printf("\n");
    }
    else{
        search(A, subset, i+1, n);
        subset.push_back(A[i]);
        search(A, subset, i+1, n);
        subset.pop_back();
    }
    return 0;
}

int main(){
    int A[]{1,2,3,4,5};
    std::vector<int> subset;
    int n = sizeof(A)/sizeof(A[0]);
    bool choosen[n];
    for(int i{0}; i<n; ++i){
        choosen[i] = false;
    }

    /*
    search(A, subset, 0, n);
    std::cout<<"\n";
    getSubset(A, n, subset);
    */

    // search_permutation(A, n, subset, choosen);
    // permutation(n);

    /* good, test pass
    while(wenchen::next_permutation(A, 0, n-1) == 0){
        for(int i{0}; i<n; ++i){
            std::cout<<A[i];
        }
        printf("\n");
    }
    */

    /*
    int B[]{3,4, 5, 2, 9};
    // std::sort(B, &B[4]);
    // std::sort(B, &B[4], std::less<int>());
    std::sort(B, &B[5], std::greater<int>()); // !! std::sort(data.begin(), data.end());
    for(int i{0}; i<5; ++i){
        std::cout<<B[i];
    }
    */


    std::cout<<search_queens(8)<<"\n"; // 2
    std::cout<<search_queens(4)<<"\n"; // 92
    time_t time1, time2;
    time(&time1);
    std::cout<<search_queens(15)<<"\n";
    time(&time2);
    std::cout<<"time consumed: "<<std::difftime(time2, time1);
}
