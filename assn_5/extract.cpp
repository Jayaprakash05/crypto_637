#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string trim(const string& str, const string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

int main() {

    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("out.txt");

        // Create and open a text file
    ofstream MyWriteFile("output.txt",ios::trunc);
   

    int flag = 0;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    
        if(flag == 1){
            MyWriteFile << trim(myText) << endl;
            flag = 0;
        }
        if (myText.find("Slowly, a new text starts appearing on the screen. It reads ...", 0) != string::npos) {
            flag = 1;
            //cout << "found it" << endl;
        }
    }

    // Close the file
    MyReadFile.close();
    MyWriteFile.close();
} 
