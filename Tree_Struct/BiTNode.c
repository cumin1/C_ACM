#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct BiTNode{
    ElementType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BitTree;

void CreateBiTree(BitTree *bt)    // ���������� Լ���û���ǰ�����е�˳���������
{
    char c;
    scanf("%c",&c);

    if (c == ' ')
    {
        *bt =  NULL;
    }else{
        *bt = (BitTree) malloc(sizeof(BiTNode));
        (*bt)->data = c;
        CreateBiTree(&(*bt)->lchild);   // ����������
        CreateBiTree(&(*bt)->rchild);   // ����������
    }
}

void visit(BitTree bt,int level){ // ���ʶ������ڵ�ľ������
    printf("�������ĵ�%d�㣬���ݣ�%c\n",level,bt->data);
}

int _preOrder(BitTree bt,int level){  // ǰ�����
    if (bt==NULL) return 0;
    else{
        visit(bt,level);
        _preOrder(bt->lchild,level+1);
        _preOrder(bt->rchild,level+1);
    }

    return 1;
}

int _inOrder(BitTree bt,int level){  // �������
    if (bt==NULL) return 0;
    else{
        _inOrder(bt->lchild,level+1);
        visit(bt,level);
        _inOrder(bt->rchild,level+1);
    }

    return 1;
}

int _postOrder(BitTree bt,int level){  // �������
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
