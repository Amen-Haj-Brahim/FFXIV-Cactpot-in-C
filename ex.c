#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int verify(int x,int t[]){
    for (int  i = 0; i < 9; i++)
    {
        if (x==t[i])
        {
            return 1;
        }
    }
    return 0;
}


int seeScore(int m[3][3]){
    int a1,a2,a3,b1,b2,b3,n,l,c,sum;
    int y=(rand()%(9))+1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j]==y)
            {
                printf("%d | ",m[i][j]);
            }
            else{
                printf("x | ");
            }
        }
        printf("\n");
    }
//-----------------------------------------------------------------------
    printf("i?");
    scanf("%d",&a1);
    printf("j?");
    scanf("%d",&b1);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j]==y || (i==a1 && j==b1))
            {
                printf("%d | ",m[i][j]);
            }
            else{
                printf("x | ");
            }
        }
        printf("\n");
    }
//-----------------------------------------------------------------------
    printf("i?");
    scanf("%d",&a2);
    printf("j?");
    scanf("%d",&b2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j]==y || (i==a1 && j==b1) ||(i==a2 && j==b2))
            {
                printf("%d | ",m[i][j]);
            }
            else{
                printf("x | ");
            }
        }
        printf("\n");
    }
//-----------------------------------------------------------------------
    printf("i?");
    scanf("%d",&a3);
    printf("j?");
    scanf("%d",&b3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j]==y || (i==a1 && j==b1) ||(i==a2 && j==b2)||(i==a3 && j==b3))
            {
                printf("%d | ",m[i][j]);
            }
            else{
                printf("x | ");
            }
        }
        printf("\n");
    }
    printf("sum | money\n");
    printf("6  10000\n7  36\n8  720\n9  360\n10  80\n11  252\n12  108\n13  72\n14  54");
    printf("\n15  180\n16  72\n17  180\n18  119\n19  36\n20  306\n21  1080\n22  144\n23  1800\n24  3600");
    printf("\nlines(1) or cols(2)?");
    scanf("%d",&n);
    if (n==1)
    {
        l=-1;
        do
        {
            printf("which line?");
            scanf("%d",&l);
        } while (l>3 && -1>l);
        return m[l][0]+m[l][1]+m[l][2];
    }
    else if(n==2)
    {
        c=-1;
        do
        {
            printf("which col?");
            scanf("%d",&c);
        } while (c>3 && -1>c);
        return m[0][c]+m[1][c]+m[2][c];
    }
}


void makezero(int x,int t[]){
    for (int i = 0; i < 9; i++)
    {
        if (x==t[i])
        {
            t[i]=0;
        }
    }
}


void fill(int m[3][3],int t[]){
    int x;
    srand( (unsigned int) time(NULL));
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            if (i==0 && j==0)
            {
                x=(rand()%(9))+1;
                makezero(x,t);
                m[i][j]=x;
            }
            else{
                do
                {
                    x=(rand()%(9))+1;
                }while(verify(x,t)==0);
                makezero(x,t);
                m[i][j]=x;
            }
            //printf("%d | ",m[i][j]);
        }
        printf("\n");
    }
}


int showmoney(int score){
    switch (score)
    {
    case 6:
        return(10000);
        break;
    case 7:
        return(36);
        break;
    case 8:
        return(720);
        break;
    case 9:
        return(360);
        break;
    case 10:
        return(80);
    case 11:
        return(252);
        break;
    case 12:
        return(108);
        break;
    case 13:
        return(72);
        break;
    case 14:
        return(54);
        break;
    case 15:
        return(180);
        break;
    case 16:
        return(72);
        break;
    case 17:
        return(180);
        break;
    case 18:
        return(119);
        break;
    case 19:
        return(36);
        break;
    case 20:
        return(306);
        break;
    case 21:
        return(1080);
        break;
    case 22:
        return(144);
        break;
    case 23:
        return(1800);
        break;
    case 24:
        return(3600);
        break;
    default:
        break;
    }
}


int play(){
    int t[9]={1,2,3,4,5,6,7,8,9};
    int m[3][3];
    int score;
    fill(m,t);
    score=seeScore(m);
    printf("your score:%d\n",showmoney(score));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d |",m[i][j]);
        }
        printf("\n");
    }
}
