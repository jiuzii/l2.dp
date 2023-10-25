//
// Created by 尹小紫 on 2023/10/25.
//
#include <iostream>
int CUT_ROD(int p[4],int n);
int main(){
    int p[4] = {1,5,8,9};
    std::cout << CUT_ROD(p,4) << std::endl;
    return 0;
}

int CUT_ROD(int p[4],int n){
    int q;
    if( n==0 ){
        return 0;
    }
    q = -1;
    for( int i=4-n;i<4;i++){
        q = std::max(q,p[i]+CUT_ROD(p,n-i-1));
    }
    return q;
}