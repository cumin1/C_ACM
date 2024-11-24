#include <stdio.h>

// 汉诺塔问题 将 n 个 x 中的圆盘借助 y 移动到 z 中
void move(int n,char x,char y,char z){
    if (n == 1) printf("%c --> %c\n",x,z);
    else{
        move(n-1,x,z,y);  // 借助z移动到y
        printf("%c --> %c\n",x,z);
        move(n-1,y,x,z);  // 借助x移动到z
    }
}

//int main()
//{
//    move(3,'x','y','z');
//    return 0;
//}