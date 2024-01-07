#include "unique-email-addr.h"

int numUniqueEmails(vector<string> &emails) {

}

void runUniqueEmailAddrExample() {
    vector<string> emails = {
            "test.email+alex@leetcode.com",
            "test.e.mail+bob.cathy@leetcode.com",
            "testemail+david@lee.tcode.com"
    };

    cout << "Number of unique email addresses = " << numUniqueEmails(emails) << endl;
}
