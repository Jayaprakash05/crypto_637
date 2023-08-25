#include <bits/stdc++.h>
using namespace std;

int IP[] = {
    58,50,42, 34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54, 46, 38, 30, 22, 14,6,
    64, 56, 48, 40,32,24, 16, 8,
    57, 49, 41, 33,25,17, 9,1,
    59, 51,43,35,27,19,11,3,
    61,53,45,37,29,21,13, 5,
    63,55, 47,39,31,23,15,7
};
int INV_IP[] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};
int main(){
    ofstream fileP;
    fileP.open("input.txt",ios::trunc);
    // xor expected after IP(L0R0)
    string xorExp="405C000004000000";
    int expectedXor[64];
    for(int i=0;i<16;i++)
    {
        int dec;
        if(xorExp[i]>='A')
            dec=10+xorExp[i]-'A';
        else dec=xorExp[i]-'0';
        for(int j=0;j<4;j++)
            expectedXor[i*4+j]=(dec>>(3-j))&1;
    }

    int xorL0R0[64];
    for(int i=0;i<64;i++)
        xorL0R0[i]=expectedXor[INV_IP[i]-1];

    for(int i=0;i<64;i++)
        cout<<xorL0R0[i];
    cout<<endl;

    long double probability=0.00038147;
    int gap=30;
    // req= ((3/4)*gap)/p;
    int req=100000;
    for(int i=0;i<req;i++)
    {
        string plaintext[2];
        int LR[2][64];
        for (int j = 0; j < 64; j++){
            LR[0][j]=rand()%2;
            LR[1][j]=xorL0R0[j]^LR[0][j];
        }

        char baseStart='d';
        for(int i=0;i<2;i++)
        {
            for(int j = 0 ; j < 16; j++){
                int hex = LR[i][j*4]*8+LR[i][j*4+1]*4+LR[i][j*4+2]*2+LR[i][j*4+3];
                plaintext[i]+=hex+baseStart;
            }
        }
        fileP<<plaintext[0]<<endl;
        fileP<<"c"<<endl;
        fileP<<plaintext[1]<<endl;
        fileP<<"c"<<endl;
    }
}
