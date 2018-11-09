// n=numRows
// Δ=2n-2    1                           2n-1                         4n-3
// Δ=        2                     2n-2  2n                    4n-4   4n-2
// Δ=        3               2n-3        2n+1              4n-5       .
// Δ=        .           .               .               .            .
// Δ=        .       n+2                 .           3n               .
// Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
// Δ=2n-2    n                           3n-2                         5n-4
// n, n + step1, n + step2, n + step1......



#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Solution {
public:
    string convert(const string &s, const int numRows) {
        int length = s.size();
        if (length < 2 || numRows == 1) {
            return s;
        }
        for (int i = 0; i != numRows; ++i) {
            int step1 = 2 * (numRows - 1 - i);
            int step2 = 2 * i;
            int index = i;
            if (index < length) {
                output << s[index];
            }
            while (true) {
                index += step1;
                if (index >= length) {
                    break;
                }
                if (step1 != 0) {
                    output << s[index];
                }

                index += step2;
                if (index >= length) {
                    break;
                }
                if (step2 != 0) {
                    output << s[index];
                }
            }
        }
        return output.str();
    }

private:
    stringstream output;
};