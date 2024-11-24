#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct BiTNode{
    ElementType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BitTree;

void CreateBiTree(BitTree *bt)    // 创建二叉树 约定用户用前序序列的顺序定义二叉树
{
    char c;
    scanf("%c",&c);

    if (c == ' ')
    {
        *bt =  NULL;
    }else{
        *bt = (BitTree) malloc(sizeof(BiTNode));
        (*bt)->data = c;
        CreateBiTree(&(*bt)->lchild);   // 创建左子树
        CreateBiTree(&(*bt)->rchild);   // 创建右子树
    }
}

void visit(BitTree bt,int level){ // 访问二叉树节点的具体操作
    printf("二叉树的第%d层，数据：%c\n",level,bt->data);
}

int _preOrder(BitTree bt,int level){  // 前序遍历
    if (bt==NULL) return 0;
    else{
        visit(bt,level);
        _preOrder(bt->lchild,level+1);
        _preOrder(bt->rchild,level+1);
    }

    return 1;
}

int _inOrder(BitTree bt,int level){  // 中序遍历
    if (bt==NULL) return 0;
    else{
        _inOrder(bt->lchild,level+1);
        visit(bt,level);
        _inOrder(bt->rchild,level+1);
    }

    return 1;
}

int _postOrder(BitTree bt,int level){  // 后序遍历
    if (bt==NULL) return 0;
    else{
        _postOrder(bt->lchild,level+1);
        _postOrder(bt->rchild,level+1);
        visit(bt,level);
    }

    return 1;
}

//int main()
//{
//    int level = 1;
//    BitTree bt = NULL;
//    CreateBiTree(&bt);
//    _preOrder(bt,level);
//
//    return 0;
//}
