#include <stdio.h>
#include <stdlib.h>
#define MODE 1

int num = 0;
typedef struct node {
    char data;
    struct node *Lpointer;
    struct node *Rpointer;
}Node;

int flag;
Node *p1;
Node *tem1 = NULL,*tem2 = NULL;

#if MODE
//创建一个二叉树
void Creat_BinaryTree (Node **s) {
    char temp;
    temp = getchar();
    if(temp == '#')
        *s = NULL;
    else
    {
        *s = (Node*)malloc(sizeof(Node));
        (*s)->data = temp;
        Creat_BinaryTree( &((*s)->Lpointer) );
        Creat_BinaryTree( &((*s)->Rpointer) );
    }
}
#else
//创建一个二叉树
Node* Creat_BinaryTree () {
	
	char temp;
	Node *s;
	temp = getchar();
	if(temp == '#')
		return NULL;
	s = (Node*)malloc(sizeof(Node));
	s->data = temp;
	s->Lpointer = Creat_BinaryTree();
	s->Rpointer = Creat_BinaryTree();
	return s;
}
#endif
//先序输出一个二叉树
void Print_BinaryTree (Node* s) {
   
    if(s != NULL)
	{
		printf("%c",s->data);
	    Print_BinaryTree((s->Lpointer));
	    Print_BinaryTree((s->Rpointer));	
	}
}
//输出二叉树中度为2的个数
void Print_num2 (Node *s) {

    if(s != NULL)
    {
        if( (s->Lpointer != NULL) && (s->Rpointer != NULL) )
            num ++;
        Print_num2(s->Lpointer);
        Print_num2(s->Rpointer);
    }
}

//交换左右结点
void Swop_BinaryTree (Node* s) {

    if( s != NULL )
    {
        Node *p;
        p = s->Lpointer;
        s->Lpointer = s->Rpointer;
        s->Rpointer = p;

        Swop_BinaryTree( s->Lpointer );
        Swop_BinaryTree( s->Rpointer );
    }
}

//叶子结点形成单链表
void Creat_List (Node *s) {

	if( s != NULL )
    {
        if( !flag )
        {
            if( (s->Lpointer == NULL) && (s->Rpointer == NULL) )
            tem1 = s;
            flag = 1;
     		p1 = tem1;       
        }
        else
        {
            if( (s->Lpointer == NULL) && (s->Rpointer == NULL) )
            tem2 = s;
          //  flag = 0;
        }

        if( (tem1 != NULL) && (tem2 != NULL) )
        {
            tem1->Rpointer = tem2 ;
            tem1 = tem2;
            tem2 = NULL;
        }   

        Creat_List(s->Lpointer);
        Creat_List(s->Rpointer);
    }
}

int main(int argc, char const *argv[])
{
    Node *s;
    #if MODE
	Creat_BinaryTree(&s);
	#else 
	s= Creat_BinaryTree();
	#endif
    /*****************/
	puts("1.\"out\"\n");
    Print_BinaryTree(s);
    /*****************
    puts("\n2. 2 number\n");
    num = 0;
    Print_num2(s);
    printf("%d\n",num);
    ******************
    puts("3.swop\n");
    Swop_BinaryTree(s);
    Print_BinaryTree(s);
    *******************/
   	 Creat_List(s);
	while(p1 != NULL)
	{
		printf("%c",p1->data);
		p1=p1->Rpointer;
	}
	
    //Print_BinaryTree(s);
    return 0;
}
 

