#include"header.h"

int n;
int compliment(string s)
{
    int b[100]={0},sum=0,n=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    for(int i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                b[j]=0;
            else
                b[j]=1;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                sum+=pow(2,j);
    }
    return sum;
}
void rlc(string &s)
{
    int b[20],sum=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    int tmp=b[0];
    for(int i=0;i<(l*4);i++)
    {
        b[i]=b[i+1];
    }
    b[7]=tmp;
    for(int i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                sum+=pow(2,j);
    }
    s=dectohex(sum);
}

void rrc(string &s)
{
    int b[20],sum=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    int tmp=b[7];
    for(int i=(l*4)-1;i>0;i--)
    {
        b[i]=b[i-1];
    }
    b[0]=tmp;
    for(int i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                sum+=pow(2,j);
    }
    s=dectohex(sum);
}

void ral(string &s,int &CF)
{
    int b[100]={0},sum=0,n=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    int i;
    int tmp=b[0];
    for( i=0;i<(l*4)-1;i++)
    {
        b[i]=b[i+1];
    }
    b[i]=CF;
    CF=tmp;
    for(int i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                sum+=pow(2,j);
    }
    s=dectohex(sum);
}

void rar(string &s,int &CF)
{
     int b[100]={0},sum=0,n=0;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    int i;
    int tmp=b[7];
    for( i=l*4;i>0;i--)
    {
        b[i]=b[i-1];
    }
    b[0]=CF;
    CF=tmp;
    for(int i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {
        if(b[j]==1)
            sum+=pow(2,j);
    }
    s=dectohex(sum);
}
void ana(string &a, string b)
{
    int temp1 = hextodec(a);
    int temp2 = hextodec(b);
    temp1 = temp1 & temp2;
    a = dectohex(temp1);
}

void ani(string &a, string b)
{
    int temp1 = hextodec(a);
    int temp2 = hextodec(b);
    temp1 = temp1 & temp2;
    a = dectohex(temp1);
}

void cmp(string a, string b,int flag[])
{
    int CF,ZF,SF;
    int tmp1 = hextodec(a);
    int tmp2 = hextodec(b);
    if(tmp1 > tmp2)
    {
        SF = 0;
        CF = 0;
        ZF = 0;
    }
    else if(tmp1 < tmp2)
    {
        SF = 1;
        CF = 1;
        ZF = 0;
    }
    else
    {
        SF = 0;
        CF = 0;
        ZF = 1;
    }
    flag[0]=SF;
    flag[2]=ZF;
    flag[7]=CF;
}

void stc(int &CF)
{
    CF = 1;
}

void cmc(int &CF)
{
    if(CF == 1)
        CF = 0;
    else
        CF = 1;
}
