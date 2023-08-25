#include<bits/stdc++.h>
using namespace std;
int main()
{
    string pswdCiphertext="jghugmmhhojtmqinijkrmumkkukhikjq";
    string plainTextPswd;
    for(int i=0;i<2;i++)
    {
        string prev="ffffffffffffffff";
        for(int r=0;r<8;r++)
        {
            ofstream inputfile,outputfile;
            inputfile.open("input.txt",ios::trunc);
            outputfile.open("out.txt",ios::trunc);
            vector<string>s(128,prev);
            for(char c = 'f'; c <= 'm'; c++)
            {
                for(char d = 'f'; d <= 'u'; d++)
                {
                    s[(c-'f')*16 +d-'f'][2*r] = c;
                    s[(c-'f')*16 +d-'f'] [2*r+1]= d;
                }
            }
            for(auto i : s)
            {
                inputfile<<i<<"\n";
                inputfile<<"c"<<"\n";
            }
            inputfile<<"back\nexit\n";
            inputfile.close();
            system("./interact.sh");
            system("./extract.out");
            ifstream outfile;
            outfile.open("output.txt");
            int pos=0;
            string curStr;
            while(getline(outfile,curStr))
            {
                if(curStr.substr(0,r*2+2)==pswdCiphertext.substr(i*16,r*2+2))
                {
                    prev[2*r+1]=pos%16+'f';
                    prev[2*r]=pos/16+'f';
                    cout<<prev<<endl;
                    break;
                }
                pos++;
            }
            ifstream i1_file("input.txt");
            ifstream i2_file("output.txt");
            string inputFileName="input_";
            string outputFileName="output_";
            inputFileName+=to_string(i*8+r+1);
            outputFileName+=to_string(i*8+r+1);
            inputFileName+=".txt";
            outputFileName+=".txt";
            ofstream o1_file(inputFileName,ios::trunc);
            ofstream o2_file(outputFileName,ios::trunc);
            string line1,line2;
            while(getline(i1_file,line1) && getline(i2_file,line2))
            {
                o1_file<<line1<<endl;
                o2_file<<line2<<endl;
            }
        }
        plainTextPswd+=prev;
    }
    ofstream decryptedTxt("decrypted.txt",ios::trunc);
    decryptedTxt<<"Ciphertext of password: "<<pswdCiphertext<<endl;
    decryptedTxt<<"Decrypted plainText: "<<plainTextPswd<<endl;
    string password;
    for(int i = 0; i < plainTextPswd.length()-1; i+=2)
    {
        int num = (plainTextPswd[i]-'f')*16 + plainTextPswd[i+1]-'f';
        password+=(char)num;
    }
    decryptedTxt<<"ASCII values: ";
    for(auto i:password)
        decryptedTxt<<(int)i<<" ";
    decryptedTxt<<endl;
    decryptedTxt<<"Password: "<<password<<endl;
    return 0;
}
