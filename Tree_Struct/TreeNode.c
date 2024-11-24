#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode,* Node;

typedef struct StackNode{
    Node element;
    struct StackNode * next;
} StackNode,*SNode;

void initStack(SNode node){
    node->next = NULL;
}

int pushStack(SNode head,Node element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

Node popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    Node e = top->element;
    free(top);
    return e;
}

//int isEmpty(SNode head){
//    return head->next == NULL;
//}

typedef Node T;   //还是将Node作为元素

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool _initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool _offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool _isQEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T _pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}
//--------------------------------

void levelOrder(Node root){
    struct Queue queue;   //先搞一个队列
    _initQueue(&queue);
    _offerQueue(&queue, root);  //先把根节点入队
    while (!_isQEmpty(&queue)) {   //不断重复，直到队列空为止
        Node node = _pollQueue(&queue);   //出队一个元素，打印值
        printf("%c ", node->element);
        if(node->left)    //如果存在左右孩子的话
            _offerQueue(&queue, node->left);  //记得将左右孩子入队，注意顺序，先左后右
        if(node->right)
            offerQueue(&queue, node->right);
    }
}

void preOrder(Node root){ // 前序遍历的函数 传入根节点
    printf("%c ",root->element);  // 先打印根节点的数据
    if (root->left != NULL) preOrder(root->left);
    if (root->right != NULL) preOrder(root->right);
}

void preOrder_onStack(Node root){ // 接收根节点
    /*
     * 我们依然是从第一个结点开始，先走左边，每向下走一步，先输出节点的值，
     * 然后将对应的结点丢到栈中，当走到尽头时，表示左子树已经遍历完成，
     * 接着就是从栈中依次取出栈顶节点，如果栈顶结点有右子树，
     * 那么再按照同样的方式遍历其右子树，重复执行上述操作，直到栈清空为止。
     */
    struct StackNode stack;  //栈先搞出来
    initStack(&stack);
    while (root || !isEmpty(&stack)){   //两个条件，只有当栈空并且节点为NULL时才终止循环
        while (root) {    //按照我们的思路，先不断遍历左子树，直到没有为止
            pushStack(&stack, root);   //途中每经过一个结点，就将结点丢进栈中
            printf("%c ", root->element);   //然后打印当前结点元素值
            root = root->left;  //继续遍历下一个左孩子结点
        }
        root = popStack(&stack);  //经过前面的循环，明确左子树全部走完了，接着就是右子树了
        root = root->right;  //得到右孩子，如果有右孩子，下一轮会重复上面的步骤；如果没有右孩子那么这里的root就被赋值为NULL了，下一轮开始会直接跳过上面的while，继续出栈下一个结点再找右子树
    }
}

void inOrder(Node root){
    if (root->left != NULL) inOrder(root->left);
    printf("%c ",root->element);
    if (root->right != NULL) inOrder(root->right);
}

void postOrder(Node root){
    if (root->left != NULL) postOrder(root->left);
    if (root->right != NULL) postOrder(root->right);
    printf("%c ",root->element);
}

//int main()
//{
//    Node a = malloc(sizeof(struct TreeNode));
//    Node b = malloc(sizeof(struct TreeNode));
//    Node c = malloc(sizeof(struct TreeNode));
//    Node d = malloc(sizeof(struct TreeNode));
//    Node e = malloc(sizeof(struct TreeNode));
//    Node f = malloc(sizeof(struct TreeNode));
//
//    a->element = 'A';
//    b->element = 'B';
//    c->element = 'C';
//    d->element = 'D';
//    e->element = 'E';
//    f->element = 'F';
//
//    a->left = b;
//    a->right = c;
//    b->left = d;
//    b->right = e;
//    c->left = NULL;
//    c->right = f;
//    d->left = d->right = NULL;
//    e->left = e->right = NULL;
//    f->left = f->right = NULL;
//
////    printf("%c",a->left->left->element);
//    preOrder(a);
//    printf("\n");
//    preOrder_onStack(a);
//    printf("\n");
//    inOrder(a);
//    printf("\n");
//    postOrder(a);
//    printf("\n");
//    levelOrder(a);
//    return 0;
//}