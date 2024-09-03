#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

clock_t start1,start2,stop1,stop2;
double duration1,duration2;

#define MAXN 1000 //多项式的最大项数，即多项式阶数+1
#define MAXK 1e4 //被测函数被调用的总次数，多执行几次，最后计算平均值，这里是10的7次方

double f1(int n,double a[],double x){
    int i;
    double sum=a[0];
    for(i=1;i<=n;i++){
        sum+=(a[i]*pow(x,i));  //使用 pow() 函数，前面要加上头文件，<math.h>
    }
    return sum;
}

//秦九韶公式
double f2(int n,double a[],double x){
    int i;
    double sum=a[n];
    for(i=n;i>0;i--){
        sum=a[i-1]+x*sum;
    }
    return sum;
}

//应该写一个计算时间的函数，这样写太冗杂了
int main(){
    int i;
    double a[MAXN];
    for(i=0;i<MAXN;i++) a[i]=(double)i;

    //第一种暴力算法
    start1=clock();
    //执行MAXK次
    for(i=0;i<MAXK;i++) {
        f1(MAXN - 1, a, 6.25);
    }
    stop1=clock();
    duration1=(((double)(stop1-start1))/CLK_TCK)/MAXK; //除MAXK 得到平均的时间
    cout<<"Brute Force takes ticks:"<<double(stop1-start1)<<endl;
    cout<<"duration1="<<duration1<<"s"<<endl;


    //秦九韶公式
    start2=clock();
    //执行MAXK次
    for(i=0;i<MAXK;i++) {
        f1(MAXN - 1, a, 6.25);
    }
    stop2=clock();
    duration2=(((double)(stop2-start2))/CLK_TCK)/MAXK;

    cout<<"QJS formula takes ticks:"<<double(stop2-start2)<<endl;
    cout<<"duration2="<<duration2<<"s"<<endl;

    return 0;
}



