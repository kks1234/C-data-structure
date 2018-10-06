#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coef; //xi shu
    int expn; //zhi shu
    struct node* next;

}Node;

//jian li duo xiang shi
void CreatePoly(Node**H){
    Node *s,*p;
    int c,e;
    p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    *H=p;
    scanf("%d,%d",&c,&e);
    while(c)
    {
        s=(Node*)malloc(sizeof(Node));
        s->coef=c;
        s->expn=e;

        p->next=s;
        p=s;
        scanf("%d,%d",&c,&e);
    }
    p->next=NULL;

}

// shu chu duo xiang shi
void PrintPolyn (Node* p){
    int flag=1;
    Node *s=p->next;

    if(s==NULL){
        printf("0\n");
        return;
    }
    while(s){
        if(flag!=1&&s->coef>0)
            printf("+");
        if(s->coef!=-1&&s->coef!=1){
                printf("%d",s->coef);
             if(s->expn==1)
                printf("X");
            else if(s->expn)
                printf("X^%d",s->expn);
        }
        else{
            if(s->coef==1){
                if(!s->expn)
                    printf("1");
                else if(s->expn==1)
                    printf("X");
                else
                    printf("X^%d",s->expn);
            }
            if(s->coef=-1){
                if(!s->expn)
                    printf("-1");
                else if(s->expn==1)
                    printf("-X");
                else
                    printf("-X^%d",s->expn);
            }
        }
        flag++;
        s=s->next;
    }
    printf("\n");
}

// xiang jia

void AddPolyn (Node*Pa,Node*Pb,Node**Pc){
    Node *a,*b,*PC,*Hpc,*t;
    a=Pa->next;
    b=Pb->next;

    Hpc=(Node*)malloc(sizeof(Node));
    Hpc->next=NULL;
    *Pc=t=Hpc;

    while(a!=NULL&&b!=NULL){
        PC=(Node*)malloc(sizeof(Node));
        if(a->expn<b->expn){
            PC->coef=a->coef;
            PC->expn=a->expn;
            a=a->next;
        }else if(a->expn==b->expn){
            PC->coef=a->coef+b->coef;
            PC->expn=a->expn;
            a=a->next;
            b=b->next;
        }else{
            PC->coef=b->coef;
            PC->expn=b->expn;
            b=b->next;
        }
        if(PC->coef!=0){
            PC->next=t->next;
            t->next=PC;
            t=PC;
        }else free(PC);
    }
    while(a!=NULL){
        PC=(Node*)malloc(sizeof(Node));
        PC->coef=a->coef;
        PC->expn=a->expn;

        PC->next=t->next;
        t->next=PC;
        t=PC;
        a=a->next;
    }
    while(b!=NULL){
        PC=(Node*)malloc(sizeof(Node));
        PC->coef=b->coef;
        PC->expn=b->expn;

        PC->next=t->next;
        t->next=PC;
        t=PC;
        b=b->next;
    }
}

// xiang jian
void SubtractPolyn(Node*Pa,Node*Pb,Node**Pc){
    Node *a,*b,*s;
    s=Pb;
    b=Pb->next;
    while(b!=NULL){
        b->coef*=-1;
        b=b->next;
    }
    AddPolyn(Pa,s,Pc);
    while(s->next!=NULL){
        s->next->coef*=-1;
        s=s->next;
    }
}

int main(){
    Node*a,*b,*add,*sub;
    printf("------shu ru di yi ge-------\n");
    CreatePoly(&a);
    printf("------shu ru di er ge-------\n");
    CreatePoly(&b);

    printf("---------num is--------------\n");
    AddPolyn(a,b,&add);
    PrintPolyn(add);

    printf("---------cha is---------------\n");
    SubtractPolyn(a,b,&sub);
    PrintPolyn(sub);

    return  0;
}



