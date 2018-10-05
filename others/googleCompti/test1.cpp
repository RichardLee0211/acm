#include<set>
#include<iostream>

int main(){
    std::set<int> ints{1,2,3,4,5};
    for(auto &i: ints){
        // i = 4; can't assign, because it will broken binary tree of set
        std::cout<<i;
    }

    for(auto i = ints.begin(); i!=ints.end(); ++i){
        // *i = 5;
    }
}
