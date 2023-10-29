//
// Created by 尹小紫 on 2023/10/29.
//
//最长公共子序列 LCS X=<x1,x2,...xn>  Y=<y1,y2,...ym>的最长公共子序列 Z=<z1,z2,...zk>
#include <iostream>
using namespace std;


const int X_LEN = 7;
const int Y_LEN = 6;
const int K_LEN = max(X_LEN+1,Y_LEN+1);
int LSC_LENGTH(char X[X_LEN+1],char Y[Y_LEN+1]);
int Z[K_LEN][K_LEN];
int main(){
    char X[X_LEN+1] = {'\0','A','B','C','B','D','A','B'};
    char Y[Y_LEN+1] = {'\0','B','D','C','A','B','A'};
    cout << LSC_LENGTH(X,Y) <<endl;
    return 0;
}
int LSC_LENGTH(char X[X_LEN+1],char Y[X_LEN+1]){

    int i,j;
    Z[0][0] = 1;
    Z[1][0] = 1;
    Z[0][1] = 1;
    for(i = 1;i<X_LEN+1;i++){
        for(j = 1;j<Y_LEN+1;j++){
            if(X[i] == Y[j]){
                Z[i][j] = Z[i-1][j-1] + 1;
            }else{
                Z[i][j] = max(Z[i-1][j],Z[i][j-1]);
            }
        }
    }
    return Z[i-1][j-1]-1;

}