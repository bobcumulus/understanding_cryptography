/**
 * 1.1. The ciphertext below was encrypted using a substitution cipher. Decrypt the ci-
phertext without knowledge of the key.

 lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi
bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx
ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr
yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk
lmird jk xjubt trmui jx ibndt
wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi
iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m
vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd
wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr
jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii
ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh
mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb
bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd
wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr
riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb

 1. Compute the relative frequency of all letters A...Z in the ciphertext. You may
want to use a tool such as the open-source program CrypTool [50] for this task.
However, a paper and pencil approach is also still doable.
2. Decrypt the ciphertext with the help of the relative letter frequency of the English
language (see Table 1.1 in Sect. 1.2.2). Note that the text is relatively short and
that the letter frequencies in it might not perfectly align with that of general
English language from the table.
3. Who wrote the text?
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




