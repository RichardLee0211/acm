// draft
//
#include<iostream>
#include<cmath>

/*
 * this is for calculate what's my computer could do in 2 min
 * for coins {1, 2, 5, 10}, if using stupid way, how much is needed to calc sum 40
 **/
#define N 40
long cal(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==2) return 3;
    return cal(n-1)+cal(n-2)+cal(n-5)+cal(n-10);

}
int main(){
    printf("%le", (double)cal(N));
}
