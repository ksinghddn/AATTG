#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>
#include<windows.h>

using namespace std;

FILE *fp;

char ch;

void listfac(char *);
void listsub(char *);
void listcls(char *);

void addfac(char *);
void addsub(char *);
void addcls(char *);

void allocate();

void cls1();
void sub1();
void fac1();

int no_of_act;

struct fac
{
       char name[20];
       int code;
       struct fac *next;
};

struct sub
{
       char name[20];
       int code;
       struct sub *next;
};

struct cls
{
       char name[20];
       int code;
       struct cls *next;
};

struct facnode
{
	int code;
	facnode *link;
    struct subnode *sub_link;
	char name[20];
};

struct subnode
{
	int code;
	subnode *link;
    struct clsnode *cls_link;
	char name[20];
};

struct clsnode
{
	int code;
	clsnode *link;
	char name[20];
};

facnode *startfac=NULL,*start=NULL;
subnode *startsub=NULL;
clsnode *startcls=NULL;

facnode *a;
subnode *b;
clsnode *c;

clsnode n1[2000];
subnode n2[1000];
facnode n3[100];

cls n6[1000];
sub n5[1000];
fac n4[1000];

int count1=0,count2=0,count3=0,count4=0,count6=0,count5=0;

fac *x,*x1,*q1;
sub *y,*y1,*q2;
cls *z,*z1,*q3;

static fac *start1=NULL;
static sub *start2=NULL;
static cls *start3=NULL;

int searchfac(fac *, char *);
int searchsub(sub *, char *);
int searchcls(cls *, char *);

void addact(facnode *,subnode *,clsnode *);

int arr[5000],i=0;

int xx1=0,xx2=0,xx3=0;

int tfitness=0;

int batch_t[16][6][9];
int room_t[11][6][8];
int lroom_t[4][6][8];

class Allocation
{
 public:
            int faculty, subject, batch;
            int fact_t[99][6][8];
            int algo(int);
            int algo1(int);
            void create();
            void print();
            int fitness();
            void output();
};     

Allocation allow,allow1;    

void addact(facnode *l,subnode *m,clsnode *n)
{     
      int bbb;
      bbb=l->code*10000 + m->code*100 +n->code;
      for(int y=1;y<=no_of_act-48;y++)
      {
        arr[i++]=bbb;
      }
}

int searchfac(fac *d,char *name)
{
    while(d!=NULL)
    {
                  if(!strcmp((d->name),(name)))
                  {
                    return d->code;
                  }
                  else
                  {
                  d=d->next;
                  }
    }
}

int searchsub(sub *d,char *name)
{
    while(d!=NULL)
    {
                  if(!strcmp((d->name),(name)))
                  {
                    return d->code;
                  }
                  else
                  {
                    d=d->next;
                  }
    }
}

int searchcls(cls *d,char *name)
{
    while(d!=NULL)
    {
                  if(!strcmp((d->name),(name)))
                  {
                     return d->code;
                  }
                  else
                  {
                    d=d->next;
                  }
    }
}

void listfac(char *name)
{
     if(start1==NULL)
     {
       start1=&n4[count4];
       n4[count4].next=NULL;
       strcpy((start1->name),(name));
       n4[count4++].code=1;
     }
     else
     {
       x=start1;
       while(x!=NULL)
         {
                       if(!strcmp((x->name),(name)))
                       {
                           return;
                       }
                       else
                       {
                           x1=x;
                           x=x->next;
                       }
          }
          x1->next=&n4[count4++];
          x=x1->next;
          strcpy((x->name),(name));
          x->code=x1->code+1;
          x->next=NULL;
         
     }
}

void listsub(char *name)
{
     if(start2==NULL)
     {
        start2=&n5[count5++];
        start2->next=NULL;
        strcpy((start2->name),(name));
        start2->code=1;
     }
     else
     {
        y=start2;
        while(y!=NULL)
         {
                       if(!strcmp((y->name),(name)))
                       {
                           return;
                       }
                       else
                       {
                           y1=y;
                           y=y->next;
                       }
          }
          y1->next=&n5[count5++];
          y=y1->next;
          strcpy((y->name),(name));
          y->code=y1->code+1;
          y->next=NULL;
     }
}

void listcls(char *name)
{
     if(start3==NULL)
     {
        start3=&n6[count6];
        n6[count6].next=NULL;
        strcpy((start3->name),(name));
        n6[count6++].code=1;
     }
     else
     {
         z=start3;
         while(z!=NULL)
         {
                       if(!strcmp((z->name),(name)))
                       {
                           return;     
                       }
                       else
                       {
                           z1=z;
                           z=z->next;
                       }
          }
          z1->next=&n6[count6++];
          z=z1->next;
          strcpy((z->name),(name));
          z->code=z1->code+1;
          z->next=NULL;
     }
}

void addcls(char *name)
{
     
	if(startcls==NULL)
	{
          b->cls_link=&n1[count3++];
          startcls=&n1[count3];
          c=startcls;
          strcpy((startcls->name),(name));
          n1[count3].code=searchcls(start3, name);
          n1[count3].link=NULL;
    }
    else
    {
        c=startcls;
        while((c->link)!=NULL)
        {
         c=c->link;
        }
        c->link=&n1[count3++];
        c=c->link;
        strcpy((c->name),(name));
        c->code=searchcls(start3, name);
        c->link=NULL;
    }
    addact(a,b,c);
 }

void addsub(char *name)
{
	if(startsub==NULL)
	{
          startsub=&n2[count2];
          a->sub_link=&n2[count2];
          b=&n2[count2];
          strcpy((b->name),(name));
          b->code=searchsub(start2, name);
          b->link=NULL;
          b->cls_link=NULL;
          count2++;
    }
    else
    {
        b=startsub;
        while(b->link!=NULL)
        {
          b=b->link;
        }
        b->link=&n2[count2];
        b=b->link;
        strcpy((b->name),(name));
        b->code=searchsub(start2, name);
        b->link=NULL;
        b->cls_link=NULL;
        count2++;
     }
    
}
void addfac(char *name)
{
    startfac=start;
 	if(startfac==NULL)
	{
        startfac=&n3[count1];
        a=&n3[count1];
        strcpy((a->name),(name));
        n3[count1].code=searchfac(start1, name);
        n3[count1].link=NULL;
        n3[count1++].sub_link=NULL;
    }
    else
    {
        a=startfac;
        while(a->link!=NULL)
        {
          a=a->link;
        }
        a->link=&n3[count1];
        a=a->link;
        strcpy((a->name),(name));
        a->code=searchfac(start1, name);
        a->link=NULL;
        a->sub_link=NULL;
        count1++;
    }
}

void fac1()
{
     int i=0;
     char facname[3];
     ch=getc(fp);
     ch=getc(fp);
     while(ch!=';')
      {
                    
        facname[i]=ch;
        ch=getc(fp);
        i++;
      }
     facname[i]=NULL;  
	 listfac(facname);
	 addfac(facname);
	 sub1();
}

void sub1()
{
     int i=0;
     char subname[20];
     ch=getc(fp);
     while(ch!=',')
      {
        subname[i]=ch;
        ch=getc(fp);
        i++;
      }
     subname[i]=NULL;  
	 listsub(subname);
	 addsub(subname);
     cls1();
}

void cls1()
{
     int i=0;
     char clsname[20];
     ch=getc(fp);
     while(ch!=';'&&ch!=':'&&ch!=','&&ch!=EOF)
      {
        clsname[i]=ch;
        ch=getc(fp);
        i++;
      }
     clsname[i]=NULL;
     char mmm=clsname[i-1];
     clsname[i-2]=NULL;
     no_of_act=mmm;
     if(ch==',')
      {
	     listcls(clsname);
	     addcls(clsname);
	     cls1();
      }
     else if(ch==';')
      {
         listcls(clsname);
         addcls(clsname);
         sub1();
      }
    else if(ch==':')
      {
         listcls(clsname);
         addcls(clsname);
         fac1();
      }
    else if(ch==EOF)
      {
         listcls(clsname);
         addcls(clsname);
      }
    else
     {
     }
}

void Allocation::create()
{
     for(int i=0;i<99;i++)
     {
         for(int j=0;j<6;j++)
         {
              for (int k=0;k<8;k++)
              {
                    fact_t[i][j][k]=-1;
              }
         }
     }
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<6;j++)
         {
              for (int k=0;k<8;k++)
              {
                     lroom_t[i][j][k]=-1;
              }
         }
     }
     for(int i=0;i<11;i++)
     {
         for(int j=0;j<6;j++)
         {
              for (int k=0;k<8;k++)
              {
                   room_t[i][j][k]=-1;
              }
         }
     }
     for(int i=0;i<16;i++)
     {
          for(int j=0;j<6;j++)
          {
               for (int k=0;k<9;k++)
               {
                   if(k==8)
                   batch_t[i][j][k]=0;
                   else
                   batch_t[i][j][k]=-1;
               }
           }
     }
}

int kul;

void Allocation::print()
{
     int i,j,k;
     for(i=0;i<16;i++)
     {
         for(j=0;j<6;j++)
         {
             for(k=0;k<9;k++)
             {
                 cout<<batch_t[i][j][k]<<" ";
             }
             cout<<"\n";
         }
         cout<<"\n";
     }
getch();
}

int Allocation::algo(int cond)
{
    int ret;
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds) ;
    do
     {
      int k; 
      kul=0;
      for(k=0;k<5000;k++)
      {
         if(arr[k]!=0)
         {
           kul++;
         }
         else
         {
         break;
         }
      }     
     k=rand()% kul;     
     int ca=arr[k];
     int temp=ca;
     batch=ca%100;  
     ca=ca/100;
     subject=ca%100;     
     ca=ca/100;
     faculty=ca;     
     if(cond==0)
     {
        ret=allow.algo1(k);
     }
     else
     {
        ret=allow1.algo1(k);
     }
     if(ret==0)
     {
        break;
     }
    }
     while(arr[0]!=0);
      if(ret==0)
      {
        return 0;
      }
     else
     {
        return 1;
     }
}

int Allocation::algo1(int t)
{
     int temp=1;
     time_t seconds;
     time(&seconds);
     srand((unsigned int) seconds);
     while(temp<1000)
     {
                     q2=start2;
                     for(int g=0;g<subject-1;g++)
                     {
                             q2=q2->next;
                     }
        if(q2->name[0]=='L')
        {
        if(temp<500)
        {
            temp++;
        int l=rand()%24;
        int day;
        int slot;
        if(l%4!=0)
         {
            day=(l/4)+1 ;
         }
        else
         {
            if(l!=0)
             {
               day=l/4;
               slot=4;
             }
             else
              {
                day=1;
                slot=1;
              }
          }
          if(l%4!=0)
          {
             slot=(l%4);
          }
          if(fact_t[faculty-1][day-1][slot-1]==-1)
          {
                                                        
          }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;         
                                 
        }
        else if(temp>=500&&temp<700)
        {
             temp++;
        int l=rand()%35;
        int day;
        int slot;
        if(l%6!=0)
         {
            day=(l/6)+1 ;
         }
        else
         {
            if(l!=0)
             {
               day=l/6;
               slot=6;
             }
             else
              {
                day=1;
                slot=1;
              }
          }
          if(l%6!=0)
          {
             slot=(l%6);
          }
          if(fact_t[faculty-1][day-1][slot-1]==-1)
          {
                                                        
          }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;         
        }
        else if(temp>=700&&temp<900)
        {
          temp++;
          int l=rand()%40;
          int day;
          int slot;
          if(l%7!=0)
          {
             day=(l/7)+1 ;
          }
          else
          {
            if(l!=0)
             {
               day=l/7;
               slot=7;
             }
             else
              {
                day=1;
                slot=1;
              }
           }
           if(l%7!=0)
           {
             slot=(l%7);
           }
           if(fact_t[faculty-1][day-1][slot-1]==-1)
           {
                                                        
           }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==8||slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;          
      }
      else
        {
          temp++;
          int l=rand()%45;
          int day;
          int slot;
          if(l%8!=0)
          {
             day=(l/8)+1 ;
          }
          else
          {
            if(l!=0)
             {
               day=l/8;
               slot=8;
             }
             else
              {
                day=1;
                slot=1;
              }
           }
           if(l%8!=0)
           {
             slot=(l%8);
           }
           if(fact_t[faculty-1][day-1][slot-1]==-1)
           {
                                                        
           }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==8||slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;          
      }
      }
      else
      {
          if(temp<500)
        {
            temp++;
        int l=rand()%35;
        int day;
        int slot;
        if(l%6!=0)
         {
            day=(l/6)+1 ;
         }
        else
         {
            if(l!=0)
             {
               day=l/6;
               slot=6;
             }
             else
              {
                day=1;
                slot=1;
              }
          }
          if(l%6!=0)
          {
             slot=(l%6);
          }
          if(fact_t[faculty-1][day-1][slot-1]==-1)
          {
                                                        
          }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;         
                                 
        }
        else if(temp>=500&&temp<800)
        {
             temp++;
        int l=rand()%40;
        int day;
        int slot;
        if(l%7!=0)
         {
            day=(l/7)+1 ;
         }
        else
         {
            if(l!=0)
             {
               day=l/7;
               slot=7;
             }
             else
              {
                day=1;
                slot=1;
              }
          }
          if(l%7!=0)
          {
             slot=(l%7);
          }
          if(fact_t[faculty-1][day-1][slot-1]==-1)
          {
                                                        
          }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;         
        }
        else
        {
          temp++;
          int l=rand()%45;
          int day;
          int slot;
          if(l%8!=0)
          {
             day=(l/8)+1 ;
          }
          else
          {
            if(l!=0)
             {
               day=l/8;
               slot=8;
             }
             else
              {
                day=1;
                slot=1;
              }
           }
           if(l%8!=0)
           {
             slot=(l%8);
           }
           if(fact_t[faculty-1][day-1][slot-1]==-1)
           {
                                                        
           }
          else 
          {
             continue;
          }
          if(batch_t[batch-1][day-1][slot-1]==-1)
          {
          }
          else
          { 
            continue;
          }
          if(slot==4)
          {
            if(batch_t[batch-1][day-1][4]==-1)
             {
                batch_t[batch-1][day-1][4]=0;                                               
             }
             else
             {
                continue;
             }
           }
             if(slot==5)
             {
                if(batch_t[batch-1][day-1][3]==-1)
                 {
                    batch_t[batch-1][day-1][3]=0;
                 }
                else 
                {
                    continue;
                }
              }
              q2=start2;
       while(q2->code!=subject)
       {
         q2=q2->next;
       }
       int room=-1;
       if(q2->name[0]!='P')
       {
          if(batch_t[batch-1][day-1][8]==5)
            continue;
          int l=0;
          for(int k=0;k<8;k++)
          {
             if(((batch_t[batch-1][day-1][k]/100)%100)==subject)
             {
                l=1;
                break;
             }
          }
          if(l==1)
           continue;
          room=-1;
          for(int temp3=0;temp3<11;temp3++)
          {
            if(room_t[temp3][day-1][slot-1]==-1)
            {
              room=temp3;
              break;
            }
          }
          if(room==-1)
          {
              continue;
          }
     }
     else
     {     
        if((slot==8||slot==4)||(batch_t[batch-1][day-1][slot]!=-1)||(fact_t[faculty-1][day-1][slot]!=-1))
        continue;
        room=-1;
        for(int temp3=0;temp3<4;temp3++)
        {
           if(lroom_t[temp3][day-1][slot-1]==-1)
             {
                room=temp3;
                break;
             }
        }
           if(room==-1)
           {
              continue;
           }
      }
      if(q2->name[0]!='P')
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           if(q2->name[0]=='L')
           batch_t[batch-1][day-1][8]=batch_t[batch-1][day-1][8]+1;
           room_t[room][day-1][slot-1]=arr[t];
       }
      else
       {
           fact_t[faculty-1][day-1][slot-1]=arr[t];
           fact_t[faculty-1][day-1][slot]=arr[t];
           batch_t[batch-1][day-1][slot-1]=arr[t];
           batch_t[batch-1][day-1][slot]=arr[t];
           lroom_t[room][day-1][slot-1]=arr[t];
           lroom_t[room][day-1][slot]=arr[t];
        }
       int temp4=t;
       do
        {
            arr[temp4]=arr[temp4+1];
            temp4++;
        }
       while(arr[temp4]!=0);
      kul=0;          
      }
      }   
      break;
     }
     if(temp<1000)
     {
       return 1;
     }
     else
     {    
       return 0;
     }
}
int Allocation::fitness()
{
     int currentact,currentsub;
     tfitness=0;
     char c;

     for(int i=0;i<16;i++)
     {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<8;k++)
            {
               currentact=batch_t[i][j][k];
               currentsub=(currentact/100)%100;
               q2=start2;                       
               for(int l=1;l<currentsub;l++)
               {
                q2=q2->next;
               }
                c=q2->name[0];
               if(c=='L'&&k<=4)
               {
                  tfitness=tfitness+10;
               }
               if(c=='L'&&k==5)
               {
                  tfitness=tfitness-1;
               }
               if(c=='L'&&k==6)
               {
                  tfitness=tfitness-2;
               }
               if(c=='L'&&k==7)
               {
                  tfitness=tfitness-2;
               }
               if(c!='L'&&(k==5||k==6))
               {
                  tfitness=tfitness+3;
               }
               if(c!='L'&&k==7)
               {
                  tfitness=tfitness-1;
               }
               if(c!='L'&&k<4)
               {
                  tfitness=tfitness-10;
               }
               if(currentact==-1)
               {
                  if(k>=0&&k<=2)
                  {
                  tfitness=tfitness-10;
                  }
                  if(k==5)
                  {
                  tfitness=tfitness-3;
                  }
               }
          }
     }
}    
int currentfact;
int currentact1;
int currentact2;
int currentact3;
int currentsub1;
int currentsub2;
int currentsub3;

char c1,c2,c3;

for(int i=0;i<16;i++)
{
    for(int j=0;j<6;j++)
    {
       for(int k=0;k<6;k++)
       {
           currentact1=fact_t[i][j][k];
           currentact2=fact_t[i][j][k+1];
           currentact3=fact_t[i][j][k+2];
           if(currentact1!=-1&&currentact2!=-1&&currentact3!=-1)
           {
                currentsub1=(currentact1/100)%100;
                currentsub2=(currentact2/100)%100;
                currentsub3=(currentact3/100)%100;
                q2=start2;                       
                for(int l=1;l<currentsub1;l++)
                {
                  q2=q2->next;
                }
                c1=q2->name[0];
                q2=start2;                       
                for(int l=1;l<currentsub2;l++)
                {
                  q2=q2->next;
                }
                c2=q2->name[0];
                q2=start2;                       
                for(int l=1;l<currentsub3;l++)
                {
                  q2=q2->next;
                }
                c3=q2->name[0];
                if(c1=='L'&&c2=='L'&&c3=='L')
                 {
                    return -1;
                 }
             }
        }
    }
}
return tfitness;
}

void allocate()
{
     int i;
     for(i=0;i<5000;i++)
     {
       arr[i]=0;
     }
       fp=fopen("D:\database3.txt","r");
   	  if(fp == NULL)
      {
        printf("File does not exist,please check!\n");
      }
      else
      {
        printf("we are connected to the file!\n");
      }
      fac1();    

      q1=start1;
      q2=start2;
      q3=start3;

      while(q1!=NULL) 
      {
        xx1++;
        cout<<q1->name<<" "<<q1->code<<"\n";
        q1=q1->next;
      }
      while(q2!=NULL)
      {
        xx2++;
        cout<<q2->name<<" "<<q2->code<<"\n";
        q2=q2->next;
      }
      while(q3!=NULL)
      {
        xx3++;
        cout<<q3->name<<" "<<q3->code<<"\n";
        q3=q3->next;
      }
      i=0;
      int arr2[5000];
      while(arr[i]!=0)
      {
        arr2[i]=arr[i];
        i++;
      }
      fclose(fp);
      int ret,ret1;
      kul=i;
      int kuldeep=0;
      int prashant=0;
      int kuld=1,prash=1;
      int generation=0;
      while(generation<1000)
      {
        cout<<"generation no. "<<generation<<"\n";
        generation++; 
        if(kuld==1)
        {
          do
          {
            i=0;
            while(arr2[i]!=0)
            {
              arr[i]=arr2[i];
              i++;
            }
            kul=i;
            allow.create();
            ret=allow.algo(0);
          }
          while(ret==0);
        }
        if(prash==1)
         {
           do
           {
            i=0;
            while(arr2[i]!=0)
            {
              arr[i]=arr2[i];
              i++;
            }
            kul=i;
            allow1.create();
            ret1=allow1.algo(1);
           }
           while(ret1==0);
         }
         kuldeep=allow.fitness();
         prashant=allow1.fitness();
         if(kuldeep>prashant)
          {
             prash=1;
             kuld=0;
          }
          else
          {
            kuld=1;
            prash=0;
          }
       }
      if(kuldeep>prashant)
      {
        allow.print();
        cout<<"fitness is "<<kuldeep;
      }
      else
      {
         allow1.print();
         cout<<"fitness is "<<prashant;
      }
  getch();
}
