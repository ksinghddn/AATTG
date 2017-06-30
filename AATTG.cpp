#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ABC.h>

using namespace std;

void searchfac();
void searchsub();
void searchroom(int,int);

int fac,sub,room;
int cact,h=0;


extern int batch_t[16][6][9];
extern int room_t[11][6][8];
extern int lroom_t[4][6][8];

void searchfac()
{
     q1=start1;
     for(int a=0;a<fac-1;a++)
     {
     q1=q1->next;
     }
     
}
void searchsub()
{
     q2=start2;
     for(int a=0;a<sub-1;a++)
     q2=q2->next;
}
void searchroom(int j,int k)
{
     if(q2->name[0]!='P')
     {
        int i;
        for(i=0;i<11;i++)
        {
                if(room_t[i][j][k]==cact)
                break;
        }
        room =301+i;
     }  
     else
     {
         int i;
         for(i=0;i<4;i++)
         {
                         if(lroom_t[i][j][k]==cact)
                         break;
         }
         room=101+(i%4);
     }
}
int main()
{
    allocate();
    ofstream TT("D:\Timetable.txt");
    q3=start3;
    char days[6][3]={{'M','o','n'},{'T','u','e'},{'W','e','d'},{'T','h','u'},{'F','r','i'},{'S','a','t'}};
    
    for(int i=0;i<16;i++)
    {
            for(int r=0;r<30;r++)
            TT<<"___________";
            TT<<"\n\n\n\n\n                                                                                                         "<<q3->name;
            TT<<"\n                                                                                                         ~~~~~~"<<"\n\n";
            TT<<"                      9 - 10                      10 - 11                      11 - 12                      12 - 1                        1 - 2                        2 - 3                        3 - 4                        4 - 5\n\n\n";
            q3=q3->next;
            for(int j=0;j<6;j++)
            {
                    
                    for(int q=0;q<3;q++)
                    {
                            
                           for(int k=0;k<8;k++)
                             {
                                   if(q==0)
                                   { 
                                           if(k==0)
                                           TT<<"                    ";
                                        if(batch_t[i][j][k]!=-1&&batch_t[i][j][k]!=0)
                                            {
                                                cact=batch_t[i][j][k];                                                 
                                                fac=cact/10000;
                                                searchfac();                                  
                                                TT<<q1->name<<"                        ";
                                            }       
                                        else
                                            {
                                                TT<<"FREE                        ";
                                            }
                                            if(k==7)
                                            TT<<"\n";
                                   }
                                   if(q==1)
                                   {
                                           if(k==0)
                                           {
                                                         for(int l=0;l<3;l++)
                                                            {
                                                               TT<<days[j][l];
                                                            }
                                           TT<<"              ";
                                           }
                                           if(batch_t[i][j][k]!=-1&&batch_t[i][j][k]!=0)
                                           {
                                                cact=batch_t[i][j][k];
                                                cact=cact/100;
                                                sub=cact%100;
                                                searchsub();
                                                TT<<q2->name<<"                "; 
                                           }
                                           else
                                           {
                                               TT<<"                                ";
                                           }
                                           if(k==7)
                                           TT<<"\n";                                                                                      
                                   }
                                   if(q==2)
                                   {
                                           if(k==0)
                                           TT<<"                    ";
                                           if(batch_t[i][j][k]!=-1&&batch_t[i][j][k]!=0)
                                           {
                                           cact=batch_t[i][j][k];
                                           sub=(cact/100)%100;
                                           searchsub();
                                           if(q2->name[0]!='P')
                                           searchroom(j,k);
                                           else
                                           {
                                           if(h!=1)
                                           {
                                           
                                           searchroom(j,k);
                                           h=1;
                                           }
                                           else
                                           {
                                               h=0;
                                           }
                                           }
                                           TT<<room<<"                          ";
                                           }
                                           else
                                           {
                                               TT<<"                                ";
                                           }
                                   }
                             }
                             
                    }
                    TT<<"\n\n\n";
            }
    }
   getch();
}
