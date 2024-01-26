#include "longest-substring-without-repeating-chars.h"

int lengthOfLongestSubstringMedium(string s) {
    unordered_set<char> st;
    int maxLen = 0;

    for(int i=0, j=0; j<s.size(); j++) {
        if(!st.count(s[j])) {
            st.insert(s[j]);
            continue;
        }
        maxLen = max(maxLen, (j-i));
        while(st.count(s[j])) {
            st.erase(s[i++]);
        }
        st.insert(s[j]);
    }
    maxLen = max(maxLen, (int)st.size());

    return maxLen;
}

int lengthOfLongestSubstringMediumOptimized(string s) {
    vector<int> mp(128);
    int maxLen = 0;

    for(int i=0, j=0; j<s.size(); j++) {
        mp[s[j]]++;
        while(mp[s[j]] > 1) {
            mp[s[i++]]--;
        }
        maxLen = max(maxLen, (j-i+1));
    }

    return maxLen;
}

int lengthOfLongestSubstringMediumUnorderedSetOptimized(string s) {
   unordered_set<char> st;
   int maxLen = 0;

   for(int i=0, j=0; j<s.size(); j++) {
       while(st.count(s[j])) {
           st.erase(s[i++]);
       }
       st.insert(s[j]);
       maxLen = max(maxLen, (j-i+1));
   }

   return maxLen;
}

int lengthOfLongestSubstringMediumVectorDelayedInsert(string s) {
    vector<int> mp(128);
    int maxLen = 0;

    for(int i=0, j=0; j<s.size(); j++) {
        while(mp[s[j]] > 0) {
            mp[s[i++]]--;
        }
        maxLen = max(maxLen, (j-i+1));
    }

    return maxLen;
}

void runLongestSubstringWithourRepeatingCharactersMediumExample() {
    string s1 = "ohomm";
    cout << "Longest substr = " << lengthOfLongestSubstringMedium(s1) << endl;
    unordered_set<char> st;
    auto res = st.insert('a').second;
}
