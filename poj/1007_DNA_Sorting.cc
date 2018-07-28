// 1007_DNA Sorting

// Description
// One measure of ``unsortedness''in a sequence is the number of pairs of
// entries that are out of order with respect to each other. For instance, in
// the letter sequence ``DAABEC'', this measure is 5, since D is greater than
// four letters to its right and E is greater than one letter to its right. This
// measure is called the number of inversions in the sequence. The sequence
// ``AACEDGG''has only one inversion (E and D)---it is nearly sorted---while the
// sequence ``ZWQM'' has 6 inversions (it is as unsorted as can be---exactly the
// reverse of sorted).

// You are responsible for cataloguing a sequence of DNA strings (sequences
// containing only the four letters A, C, G, and T). However, you want to
// catalog them, not in alphabetical order, but rather in order of
// ``unsortedness'', from ``most sorted'' to ``least sorted''. All the strings are
// of the same length. Input

// The first line contains two integers: a positive integer n (0 < n <= 50)
// giving the length of the strings; and a positive integer m (0 < m <= 100)
// giving the number of strings. These are followed by m lines, each containing
// a string of length n.

// Output
// Output the list of input strings, arranged from ``most sorted''to ``least
// sorted''. Since two strings can be equally sorted, then output them according
// to the orginal order.

// Sample Input
// 10 6
// AACATGAAGG
// TTTTGGCCAA
// TTTGGCCAAA
// GATCAGATTT
// CCCGGGGGGA
// ATCGATGCAT

// Sample Output
// CCCGGGGGGA
// AACATGAAGG
// GATCAGATTT
// ATCGATGCAT
// TTTTGGCCAA
// TTTGGCCAAA

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::sort;
using std::string;
using std::vector;

class DNA {
public:
    int unsortedness;
    string sequence;

    DNA();
    ~DNA();
    bool operator<(const DNA &b);
    void calculateSortedness();
};

DNA::DNA() {}
DNA::~DNA() {}

void DNA::calculateSortedness() {
    int a = 0, c = 0, g = 0, t = 0;
    int s = sequence.size();
    for (int i = 0; i != s; ++i) {
        switch (sequence[i])
        {
            case 'a':
                ++t;
                ++g;
                ++c;
                ++a;
                break;

            case 'c':
                ++t;
                ++g;
                ++c;
                break;

            case 'g':
                ++t;
                ++g;
                break;

            case 't':
                ++t;
                break;

            default:
                break;
        }
    }
    unsortedness = a + c + g + t;
    return;
}

bool DNA::operator< (const DNA & b) {
    if (unsortedness == b.unsortedness) {
        return sequence < b.sequence;
    } else {
        return unsortedness < b.unsortedness;
    }
}

istream & operator>>(istream & is, DNA & dna) {
    is >> dna.sequence;
    if (is) {
        dna.calculateSortedness();
    } else {
        dna.sequence = "";
        dna.unsortedness = 0;
    }
    return is;
}

int main() {
    std::ios::sync_with_stdio(false);
    int length;
    int m;
    DNA dna;
    vector<DNA> DNAs;
    DNAs.resize(m);
    cin >> length >> m;

    for (int i = 0; i != m; ++i) {
        cin >> DNAs[i];
    }

    sort(DNAs.begin(), DNAs.end());

    for (int i = 0; i != m; ++i) {
        cout << DNAs[i].sequence << endl;
    }
}