#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std; 

#define BYTE unsigned char
#define INT unsigned int


INT S[8][64]=
{
    {14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
        0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
        4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
        15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13} ,

    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
        3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
        0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
        13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9},

    {10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
        13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
        13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
        1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},

    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4, 
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},


    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
        14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
        4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
        11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}, 



    {12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11, 
        10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
        9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
        4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}, 

    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
        13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
        1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
        6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},

    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7, 
        1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
        7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
        2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
};

/* INITIAL PERMUTATION (IP) */

INT IP[] = {
    58,50,42, 34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54, 46, 38, 30, 22, 14,6,
    64, 56, 48, 40,32,24, 16, 8,
    57, 49, 41, 33,25,17, 9,1,
    59, 51,43,35,27,19,11,3,
    61,53,45,37,29,21,13, 5,
    63,55, 47,39,31,23,15,7
};

/* REVERSE PERMUTATION (RFP) */

INT RFP[] = {
    8,40,16,48,24,56,32,64,
    7, 39,15,47,23,55,31,63,
    6,38,14,46,22,54,30,62,
    5,37,13,45, 21,53,29,61,
    4,36,12,44,20,52,28,60,
    3, 35, 11,43,19,51,27,59,
    2, 34, 10, 42,18, 50,26,58,
    1,33,9,41, 17, 49, 25,57,
};

INT INV_RFP[] = {
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7,
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8
};

/* E BIT_SELECTION TABLE */
INT E[] = {
    32, 1, 2, 3, 4, 5,
    4, 5,6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17, 
    16, 17, 18, 19, 20, 21, 
    20, 21, 22, 23, 24, 25, 
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};


/* PERMUTATION FUNCTION P */
INT P[] = {
    16, 7, 20, 21, 
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31,10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25,
};


/* Inverse of P */
INT INV_P[] = {
    9, 17, 23, 31,
    13, 28, 2, 18,
    24, 16, 30, 6,
    26, 20, 10, 1,
    8, 14, 25, 3,
    4, 29, 11, 19,
    32, 12, 22, 7,
    5, 27, 15, 21,
};

vector<vector<int>>freq(8,vector<int>(64));
int posS(int val)
{      
    return 16*(2*(val/32)+val%2)+(val/2)%16;
}
void compute_key_set(int s_box, BYTE betaXor[48], BYTE gammaXor[32], BYTE alpha[48])
{
    int k, a, b, g;
    int ind = 6*(s_box-1);
    int ind_g = 4*(s_box-1);

    // alpha corresponding to s-box
    int t = alpha[ind];
    t = (t<<1) | alpha[ind+1];
    t = (t<<1)| alpha[ind+2];
    t = (t<<1)| alpha[ind+3];
    t = (t<<1)| alpha[ind+4];
    t = (t<<1)| alpha[ind+5];
    a = t;


    // beta corresponding to s-box
    t = betaXor[ind];
    t = (t<<1) | betaXor[ind+1];
    t = (t<<1)| betaXor[ind+2];
    t = (t<<1)| betaXor[ind+3];
    t = (t<<1)| betaXor[ind+4];
    t = (t<<1)| betaXor[ind+5];
    b = t;


    // gamma corresponding to s-box
    t = gammaXor[ind_g];
    t = (t<<1) | gammaXor[ind_g+1];
    t = (t<<1)| gammaXor[ind_g+2];
    t = (t<<1)| gammaXor[ind_g+3];
    g = t;



    for(int i = 0; i < 64; i++){ 
        int j=b^i;
        if ((S[s_box-1][posS(i)]^S[s_box-1][posS(j)]) == g)
        {
            k = i^a;
            freq[s_box-1][k]++;
        }
    }

}

int main()
{
    static BYTE L5Xor[32] =  {
        0, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    }; // 04000 0000

    ifstream outfile("binary_output.txt");
    ofstream keyfile,frequency;
    keyfile.open("key_temp.txt",ios::trunc);
    frequency.open("frequency.txt",ios::trunc);

    string s1, s2;

    static BYTE LR_o1[64], LR_o2[64],LR1[64],LR2[64];
    BYTE alpha1[48], betaXor[48], gammaXor_p[32],gammaXor[32];


    string junk;
    getline(outfile,junk);
    while(getline(outfile, s1))
    { 
        getline(outfile, s2);

        // get output
        for (int i = 0; i<64; i++){
            LR_o1[i] = (unsigned char)(int(s1[i])- 48); // output 1
            LR_o2[i] = (unsigned char)(int(s2[i])- 48); // output 2
        }

        // find inv of final reverse permutation
        for (int j = 0; j < 64; j++){
            LR1[j] = LR_o1[INV_RFP[j]-1];
            LR2[j] = LR_o2[INV_RFP[j]-1];
        }

        // take xor with L_5 and invert using P^-1 to get output of S box (Round 6) --> gamma 

        for (int j = 0; j < 32; j++)
            gammaXor_p[j] = LR1[j+32]^LR2[j+32]^L5Xor[j];
        for (int j = 0; j < 32; j++)
            gammaXor[j] = gammaXor_p[INV_P[j]-1];

        // E(L6) ^ E(L6')
        for( int j=0; j < 48; j++) {
            betaXor[j]=LR1[E[j]-1]^LR2[E[j]-1];
            alpha1[j] = LR1[E[j]-1];
        }

        // write keys for the i^th songbox in (i)key.txt

        for(int j=0;j<8;j++)
            compute_key_set(j+1, betaXor, gammaXor, alpha1);
    }

    // Print keys with gaps
    cout<<endl;
    string key;
    for(int i=0;i<8;i++)
    {
        int maxIdx=0,secondMaxIdx=-1;
        for(int j=1;j<64;j++)
        {
            if(freq[i][maxIdx]<freq[i][j])
            {
                secondMaxIdx=maxIdx;
                maxIdx=j;
            }
            else if(secondMaxIdx==-1 || freq[i][secondMaxIdx]<freq[i][j])
            {
                secondMaxIdx=j;
            }
        }
        printf("Key %d = %d with frequency =  %d with frequency gap = %d\n",i+1,maxIdx,freq[i][maxIdx],freq[i][maxIdx]-freq[i][secondMaxIdx]);
        frequency<<"Key "<<i+1<<" = "<<maxIdx<<" with frequency = "<<freq[i][maxIdx]<<" with frequency gap = "<<freq[i][maxIdx]-freq[i][secondMaxIdx]<<endl;
        if(freq[i][maxIdx]-freq[i][secondMaxIdx]>=30)
            key+=bitset<6>(maxIdx).to_string();
        else key+=string(6,'X');
    }
    cout<<"\nCorresponding key: "<<key<<endl;
    frequency<<"\nCorresponding key: "<<key<<endl;
    keyfile<<key<<endl;
    outfile.close(); 
    frequency.close(); 

}
