#include<iostream>

typedef unsigned int uint;
typedef unsigned char uchar;

int main(){
    scanf("%*[^\n]\n", NULL);
    uint row, col;
    uchar *buffer = (uchar*) malloc(10000);
    scanf("%d %d", &row, &col);
    scanf("%s\n", buffer);
    printf("%s", buffer);
}
