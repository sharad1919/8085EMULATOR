#include<iostream>
#include <sstream>
#include <string>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<map>
#include<iterator>

using namespace std;

class program
{
    public:
            string memloc,inst;
};

void help();
void mov(string &a, string b);
string mvi(string  &a, string data);
void lda(string &a, string data);
void sta(string a, string loc);
void lhld(string &l, string &h, string loc);
void shld(string l, string h, string loc);
void in(string &a, string loc);
void out(string a, string loc);
void lxi(string &h, string &l, string loc);
void xchg(string &d, string &e, string &h, string &l);
int hextodec(string s);
string dectohex(int i);
int compliment(string s);
void rlc(string &s);
void rrc(string &s);
void ral(string &s,int &CF);
void rar(string &s,int &CF);
void ana(string &a, string b);
void ani(string &a, string b);
void cmp(string a, string b,int flag[]);
int jump(program ob[],string s);
string instructionsize(string cmd);
int toint(string a);
string tostring(int a);
void xthl(string &h, string &l,string stack[],int &n);
void push(string v,string stack[],int &n);
string pop(string stack[],int &n);
void sphl(string h, string l, string sp[]);
void stc(int &CF);
void cmc(int &CF);
int subcarry(string A,string B);
int addcarry(int *res);
string checkstr(string s);
void zerosignparity(string s,int a[]);
void sets(string loc, string data);
string dectohexmem(int i);

