#include <stdio.h>
#include <stdlib.h>
#define MODE 1
typedef struct node {
    char data;
    struct node *Lpointer;
    struct node *Rpointer;
}Node;
#if MODE
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

void Print_BinaryTree (Node* s) {
   
    if(s != NULL)
	{
		printf("%c",s->data);
	    Print_BinaryTree((s->Lpointer));
	    Print_BinaryTree((s->Rpointer));	
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
	
    Print_BinaryTree(s);
    return 0;
}
 

