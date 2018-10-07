// build huffman coding
#include<iostream>
#include<string>
#include<set>
#include<unordered_set>

#define DEBUG 1

typedef unsigned int uint;
typedef unsigned long ulong;

class Character{
    public:
        std::string str;
        ulong count;
        std::string code;

        Character * left;
        Character * right;

        Character(std::string str, ulong count){
            this->str = str;
            this->count = count;
            left=nullptr;
            right = nullptr;
        }
};

struct CharacterCmp{
    bool operator()(Character *l, Character *r) const {
        if(l->count < r->count)
            return true;
        else if(l->count > r->count)
            return false;
        else // if(l->count == r->count)
            return l->str < r->str;
    }
};
/*
bool operator<(const Character &l, const Character &r){
    return l.count < r.count;
}
Character *operator+(const Character &l, const Character &r){
    Character *newC = new Character(l.str+r.str, l.count+r.count);
    newC->left = &const_cast<Character&>(l);
    newC->right= &const_cast<Character&>(r);
    return newC;
}
*/

int setCode(Character* top, std::string str){
    // std::cout<<top->str<<" "<<top->count<<" "<<str<<"\n";
    if(top->left == nullptr && top->right == nullptr) {
        top->code = str;
        return -1;
    }
    setCode(top->left, str+"1");
    setCode(top->right, str+"0");
    return 0;
}

std::string duffman(const std::string &str){
    // do counting
    std::unordered_set<Character*> usetChar;
    for(uint i{0}; i<str.size(); ++i){
        auto it = std::find_if(usetChar.begin(), usetChar.end(), [=](Character *temp){
                return  temp->str[0] == str[i];
                });
        if(it == usetChar.end()){
            usetChar.insert(new Character(std::string{str[i]}, 1));
        } else {
            (*it)->count++;
        }
    }


    std::set<Character*, CharacterCmp> setChar;
    for(auto temp: usetChar){
        setChar.insert(temp);
    }

    while(setChar.size() > 1){
        Character *l = *setChar.begin();
        setChar.erase(setChar.begin());
        Character *r = *setChar.begin();
        setChar.erase(setChar.begin());
        Character *newC = new Character(l->str+r->str, r->count+l->count);
        newC->left = l;
        newC->right= r;
        setChar.insert(newC);
    }

    Character* charTop = *setChar.begin();
    setCode(charTop, "");

#if 1 // pass DEBUG
    for(auto i: usetChar){
        std::cout<<i->str<<" "<<i->count<<" "<<i->code<<"\n";
    }
    return "what";
#endif

    return "";
}
int main(){
    /*
    std::string test{"111233333"};
    duffman(test);
    */
    std::string test2{"31415926535------------------wawswaaweaeseaewasewdddddddddddddddddd----------------dddddddddddddd"};
    duffman(test2);
}
