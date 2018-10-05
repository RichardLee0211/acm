// Gbus count, how many bus serve the city
#include<iostream>
#include<cstdlib>
#include<set>

#define DEBUG 1

using namespace std;

// creating a new class is not a good choice when doing a compititive programming
class Stop{
    public:
    long distance;
    int isStart;
    int isEnd;
    int isCity; // 1 means it's also interested cities

    Stop(long dis, int isStart= 0, int isEnd= 0, int isCity = 0){
        this->distance = dis;
        this->isStart = isStart;
        this->isEnd = isEnd;
        this->isCity = isCity;
    }
};

struct StopCmp {
    bool operator()(const Stop& lhs, const Stop& rhs) const {
        return lhs.distance<rhs.distance;
        /*
        if(lhs.distance < rhs.distance ) return true;
        else if(lhs.distance > rhs.distance ) return false;
        else{
            if(lhs.isStart==1)
                return true;
            else
                return false;
        }
        */
    }
};

// a broken solution with set
int solution_1(long *A, long* B, long N, long* C, long *D, long P){
    long count{0};
    std::set<Stop, StopCmp> stops;
    for(long i{0}; i<N; ++i){
        std::set<Stop, StopCmp>::iterator temp = stops.begin();
        if((temp = stops.find(Stop(A[i]))) != stops.end()){
            // const_cast<std::set<Stop, StopCmp>::iterator> (temp->isStart) = 1; // set only have const iterator
            // here, although change isStart doesn't matter for the binary tree, it's not allowd for the set
        }
        else
            stops.insert(Stop(A[i], 1));
        stops.insert(Stop(B[i], 0));
    }

    for(auto i: stops){
#if 0
        // good, do is increase sequence
        printf("%ld ", i.distance);
#endif
        if(i.isStart == 1){
            count++;
        }
        // city records
        for(int j{0}; j<P; ++j){
            if(C[j] == i.distance && D[j]<=count)
                D[j] = count;
        }
        if(i.isStart == 0){
            count--;
        }
    }

    return 0;
}

// most obvious solution, take N*P time
int solution_2(long *A, long *B, long N, long* C, long *D, long P){
    for(long i{0}; i<P; ++i){
        long count{0};
        for(long j{0}; j<N; ++j){
            if(A[j]<=C[i] && C[i] <= B[j])
                count++;
        }
        D[i] = count;
    }
    return 0;
}

// solution_3
// since it's all in array, use quick partition for each C[i] in A[i], B[i]
// there is i start stops ahead and j end stop ahead, I start stops and J end stop in the city
// then D[i] is i-j+I

int main(){
    int T{0};
    scanf("%d\n", &T);
    for(long k{0}; k<T; ++k){
        long N{0};
        scanf("%ld", &N);

        long *A = (long*) malloc(N*sizeof(long)); // A[i] is the begining of i Gbus
        long *B = (long*) malloc(N*sizeof(long)); // B[i] is the ending of i Gbus
        for(long i{0}; i<N; ++i){
            scanf("%ld", &A[i]);
            scanf("%ld", &B[i]);
        }

        long P{0};
        scanf("%ld", &P);
        long *C = (long*) malloc(P*sizeof(long)); // C[i] is the i city
        long *D = (long*) malloc(P*sizeof(long)); // D[i] is the result
        memset(D, 0, P*sizeof(long));
        for(long i{0}; i<P; ++i){
            scanf("%ld", &C[i]);
        }

        solution_2(A, B, N, C, D, P);

        printf("Case #%ld: ", k+1);
        for(long j{0}; j<P; ++j){
            printf(" %ld", D[j]);
        }
        printf("\n");



    }
}
