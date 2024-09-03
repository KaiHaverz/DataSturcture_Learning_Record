#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;

    int price[99]={0};
    for(int i=0;i<num;i++){
        cin>>price[i];
    }

    int maxProfit=0;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++) {
            if(price[j]-price[i]>maxProfit){
                maxProfit=price[j]-price[i];
            }
        }
    }

    cout<<maxProfit<<endl;

    return 0;
}