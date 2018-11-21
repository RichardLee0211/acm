#include<set>
#include<vector>
#include<iostream>

struct My{
    int a;
    int b;
    My(int x): a{x}, b{x}{}
    void seta(int x){ this->a = x; }
};

int main(){
    std::set<My> setMy{{1}, {2}, {3}};
    /* !!set.begin always return const-iterator because it's order
     * it's inconvientent because to update element in set need to remove and insert new one
     */
    // auto i = setMy.begin();
    // (*i).a = 1;
    // *i.seta(1);
    // std::set<My>::iterator j;
    // j = setMy.begin();
    // j->a = 1;

    std::vector<My> vecMy{{1}, {2}, {3}};
    auto i = vecMy.begin();
    i->a = 1;
}
