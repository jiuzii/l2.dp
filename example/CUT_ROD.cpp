//
// Created by 尹小紫 on 2023/10/25.
//
#include <iostream>
#include <chrono>
const int ARRAYLEN = 10;
int CUT_ROD(int p[ARRAYLEN],int n);
int MEMOIZED_CUT_ROD(int p[ARRAYLEN],int n,int r[ARRAYLEN]);
int main(){

    int p[ARRAYLEN] = {1,5,8,9,10,17,17,20,24,30};
    int r[ARRAYLEN] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    auto start = std::chrono::high_resolution_clock ::now();
    std::cout << CUT_ROD(p,ARRAYLEN) << std::endl;
    auto end = std::chrono::high_resolution_clock ::now();
    std::chrono::duration<double,std::milli> duration = end-start;
    std::cout << "程序执行时间:" << duration.count() << "毫秒"<< std::endl;

    auto mstart = std::chrono::high_resolution_clock ::now();
    std::cout << MEMOIZED_CUT_ROD(p,ARRAYLEN,r) << std::endl;
    auto mend = std::chrono::high_resolution_clock ::now();
    std::chrono::duration<double,std::milli> mduration = mend-mstart;
    std::cout << "带备忘的程序执行时间:" << mduration.count() << "毫秒"<< std::endl;

    return 0;
}

int CUT_ROD(int p[ARRAYLEN],int n){
    int q;
    if( n==0 ){
        return 0;
    }
    q = -1;
    for( int i=1;i<=n;i++){
        q = std::max(q,p[i-1]+CUT_ROD(p,n-i));
    }
    return q;
}


int MEMOIZED_CUT_ROD(int p[ARRAYLEN],int n,int r[ARRAYLEN]){
    int q;
    if( n==0 ){
        std::cout << 0 << std::endl;
        return 0;
    }
    if( n==1 ){
        std::cout << r[0] << std::endl;
        r[0] = p[0];
        return r[0];
    }
    q = -1;
    for( int i=1;i<=n;i++){
        if(n-i > 0 && r[n-i-1] > 0 ){
            q = std::max(q,p[i-1]+r[n-i-1]);
        }else{
            q = std::max(q,p[i-1]+MEMOIZED_CUT_ROD(p,n-i,r));

        }

    }
    r[n-1] = q;
    std::cout<< n-1 << " "<<q <<std::endl;
    return q;

}