#include "max-num-of-vowels-in-substr.h"

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowelsMedium(string &s, int k) {
   int maxNum = 0;
   int currNum = 0;

   for(int i=0; i<k; i++) {
       if(isVowel(s[i])) {
           currNum++;
       }
   }

   maxNum = currNum;
   for(int i=0, j=k; j<s.size(); i++, j++) {
       if(isVowel(s[i])) {
          currNum--;
       }
       if(isVowel(s[j])) {
           currNum++;
       }
       maxNum = max(currNum, maxNum);
   }

   return maxNum;
}

void runMaximumNumberOfVowelsInASubstringOfGivenLengthMediumExample() {
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Max vowels" << maxVowelsMedium(s1, k1) << endl;
}
