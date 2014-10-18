/*
ID: paramak1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <string.h>

int number(char a[],int s)
{
    int i,r=1;

    for(i=0;i<s;i++)
        r = r*((int)a[i]-64);

    return r%47;
}

int main(void)
{
    FILE *x,*y;
    char cmt[10],grp[10];
    int lcmt,lgrp;
    
    x = fopen("ride.in","r");
    y = fopen("ride.out","w");

//    fscanf(x,"%s",cmt);
//    fscanf(x,"%s",grp);
    fgets(cmt,10,x);
    fgets(grp,10,x);

//    printf("%s\n%s\n",cmt,grp);
    lcmt = strlen(cmt);
    lgrp = strlen(grp);

    if(number(cmt,lcmt) == number(grp,lgrp))
        fprintf(y,"GO\n");
    else
        fprintf(y,"STAY\n");

    fclose(x);
    fclose(y);

    return 0;
}
