#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 100

typedef struct {
    int row,col;
    int temp;
}node;

typedef struct {
    node data[MAXSIZE];
    int rows,cols,nums;
}TSMatrix;

void creat_nums(TSMatrix *s) {
    int x,row,col,i=0;
    puts("---rows-----");
    scanf("%d",&(s->rows));
    puts("---cols-----");
    scanf("%d",&(s->cols));
    puts("----nums------");
    scanf("%d",&(s->nums));
    puts("----data------");
    scanf("%d%d%d",&row,&col,&x);
    while( i < s->nums)
    {
        s->data[i].temp = x;
        s->data[i].row = row;
        s->data[i].col = col;
        if(scanf("%d%d%d",&row,&col,&x) != 3 )
            break;
        i++;
    }
}


void print_nums(TSMatrix s)
{
   /* int i;
    puts("---rows---cols---nums---");
    printf("%d  %d  %d\n",s.rows,s.cols,s.nums);
    puts("----data------");
    puts("---rows---col---num----");
    for(i=0 ; i<s.nums ; i++)
    {
        printf("%d  %d  %d\n",s.data[i].row,s.data[i].col,s.data[i].temp);
    }*/
    int i,j;
    for(i=0  ; i<s.rows ; i++)
    {
        for(j=0 ; j<s.cols ; j++)
        {
            printf("%d ",s.data[i*s.rows+j].temp);
        }
        printf("\n");
    }
}

void fast_transpose(TSMatrix* A , TSMatrix* B) {
    int num[MAXSIZE],positon[MAXSIZE];
    int col,t,p,q;
    B->rows = A->rows;
    B->cols = A->cols;
    B->nums = A->nums;
    if(B->nums)
    {
        for(col=0 ; col<A->cols ; col++)
            num[col] = 0;
        for(t=0 ; t<A->nums ; t++)
            num[A->data[t].col]++;
        positon[0] = 0;
        for(col=1 ; col<A->cols ; col++)
            positon[col] = positon[col-1] + num[col-1] ;
        for(p=0 ; p<A->nums ; p++)
        {   
            col = A->data[p].col;
            q=positon[col];

            B->data[q].row = A->data[p].col ;
            B->data[q].col = A->data[p].row ;
            B->data[q].temp = A->data[p].temp ;
            positon[col]++;
        }
    }
}


int main() {
    TSMatrix s;
     TSMatrix B;
    creat_nums(&s);
    fast_transpose(&s,&B);
    print_nums(B);
    return 0;
}