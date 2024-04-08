/**
 * 1.2. We received the following ciphertext which was encoded with a shift cipher:
xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpit
ghlxiwiwtxgqadds.
1. Perform an attack against the cipher based on a letter frequency count: How
many letters do you have to identify through a frequency count to recover the
key? What is the cleartext?
2. Who wrote this message?
 */


#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

// English alphabet
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// Percentages corrected based on provided percentages
double percentages[] ={0.0817, 0.0150, 0.0278, 0.0425, 0.1270,
0.0223, 0.0202, 0.0609, 0.0697, 0.0015,
0.0077, 0.0403, 0.0241, 0.0675, 0.0751,
0.0193, 0.0010, 0.0599, 0.0633, 0.0906,
0.0276, 0.0098, 0.0236, 0.0015, 0.0197,
0.0007
};
char questionAlpha[26]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
double questionFrequency[26] ={0};

void question_1(string &cipherText);
void question_2(string &cipherText);
void sorting(double array[], char alphabet[], int i);
map<char, char> substituion;

int main() {
    string cipherText= "xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpit"
                       "ghlxiwiwtxgqadds";

    question_1(cipherText);
    return 0;
}

void question_1(string &cipherText) {

        string word = "xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpit"
                      "ghlxiwiwtxgqadds";

        for(int i=0;i<26;i++){
            cout<<"Key: "<<i<<" "<<endl;
            for(char alpha: word){
                int value=((int)alpha-i-97+26)%26+(97);
                cout<<(char)value;
            }
            cout<<endl;
        }
}




