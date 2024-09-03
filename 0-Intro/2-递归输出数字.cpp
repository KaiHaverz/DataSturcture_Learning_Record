#include <iostream>
#include <time.h>
using namespace std;

clock_t start1,start2,stop1,stop2;
double duration;

//第一种办法：循环输出
void PrintN1(int N){
    int i=1;

    for(i;i<=N;i++){
        cout<<i<<" ";
    }
}

//第二种办法：递归输出
void PrintN2(int N){
    if(N){
        PrintN2(N-1);
        cout<<N<<" ";
    }
}

int main(){
    int n;
    cout<<"我们来测试下输出(1-n)中所有正整数所需要的时间，并且比较两种方法的时间效率，请先输入一个正整数：";
    cin>>n;

    //循环的方法计时
    start1=clock();
    PrintN1(n);
    stop1=clock();
    duration=((double)(stop1-start1))/CLK_TCK;
    cout<<endl<<"the cycle PrintN() takes "<<duration<<" s"<<endl;

    //递归方法计时
    start2=clock();
    PrintN2(n);
    stop2=clock();
    duration=((double)(stop2-start2))/CLK_TCK;
    cout<<endl<<"the recursion PrintN() takes "<<duration<<" s"<<endl;

    return 0;
}