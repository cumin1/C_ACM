

/*
 * 有n个数字，为a[1]…a[n]。
再来q个询问， 每个询问包含两个数字,l,r，表示询问
∑
i=l
r
​
 {a[i]}

小码哥可以重新排列给出的a数组，使这q组询问所得结果之和最大，输出这个最大值。

格式
输入格式：
第一行输入n和q；
第二行输入n个数字，第i个数字为ai；
接下来q行，每组询问占一行，包含两个数li,ri。

输出格式：
一个数，即上述答案。

样例 1
输入：
3 3
5 3 2
1 2
2 3
1 3

输出：
25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假设数组和询问的最大数量不超过100000
#define MAX_N 100005

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // 降序排序
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), cmp); // 对数组a进行降序排序

    int cover[MAX_N] = {0}; // 记录每个位置的覆盖次数

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        cover[l-1]++; // 区间左端点开始的位置（从0开始计数）
        if (r < n) cover[r]--; // 区间右端点的下一个位置减少覆盖次数（因为要形成区间的前缀和）
    }

    for (int i = 1; i < n; i++) {
        cover[i] += cover[i-1];
    }

    long long max_sum = 0;
// 由于a数组已经降序排序，我们可以直接从后往前遍历，这样每次乘的都是当前的最大值
    for (int i = n-1; i >= 0; i--) {
        // 注意：这里直接使用cover[i]，因为它已经是前缀和，表示了到当前位置为止的累计覆盖次数
        max_sum += (long long)a[i] * cover[i];
        // 因为我们是从后往前遍历的，所以一旦某个位置被计算过，我们就需要将其从cover中减去
        // 这样可以确保每个值只被乘以它对应区间内的覆盖次数
        if (i < n-1) {
            cover[i] -= cover[i]; // 将当前位置的覆盖次数减为0，因为我们已经使用了它
        }
    }

    printf("%lld\n", max_sum);

    return 0;
}