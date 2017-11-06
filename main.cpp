#include"header.h"

//Driver function
map <string,string> mem;
map <string,string>::iterator iter;
int main(int argc, char *argv[])
{
    string  A = "25", B = "25" , C = "30" , D = "40", E= "50" , F = "60", H = "70" , L = "80", M = "3050";
    string sp[2], arg1, arg2, arg3;
    string s, stacks[20], psw = "";
//    memory ob[20];
    program pg[20];
    int num=0, i = 0, j =0, flag[10], SF=0, ZF=0, PF=0, AF=0, CF=0, n=0;
    string subs,gdb="";
    string cmd[5];
    ifstream fin;

    int debugger=0, cof=0;
    if(argc == 3)
    {
        string str = argv[2];
        if(str == "debugger")
        {
            debugger = 1;
        }
    }
    else if(argc == 2)
    {
        string str = argv[1];
        if(str == "debugger")
        {
            debugger = 1;
            cof = 1;
        }
    }
    cout<<"ASSEMBLY LANGUAGE CODE :"<<endl<<endl;
    string location = "0000";
    string byte = "0";
    int k = 0;
    if(cof==1 || argc==1)
    {
        while(s != "HLT")
        {
            int str = hextodec(location) + hextodec(byte);
            pg[k].memloc = dectohexmem(str);
            location = dectohex(str);
            cout<<pg[k].memloc<<" ";
            getline(cin,s);
            pg[k].inst = s;
            k++;
            i = 0;
            istringstream iss(s);
            do
            {
                string subs;
                iss >> subs;
                cmd[i++] = subs;
            } while (iss);
            byte = instructionsize(cmd[0]);
        }
    }
    else
    {
        fin.open(argv[1]);
        if(!fin)
        {
            cout<<"Error:File Not Found"<<endl;
            return 0;
        }
        while(s!="HLT")
        {

            getline(fin,s);
            pg[k].inst = s;
            int str =hextodec(location) + hextodec(byte);
            pg[k].memloc = dectohexmem(str);
            location = dectohex(str);
            cout<<pg[k].memloc<<"   "<<s<<endl;
            k++;
            i = 0;
            istringstream iss(s);
            do
            {
                string subs;
                iss >> subs;
                cmd[i++] = subs;
            }while (iss);
            byte = instructionsize(cmd[0]);
        }
        fin.close();
    }
    M = H + L;
    s = "";
    int index = 0, p=0,br[10]={0},nof=0,brk=0;
    while(s != "HLT")
    {
        s = pg[index].inst;
        if((debugger==1 && index==num )||gdb.substr(0,5)=="break" ||p==1||gdb[0]=='b')
        {
            getline(cin,gdb);
            if(gdb=="run" || gdb=="r")
            {
                p=0;
            }
            else if(gdb == "help")
            {
                p=1;
                help();
            }
            else if(gdb == "quit"|| gdb=="q")
            {
                    debugger = 0;
                    p=0;
            }
            else if(gdb.substr(0,5)=="print" || gdb[0]=='p')
            {
                p=1;
                if(gdb.length() > 6)
                {
                    int l = gdb.length()-5-1;
                    string dp = gdb.substr(6, l);
                    if(dp == "A")
                        cout<<"A = "<<A<<endl;
                    else if(dp == "B")
                        cout<<"B = "<<B<<endl;
                    else if(dp == "C")
                        cout<<"C = "<<C<<endl;
                    else if(dp == "D")
                        cout<<"D = "<<D<<endl;
                    else if(dp == "E")
                        cout<<"E = "<<E<<endl;
                    else if(dp == "H")
                        cout<<"H = "<<H<<endl;
                    else if(dp == "L")
                        cout<<"L = "<<L<<endl;
                    else if(dp=="M")
                        cout<<"M = "<<M<<endl;
                    else
                    {
                        if(mem.find(dp)!=mem.end())
                            cout<<dp<<" "<<mem[dp]<<endl;
                        else
                            cout<<dp<<" "<<"01"<<endl;
                    }
                    gdb = '\0';
                }
                else
                {
                    int l = gdb.length()-1-1;
                    string dp = gdb.substr(2, l);
                    if(dp == "A")
                        cout<<"A = "<<A<<endl;
                    else if(dp == "B")
                        cout<<"B = "<<B<<endl;
                    else if(dp == "C")
                        cout<<"C = "<<C<<endl;
                    else if(dp == "D")
                        cout<<"D = "<<D<<endl;
                    else if(dp == "E")
                        cout<<"E = "<<E<<endl;
                    else if(dp == "H")
                        cout<<"H = "<<H<<endl;
                    else if(dp == "L")
                        cout<<"L = "<<L<<endl;
                    else if(dp=="M")
                        cout<<"M = "<<M<<endl;
                    else
                    {
                        if(mem.find(dp)!=mem.end())
                            cout<<dp<<" "<<mem[dp]<<endl;
                        else
                            cout<<dp<<" "<<"01"<<endl;
                    }
                    gdb = '\0';
                }
            }
            else if(gdb == "step" || gdb == "s")
                     p = 0;
            else if(gdb.substr(0,5) == "break" || gdb[0] == 'b')
            {
                p = 1;
                if(gdb.length() > 6)
                {
                    int l = gdb.length()-5-1;
                    string str = gdb.substr(6, l);
                    stringstream geek(str);
                    geek>>br[brk++];
                }
                else
                {
                    int l = gdb.length()-1 -1;
                    string str = gdb.substr(2, l);
                    stringstream geek(str);
                    geek>>br[brk++];
                }
            }
            if(brk == 1 && nof == 0)
                num = br[nof++];
            else if(brk >= nof && index==num)
                    num = br[nof++];
        }
        if(p == 0)
        {
                cout<<s<<endl;
                if(gdb =="s" ||gdb == "step")
                    p = 1;
                index++;
                flag[0] = SF;
                flag[2] = ZF;
                flag[4] = AF;
                flag[6] = PF;
                flag[7] = CF;
                if(s == "MOV A,B")
                    mov(A, B);
                else if(s[0] == 'S' && s[1] == 'E' && s[2] == 'T')
                {
                    string a = s.substr(4, 4);
                    string b = s.substr(9,2);
                    mem[a]=b;
                }
                else if(s == "MOV A,C")
                    mov(A, C);
                else if(s == "MOV A,D")
                    mov(A, D);
                else if(s == "MOV A,E")
                    mov(A, E);
                else if(s == "MOV A,H")
                    mov(A, H);
                else if(s == "MOV A,L")
                    mov(A, L);
                else if(s == "MOV B,A")
                    mov(B, A);
                else if(s == "MOV B,C")
                    mov(B, C);
                else if(s == "MOV B,D")
                    mov(B, D);
                else if(s == "MOV B,E")
                    mov(B, E);
                else if(s == "MOV B,H")
                    mov(B, H);
                else if(s == "MOV B,L")
                    mov(B, L);
                else if(s == "MOV C,A")
                    mov(C, A);
                else if(s == "MOV C,B")
                    mov(C, B);
                else if(s == "MOV C,D")
                    mov(C, D);
                else if(s == "MOV C,E")
                    mov(C, E);
                else if(s == "MOV C,H")
                    mov(C, H);
                else if(s == "MOV C,L")
                    mov(C, L);
                else if(s == "MOV D,A")
                    mov(D, A);
                else if(s == "MOV D,B")
                    mov(D, B);
                else if(s == "MOV D,C")
                    mov(D ,C);
                else if(s == "MOV D,E")
                    mov(D, E);
                else if(s == "MOV D,H")
                    mov(D, H);
                else if(s == "MOV D,L")
                    mov(D, L);
                else if(s == "MOV E,A")
                    mov(E, A);
                else if(s == "MOV E,B")
                    mov(E, B);
                else if(s == "MOV E,C")
                    mov(E, C);
                else if(s == "MOV E,D")
                    mov(E, D);
                else if(s == "MOV E,H")
                    mov(E, H);
                else if(s == "MOV E,L")
                    mov(E, L);
                else if(s == "MOV H,A")
                    mov(H, A);
                else if(s == "MOV H,B")
                    mov(H, B);
                else if(s == "MOV H,C")
                    mov(H, C);
                else if(s == "MOV H,D")
                    mov(H, D);
                else if(s == "MOV H,E")
                    mov(H, E);
                else if(s == "MOV H,L")
                    mov(H, L);
                else if(s == "MOV L,A")
                    mov(L, A);
                else if(s == "MOV L,B")
                    mov(L, B);
                else if(s == "MOV L,C")
                    mov(L, C);
                else if(s == "MOV L,D")
                    mov(L, D);
                else if(s == "MOV L,E")
                    mov(L, E);
                else if(s == "MOV L,H")
                    mov(L, H);
                else if(s[0] == 'J' && s[1] == 'M' && s[2] == 'P')
                {
                     string t = s.substr(4,4);
                     k = jump(pg,t);
                     index = k;
                }
                else if(s[0] == 'J' && s[1] == 'C')
                {
                    if(CF == 1)
                    {
                        string t = s.substr(3, 4);
                        k = jump(pg,t);
                        index = k;
                    }
                }
                else if(s[0] == 'J' && s[1] == 'N' && s[2] == 'C')
                {
                     if(CF == 0){
                     string t = s.substr(4,4);
                     k = jump(pg,t);
                     index = k;
                     }
                }
                else if(s[0] == 'J' && s[1] == 'Z')
                {
                    if(ZF == 1)
                    {
                        string t = s.substr(3,4);
                        k = jump(pg,t);
                        index = k;
                    }
                }
                else if(s[0] == 'J' && s[1] == 'N' && s[2] == 'Z')
                {
                    if(ZF == 0)
                    {
                        string t=s.substr(4,4);
                        k=jump(pg,t);
                        index = k;
                    }
                }
                else if(s[0]=='J' && s[1]=='P' && s[2]=='O')
                {
                    if(PF == 0)
                    {
                        string t = s.substr(4,4);
                        k = jump(pg,t);
                        index = k;
                    }
                }
                else if(s[0]=='J' && s[1]=='P' && s[2]=='E')
                {
                    if(ZF == 1)
                    {
                        string t = s.substr(4,4);
                        k = jump(pg,t);
                        index = k;
                    }
                }
                else if(s == "SPHL")
                    sphl(H, L, sp);
                else if(s == "XTHL")
                    xthl(H, L,stacks,n);
                else if(s == "RLC")
                    rlc(A);
                else if(s == "RRC")
                    rrc(A);
                else if(s == "RAL")
                    ral(A,CF);
                else if(s == "RAR")
                    rar(A,CF);
                else if(s == "STC")
                    stc(CF);
                else if(s == "CMC")
                    cmc(CF);
                else if(s[0]=='C' && s[1]=='M' && s[2]=='P' && s[4]!='M')
                {
                        if(s == "CMP B")
                            cmp(A, B, flag);
                        else if(s == "CMP C")
                            cmp(A, C, flag);
                        else if(s == "CMP D")
                            cmp(A, D, flag);
                        else if(s == "CMP E")
                            cmp(A, E, flag);
                        else if(s == "CMP H")
                            cmp(A, H, flag);
                        else if(s == "CMP L")
                            cmp(A, L, flag);
                        CF = flag[7];
                        SF = flag[0];
                        ZF = flag[2];
                }
                else if(s[0] == 'C' && s[1] == 'M' && s[2] == 'P' && s[4] == 'M')
                {
                        if(mem.find(M)!=mem.end())
                        {
                            string d = mem[M];
                            cmp(A, d, flag);
                            CF = flag[7];
                            SF = flag[0];
                            ZF = flag[2];
                        }
                }
                else if(s == "PUSH B")
                {
                    push(C, stacks,n);
                    push(B, stacks,n);
                }
                else if(s == "PUSH D")
                {
                    push(E, stacks,n);
                    push(D, stacks,n);
                }
                else if(s == "PUSH H")
                {
                    push(L, stacks,n);
                    push(H, stacks,n);
                }
                else if(s == "PUSH PSW")
                {
                    psw = tostring(SF) + tostring(ZF) + "0" + tostring(AF) + "0" + tostring(PF) + "0" + tostring(CF) ;
                    string l1 = checkstr(psw.substr(0,4));
                    string l2 = checkstr(psw.substr(4,4));
                    psw = l1 + l2;
                    push(psw, stacks, n);
                    push(A, stacks, n);
                }
                else if(s == "POP PSW")
                {
                    A = pop(stacks,n);
                    psw = pop(stacks,n);
                    string temp = psw;
                    int tmp = CF;
                    ral(temp, CF);
                    SF = CF;
                    ral(temp, CF);
                    ZF = CF;
                    ral(temp, CF);
                    ral(temp, CF);
                    AF = CF;
                    ral(temp, CF);
                    ral(temp, CF);
                    PF = CF;
                    ral(temp, CF);
                    ral(temp, CF);
                    flag[0] = SF;
                    flag[2] = ZF;
                    flag[4] = AF;
                    flag[6] = PF;
                    flag[7] = CF;
                }
                else if(s == "POP B")
                {
                    B = pop(stacks, n);
                    C = pop(stacks, n);
                }
                else if(s == "POP D")
                {
                    D = pop(stacks, n);
                    E = pop(stacks, n);
                }
                else if(s == "POP H")
                {
                    H = pop(stacks, n);
                    L = pop(stacks, n);
                }
                else if(s == "HLT");
                else if(s[0]=='A' && s[1]=='D' && s[2]=='D')
                {
                    int res;
                    if(s[4] == 'B')
                        res = hextodec(A) + hextodec(B);
                    else if(s[4] == 'D')
                        res = hextodec(A) + hextodec(D);
                    else if(s[4] == 'C')
                        res = hextodec(A) + hextodec(C);
                    else if(s[4] == 'E')
                        res = hextodec(A) + hextodec(E);
                    else if(s[4] == 'H')
                        res = hextodec(A) + hextodec(H);
                    else if(s[4] == 'L')
                        res = hextodec(A) + hextodec(L);
                    else if(s[4] == 'M')
                    {
                        if(mem.find(M)!=mem.end())
                        {
                            string d = mem[M];
                            res = hextodec(A) + hextodec(d);
                        }
                    }
                    CF = addcarry(&res);
                    A = dectohex(res);
                    zerosignparity(A, flag);
                    PF = flag[6];
                    ZF = flag[2];
                    SF = flag[0];
                    }
                    else if(s[0]=='A' && s[1]=='D' && s[2]=='C')
                    {
                        int res;
                        if(s[4] == 'B')
                            res = hextodec(A) + hextodec(B) + CF;
                        else if(s[4] == 'D')
                            res = hextodec(A) + hextodec(D) + CF;
                        else if(s[4] == 'C')
                            res = hextodec(A) + hextodec(C) + CF;
                        else if(s[4] == 'E')
                            res = hextodec(A) + hextodec(E) + CF;
                        else if(s[4] == 'H')
                            res = hextodec(A) + hextodec(H) + CF;
                        else if(s[4] == 'L')
                            res = hextodec(A) + hextodec(L) + CF;
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                string d = mem[M];
                                res = hextodec(A) + hextodec(d)+CF;
                            }
                        }
                        CF = addcarry(&res);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                         PF=flag[6];
                         ZF=flag[2];
                         SF=flag[0];
                    }
                    else if(s[0]=='A' && s[1]=='D' && s[2]=='I')
                    {
                        string t = s.substr(4,2);
                        int res = hextodec(A) + hextodec(t);
                        CF = addcarry(&res);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='A' && s[1]=='C' && s[2]=='I')
                    {
                        string t = s.substr(4,2);
                        int res = hextodec(A) + hextodec(t) + CF;
                        CF = addcarry(&res);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='S' && s[1]=='U' && s[2]=='B')
                    {
                        int res;
                        if(s[4] == 'B'){
                           res = abs(hextodec(A) - hextodec(B));
                           CF = subcarry(A, B);
                        }
                        else if(s[4] == 'C'){
                           res = abs(hextodec(A) - hextodec(C));
                           CF = subcarry(A, C);
                        }
                        else if(s[4] == 'D'){
                           res = abs(hextodec(A) - hextodec(D));
                           CF = subcarry(A, D);
                        }
                        else if(s[4] == 'E'){
                           res = abs(hextodec(A) - hextodec(E));
                           CF = subcarry(A, E);
                        }
                        else if(s[4] == 'H'){
                           res = abs(hextodec(A) - hextodec(H));
                           CF = subcarry(A, H);
                        }
                        else if(s[4]=='L'){
                           res = abs(hextodec(A) - hextodec(L));
                           CF = subcarry(A, L);
                        }
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                string d = mem[M];
                                res = abs(hextodec(A) - hextodec(d));
                                CF = subcarry(A,d);
                            }
                        }
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='S' && s[1]=='U' && s[2]=='I')
                    {
                        string t = s.substr(4,2);
                        int res = abs(hextodec(A) - hextodec(t));
                        CF = subcarry(A, t);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='S' &&s[1]=='B'&&s[2]=='I')
                    {
                        string t = s.substr(4,2);
                        int res = abs(hextodec(A) - hextodec(t)) - CF;
                        CF = subcarry(A, t);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0] == 'S' && s[1]=='B' && s[2]=='B')
                    {
                        int res;
                        if(s[4] == 'B'){
                           res = abs(hextodec(A) - hextodec(B)) - CF;
                           CF = subcarry(A, B);
                        }
                        else if(s[4] == 'C'){
                           res = abs(hextodec(A) - hextodec(C)) - CF;
                           CF = subcarry(A, C);
                        }
                        else if(s[4] == 'D'){
                           res = abs(hextodec(A) - hextodec(D)) - CF;
                           CF = subcarry(A, D);
                        }
                        else if(s[4] == 'E'){
                           res = abs(hextodec(A) - hextodec(E)) - CF;
                           CF = subcarry(A, E);
                        }
                        else if(s[4] == 'H'){
                           res = abs(hextodec(A) - hextodec(H)) - CF;
                           CF = subcarry(A, H);
                        }
                        else if(s[4] == 'L'){
                           res = abs(hextodec(A) - hextodec(L)) - CF;
                           CF = subcarry(A, L);
                        }
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                string d = mem[M];
                                res = (hextodec(A) - hextodec(d))- CF;
                            }
                        }
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='I' && s[1] == 'N' && s[2] == 'R')
                    {
                        int res;
                        if(s[4] == 'A'){
                            res = hextodec(A) + 1;
                            CF = addcarry(&res);
                            A = dectohex(res);
                            zerosignparity(A, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else if(s[4] == 'B'){
                            res = hextodec(B) + 1;
                            CF = addcarry(&res);
                            B = dectohex(res);
                            zerosignparity(B, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'C'){
                            res = hextodec(C) + 1;
                            CF = addcarry(&res);
                            C = dectohex(res);
                            zerosignparity(C, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'D'){
                            res = hextodec(D) + 1;
                            CF = addcarry(&res);
                            D = dectohex(res);
                            zerosignparity(D, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                          else  if(s[4] == 'E'){
                            res = hextodec(E) + 1;
                            CF = addcarry(&res);
                            E = dectohex(res);
                            zerosignparity(E, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'H'){
                            res = hextodec(H) + 1;
                            CF = addcarry(&res);
                            H = dectohex(res);
                            zerosignparity(H, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'L'){
                            res = hextodec(L) + 1;
                            CF = addcarry(&res);
                            L = dectohex(res);
                            zerosignparity(L, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                int res = hextodec(M)+1;
                                M = dectohex(res);
                            }
                        }
                    }
                    else if(s[0] == 'D' && s[1] == 'C' && s[2] == 'R')
                    {
                        int res;
                        if(s[4] == 'A'){
                            res = abs(hextodec(A)-1);
                            CF = subcarry(A,"01");
                            A = dectohex(res);
                            zerosignparity(A, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'B'){
                            res = abs(hextodec(B)-1);
                            CF = subcarry(B, "01");
                            B = dectohex(res);
                            zerosignparity(B, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else if(s[4] == 'C'){
                            res = abs(hextodec(C)-1);
                            CF = subcarry(C, "01");
                            C = dectohex(res);
                            zerosignparity(C, flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else if(s[4] == 'D'){
                            res = abs(hextodec(D)-1);
                            CF = subcarry(D,"01");
                            D = dectohex(res);
                            zerosignparity(D,flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                          else if(s[4]=='E'){
                            res = abs(hextodec(E)-1);
                            CF = subcarry(E,"01");
                            E = dectohex(res);
                            zerosignparity(E,flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4] == 'H'){
                            res = abs(hextodec(H)-1);
                            CF = subcarry(H,"01");
                            H = dectohex(res);
                            zerosignparity(H,flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else  if(s[4]=='L'){
                            res = abs(hextodec(L)-1);
                            CF = subcarry(L,"01");
                            L = dectohex(res);
                            zerosignparity(L,flag);
                            PF = flag[6];
                            ZF = flag[2];
                            SF = flag[0];
                        }
                        else if(s[4] == 'M')
                        {
                            int res = abs(hextodec(M)-1);
                            M = dectohex(res);
                        }

                    }
                    else if(s[0] == 'D' && s[1] == 'A' && s[2] == 'A')
                    {
                        int i = 1, res = hextodec(A);
                        while(res>0)
                        {
                            A[i--] = (res%10) + 48;
                            res = res/10;
                        }
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='D' && s[1]=='A' && s[2]=='D')
                    {
                        int res = hextodec(L) + hextodec(E);
                        CF = addcarry(&res);
                        L = dectohex(res);
                        res = hextodec(H)+hextodec(D)+CF;
                        CF = addcarry(&res);
                        H = dectohex(res);
                        zerosignparity(H+L, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0] =='C' && s[1]=='M' && s[2]=='A')
                    {
                        int res = compliment(A);
                        A = dectohex(res);
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                     else if(s[0]=='O' && s[1]=='R' && s[2]=='A')
                    {
                        if(s[4] == 'B')
                        {
                            int res = hextodec(A) | hextodec(B);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'C')
                        {
                            int res = hextodec(A) | hextodec(C);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'D')
                        {
                            int res = hextodec(A)|hextodec(D);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'E')
                        {
                            int res = hextodec(A) | hextodec(E);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'H')
                        {
                            int res = hextodec(A) | hextodec(H);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'L')
                        {
                            int res = hextodec(A) | hextodec(L);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                int res = hextodec(A) | hextodec(mem[M]);
                                A = dectohex(res);
                            }
                        }
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0] =='O' && s[1]=='R' && s[2]=='I')
                    {
                         string t = s.substr(4,2);
                         int res = hextodec(A)|hextodec(t);
                         A = dectohex(res);
                         zerosignparity(A, flag);
                         PF = flag[6];
                         ZF = flag[2];
                         SF = flag[0];
                    }
                    else if(s[0]=='X' && s[1]=='R' && s[2]=='A')
                    {
                        if(s[4] == 'B')
                        {
                            int res = hextodec(A)^hextodec(B);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'C')
                        {
                            int res = hextodec(A)^hextodec(C);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'D')
                        {
                            int res = hextodec(A)^hextodec(D);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'E')
                        {
                            int res = hextodec(A)^hextodec(E);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'H')
                        {
                            int res = hextodec(A)^hextodec(H);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'L')
                        {
                            int res = hextodec(A) ^ hextodec(L);
                            A = dectohex(res);
                        }
                        else if(s[4] == 'M')
                        {
                            if(mem.find(M)!=mem.end())
                            {
                                int res = hextodec(A) ^ hextodec(mem[M]);
                                A = dectohex(res);
                            }
                        }
                        zerosignparity(A, flag);
                        PF = flag[6];
                        ZF = flag[2];
                        SF = flag[0];
                    }
                    else if(s[0]=='X' && s[1]=='R' && s[2]=='I')
                    {
                         string t = s.substr(4,2);
                         int res = hextodec(A)^hextodec(t);
                         A = dectohex(res);
                         zerosignparity(A,flag);
                         PF = flag[6];
                         ZF = flag[2];
                         SF = flag[0];
                    }
                    else if(s[0]=='I' && s[1]=='N' && s[2]=='X')
                    {
                        if(s[4] == 'B')
                        {
                            string t = B+C;
                            int res = hextodec(t);
                            res = res+1;
                            if(res > 65535){
                               CF = 1;
                               res = res-65536;
                            }
                            t = dectohex(res);
                            if(t.length() == 2)
                            {
                                B = "00";
                                C = t.substr(0,2);
                            }
                            else{
                                B = t.substr(0,2);
                                C = t.substr(2,2);
                            }
                        }
                        else if(s[4] == 'D')
                        {

                            string t = D+E;
                            int res = hextodec(t);
                            res = res+1;
                            if(res > 65535){
                               CF = 1;
                               res = res-65536;
                            }
                            t = dectohex(res);
                            if(t.length() == 2)
                            {
                                D = "00";
                                E = t.substr(0,2);
                            }
                            else{
                                D = t.substr(0,2);
                                E = t.substr(2,2);
                            }
                        }
                        else if(s[4] == 'H')
                        {
                            string t = H+L;
                            int res = hextodec(t);
                            res = res+1;
                            if(res > 65535){
                               CF = 1;
                               res = res-65536;
                            }
                            t = dectohex(res);
                            if(t.length() == 2)
                            {
                                H = "00";
                                L = t.substr(0,2);
                            }
                            else{
                                H = t.substr(0,2);
                                L = t.substr(2,2);
                            }
                            M = H + L;
                            if(mem.find(M)==mem.end())
                                mem[M]="00";
                        }
                    }
                    else if(s[0]=='D' && s[1]=='C' && s[2]=='X')
                    {
                        if(s[4] == 'B')
                        {
                            string t = B+C;
                            int res = hextodec(t);
                            res = abs(res-1);
                            t = dectohex(res);
                            if(t.length()==2)
                            {
                                B = "00";
                                C = t.substr(0,2);
                            }
                            else{
                                 B = t.substr(0,2);
                                 C = t.substr(2,2);
                            }
                        }
                        else if(s[4] == 'D')
                        {
                            string t = D+E;
                            int res = hextodec(t);
                            res = abs(res-1);
                            t = dectohex(res);
                            if(t.length()==2)
                            {
                                D = "00";
                                E = t.substr(0,2);
                            }
                            else{
                                 D = t.substr(0,2);
                                 E = t.substr(2,2);
                            }
                        }
                        else if(s[4] == 'H')
                        {
                            string t = H+L;
                            int res = hextodec(t);
                            res = abs(res-1);
                            t = dectohex(res);
                            if(t.length() == 2)
                            {
                                H = "00";
                                L = t.substr(0,2);
                            }
                            else{
                                 H = t.substr(0,2);
                                 L = t.substr(2,2);
                            }
                            M = H + L;
                            if(mem.find(M)==mem.end())
                                mem[M]="00";
                        }
                    }
                else
                {
                    i = 0;
                    istringstream iss(s);
                    do
                    {
                        string subs;
                        iss >> subs;
                        cmd[i++] = subs;
                    } while (iss);
                    if(cmd[0] == "MVI" && cmd[1] == "A")
                        A = mvi(A, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "B")
                        B = mvi(B, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "C")
                        C = mvi(C, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "D")
                        D = mvi(D, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "E")
                        E = mvi(E, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "H")
                        H = mvi(H, cmd[2]);
                    else if(cmd[0] == "MVI" && cmd[1] == "L")
                        L = mvi(L, cmd[2]);
                    else if(cmd[0] == "LDA")
                    {
                        if(mem.find(cmd[1])==mem.end())
                            mem[cmd[1]]="00";
                        A=mem[cmd[1]];
                    }
                    else if(cmd[0] == "STA")
                    {
                        mem[cmd[1]]=A;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'A'&& s[6]=='M')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        A=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'B')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        B=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'C')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        C=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'D')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        D=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'E')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        E=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'H')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        H=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' &&s[2] == 'V' && s[4] == 'L')
                    {
                        if(mem.find(M)==mem.end())
                            mem[M]="00";
                        B=mem[M];
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'A')
                    {
                        mem[M]=A;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'B')
                    {
                        mem[M]=B;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'C')
                    {
                        mem[M]=C;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'D')
                    {
                        mem[M]=D;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'E')
                    {
                        mem[M]=E;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'H')
                    {
                        mem[M]=H;
                    }
                    else if(s[0] == 'M' && s[1] == 'O' && s[2] == 'V' && s[4] == 'M' && s[6] == 'L')
                    {
                        mem[M]=L;
                    }
                    else if(cmd[0] == "LHLD")
                    {
                        if(mem.find(cmd[1])==mem.end())
                            mem[cmd[1]]="00";
                        if(mem.find(dectohex(hextodec(cmd[1])+1))==mem.end())
                            mem[dectohex(hextodec(cmd[1])+1)]="00";
                        L=mem[cmd[1]];
                        H=mem[dectohex(hextodec(cmd[1])+1)];
                    }
                    else if(cmd[0] == "SHLD")
                    {
                        mem[cmd[1]]=L;
                        mem[dectohex(hextodec(cmd[1])+1)]=H;
                    }
                    else if(cmd[0] == "LDAX" && cmd[1] == "B")
                    {
                        if(mem.find(B+C)==mem.end())
                            mem[B+C]="00";
                        A=mem[B+C];
                    }
                    else if(cmd[0] == "LDAX" && cmd[1] == "D")
                    {
                        if(mem.find(D+E)==mem.end())
                            mem[D+E]="00";
                        A=mem[D+E];
                    }
                    else if(cmd[0] == "LDAX" && cmd[1] == "H")
                    {
                        if(mem.find(H+L)==mem.end())
                            mem[H+L]="00";
                        A=mem[H+L];
                    }
                    else if(cmd[0] == "STAX" && cmd[1] == "B")
                    {
                        mem[B+C]=A;
                    }
                    else if(cmd[0] == "STAX" && cmd[1] == "D")
                    {
                        mem[D+E]=A;
                    }
                    else if(cmd[0] == "STAX" && cmd[1] == "H")
                    {
                        mem[H+L]=A;
                    }
                    else if(cmd[0] == "IN")
                    {
                        if(mem.find(cmd[1])==mem.end())
                            mem[cmd[1]]="00";
                        A=mem[cmd[1]];
                    }
                    else if(cmd[0] == "OUT")
                    {
                        mem[cmd[1]]=A;
                    }
                    else if(cmd[0] == "XCHG")
                        xchg(D, E, H, L);
                    else if(cmd[0] == "LXI" && cmd[1] == "H")
                    {
                        if(mem.find(cmd[2])==mem.end())
                            mem[cmd[2]]="01";
                        lxi(H,L,cmd[2]);
                        M = H + L;
                    }
                    else if(cmd[0] == "LXI" && cmd[1] == "B")
                    {
                        if(mem.find(cmd[2])==mem.end())
                            mem[cmd[2]]="01";
                         lxi(B, C, cmd[2]);
                    }
                    else if(cmd[0] == "LXI" && cmd[1] == "D")
                    {
                         if(mem.find(cmd[2])==mem.end())
                            mem[cmd[2]]="01";
                        lxi(D, E, cmd[2]);
                    }
                    else if(cmd[0] == "SET")
                        mem[cmd[1]]=cmd[2];
                    else if(cmd[0]=="ANI" || cmd[0]=="ANA")
                    {
                            if(cmd[0] == "ANI")
                                ani(A, cmd[1]);
                            else if(cmd[0] == "ANA" && cmd[1] == "B")
                                ana(A, B);
                            else if(cmd[0] == "ANA" && cmd[1] == "C")
                                ana(A, C);
                            else if(cmd[0] == "ANA" && cmd[1] == "D")
                                ana(A, D);
                            else if(cmd[0] == "ANA" && cmd[1] == "E")
                                ana(A, E);
                            else if(cmd[0] == "ANA" && cmd[1] == "H")
                                ana(A, H);
                            else if(cmd[0] == "ANA" && cmd[1] == "L")
                                ana(A, L);
                            else if(cmd[0] == "ANA" && cmd[1] == "M")
                            {
                                if(mem.find(M)!=mem.end())
                                {
                                    int res = hextodec(A) & hextodec(mem[M]);
                                    A = dectohex(res);
                                }
                            }
                            zerosignparity(A,flag);
                            PF = flag[6];
                            SF = flag[0];
                            ZF = flag[2];
                    }
                    else if(cmd[0] == "CPI")
                    {
                        cmp(A, cmd[1], flag);
                        PF = flag[6];
                        SF = flag[0];
                        ZF = flag[2];
                    }
                    else
                    {
                        cout<<"Error:Invalid Instruction : "<<s<<endl;
                        break;
                    }
                }
        }
    }
    cout<<endl<<"VALUES IN REGISTERS :"<<endl<<endl;
    cout<<"A = "<<A<<endl;
    cout<<"B = "<<B<<endl;
    cout<<"C = "<<C<<endl;
    cout<<"D = "<<D<<endl;
    cout<<"E = "<<E<<endl;
    cout<<"H = "<<H<<endl;
    cout<<"L = "<<L<<endl;
    cout<<endl<<"VALUES OF FLAGS :"<<endl<<endl;
    cout<<"CARRY FLAG = "<<CF<<endl;
    cout<<"SIGN FLAG = "<<SF<<endl;
    cout<<"AUXILLAY FLAG = "<<AF<<endl;
    cout<<"PARITY FLAG = "<<PF<<endl;
    cout<<"ZERO FLAG = "<<ZF<<endl<<endl;
    if(mem.begin()!=mem.end())
    {
        cout<<"MEMORY LOCATION USED"<<endl<<endl;
        for(iter=mem.begin();iter!=mem.end();iter++)
        {
            cout<<iter->first<<" "<<iter->second<<endl;
        }
    }
    return 0;
}



