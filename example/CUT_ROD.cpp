//
// Created by 尹小紫 on 2023/10/25.
//
#include <iostream>
#include <chrono>
const int ARRAYLEN = 10;
int CUT_ROD(int p[ARRAYLEN],int n);
int MEMOIZED_CUT_ROD(int p[ARRAYLEN],int n,int r[ARRAYLEN]);
int BUTTOM_UP_CUT_ROD(int p[ARRAYLEN],int n,int r[ARRAYLEN]);
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

    auto bstart = std::chrono::high_resolution_clock ::now();
    std::cout << BUTTOM_UP_CUT_ROD(p,ARRAYLEN,r) << std::endl;
    auto bend = std::chrono::high_resolution_clock ::now();
    std::chrono::duration<double,std::milli> bduration = bend-bstart;
    std::cout << "自底向上的程序执行时间:" << bduration.count() << "毫秒"<< std::endl;

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
        return 0;
    }
    if(r[n-1] > 0){
      return r[n-1];
    }
    q = -1;
    for( int i=1;i<=n;i++ ){
      q = std::max(q,p[i-1]+MEMOIZED_CUT_ROD(p,n-i,r));
    }
    r[n-1] = q;
    return q;
}

int BUTTOM_UP_CUT_ROD(int p[ARRAYLEN],int n,int r[ARRAYLEN]){
  for(int k=0;k<n;k++){
    r[k] = p[k];
    for(int i = 0;i<k;i++){
      r[k] = std::max(r[k],p[i]+r[k-i-1]);
    }
  }
  return r[n-1];
}