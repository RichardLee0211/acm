#include<iostream>
#include<utility>

/**
 * maybe using struct _index{int x; int y}index;
 */

int M = 3;
int** myArray;
int** myArrayNext;
typedef std::pair<int, int> position;

position up(position pos)
{
    int first = pos.first-1;
    int second = pos.second;
    if(first == -1)
        first = M-1;
    return position(first, second);
}

position down(position pos)
{
    int first = pos.first+1;
    int second = pos.second;
    if(first == M)
        first = 0;
    return position(first, second);
}

position left(position pos)
{
    int first = pos.first;
    int second = pos.second-1;
    if(second == -1)
        second = M-1;
    return position(first, second);
}

position right(position pos)
{
    int first = pos.first;
    int second = pos.second+1;
    if(second == M)
        second = 0;
    return position(first, second);
}

position rightup(position pos)
{
    int first = pos.first-1;
    int second = pos.second+1;
    if(first == -1) first = M-1;
    if(second == M) second = 0;
    return position(first, second);
}

position leftup(position pos)
{
    int first = pos.first-1;
    int second = pos.second-1;
    if(first == -1) first = M-1;
    if(second == -1) second = M-1;
    return position(first, second);
}

position rightdown(position pos)
{
    int first = pos.first+1;
    int second = pos.second+1;
    if(first == M) first = 0;
    if(second == M) second = 0;
    return position(first, second);
}

position leftdown(position pos)
{
    int first = pos.first+1;
    int second = pos.second-1;
    if(first == M) first = 0;
    if(second == -1) second = M-1;
    return position(first, second);
}

// TODO: can function pointer helps to reduce these repeat
int checkforNeighbors(position pos)
{
    int ret = 0;
    if(right(pos).first != -1 &&
            myArray[right(pos).first][right(pos).second] == 1){
        ret++;
    }
    if(left(pos).first != -1 &&
            myArray[left(pos).first][left(pos).second] == 1){
        ret++;
    }
    if(up(pos).first != -1 &&
            myArray[up(pos).first][up(pos).second] == 1){
        ret++;
    }
    if(down(pos).first != -1 &&
            myArray[down(pos).first][down(pos).second] == 1){
        ret++;
    }
    if(rightup(pos).first != -1 &&
            myArray[rightup(pos).first][rightup(pos).second] == 1){
        ret++;
    }
    if(rightdown(pos).first != -1 &&
            myArray[rightdown(pos).first][rightdown(pos).second] == 1){
        ret++;
    }
    if(leftup(pos).first != -1 &&
            myArray[leftup(pos).first][leftup(pos).second] == 1){
        ret++;
    }
    if(leftdown(pos).first != -1 &&
            myArray[leftdown(pos).first][leftdown(pos).second] == 1){
        ret++;
    }
    return ret;
}

void updateMyArrayNext()
{
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            int tmp = checkforNeighbors(position(i, j));
            if(myArray[i][j] == 1 && tmp < 2)
                myArrayNext[i][j] = 0;
            else if(myArray[i][j] == 1 && tmp >= 2 && tmp <= 3 )
                myArrayNext[i][j] = 1;
            else if(myArray[i][j] == 1 && tmp > 3)
                myArrayNext[i][j] = 0;
            else if(myArray[i][j] == 0 && tmp == 3)
                myArrayNext[i][j] = 1;
            else
                myArrayNext[i][j] = 0;
        }
    }
}

void outputHandler()
{
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            std::cout<<myArrayNext[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void input_handler()
{
    std::cin>>M;
    myArray=(int**) malloc(M*sizeof(int*));
    myArrayNext=(int**) malloc(M*sizeof(int*));
    for(int i=0; i<M; ++i){
        myArray[i] = (int*) malloc(M*sizeof(int));
        myArrayNext[i] = (int*) malloc(M*sizeof(int));
    }

    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            std::cin>>myArray[i][j];
        }
    }
}

int main()
{
    input_handler();
    updateMyArrayNext();
    outputHandler();
}
