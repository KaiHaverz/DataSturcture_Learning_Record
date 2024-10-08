#include<iostream>
using namespace std;

//递归实现欧几里得算法，求最大公约数
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int a,b;
    cin>>a>>b;

    cout<<gcd(a,b)<<endl;

    return 0;
}