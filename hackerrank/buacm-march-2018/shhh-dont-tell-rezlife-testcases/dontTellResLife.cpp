/**
 *  this is from
 *  https://www.hackerrank.com/contests/buacm-march-2018/challenges/shhh-dont-tell-rezlife
 *  testCase01 problem, erase more than it should
 */

#include<iostream>
#include<vector>
#include<string>

/* debug helpers */
void printVector(std::vector<std::string> &v){
    for(auto e: v){
        if(e.empty()) continue;
        std::cout<<e<<"\n";
    }
}

/* process */
void findandSubstitude(std::vector<std::string> &v, int i){
    for(int j=i-1; j>=0; --j){
        if(j < 0) break;
        bool isChange = false;
        auto it = v[j].find(v[i]);
        while( it != std::string::npos){ // get rid of all concurrence
            v[j].erase(it, it+v[i].size());
            it = v[j].find(v[i]);
            isChange = true;
        }
        if(isChange == true && !v[j].empty())
            findandSubstitude(v, j); // iterate
    }
}

void func(std::vector<std::string> &v){
    for(size_t i=1; i<v.size(); ++i){
        findandSubstitude(v, i);
    }
    printVector(v);
}

int main(){
    int lengthofArray{0};
    std::cin>>lengthofArray;
    std::vector<std::string> v;
    for(int i=0; i<lengthofArray; ++i){
        v.push_back("");
        std::cin>>v[i];
    }
    func(v);
}
