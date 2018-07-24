//Check all the number one by one

#include <iostream>
using std::cout;
using std::endl; 

int DigitalSum(int dividend, int division)
{
    int sum = 0;
    while (dividend != 0) {
        sum += (dividend % division);
        dividend /= division;
    }
    
    return sum;
}

int main()
{   
    for (int i = 1000; i != 10000; ++i) {
        if(DigitalSum(i, 10) == DigitalSum(i, 12))
            if(DigitalSum(i, 10) == DigitalSum(i, 16))
                cout << i << endl;
    }

    return 0;
}
