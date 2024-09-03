#include <iostream>
using namespace std;

void PrintN(int N){
    if(N){
        PrintN(N-1);
        cout<<N<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    PrintN(n);

    return 0;
}