/*
ID: paramak1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>

int gsearch(char a[],char b[][15],int np)
{
    int i;
    for(i=0;i<np;i++)
        if(strcmp(a,b[i]) == 0)
        {
//            printf("inside gsearch --> %s %s %d\n",a,b[i],i);
//            printf("exiting gsearch\n");
            return i;
        }
}

int main(void)
{
    int i,np,ac[10],cg,ngi,mo,j,a,x;
    char peop[10][15],cgc[15],temp[15];
    FILE *in,*out;
    int debug;
    
    in = fopen("gift1.in","r");
    out = fopen("gift1.out","w");
    
    // scaning the people in
    fscanf(in,"%d\n",&np);
//    printf("np=%d\n",np);
    for(i=0;i<np;i++)
    {
        fgets(peop[i],15,in);
        ac[i] = 0;
//        printf("peop[%d]=%s",i,peop[i]);
    }

    // acount transactions
    for(i=0;i<np;i++)
    {
        fgets(cgc,15,in);
        cg = gsearch(cgc,peop,np);
//        printf("%d\n",cg);
        fscanf(in,"%d %d\n",&mo,&ngi);        
//        printf("mo=%d, ngi=%d\n",mo,ngi);
        
        if(ngi != 0)
        {
            
            ac[cg] = ac[cg] - mo;
            ac[cg] = ac[cg] + (mo%ngi);
        }


        for(j=0;j<ngi;j++)
        {
            fgets(temp,15,in);
            x = gsearch(temp,peop,np);
            if(ngi != 0)
                ac[x] = ac[x]+(mo/ngi);

        }
    }
    for(i=0;i<10;i++)
        for(a=0;a<15;a++)
            if(peop[i][a] == 10)
                peop[i][a] = 0;
    
    
    for(i=0;i<np;i++)
    {
        fputs(peop[i],out);
        fprintf(out," %d\n",ac[i]);
    }

    fclose(in);
    fclose(out);

    return 0;
}
