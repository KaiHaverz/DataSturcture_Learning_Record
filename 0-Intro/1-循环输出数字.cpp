#include<iostream>
#include<time.h>
using namespace std;

clock_t start,stop;
double duration;

void PrintN(int N){
    int i=1;

    for(i;i<=N;i++){
        cout<<i<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    start=clock();

    PrintN(n);

    stop=clock();

    duration=((double)(stop-start))/CLK_TCK;
    cout<<"the fuction PrintN() takes "<<duration<<" s"<<endl;

    return 0;
}