#include <iostream>
using namespace std;

int main()
{
    int n = 0, sum=0, temp = 0;
    cin >> n;
    if (n <= 0) 
        return -1;

    for (int i = 0; i != n; ++i) {
        cin >> temp;
        sum += temp;
    }

    cout << sum << endl;
}