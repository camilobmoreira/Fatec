#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparacao(int S1, int S2)
{
    int flag=2;
    if (S1 < S2) flag=0;
    if (S1 > S2) flag=1;
    return flag;
}

void main(){
    int grupo, i, pos, v[12];
    srand ((unsigned) time(NULL));
    pos=rand()%12;
    for(i=0;i<12;i++)
        if(i!=pos) v[i]=5;
        else v[i]=4;
    grupo=4;
    i=grupo*comparacao(v[0]+v[1]+v[2]+v[3],v[4]+v[5]+v[6]+v[7]);
    grupo=2;
    i=i+grupo*comparacao(v[i]+v[i+1],v[i+2]+v[i+3]);
    printf("\nA bolinha com menor peso esta na posição: %d",i+comparacao(v[i],v[i+1]));
    printf ("\n\n*******************\n");
    for(i=0;i<12;i++) printf("v[%d] = %d\t",i,v[i]);
    getch();
}
