//
// Created by 尹小紫 on 2023/10/25.
//
#include <iostream>
#include <chrono>
const int ARRAYLEN = 10;
int CUT_ROD(int p[ARRAYLEN],int n);
int main(){

    int p[ARRAYLEN] = {1,5,8,9,10,17,17,20,24,30};
    auto start = std::chrono::high_resolution_clock ::now();
    std::cout << CUT_ROD(p,ARRAYLEN) << std::endl;
    auto end = std::chrono::high_resolution_clock ::now();
    std::chrono::duration<double,std::milli> duration = end-start;
    std::cout << "程序执行时间:" << duration.count() << "毫秒"<< std::endl;
    return 0;
}

int CUT_ROD(int p[ARRAYLEN],int n){
    int q;
    if( n==0 ){
        return 0;
    }
    q = -1;
    for( int i=ARRAYLEN-n;i<ARRAYLEN;i++){
        q = std::max(q,p[i]+CUT_ROD(p,n-i-1));
    }
    return q;
}