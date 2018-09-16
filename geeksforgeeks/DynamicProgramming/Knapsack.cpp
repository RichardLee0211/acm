#include<iostream>
#include<vector>

#define DEBUG 1

typedef unsigned int uint;
#if 0
typedef struct Item_t{
    uint size;
    uint value;
} Item;
#endif

int knapsack(int CAPACITY, const std::vector<int> &weights, const std::vector<int> &values){
    uint M[CAPACITY+1];

    M[0] = 0;
    for(int i=1; i<CAPACITY+1; ++i){
        uint max = M[i-1];
        for(uint j{0}; j<weights.size(); ++j){
            if((int)(i-weights[j])>=0 && M[i-weights[j]]+values[j] > max)
                max = M[i-weights[j]]+values[j];
        }
        M[i] = max;
    }
#if DEBUG
    for(auto i :M)
        printf("%u\t", i);
    printf("\n");
#endif

    return 0;
}

int main(){
    // build input program
    int T; // number of test cases
    scanf("%d", &T);
    while(T--){
        // TODO: skip the first line of data, which usually is explanation
        // std::string str;
        // std::cin.getline();
        //
        scanf("%*[^\n]\n", NULL);
        int N; scanf("%d", &N); // length of array
        int CAPACITY; scanf("%d", &CAPACITY);
        std::vector<int> weights(N, 0);
        std::vector<int> values(N, 0);
        for(int i{0}; i<N; ++i){
            scanf("%d", &values[i]);
        }
        for(int i{0}; i<N; ++i){
            scanf("%d", &weights[i]);
        }
        int maxValue = knapsack(CAPACITY, weights, values);
        printf("%d\n", maxValue);
    }
}
