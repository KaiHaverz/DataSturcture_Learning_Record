#include <iostream>
#include <time.h>

// clock_t 是 clock() 函数返回的变量类型
clock_t start,stop;
double duration; // 记录时间，单位是秒

int main(){
    start = clock();
    //函数放在中间
    //MyFuction();
    stop = clock();

    duration= (double(start-stop))/CLK_TCK;

    return 0;
}