#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char E;
typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int value;   // 权值
} *Node;




typedef Node T;
typedef struct LNode{
    T element;
    struct LNode * next;
} *LNode;

struct Queue{
    LNode front,rear;
};
typedef struct Queue *LinkedQueue;

//int initQueue(LinkedQueue queue)
//{
//    LNode node = malloc(sizeof(struct Queue));
//    if (node==NULL) return 0;
//    queue->front = queue->rear = node;
//    node->next = NULL;
//    return 1;
//}

//int offerQueue(LinkedQueue queue, T element){
//    LNode node = malloc(sizeof(struct LNode));
//    if(node == NULL) return 0;
//    node->element = element;
//    node->next = NULL;
//    LNode pre = queue->front;
//    while (pre->next && pre->next->element->value <= element->value)   //注意这里改成权重的比较，符号改成小于
//        pre = pre->next;
//    if(pre == queue->rear) {
//        queue->rear->next = node;
//        queue->rear = node;
//    } else {
//        node->next = pre->next;
//        pre->next = node;
//    }
//    return 1;
//}

//T pollQueue(LinkedQueue queue){
//    T e = queue->front->next->element;
//    Node node = queue->front->next;
//    queue->front->next = queue->front->next->next;  //直接让头结点指向下下个结点
//    if(queue->rear == node) queue->rear = queue->front;   //如果队尾就是待出队的结点，那么队尾回到队首位置上
//    free(node);   //释放内存
//    return e;
//}

void printQueue(LinkedQueue queue)
{
    LNode pre = queue->front;
    while(pre->next != NULL)
    {
        pre = pre->next;
        printf("%c ",pre->element->element);
    }
}

Node createNode(E element, int value){   //创建一个结点
    Node node = malloc(sizeof(struct TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->value = value;
    return node;
}

char * encode(Node root, E e){
    if(root == NULL) return NULL;   //为NULL肯定就是没找到
    if(root->element == e) return "";   //如果找到了就返回一个空串
    char * str = encode(root->left, e);  //先去左边找
    char * s = malloc(sizeof(char) * 10);
    if(str != NULL) {
        s[0] = '0';
        str = strcat(s, str);   //如果左边找到了，那么就把左边的已经拼好的字符串拼接到当前的后面
    } else {    //左边不行那再看看右边
        str = encode(root->right, e);
        if(str != NULL) {
            s[0] = '1';
            str = strcat(s, str);   //如果右边找到了，那么就把右边的已经拼好的字符串拼接到当前的后面
        }
    }
    return str;   //最后返回操作好的字符串给上一级
}

void printEncode(Node root, E e){
    printf("%c 's encode is：%s", e, encode(root, e));   //编码的结果就是了
    putchar('\n');
}

//int main()
//{
//    struct Queue queue;
//    initQueue(&queue);
//
//    offerQueue(&queue, createNode('A', 5));
//    offerQueue(&queue, createNode('B', 16));
//    offerQueue(&queue, createNode('C', 8));
//    offerQueue(&queue, createNode('D', 13));
//
//    while (queue.front->next != queue.rear) {   //如果front的下一个就是rear那么说明队列中只有一个元素了
//        Node left = pollQueue(&queue);
//        Node right = pollQueue(&queue);
//        Node node = createNode(' ', left->value + right->value);   //创建新的根结点
//        node->left = left;
//        node->right = right;
//        offerQueue(&queue, node);   //最后将构建好的这棵树入队
//    }
//
//    Node root = pollQueue(&queue);   //最后出来的就是哈夫曼树的根结点了
//
//    printEncode(root, 'A');
//    printEncode(root, 'B');
//    printEncode(root, 'C');
//    printEncode(root, 'D');
//
//    return 0;
//}