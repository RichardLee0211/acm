// \pi has the random bits??
#include<ostream>
#include<cmath>

int main(int argc, char* arg[]){
    if(argc != 2) {
        printf("uaage: ./test3 pi_file\n");
        return -1;
    }

    // long double i = M_PI;
    printf("%.20lf", M_PI);
    FILE* pi = fopen(arg[1], "r");
    int d;
    long long count[10]{0};
    while(fscanf(pi, "%1d", &d) != EOF){
        switch(d){
            case 0: count[0]++; break;
            case 1: count[1]++; break;
            case 2: count[2]++; break;
            case 3: count[3]++; break;
            case 4: count[4]++; break;
            case 5: count[5]++; break;
            case 6: count[6]++; break;
            case 7: count[7]++; break;
            case 8: count[8]++; break;
            case 9: count[9]++; break;
        }
    }

    for(int i{0}; i<10; ++i){
        printf("count[%d]: %lld\n", i, count[i]);
    }
}
