#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<complex>

using namespace std;

int swap(int& a, int& b){
    int tmp;
    tmp =a;
    a = b;
    b = tmp;
    return 0;
}

int main(){
    int count;
    cin>>count;

    for(int h=0; h<count; h++){
        int array[4][4] = {0};
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++)
                scanf("%d", &array[i][j]);
        }

        int newArray[4][4];
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                newArray[i][j] = array[j][3-i];
            }
        }

        int first =
            newArray[0][0]*pow(2, 5)+
            newArray[0][1]*pow(2, 4)+
            newArray[0][2]*pow(2, 3)+
            newArray[0][3]*pow(2, 2)+
            newArray[1][0]*pow(2, 1);
        int second=
            newArray[1][1]*pow(2, 5)+
            newArray[1][2]*pow(2, 4)+
            newArray[1][3]*pow(2, 3)+
            newArray[2][0]*pow(2, 2)+
            newArray[2][1]*pow(2, 1);
        int third=
            newArray[2][2]*pow(2, 5)+
            newArray[2][3]*pow(2, 4)+
            newArray[3][0]*pow(2, 3)+
            newArray[3][1]*pow(2, 2)+
            newArray[3][2]*pow(2, 1);
        printf("%c%c%c\n", (char)first, (char)second, (char)third);

    }



    return 0;
}
