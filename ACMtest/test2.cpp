#include <stdio.h>
#include<iostream>
#include <algorithm>

using namespace std;

//返回单个元素的个数
int GeShu(float a[], int size, float x){
    int i,num = 0;

    for (i = 0; i < size; ++i)
    {
        if (x == a[i])
        {
            ++num;
        }
    }
    return num;
}
//对返回个数处理，得出对多的个数
float Arr(float a[], int size){
    float temp = 0.0;
    int i;

    temp = a[0];
    for (i = 0; i < size; ++i)
    {
        if (GeShu(a, size, a[i]) < GeShu(a, size , a[i+1]))//第一次：a[0]出现的次数与a[1]出现的次数比较
        {
            temp = a[i+1];//保存出现次数多的数字
        }
    }
    return temp;
}

int main()
{
    float myFloat[1000];
    int count=0;
    char buffer[1024];
    char* p = buffer;
    gets(buffer);
    while (*p != '\0'){
        if(*p == ' ') p++;
        else sscanf(p, "%f", &myFloat[count++]);
    }
    float sum = 0.0;
    for(int i=0; i<count; i++){
        sum += myFloat[i];
    }
    float mean = sum/count;
    cout<<sum/count<<endl;
    sort(myFloat, &myFloat[count-1]);
    if(count%2 == 1)
        cout<<myFloat[count/2]<<endl;
    else{
        cout<<(myFloat[count/2]+myFloat[count/2+1])/2<<endl;
    }

    float mode = Arr(myFloat, count);
    if(mode == 0.0) cout<<endl;
    else cout<<mode<<endl;

    float tmp =0.0;
    for(int i=0; i<count; i++){
        tmp += (myFloat[i] - mean)*(myFloat[i] - mean);
    }
    cout<<tmp<<endl;
    cout<<tmp/count<<endl;

    return 0;
}
