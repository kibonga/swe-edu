#include "min-num-of-swaps-to-make-string-balanced.h"
using namespace std;

int minSwaps(string &s) {
    int i = 0, j = s.size()-1;
    int balance = 0;
    int numOfSwaps = 0;

    while(i < j) {
        if(s[i] == ']') {
            balance--;
        }else {
            balance++;
        }
        if(balance < 0) {
            swap(s[i], s[j]);
            j--;
            numOfSwaps++;
            balance += 2;
        }
        i++;
    }

    return numOfSwaps;
}

void runMinNumberOfSwapsToMakeStringBalancedExample() {
    string s1 = "][][";
    cout << "Min number of swaps = " << minSwaps(s1) << endl;
}
