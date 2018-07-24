// 1000_A+B
// 
// Description
// Calculate a+b

// Input
// Two integer a,b (0<=a,b<=10)

// Output
// Output a+b

// Sample Input
// 1 2

// Sample Output
// 3

// 1.0 直接实现
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}
