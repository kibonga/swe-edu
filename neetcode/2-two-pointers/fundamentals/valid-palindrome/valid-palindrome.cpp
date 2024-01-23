#include "valid-palindrome.h"

bool is_alphanum(char c) {
   if((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
       return true;
   }
   return false;
}

bool isPalindrome(string &s) {
    int i = 0, j = s.size()-1;
    char l, r;
    while(i < j) {
       l = s[i];
       r = s[j];
       if(!is_alphanum(l)) {
           i++;
           continue;
       }
       if(!is_alphanum(r)) {
           j--;
           continue;
       }
       if((l >= 48 && l <= 57) && l != r) {
          return false;
       }
       if((l == r) || (l+32 == r) || (l-32 == r)) {
           i++;
           j--;
           continue;
       }
       return false;
    }
    return true;
}

void runValidPalindromeExample() {
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Is palindrome = " << isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << "Is palindrome = " << isPalindrome(s2) << endl;
}
