#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {

    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("output.txt");

    // Create and open a text file
    ofstream MyWriteFile("binary_output.txt",ios::trunc);
   

    int flag = 0;

    // Use a while loop together with the getline() function to read the file line by line
    char baseStart='d';
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
        string binary = "";
        for(int i = 0; i < myText.length()-1; i++){
                int  x=myText[i]-baseStart;
                binary+=bitset<4>(x).to_string();
        }
        MyWriteFile << binary << endl;
    }

    // Close the file
    MyReadFile.close();
    MyWriteFile.close();
} 
