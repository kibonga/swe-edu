#include "longest-common-prefix.h"

string longestCommonPrefix(vector<string> &strs) {
    string result;
    int i, minLen = 201;

    for(auto &s : strs) {
        minLen = min(minLen, (int)s.size());
    }

    for(i=0; i<minLen; i++) {
        char c = strs[0][i];
        for(int j=1; j<strs.size(); j++) {
            if(c != strs[j][i]) {
                return result;
            }
        }
        result += c;
    }

    return result;
}

void runLongestCommonPrefixExample() {
    vector<string> strs = {
            "flower",
            "flow",
            "flight"
    };

    cout << "Longest common prefix = " << longestCommonPrefix(strs) << endl;
}
