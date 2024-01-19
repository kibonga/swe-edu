#include "unique-len-3-palindromic-subseq.h"

int countPalindromicSubsequenceReviewFri19Jan2024(string &s) {
      vector<int> set(26, 0);
      vector<int> map(26, 0);
      unordered_set<string> seen;

      for(int i=1; i<s.size(); i++) {
          map[s[i]-'a']++;
      }
      // Iterator for _x_ position
      // Check for every a-z (each time) char if it exists in set and map
      // Check for current char if given string has already been seen

      set[s[0]-'a']++;
      for(int i=1; i<s.size()-1; i++) {
          // Remove current char from map
          map[s[i]-'a']--;
          for(int j=0; j<26; j++) {
              // Check for each char in alphabet
             if(set[j] && map[j] >= 1) {
                 seen.insert(string(1, j+'a') + s[i] + (char)(j+'a'));
             }
          }
          set[s[i]-'a']++;
      }

      return seen.size();
}

void runUniqueLen3PalindromicSubseqExampleReviewFri19Jan2024() {
    string s1 = "aabca";
    string s2 = "adc";
    string s3 = "bbcbaba";
    string s4 = "ckafnafqo";
    cout << "Number of unique subseq = " << countPalindromicSubsequenceReviewFri19Jan2024(s1) << endl;
    cout << "Number of unique subseq = " << countPalindromicSubsequenceReviewFri19Jan2024(s2) << endl;
    cout << "Number of unique subseq = " << countPalindromicSubsequenceReviewFri19Jan2024(s3) << endl;
    cout << "Number of unique subseq = " << countPalindromicSubsequenceReviewFri19Jan2024(s4) << endl;
}
