#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN  50
#define TURE  1
#define FALSE 0

typedef struct{
    char ch[MAXLEN];
    int len;
}Str;
/**/

/*creat strings*/
int Creat_Strings(Str* s,char*chars) {
    int i,len;char*c;
   // s = (Str*)malloc(sizeof(Str));
    for(len=0, c= chars; *c!='\0';++c,++len);
    for(i=0; i < len; i++)
        s->ch[i]=chars[i];
    s->len=len;
}
/*insert strings*/
int Str_Insert(Str* s,int pos,const Str p) {
    int i;
    /*check parameters*/
    if(s==NULL||p.ch==NULL) return FALSE;
    if(pos<=0||pos>s->len)  return FALSE;

    if(s->len+p.len<MAXLEN)
    {
        for(i=s->len+p.len-1; i >= pos+p.len-1; i--)
            s->ch[i]=s->ch[i-p.len];
        for(i=pos-1; i < pos+p.len-1; i++)
            s->ch[i]=p.ch[i-pos+1];
        s->len=s->len+p.len;
    }
    else if(pos+p.len-1<MAXLEN)
    {
        for(i=MAXLEN-1; i >= pos+p.len-1; i--)
            s->ch[i]=s->ch[i-p.len];
        for(i=pos-1; i < pos+p.len-1; i++)
            s->ch[i]=p.ch[i-pos+1];
        s->len=MAXLEN;
    }
    else
    {
        for(i=pos-1; i < MAXLEN; i++)
            s->ch[i]=p.ch[i-pos+1];
        s->len=MAXLEN;
    }
    return TURE;
}

/*remove strings*/
int Str_Delete(Str*s ,int pos ,int len) {
    int i;
    /*check parameters*/
    if(s==NULL||pos<1||pos>s->len)  return FALSE;

    for(i=pos-1; i < s->len-len; i++)
        s->ch[i]=s->ch[i+len];
    s->len=s->len-len;
    return TURE;
}
/*copy strings*/
int Str_Copy(Str*s,Str p) {
    int i;
    /*check parameters*/
    if(s==NULL||p.ch==NULL||p.len>MAXLEN)  return FALSE;
    for(i=0; i < p.len; i++)
        s->ch[i]=p.ch[i];
    s->len=p.len;
}
/*compare strings*/
/* == 0    > 1    < -1   */
int Str_Compare(const Str a, const Str b) {
    int i,flag=0,flag1;
    /*check parameters*/
    if(a.ch==NULL||b.ch==NULL)  return -2;
    for(i=0;i < a.len && i < b.len;i++)
    {
        if(a.ch[i]==b.ch[i])
        {
            flag1=1;continue;
        }

        if(a.ch[i]>b.ch[i])
            flag=1;
        else if(a.ch[i]<b.ch[i])
            flag=-1;
        flag1=0;
        break;
    }
    if(flag1)
        if(i<a.len)
            flag=1;
        else if(i<b.len)
            flag=-1;

    return flag;
}
/*cat strings*/
int Str_Cat(Str*s ,const Str p) {
    int i;
    /*check parameters*/
    if(s==NULL||p.ch==NULL||s->len+p.len>MAXLEN)  return FALSE;

    for(i=s->len; i <= s->len+p.len-1; i++)
        s->ch[i]=p.ch[i-s->len];
    s->len=s->len+p.len;
    return TURE;
}
/*sub strings*/
int Str_Substrings(Str*t, Str s, int pos, int len) {
    int i;
    /*check paramenters*/
    if(t==NULL||s.ch==NULL||pos<1||pos>s.len)  return FALSE;

    for(i=pos-1; i < pos+len-1; i++)
        t->ch[i-pos+1]=s.ch[i];
    t->len=len;
}
/*index strings*/
int Str_Index(Str s, int pos, Str t) {
    int i,flag=0;
    /*check paramentsters*/
    if(s.ch==NULL||t.ch==NULL)  return -1;
    for(i=pos-1;i <= s.len-t.len; i++)
    {
        Str p;
        Str_Substrings(&p,s,i+1,t.len);
      //puts(p.ch);
        if(Str_Compare(p,t)==0)
        {  
            flag = 1;
            break;
        }
    }
    if(flag)
        return  i+1;
    else
        return  0;
}

/*replace strings*/
int Str_Replace(Str* s, Str t, Str v) {
    int i=1;
     Str q,h,m,H; 	
    /*check paramentsters*/
    if(s->ch==NULL||t.ch==NULL||v.ch==NULL||t.len==0) return FALSE;


    while( i <= s->len-t.len+1)
    {
		
		Str_Substrings(&m,*s,i,t.len);
        if(Str_Compare(m,t)==0)
        {
            Str_Substrings(&q,*s,1,i-1);
		    Str_Substrings(&h,*s,i+t.len,s->len-i-t.len+1);
            Str_Cat(&q,v);
            Str_Cat(&q,h);
            Str_Copy(s,q);
            i+=v.len;
        }
        else i++;
    }
    return TURE;
}






int main(int argc, char const *argv[])
{
    int i;
    Str a,b,c;
    /*插入*/
    /*	Creat_Strings(&a,"abcde");
        Creat_Strings(&b,"qwer");
       Str_Insert(&a,3,b);*/

    /*删除*/
    /* Creat_Strings(&a,"abcde");
       Str_Delete(&a,2,2);*/

    /*复制*/
    /* Creat_Strings(&b,"abcde");
       Str_Copy(&a,b);*/

    /*比较*/
    /* Creat_Strings(&a,"abcde");
       Creat_Strings(&b,"abcde");
       printf("%d",Str_Compare(a,b));*/

    /*拼接*/
   /*  Creat_Strings(&a,"abcd");
       Creat_Strings(&b,"qwer");
       Str_Cat(&a,b);*/

    /*子串*/
     /*Creat_Strings(&b,"abcdefghi");
       Str_Substrings(&a,b,4,4);*/

    /*查询*/
   	/* Creat_Strings(&a,"abcaabcaaabc");
       Creat_Strings(&b,"bca");
       printf("index : %d\n",Str_Index(a,4,b));*/

	/*替换*/ 
    /* Creat_Strings(&a,"abcdebccbdd");
       Creat_Strings(&b,"bc");
       Creat_Strings(&c,"vvv");
       Str_Replace(&a,b,c);*/
    	
    printf("The lenth : %d\n",a.len);
    printf("The strings : \n");
	for(i=0; i < a.len; i++)
		printf("%c",a.ch[i]);
	
    return 0;
}
