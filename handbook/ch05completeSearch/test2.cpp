// use of function pointer
#include<iostream>
#include<algorithm>

class Item{
    public:
    int i1;
    int i2;
    int i3;
};

int main(){
    Item items[] {{1,5,3}, {2,4,1}, {3,3,5}, {4,2,4}, {5,1,2}};
    /*
    std::qsort(items, 5, sizeof(Item), [](const void *l, const void *r){
            int i = static_cast<const Item*>(l)->i3;
            int j = static_cast<const Item*>(r)->i3;
            return i-j;
            });
    */
    std::sort(items, &items[5], [](const Item& l, const Item& r){
            return l.i2 < r.i2;
            });
    for(auto i: items){
        std::cout<<i.i1<<i.i2<<i.i3<<"\n";
    }

}
