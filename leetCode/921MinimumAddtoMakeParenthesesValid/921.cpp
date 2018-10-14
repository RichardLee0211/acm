// https://leetcode.com/contest/weekly-contest-106/problems/minimum-add-to-make-parentheses-valid/
#include<vector>
#include<string>
#include<iostream>

using namespace std;

/* not working */
int minAddToMakeValid_1(string S) {
    int *array = (int*)malloc(S.size()*sizeof(int));
    for(int i{0}; i<(int)S.size(); ++i){
        if(S[i] == '('){
            array[i] = 1;
        }else
            array[i] = -1;
    }

    int sum{0};
    for(int i{0}; i<(int)S.size(); ++i){
        sum+=array[i];
        if(sum<0) goto notValid;
    }
    if(sum == 0) return 0;

notValid:
    int count{0};
    sum = 0;
    // bool isDivi
    sum += array[0];
    for(int i{1}; i<(int)S.size(); ++i){
        if(array[i-1] == -1 && array[i] == 1){
            count += abs(sum);
            sum = 0;
        }
        sum += array[i];
    }
    count += abs(sum);
    return count;
}

int minAddToMakeValid(string S) {
    int *array = (int*)malloc(S.size()*sizeof(int));
    for(int i{0}; i<(int)S.size(); ++i){
        if(S[i] == '('){
            array[i] = 1;
        }else
            array[i] = -1;
    }

    int sum{0};
    for(int i{0}; i<(int)S.size(); ++i){
        sum+=array[i];
        if(sum<0) goto notValid;
    }
    if(sum == 0) return 0;

notValid:
    int count{0};
    sum = 0;
    for(int i{0}; i<(int)S.size(); ++i){
        sum += array[i];
        if(sum<0){
            count++;
            sum = 0;
        }
    }
    count += sum;
    return count;
}
int main(){
    /*
    */
    std::cout<<minAddToMakeValid("(((")<<"\n";      // 3
    std::cout<<minAddToMakeValid("()))")<<"\n";     // 2
    std::cout<<minAddToMakeValid("()))((")<<"\n";   // 4
    std::cout<<minAddToMakeValid("())")<<"\n";      // 1
    std::cout<<minAddToMakeValid("()")<<"\n";       // 0
    std::cout<<minAddToMakeValid("")<<"\n";         // 0
    std::cout<<minAddToMakeValid("()()")<<"\n";     // 0
    std::cout<<minAddToMakeValid("(()()")<<"\n";    // 1
    std::cout<<minAddToMakeValid("(()())((")<<"\n";  // 2
}
