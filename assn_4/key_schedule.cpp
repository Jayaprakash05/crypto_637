#include<bits/stdc++.h>
using namespace std;

int PC1[] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15, 
    7, 62, 54, 46, 38, 30, 22, 
    14,  6, 61, 53, 45, 37, 29, 
    21, 13,  5, 28, 20, 12,  4
};


int PC2[] = {
    14, 17, 11, 24,  1, 5, 
    3, 28 ,15,  6, 21, 10, 
    23, 19, 12,  4, 26, 8, 
    16,  7, 27, 20, 13, 2, 
    41, 52, 31, 37, 47, 55, 
    30, 40, 51, 45, 33, 48, 
    44, 49, 39, 56, 34, 53, 
    46, 42, 50, 36, 29, 32
};

unsigned short shifts[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int main(){

    ifstream read_file;
    ofstream out_file;
    read_file.open("key_temp.txt");
    out_file.open("key_out.txt",ios::trunc);

    string key6;
    getline(read_file,key6);

    char CD[56];
    memset(CD,'X',sizeof(CD));

    for(int i=0;i<48;i++){
        CD[PC2[i]-1] = key6[i];
    }
    cout<<"C6D6: ";
    for(int i=0;i<56;i++)
        cout<<CD[i];
    cout<<endl;
    int r=6;
    for (int i=0; i<r; i++){
        for (int j =0; j <shifts[5-i]; j++) {
            char t1 = CD[27];
            char t2 = CD[55];
            for (int k=27; k>=1; k--) {
                CD[k] = CD[k-1];
                CD[k+28] = CD[k+27];
            }
            CD[0] = t1;
            CD[28] = t2;
        }
    }

    cout<<"C0D0: ";
    for(int i=0;i<56;i++)
    {
            cout << CD[i];
            out_file<<CD[i];
    }
    read_file.close();
    out_file.close();

    return 0;
}
