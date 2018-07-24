#include <iostream>
using namespace std;

int main()
{
    int n = 0, max = 0, min = 0, temp = 0;
    cin >> n;
    if (n <= 0) 
        return -1;
    cin >> min;
    max = min;

    for (int i = 0; i != n-1; ++i) {
        cin >> temp;
        if (temp >= max)
            max = temp;
        else if (temp < min)
            min = temp;
    }

    cout << min << ' ' << max << endl;
}