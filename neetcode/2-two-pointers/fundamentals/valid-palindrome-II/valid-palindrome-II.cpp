#include "valid-palindrome-II.h"

bool isValidPalindromeIIMistake(string &s) {
    bool changed = false;
    int i = 0, j = s.size() - 1;
    char l, r;

    while (i < j) {
        l = tolower(s[i]);
        r = tolower(s[j]);
        if (!isalnum(l)) {
            i++;
            continue;
        }
        if (!isalnum(r)) {
            j--;
            continue;
        }
        if (l != r && !changed) {
            changed = true;
            if (i + 1 >= j || j - 1 <= i) {
                return true;
            }
            if (s[i + 1] == s[j]) {
                i++;
                continue;
            }
            if (s[j - 1] == s[i]) {
                j--;
                continue;
            }
            return false;
        }
        if (l != r) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool isPali(string &s) {
   int i=0, j=s.size()-1;
   char l, r;
   while(i < j) {
       if(s[i] != s[j]) {
           return false;
       }
       i++;
       j--;
   }
   return true;
}

bool isValidPalindromeII(string &s) {
    bool changed = false;
    int i = 0, j = s.size()-1;
    char l, r;

    while (i < j) {
        l = tolower(s[i]);
        r = tolower(s[j]);
        if (!isalnum(l)) {
            i++;
            continue;
        }
        if (!isalnum(r)) {
            j++;
            continue;
        }
        if(l != r && !changed) {
            string s1 = s.substr(i, j-i);
            string s2 = s.substr(i+1, j-i);
            if(isPali(s1) || isPali(s2)) {
                return true;
            }
            return false;
        }
        if(l != r) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool checkPali(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool isValidPali(string &s) {
    int i=0, j=s.size()-1;
    while(i < j) {
        if(s[i] == s[j]) {
            i++;
            j++;
            continue;
        }
        bool isPali1 = checkPali(s, i+1, j);
        bool isPali2 = checkPali(s, i, j-1);

        return isPali1 || isPali2;
    }
}


void runValidPalindromeIIExample() {
    string s1 = "abca";
    cout << "Is valid palindrome II = " << isValidPalindromeII(s1) << endl;
    string s2 = "abc";
    cout << "Is valid palindrome II = " << isValidPalindromeII(s2) << endl;
    string s3 = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    cout << "Is valid palindrome II = " << isValidPalindromeII(s3) << endl;
    string s4 = "deeee";
    cout << "Is valid palindrome II = " << isValidPalindromeII(s4) << endl;
}
