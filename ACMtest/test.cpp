#include<string>
#include<iostream>

using namespace std;

string foo(){
    string tmpStr;
    string str = "Wednesday";
    int count = 0;
    cin>>tmpStr;
    if(tmpStr.length() != 9) return "me too thanks";
    if(tmpStr[0] == 'W' || tmpStr[0]=='w')
        count++;
    if(tmpStr[1] == 'E' || tmpStr[1]=='e')
        count++;
    if(tmpStr[2] == 'D' || tmpStr[2]=='d')
        count++;
    if(tmpStr[3] == 'N' || tmpStr[3]=='n')
        count++;
    if(tmpStr[4] == 'E' || tmpStr[4]=='e')
        count++;
    if(tmpStr[5] == 'S' || tmpStr[5]=='s')
        count++;
    if(tmpStr[6] == 'D' || tmpStr[6]=='d')
        count++;
    if(tmpStr[7] == 'A' || tmpStr[7]=='a')
        count++;
    if(tmpStr[8] == 'Y' || tmpStr[8]=='y')
        count++;
    if(count == 9)
        return "It is Wednesday, my dudes";

    else{

        return "me too thanks";
    }




}

int main(){

    cout<<foo();
    return 0;
}
