#include "tiny-url.h"

namespace TinyUrl {
    class Solution {
    public:
        unordered_map<string, string> encodeMap;
        unordered_map<string, string> decodeMap;
        string baseUrl = "http://tinyurl.com/";
        Solution() {}
        string encode(string longUrl) {
            if(encodeMap.find(longUrl) == encodeMap.end()) {
                int count = encodeMap.size() + 1;
                encodeMap[longUrl] = count;
                decodeMap[baseUrl+ to_string(count)] = longUrl;
                return baseUrl + to_string(count);
            }
            return baseUrl + encodeMap[longUrl];
        }

        string decode(string shortUrl) {
            return decodeMap[shortUrl];
        }
    };

}

void runEncodeDecodeTinyUrlExample() {
    TinyUrl::Solution sln = TinyUrl::Solution();
    string longUrl1 = "http://leetcode.com/problems/design-tinyurl";
    string encodedUrl1 = sln.encode(longUrl1);
    cout << "Encoded url = " << encodedUrl1 << endl;
    string decodedUrl1 = sln.decode(encodedUrl1);
    cout << "Decoded url = " << decodedUrl1 << endl;
    string nonExistingEncodedUrl2 = "http://non-existing-url.com";
    string decodedUrl2 = sln.decode(nonExistingEncodedUrl2);
    cout << "Decoded url = " << decodedUrl2 << endl;
}
