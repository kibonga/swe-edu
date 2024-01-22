#include "unique-len-3-palindromic-subseq.h"

int countPalindromicSubsequenceReviewMon22Jan2024(string s) {
    unordered_set<char> st;
    unordered_map<char, int> mp;
    unordered_set<string> re;

    for (char c : s) {
        mp[c]++;
    }

    for (char b : s) {
        mp[b]--;
        for (int i = 0; i < 26; i++) {
            char a = (char)(i + 'a');
            string str = string() + a + b + a;
            if (st.count(a) && mp.count(a) && mp[a] >= 1 && !re.count(str)) {
                re.insert(str);
            }
        }
        st.insert(b);
    }

    return re.size();
}

void runUniqueLength3PalindromicSubsequencesExampleMon22Jan2024() {
    string str = "aabca";
    cout << "Result = " << countPalindromicSubsequenceReviewMon22Jan2024(str) << endl;
}
