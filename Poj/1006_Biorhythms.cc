// 1006 Biorthythms

// Description
// Some people believe that there are three cycles in a person's life that start
// the day he or she is born. These three cycles are the physical, emotional,
// and intellectual cycles, and they have periods of lengths 23, 28, and 33
// days, respectively. There is one peak in each period of a cycle. At the peak
// of a cycle, a person performs at his or her best in the corresponding field
// (physical, emotional or mental). For example, if it is the mental curve,
// thought processes will be sharper and concentration will be easier. Since the
// three cycles have different periods, the peaks of the three cycles generally
// occur at different times. We would like to determine when a triple peak
// occurs (the peaks of all three cycles occur in the same day) for any person.
// For each cycle, you will be given the number of days from the beginning of
// the current year at which one of its peaks (not necessarily the first)
// occurs. You will also be given a date expressed as the number of days from
// the beginning of the current year. You task is to determine the number of
// days from the given date to the next triple peak. The given date is not
// counted. For example, if the given date is 10 and the next triple peak occurs
// on day 12, the answer is 2, not 3. If a triple peak occurs on the given date,
// you should give the number of days to the next occurrence of a triple peak.

// Input
// You will be given a number of cases. The input for each case consists of one
// line of four integers p, e, i, and d. The values p, e, and i are the number
// of days from the beginning of the current year at which the physical,
// emotional, and intellectual cycles peak, respectively. The value d is the
// given date and may be smaller than any of p, e, or i. All values are
// non-negative and at most 365, and you may assume that a triple peak will
// occur within 21252 days of the given date. The end of input is indicated by a
// line in which p = e = i = d = -1.

// Output
// For each test case, print the case number followed by a message indicating
// the number of days to the next triple peak, in the form:

// Case 1: the next triple peak occurs in 1234 days.

// Use the plural form ``days'' even if the answer is 1.

// Sample Input
// 0 0 0 0
// 0 0 0 100
// 5 20 34 325
// 4 5 6 7
// 283 102 23 320
// 203 301 203 40
// -1 -1 -1 -1

// Sample Output
// Case 1: the next triple peak occurs in 21252 days.
// Case 2: the next triple peak occurs in 21152 days.
// Case 3: the next triple peak occurs in 19575 days.
// Case 4: the next triple peak occurs in 16994 days.
// Case 5: the next triple peak occurs in 8910 days.
// Case 6: the next triple peak occurs in 10789 days.

// 使用中国剩余定理
// 28 * 33 = 924
// 23 * 33 = 759
// 23 * 28 = 644

// 924 * a1 % 23 == 1
// 759 * a2 % 28 == 1
// 644 * a3 % 33 == 1

// a1 = 6, a2 = 19, a3 = 2

// ((p % 23) * a1 * 924) % 23 = (p % 23)
// ((e % 28) * a2 * 759) % 28 = (e % 28)
// ((i % 33) * a3 * 644) % 33 = (i % 33)

// 答案是 ( ((p % 23) * a1 * 924) + ((e % 28) * a2 * 759) + ((i % 33) * a3 * 644) ) % 21252 - d

// 求解 a_i 代码
// void init() {
//     std::ios::sync_with_stdio(false);
//     int a1 = 0;
//     while (924 * a1 % 23 != 1) {
//         ++a1;
//     }
//     cout << "924 * " << a1 << " mod 23 == 1" << endl;

//     int a2 = 0;
//     while (759 * a2 % 28 != 1) {
//         ++a2;
//     }
//     cout << "759 * " << a2 << " mod 28 == 1" << endl;
    
//     int a3 = 0;
//     while (644 * a3 % 33 != 1) {
//         ++a3;
//     }
//     cout << "644 * " << a3 << " mod 33 == 1" << endl;
// }

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int a1 

int nextPeak(int p, int e, int i, int d) {
    int peak = (((p % 23) * 5544) + ((e % 28) * 14421) + ((i % 33) * 1288)) - d;
    if (peak > 0) {
        return peak % 21252;
    } else {
        return peak % 21252 + 21252;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int p = 0, e = 0, i = 0, d = 0;
    int count = 0;
    while (cin >> p >> e >> i >> d) {
        if (p == -1) {
            break;
        }    
            ++count;
            cout << "Case " << count << ": the next triple peak occurs in "
                 << nextPeak(p, e, i, d) << " days." << endl;
    }
    return 0;
}