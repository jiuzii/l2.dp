# l2.dp

动态规划

##   自定向下的递归实现

```c++

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
```

这是一个递归树，可以看到其时间复杂度是2^n

## 使用动态规划求解

朴素的递归算法因为反复求解相同的子问题，因此效率很低。动态规划设计求解顺序，对每个子问题只求解一次，并将结果保存下来。

- 带备忘的自顶向下法，在求解过程中保存每个子问题的解
- 自底向上法，将子问题按照规模排序，按照有小到大依次求解

