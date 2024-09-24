#include <stdio.h>
#include <stdlib.h>

/*
 * ��֤��ʵ��2 ���Ա���ϵͳ
 */

typedef struct linknode
{
    char data;
    struct linknode* next;
}linnode;

linnode* head;
int n;

// �������Ա�
void CreateList()
{
    n = 0;
    linnode *p,*s;  // s ��ʾ�½��
    char x;
    int z = 1;
    head = malloc(sizeof(linnode));
    p = head;
    printf("\n\t\t�����������, �� 'x' Ϊ�������! \n");
    printf("\n");
    while(z)
    {
        printf("\t\t����һ���ַ����ݣ������س��� ");
        scanf("%c",&x);
        getchar();
        if (x != 'x')
        {
            s = malloc(sizeof(linnode));
            n++;
            s->data = x;
            p->next = s;
            s->next = NULL;
            p = s;
        }
        else z = 0;
    }
}

// �ڵ�i��λ�ò���Ԫ��
void InsList(int i,char x)
{
    linnode *p,*s;
    p = head;
    int j = 0;
    while(p!=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    if (p!=NULL)
    {
        s = malloc(sizeof(linnode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        n++;
    }
    else printf("\n\t\t���Ա�Ϊ�ջ����λ�ó���! \n");
}

// ����ֵɾ�����Ԫ��
void DelList(char x) {
    linnode *p, *q;
    if (head == NULL) {
        printf("\n\t\t����Ϊ�գ�");
        return;
    }

    // ���ͷ�ڵ��Ƿ����Ҫɾ���Ľڵ�
    if (head->data == x) {
        p = head;
        head = head->next;
        free(p);
        n--;
        printf("\n\t\t��� %c �Ѿ���ɾ����ͷ�ڵ㣩��", x);
        return;
    }

    q = head;
    p = head->next;
    while (p != NULL && p->data != x) {
        q = p;
        p = p->next;
    }
    if (p != NULL) {
        q->next = p->next;
        free(p);
        n--;
        printf("\n\t\t��� %c �Ѿ���ɾ����", x);
    } else {
        printf("\n\t\t��Ǹ�� û���ҵ���Ҫɾ���Ľ��.");
    }
}

// ��ӡ����
void ShowList()
{
    linnode *p = head;
    printf("\n\t\t��ʾ���Ա�����Ԫ��: ");
    if (head->next==NULL||p==NULL)
        printf("\n\t\t����Ϊ�գ�");
    else
    {
        printf("\n\t\t");
        while(p->next!=NULL)
        {
            printf("%5c",p->next->data);
            p = p->next;
        }
    }
}

// ��ֵ��������
void SearchList(char x)
{
    linnode *p;
    int i = 1;
    if (head == NULL)
    {
        printf("\n\t\t�������磡");
        return;
    }
    if (head->next == NULL)
    {
        printf("\n\t\t���Ա�Ϊ��! ");
        return;
    }
    p = head->next;
    while (p!=NULL && p->data!=x)
    {
        p = p->next;
        i++;
    }
    if (p!=NULL)
    {
        printf("\n\t\t�ڱ�ĵ� %d ��λ���ҵ�ֵΪ %c �Ľ�㣡",i,x);
    }
    else printf("\n\t\t��Ǹ��δ�ҵ�ֵΪ %c �Ľ�㣡",x);
}


void main()
{
    head = NULL;
    int choice,i,j=1;
    char x;
    while (j)
    {
        printf("\n");
        printf("\n\t\t           ���Ա���ϵͳ           ");
        printf("\n\t\t********************************");
        printf("\n\t\t        1------��    ��          ");
        printf("\n\t\t        2------��    ��          ");
        printf("\n\t\t        3------ɾ    ��          ");
        printf("\n\t\t        4------��    ʾ          ");
        printf("\n\t\t        5------��    ��          ");
        printf("\n\t\t        6------�� ��  ��          ");
        printf("\n\t\t        0------��    ��          ");
        printf("\n\t\t  ��ѡ��˵��� (0--6): ");
        scanf("%d",&choice);
        getchar();
        if (choice == 1) CreateList();
        else if (choice == 2)
        {
            printf("\n\t\t����������λ�� i �Ͳ��������(�����ʽ��i,x): ");
            scanf("%d,%c",&i,&x);
            InsList(i,x);
        }
        else if (choice == 3)
        {
            printf("\n\t\t������Ҫɾ������ֵ�� ");
            scanf("%c",&x);
            DelList(x);
        }
        else if (choice == 4)
        {
            if (head==NULL) printf("\n\t\t���Ƚ������Ա� ");
            else ShowList();
        }
        else if (choice == 5)
        {
            printf("\n\t\t������Ҫ���ҵ�Ԫ�أ� ");
            scanf("%c",&x);
            SearchList(x);
        }
        else if (choice == 6)
        {
            printf("\n\t\t���Ա���Ϊ: %d",n);
        }
        else if (choice == 0) j = 0;
        else printf("\n\t\t����������������룡");
    }
}