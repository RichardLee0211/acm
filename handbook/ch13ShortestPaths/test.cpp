#include<iostream>
#include<set>
// #include<pair>
//


class My{
public:
    uint i;
    uint j;
    char c;
    My(uint i, uint j, char c): i{i}, j{j}, c{c}{
    }

};
// pay attention to const !! so much pain to get errors from const
std::ostream &operator<<(std::ostream &os, const My &my){
    os<<my.i<<" "<<my.j<<" "<<my.c<<"\n";
    return os;
}

// TODO: read again, about std [comparison] (http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/)
class My_compare{
public:
    bool operator()(const My &myl, const My &myr) const {
        return myl.i < myr.i;
    }
};

int main(){
    std::set<int> iset{2, 4,1, 5, 14, 10, 9};
    for(auto e: iset){
        std::cout<<e<<" ";
    }
    printf("\n");

    std::set<std::pair<uint, char>> pset{{1, 'a'}, {3, 'c'}, {2, 'b'}};
    for(auto e: pset){
        std::cout<<e.first<<" ";
    }
    printf("\n");

    // TODO:
    // std::set<My, My_compare> mset{{1,1,'a'}, {3,3,'c'}, {2,2,'b'}};
    std::set<My, My_compare> mset;
    mset.insert(My(1,1,'a'));
    mset.insert(My(3,3,'c'));
    mset.insert(My(2,2,'b'));
    for(auto e: mset){
        std::cout<<e;
    }
    printf("\n");


}
