#include<iostream>
#include<math.h>

int main(){
#if 0
    int A[]{-1, -2, 1, 2, 3};
    char C[] {'c', 'h', 'a', 'r'};
    for(int i{0}; C[i]; i++){
        printf("%c\t", C[i]);
    }
    printf("%d", C[4]);
#endif
#if 0
    // get the mostSignificantBit
    double N{32345.64};
    double K = log10(N);
    K = K - (int)K;
    int mostSignificantBit = pow(10, K);
    printf("%d", mostSignificantBit);
#endif
    // printf("%d", 0b0011+0b0011);
    scanf("%*[^\n]\n", NULL);
    int a;
    scanf("%d", &a);
    printf("%d", a);
}
