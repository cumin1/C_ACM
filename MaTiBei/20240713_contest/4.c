#include "stdio.h"

/*
 * 小码哥家最近种的水果熟了，小码哥打算拉去农市场卖，
 * 但是由于电商行业的冲击，没有人来农市场买水果，
 * 于是小码哥的水果就滞销了，但是小码妹是个富婆，
 * 他看小码哥太惨了于是打算每天都来农市场买小码哥的一个水果，小码哥一共有

N个水果，每个水果都有对应的价值Wi，和过期时间Ti

 ，小码哥是个有节操的人，是不会卖过期的水果的，假设时间是无穷的，那么请问小码哥最多能卖出多少价值的水果(时间从1开始)？

格式
输入格式：
第一行一个整数N，表示有N个水果；
随后N行，每行两个数字表示第i个水果的价值和过期时间Wi,Ti


输出格式：
小码哥最多能卖出多少钱?

样例
输入：
3
10 2
100 3
100 5

输出：210

其中：
1≤N≤1e5，1≤Wi,Ti≤1e5
 */

int main()
{
    int n;
    scanf("%d", &n);
    int a[100005];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &a[i + n]);
    }

    return 0;
}