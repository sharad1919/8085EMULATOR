#include"header.h"


int hextodec(string s)
{
    int b[20]={0},sum=0,n=0;
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
                sum+=pow(2,j);
    }
    return sum;
}

string dectohex(int i)
{

    char  s[88];
//care@irctc.co.in
    itoa(i,s,16);
    int j;
    for( j=0;s[j]!='\0';j++)
    {
        if(s[j]>96&&s[j]<103)
        {
            s[j]=s[j]-32;
        }
    }

    if(j==1)
    {
        s[1]=s[0];
        s[0]='0';
        s[2] = '\0';
    }
    string str(s);
    return str;
}
string dectohexmem(int i)
{

    char  s[88];
    itoa(i,s,16);
    int j;
    for( j=0;s[j]!='\0';j++)
    {
        if(s[j]>96&&s[j]<103)
        {
            s[j]=s[j]-32;
        }
    }

    if(j==2)
    {
        s[4]='\0';
        s[3]=s[1];
        s[2]=s[0];
        s[0] ='0';
        s[1]='0';
    }
    else if(j==1)
    {
        s[4]='\0';
        s[3]=s[0];
        s[2]='0';
        s[0] ='0';
        s[1]='0';
    }
    string str(s);
    return str;
}
string instructionsize(string cmd)
{
    if(cmd == "MOV"||cmd == "ADD"||cmd == "SBB"||cmd == "CMA"||cmd == "HLT"||cmd == "SUB"||cmd == "STAX"||cmd == "PUSH"||cmd=="XRA"||cmd=="RLC"||cmd=="RRC"||cmd=="RAR"||cmd=="RAL"||cmd=="LDAX"||cmd=="XCHG"||cmd=="ADC"||cmd=="DAD"||cmd == "INX"||cmd=="INR"||cmd=="DAA"||cmd=="DCR"||cmd=="DCX"||cmd=="ORA"||cmd=="ANA"||cmd=="XRA"||cmd=="CMC"||cmd=="STC"||cmd=="CMP"||cmd=="POP"||cmd=="SPHL"||cmd=="XTHL"||cmd == "POP")
        return "1";
    else if(cmd == "ADI" ||cmd == "SBI"||cmd == "MVI"||cmd == "OUT"||cmd == "IN"||cmd=="ACI"||cmd=="SUI"||cmd=="SBI"||cmd=="ORI"||cmd=="ANI"||cmd=="XRI"||cmd=="CPI")
        return "2";
    else
        return "3";
}

int jump(program ob[],string s)
{
    int i=0;
    while(s.compare(ob[i].memloc)!=0)
    {
        i++;
    }
    return i;
}

string tostring(int a)
{
    if(a == 1)
        return "1";
    return "0";
}

int toint(string a)
{
    if(a == "1")
        return 1;
    return 0;
}
int subcarry(string A,string B)
{
     if(hextodec(A)<hextodec(B))
     {
        return 1;
     }
     else
     {
        return 0;
     }
}
int addcarry(int *res)
{
      if(*res>255)
      {
          *res=*res-256;
            return 1;
     }
     else return 0;
}
string checkstr(string s)
{
    if(s == "0000")
        return "0";
    else if(s == "0001")
        return "1";
     else if(s == "0010")
        return "2";
     else if(s == "0011")
        return "3";
     else if(s == "0100")
        return "4";
     else if(s == "0101")
        return "5";
     else if(s == "0110")
        return "6";
    else if(s == "0111")
        return "7";
     else if(s == "1000")
        return "8";
     else if(s == "1001")
        return "9";
     else if(s == "1010")
        return "A";
     else if(s == "1011")
        return "B";
     else if(s == "1100")
        return "C";
     else if(s == "1101")
        return "D";
     else if(s == "1110")
        return "E";
     else if(s == "1111")
        return "F";
}
void zerosignparity(string s,int a[])
{
    int b[100]={0},coun=0,n=0,PF,ZF,SF;
    int l=s.length();
    ZF=0;
    SF=0;
    PF=0;
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
    for(int i=0;i<l*4;i++)
    {
        if(b[i]==1)
            coun++;
    }
    if(coun%2==0)
        PF=1;
    if(coun==0)
        ZF=1;
    if(b[0]==1)
        SF=1;
    a[0] = SF;
    a[2] = ZF;
    a[6] = PF;
}


void help()
{
    cout<<"1. break or b `line no`:- It will set break point on given line number."<<endl;
    cout<<"2. run or r :- Run the program until it ends or breakpoint is encountered."<<endl;
    cout<<"3. step or s :- It will run the program one instruction at a time."<<endl;
    cout<<"4. print or p:- It prints the value of register or memory location. for ex p A will print the value of"<<endl;
    cout<<"register A. p x2500 will print the value at memory location x2500 if any."<<endl;
    cout<<"5. quit or q:- quits the debugger."<<endl;
}
