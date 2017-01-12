//
//  main.c
//  EightQueens
//
//  Created by Toby on 2017/1/10.
//  Copyright © 2017年 Toby. All rights reserved.
//

#include <stdio.h>
#include <math.h>
//类比于八叉树，抽象出x[i]，i为行，x[i]的数值为列。判定条件有2，1是同行同列不等，既i!=k,x[i]!=x[k]，2是不在对角线上，既abs((j-k))!=abs(x[j]-x[k]),abs为取绝对值。
static int x[9];   //static设置全局变量
static int num;
static int sum;
int place(int k) //判定条件
{
    for (int i = 1; i<k; i++) {
        if (x[i]==x[k]||abs(i-k)==abs(x[i]-x[k])) {
            return 0;
        }
    }
    return 1;
}
void traverse(int t)   //递归遍历
{
    if (t>num)  //递归跳出条件
    {
      sum++;   //解法加一
    }
    
    
    else {
        for (int j=1; j<=num; j++) {
            x[t]=j;
            if (place(t))    //满足条件，往下递归
            {
                traverse(t+1);
            }
        }
    }
   
}
void main()
{
    num =8;   //八行八列
    sum =0;
    traverse(1);  //从第一行开始挨个放
    printf("解法共有:""%d""种\n",sum);

}


