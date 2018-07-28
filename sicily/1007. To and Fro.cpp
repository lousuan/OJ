/*
e.g:

1. original text
There's no place like home on a snowy night

2. first alternation
toioy
hpknn
eleai
rahsg
econh
semot
nlewx

toioyhpknneleairahsgeconhsemotnlewx

3. second alternation
toioy
nnkph
eleai
gshar
econh
tomes
nlewx

toioynnkpheleaigshareconhtomesnlewx

key: caculate the rows of the rectangle, rearrenge the character

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int column = 0,
        row = 0;
    bool reverse = false; 
    string code, temp, text;
    vector<string> texts;

    cin >> column;
    while (column != 0) {
        cin >> code;

        row = code.size() / column;
        
        for (int i = 0; i != column; ++i) {
           for (int j = 0; j != row; ++j) {
               if (reverse) { // odd line needs to be reversed
                    text = text + code[column*(j+1)-i-1];
                } else { 
                    text = text + code[column*j+i];
                }
                    reverse = !reverse; 
            } 
            // reset after finish one column
            reverse = false;
        }
        texts.push_back(text);

        //reset after finish one text
        text = "";
        
        cin >> column;
    }

    for (int i = 0; i != texts.size(); ++i)
        cout << texts[i] << endl;
    
    return 0;
}