#include "min-number-of-swaps-to-make-string-balanced.h"

int minSwapsReviewFri19Jan2024(string &s) {
    if(s.empty()) {return 0;}
    int count = 0;

    int balance = 0;
    for(int i=0, j=s.size()-1; i<j; i++) {
        if(s[i] == ']') {
            balance--;
        }else {
            balance++;
        }
        if(balance >= 0) {
            continue;
        }
        while(s[j] != '[') {
            j--;
        }
        swap(s[i], s[j--]);
        count++;
        balance += 2;
    }

    return count;
}

void runMinNumberOfSwapsToMakeStringBalancedExampleReviewFri19Jan2024() {
    string s1 = "][][";
    string s2 = "]]][[[";
    cout << "Min number of swaps = " << minSwapsReviewFri19Jan2024(s1) << endl;
    cout << "Min number of swaps = " << minSwapsReviewFri19Jan2024(s2) << endl;
}
