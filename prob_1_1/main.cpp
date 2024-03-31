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
//double percentages[] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0, 2.4, 6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074};
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
    string cipherText= "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi\n"
                       "bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx\n"
                       "ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr\n"
                       "yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk\n"
                       "lmird jk xjubt trmui jx ibndt\n"
                       "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi\n"
                       "iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m\n"
                       "vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd\n"
                       "wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr\n"
                       "jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii\n"
                       "ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh\n"
                       "mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb\n"
                       "bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd\n"
                       "wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr\n"
                       "riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";

    //question_1(cipherText);
    question_2(cipherText);
    return 0;
}

void question_1(string &cipherText) {
    for(char i: cipherText){
        if(i==' ' || i=='\n' || i=='\0')continue;
        int diff=i-'a';
        if(diff>=0 && diff<=25){
            questionFrequency[diff]++;
        }
    }

    for(double & i : questionFrequency){
        i=(double(i)/cipherText.length())*100.0;
    }

    sorting(questionFrequency, questionAlpha, 26);
    sorting(percentages, alphabet, 26);

    for(char alpha: alphabet){
        cout<<alpha;
    }
    cout<<"\n";
    for(char alpha: questionAlpha){
        cout<<(char)(alpha+97);
    }

    for(int i=0; i<26; i++){
        substituion[(char)(questionAlpha[i]+97)]=alphabet[i];
    }
    cout<<"\n";

    for(int i=0;i<26;i++){
        int indexOfCharNormal = 0;
        for(int index=0; index<26; index++){
            if(alphabet[index]==(char)(i+97)){
                indexOfCharNormal=index;
                break;
            }
        }
        cout<<"Character : "<<(char)(97+i)<<" Frequency : "<<questionFrequency[indexOfCharNormal]<<endl;
    }


};


void question_2(string &cipherText){
   question_1(cipherText);


   for (const auto& pair : substituion) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    for(char alpha: cipherText){

        if(alpha==' ' || alpha == '\n'){
            cout<<alpha;
        }else{
            //cout<<substituion[alpha];
            cout<<substituion[alpha];
        }

    }

}


void sorting(double frequency[],char characters[], int size) {

    // loop to access each array element
    for (int step = 0; step < size-1; ++step) {

        // loop to compare array elements
        for (int i = 0; i < size - step-1; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (frequency[i] > frequency[i + 1]) {

                // swapping elements if elements
                // are not in the intended order
                double temp = frequency[i];
                frequency[i] = frequency[i + 1];
                frequency[i + 1] = temp;

                 char tempCharacter = characters[i];
                characters[i] = characters[i + 1];
                characters[i + 1] = tempCharacter;

            }
        }
    }

}


/*
 * @robert:
 * The following was gotten as output but it has be altered to work:
 *
 *
 * yecafse the wractnce iu the yasnc mivemeots iu pata ns
the uicfs aol masterg iu sedu ns the esseoce iu
matsfyagashn rgf parate li n shadd trg ti edfcnlate the
mivemeots iu the pata accirlnob ti mg noterwretatnio
yasel io uirtg gears iu stflg
nt ns oit ao easg tasp ti exwdano each mivemeot aol nts
snbonuncaoce aol sime mfst remano foexwdanoel ti bnve a
cimwdete exwdaoatnio ioe kifdl have ti ye qfadnunel aol
noswnrel ti sfch ao exteot that he cifdl reach the state
iu eodnbhteoel mnol cawayde iu recibonjnob sifoldess
sifol aol shawedess shawe n li oit leem mgsedu the unoad
afthirntg yft mg exwerneoce knth pata has deut oi lifyt
that the uiddiknob ns the wriwer awwdncatnio aol
noterwretatnio n iuuer mg theirnes no the hiwe that the
esseoce iu ipnoakao parate kndd remano notact

 */

/**
* Substitution Inspiration:
 *
 * Key: a, Value: x
Key: b, Value: t
Key: c, Value: k
Key: d, Value: l
Key: e, Value: v
Key: f, Value: q
Key: g, Value: j
Key: h, Value: d
Key: i, Value: s
Key: j, Value: i
Key: k, Value: o
Key: l, Value: y
Key: m, Value: a
Key: n, Value: f
Key: o, Value: b
Key: p, Value: h
Key: q, Value: p
Key: r, Value: e
Key: s, Value: w
Key: t, Value: g
Key: u, Value: r
Key: v, Value: c
Key: w, Value: n
Key: x, Value: u
Key: y, Value: m
Key: z, Value: z

*/

/**
*Corrected Substitution Inspiration (I'll have to revisite this):
 *
 *
 * Key: a, Value: x
Key: b, Value: t
Key: c, Value: k
Key: d, Value: l
Key: e, Value: v
Key: f, Value: q
Key: g, Value: j
Key: h, Value: d
Key: i, Value: s
Key: j, Value: i
Key: k, Value: o
Key: l, Value: y
Key: m, Value: a
Key: n, Value: f
Key: o, Value: b
Key: p, Value: h
Key: q, Value: p
Key: r, Value: e
Key: s, Value: w
Key: t, Value: g
Key: u, Value: r
Key: v, Value: c
Key: w, Value: n
Key: x, Value: u
Key: y, Value: m
Key: z, Value: z

*/

/*
 * Character : a Frequency : 7.91826
Character : b Frequency : 0.893997
Character : c Frequency : 2.80971
Character : d Frequency : 2.93742
Character : e Frequency : 10.728
Character : f Frequency : 2.17114
Character : g Frequency : 1.66028
Character : h Frequency : 3.83142
Character : i Frequency : 6.13027
Character : j Frequency : 0.127714
Character : k Frequency : 0.63857
Character : l Frequency : 2.93742
Character : m Frequency : 2.42656
Character : n Frequency : 6.00255
Character : o Frequency : 6.25798
Character : p Frequency : 0.893997
Character : q Frequency : 0.127714
Character : r Frequency : 3.06513
Character : s Frequency : 5.23627
Character : t Frequency : 8.68455
Character : u Frequency : 2.55428
Character : v Frequency : 0.63857
Character : w Frequency : 2.17114
Character : x Frequency : 0.63857
Character : y Frequency : 1.02171
Character : z Frequency : 0
 */