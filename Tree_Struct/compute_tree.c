#include <stdio.h>

// 需求计算n个节点能够组成多少种二叉树
//int main()
//{
//    int size;
//    scanf("%d", &size);   //读取需要求的N
//    int dp[size + 1];
//    dp[0] = dp[1] = 1;   //没有结点或是只有一个结点直接得到1
//    for (int i = 2; i <= size; ++i) {
//        dp[i] = 0;   //一开始先等于0再说
//        for (int j = 0; j < i; ++j) {   //内层循环是为了计算所有情况，比如i等于3，那么就从j = 0开始，计算dp[0]和dp[2]的结果，再计算dp[1]和dp[1]...
//            dp[i] += dp[j] * dp[i - j - 1];
//        }
//    }
//    printf("%d", dp[size]);
//
//    return 0;
//}
