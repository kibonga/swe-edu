#include "max-num-of-ballons.h"

int maxNumOfBalloons(string text) {
    vector<int> table(26, 0);
    int num = 0;

    for(char c : text) {
        table[c-'a']++;
    }

    if(table['b'-'a'] < 1
    || table['a'-'a'] < 1
    || table['n'-'a'] < 1
    || table['l'-'a'] < 2
    || table['o'-'a'] < 2
    ) {
        return 0;
    }

    num = table['b'-'a'];
    num = min(num, table['a'-'a']);
    num = min(num, table['n'-'a']);

    num = min(num, table['l'-'a'] / 2);
    num = min(num, table['o'-'a'] / 2);

    return num;
}

void runMaxNumberOfBalloonsExample() {
    string s1 = "nlaebolko";
    string s2 = "loonbalxballpoon";

    cout << "Max num of balloons = " << maxNumOfBalloons(s1) << endl;
    cout << "Max num of balloons = " << maxNumOfBalloons(s2) << endl;
}
