#include<iostream>

typedef unsigned int uint;
typedef unsigned char uchar;

// #define INDEX(a, b)
/* don't know how many col a row have by this function
uint index(uint a, uint b){
    return 0;
}
*/

int solution(uint32_t **data, const uint row, const uint col_block){
    uint count{0};
    for(uint a{0}; a<row; ++a){
        for(uint b{a+1}; b<row; ++b){
            uint temp{0};
            for(uint j{0}; j<col_block; ++j){
                temp += __builtin_popcount(data[a][j]&data[b][j]);
            }
            count += temp*(temp-1)/2;
        }
    }

    return count;
}

int main(){
    uint row, col, col_block;
    // char *buffer = (char*) malloc(10000*sizeof(uchar));

    scanf("%*[^\n]\n", NULL);
    scanf("%d %d", &row, &col);
    col_block = col/32 +1;

    uint32_t **data  = (uint32_t**)malloc(row*sizeof(uint32_t*));
    for(uint i{0}; i<row; ++i){
        data[i] = (uint32_t*) malloc(col_block*sizeof(uint32_t));
        memset(data[i], 0, col_block*sizeof(uint32_t));
    }
    uint temp{0};
    for(uint i{0}; i<row; ++i){
        for(uint j{0}; j<col; ++j){
            scanf("%1d", &temp);
            data[i][j/32] = (data[i][j/32]<<1) + temp;
        }
    }
#if 1 // test of input
    for(uint i{0}; i<row; ++i){
        for(uint j{0}; j<col_block; ++j){
            printf("%08X ", data[i][j]);
        }
        printf("\n");
    }
#endif

    // sscanf(buffer, "%32u", &data[0]); // standard don't provide a binary notation
    /* input test
    printf("%s\n", buffer);
    while(col-- != 0)
        printf("%c ", buffer[col]);
    */

    printf("solution: %d\n", solution(data, row, col_block));
}
