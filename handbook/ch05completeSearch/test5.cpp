// draft
#include<iostream>
#include<string>
#include<unordered_set>

struct test{
    int i1;
    int i2;
    int i3;
    test(int i1, int i2, int i3): i1(i1), i2(i2), i3(i3){
    }
};
int main(){
    /*
     * test of std::string
    const std::string str{"what is up??"};
    std::cout<<str[0];
    const std::string str2{"what is up??"};
    if(str[0]==str2[0])
        std::cout<<"ok";
    */

    std::unordered_set<int> usetInt{1,2,3,4};
    for(auto &i: usetInt){
        std::cout<<i<<" ";
    }

    std::unordered_multiset<test*> setTest;
    auto i1 = new test(1,2,3);
    auto i2 = new test(2,2,3);
    auto i3 = new test(3,2,3);
    setTest.insert(i1);
    setTest.insert(i2);
    setTest.insert(i3);
    for(auto &i: setTest){
        std::cout<<i->i1<<" "<<i->i2<<" "<<i->i3<<std::endl;
    }

}
