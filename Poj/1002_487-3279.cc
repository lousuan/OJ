// 1002_487-3279

// Description
// Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ''three tens'' number 3-10-10-10. 

// The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows: 

// A, B, and C map to 2 
// D, E, and F map to 3 
// G, H, and I map to 4 
// J, K, and L map to 5 
// M, N, and O map to 6 
// P, R, and S map to 7 
// T, U, and V map to 8 
// W, X, and Y map to 9 

// There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010. 

// Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.) 

// Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number. 

// Input
// The input will consist of one case. The first line of the input specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters. 

// Output
// Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line: 

// No duplicates. 

// Sample Input
// 12
// 4873279
// ITS-EASY
// 888-4567
// 3-10-10-10
// 888-GLOP
// TUT-GLOP
// 967-11-11
// 310-GINO
// F101010
// 888-1200
// -4-8-7-3-2-7-9-
// 487-3279

// Sample Output
// 310-1010 2
// 487-3279 4
// 888-4567 3

#include <iostream>
#include <iomanip> 
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::map;
using std::vector;

void initializeDict(vector<int> & dict) {
    for (int i = 0; i != 16; ++i) {
        dict['A' + i] = (i / 3) + 2;
    }

    for (int i = 1; i != 9; ++i) {
        dict['Q' + i] = (i / 3) + 7;
    }
    
    for (int i = 0; i != 10; ++i) {
        dict['0' + i] = i;
    }
}

int translate(vector<int> & dict, const string & s) {
    int i = 0;
    for (unsigned j = 0; j != s.size(); ++j) {
        if (dict[static_cast<unsigned>(s[j])] != -1) {
            i *= 10;
            i += static_cast<unsigned>(dict[s[j]]);
        }
    }

    // cout << s << ": " << i << endl;

    return i;
}

void printDict(vector<int> & dict) {
    for (int i = 45; i != 90; ++i) {
        cout << static_cast<char>(i) << ": " << dict[i] << endl;
    }
}

// void Debug(map<string, int> & debug) {
//     for (auto & i : debug) {
//         cout << i.first << ": " << i.second << endl;
//     }

//     cout << "total: " << debug.size() << endl;
// }

void print(map<int, int> & result) {
    for (map<int, int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
        if (iter->second > 1) {
            cout << setfill('0');
            cout << setw(3) << (iter->first / 10000) << setw(1) << '-' << setw(4) << (iter->first % 10000);
            cout << ' ' << iter->second << endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    unsigned n = 0;
    string customTel;
    vector<int> tel(7, 0);
    vector<int> dict(100, -1);
    initializeDict(dict);
    map<int, int> result;

    // map<string, int> debug;

    cin >> n;   
 
    for (unsigned i = 0; i != n; ++i) {
        cin >> customTel;
        int tel = translate(dict, customTel);
        result[tel] = result[tel] + 1;

        // debug[customTel] = tel;
    }
    // cout << "---------------" << endl;
    // printDict(dict);
    // cout << "---------------" << endl;
    // Debug(debug);
    // cout << "---------------" << endl;

    if (n == result.size()) {
        cout << "No duplicates." << endl;
    } else {
        print(result);
    }
}
