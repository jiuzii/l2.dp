//
// Created by jiuzii on 2023/10/27.
//
//菲波那切数列的动态规划
#include <iostream>

int Fibonacci(int);
int main(){
  std::cout << Fibonacci(10) << std::endl;
  return 0;
}

int Fibonacci(int n){
  int arr[n+1] ;
  if(n<2){
    return 0;
  }
  arr[0] = 0;
  arr[1] = 1;
  for(int i=2;i<=n;i++){
    arr[i] = arr[i-1]+arr[i-2];
  }
  return arr[n];
}