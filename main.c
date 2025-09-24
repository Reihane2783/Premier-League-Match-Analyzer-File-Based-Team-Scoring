#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct play{
char HomeName[20];
char GuestName[20];
int Hgole;
int Ggole;}p[8];

struct team{
char club[20];
int MP;
int W;
int L;
int D;
int GF;
int GA;
int GD;
int Pts;} t[16];
void Stats(int i,char *p,int goalsFor, int goalsAgainst) {
    strcpy(t[i].club,p);
    t[i].MP=1;
    t[i].GF += goalsFor;
    t[i].GA += goalsAgainst;
   t[i].GD = t[i].GF - t[i].GA;
    if (goalsFor > goalsAgainst) { // win
        t[i].W++;
        t[i].Pts += 3;
    } else if (goalsFor == goalsAgainst) { // draw
        t[i].D++;
        t[i].Pts++;
    } else { // loss
        t[i].L++;}}

int main()
{FILE *f, *f2;
f=fopen("C:\\Users\\RAD-SYSTEM\\Desktop\\f\\play1.txt","r");
if(f==NULL)  printf("something1 went wrong\n");
    else
     {printf("file1 has opened\n");
if((f!=NULL))
{for (int i=0;i<8;i++)
{fscanf(f,"%s %s %9d %9d \n",p[i].HomeName,p[i].GuestName,&p[i].Hgole,&p[i].Ggole);
printf("%15s %12s %9d %9d \n",p[i].HomeName,p[i].GuestName,p[i].Hgole,p[i].Ggole);}}
for (int i=0;i<8;i++)
        {Stats(2*i,p[i].HomeName,p[i].Hgole,p[i].Ggole);
         Stats((2*i+1),p[i].GuestName,p[i].Ggole,p[i].Hgole);}

f2=fopen("C:\\Users\\RAD-SYSTEM\\Desktop\\f\\team.txt","w+");
  if(f2==NULL)  printf("something went wrong\n");
     else
        {printf("file2 has created\n");
        fputs("club\t\t\t MP W L D GF GA GD Pts\n",f2);
for(int i=0;i<16;i++)
fprintf(f2,"%s \t\t %d %d %d %d %d %d %d %d\n",t[i].club,t[i].MP,t[i].W,t[i].L,t[i].D,t[i].GF,t[i].GA,t[i].GD,t[i].Pts);

fclose(f);
fclose(f2);
return 0;}}}
