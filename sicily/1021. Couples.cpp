/*
Failed Solution:

1. Tramsform a circle into a array couples[]. 

  L R
  | |
1 2 3 3 2 1 

2. If all the couple can be removed, then the array will be empty at last. In other words, "All couple can be remove" <-> " All couple can be removed from any where clockwisly" <-> "All couple can be removed from any where counterclockwisly". Here the proof is omitted.
3. Compare couples[L] and couples[R] (Initially R = L+1; R means the next one that haven't been removed, L means the previous one that haven't been removed.)
4. If couples[L] == couples[R], then remove couples[L] and couples[R]; --L, --R.
5. Check the hole array. If it's empty, all couples can be removed.

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main()
{
    int N = 0, couple1 = 0, couple2 = 0;
    
    cin >> N;
    vector<int> couples(N, 0);
    auto L = couples.begin();
    auto R = ++L;
    
    for (int i = 0; i != N; ++i) {
        cin >> couple1 >> couple2;
        couples[couple1] = i + 1;
        couples[couple2] = i + 1;
    }

    while (L != couples.end()) {
        if (*L == *R) {
            *L = 0;
            *R = 0;
            previous(L);
            abcnext(R);
        } else {
            L=R;
            next(R);
        }
    }
    
    for (auto i : couples) {
    	if (i != 0) {
    		cout << "NO";
    		return 0;
		}
	}
	
	cout << "YES";
	
	return 0;
}

void previous(vector<int>::iterator couple) {
    while (*couple == 0) {
        --couple;
    }
}

void abcnext(vector<int>::iterator couple) {
    while (*couple == 0) {
        ++couple;
    }
}

Another solution:
Use a stack to solve the problem.

*/

#include <iostream>
#include <vector>
#include <list>
using std::cin;
using std::cout;
using std::vector;
using std::endl;

int main()
{
    int N = 0, couple1 = 0, couple2 = 0;
    cin >> N;
	
    vector<int> couples(2 * N + 1, 0);
    for (int i = 0; i != N; ++i) {
        cin >> couple1 >> couple2;
        couples[couple2] = couples[couple1] = i + 1;
    }
    
    for (int i = 1; i != 2 * N + 1; ++i) {
		cout << couples[i] << " ";
	}
	cout << endl;
	
    vector<int> matchstack(2 * N + 1, 0);
    //auto current = matchstack.begin();
    int current = 1;
	for (int i = 1; i != 2 * N + 1; ++i) {
        if (matchstack[current-1] != couples[i]) {
        	cout << matchstack[current] << " "; 
            matchstack[current] = couples[i];
            cout << matchstack[current] << endl;
			++current;
        } else {
            matchstack[current - 1] = 0;
            --current; 
        }
    }
    
    cout << "---------------------------" << endl;
    /*
	for (auto beg = matchstack.begin(); beg != current; ++beg)
    	cout << *beg << " ";
	*/
	for (int i = 0; i != current; ++i) {
		cout << matchstack[current] << " ";
	}
	cout << endl << "---------------------------" << endl;
	
    //cout << (current == matchstack.begin() ? "Yes" : "No");
    cout << (current == 1 ? "Yes" : "No");
    return 0;
}
