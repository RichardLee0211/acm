// n-grid problem
#include<iostream>
#include<cstdlib>
#include<unistd.h> // for sleep
#include<pthread.h> // for thread

#define N 7
int index(int i, int j){
    if(i<0 || i> N-1 || j<0 || j>N-1) return -1;
    return i*N+j;
}

int up(int i, int j){
    if(i<=0 || i>N-1 || j<0 || j>N-1) return -1;
    return i*N+j-N;
}
int down(int i, int j){
    if(i<0 || i>=N-1 || j<0 || j>N-1) return -1;
    return i*N+j+N;
}
int left(int i, int j){
    if(i<0 || i>N-1 || j<=0 || j>N-1) return -1;
    return i*N+j-1;
}
int right(int i, int j){
    if(i<0 || i>N-1 || j<0 || j>=N-1) return -1;
    return i*N+j+1;
}
void update(int& i, int& j, const int& direc){
    if(direc==0)  i--;
    if(direc==1)  i++;
    if(direc==2)  j--;
    if(direc==3)  j++;
}
void de_update(int& i, int& j, const int& direc){
    if(direc==0)  i++;
    if(direc==1)  i--;
    if(direc==2)  j++;
    if(direc==3)  j--;
}

// int solution1(int n){

int solution1(int i=0, int j=0){
    static int *grid{NULL};
    static int (*const func[4])(int, int) {up, down, left, right};
    static int stepNum{0}, count{0};
    if(i==0 && j==0){
        grid = (int *) malloc(N*N*sizeof(int));
        memset(grid, 0, N*N*sizeof(int));
        grid[index(0, 0)] = 1; // i*n+j
        stepNum = 0;
        count = 0;
    }

    if(stepNum >= N*N-1){
        if(i == N-1 && j== N-1){
            count++; return 0;
        }
        return -1;
    }
    // while()
    for(int direc{0}; direc<4; ++direc){
        if(func[direc](i, j) != -1 && grid[func[direc](i, j)] == 0){
            grid[func[direc](i, j)] = 1;
            stepNum++;
            update(i, j, direc);
            solution1(i, j);
            de_update(i, j, direc);
            stepNum--;
            grid[func[direc](i, j)] = 0;
        }
    }

    if(i==0 && j==0){
        free(grid);
        return count;
    }
    return 0;
}
void *thread_1(void*){
    std::cout<<solution1();
    // *(unsigned long *)i = ULONG_MAX-1;
    return NULL;
}

int main(){
    /*
     * make use of multi_thread
    */
    // unsigned long *i = (unsigned long *)malloc(sizeof(unsigned long));
    // memset(i, 0, sizeof(unsigned long));
    unsigned long i{0};

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_1, NULL);
    while(i++ < ULONG_MAX){
        sleep(1);
        if(i%60 == 0) printf("\n");
        printf("#"); fflush(stdout);
    }
    pthread_join(thread_id, NULL);

    // may be broken at N=7
    // std::cout<< solution1();

}
