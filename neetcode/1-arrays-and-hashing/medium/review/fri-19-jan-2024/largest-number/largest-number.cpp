#include "largest-number.h"

string largestNumberReviewFri19Jan2024(vector<int> &nums) {
    if(nums.empty()) {return "";}
    string number = "";

    sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
        string a = to_string(x);
        string b = to_string(y);
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    });

    for(int num : nums) {
        if(number.empty() && num == 0) { continue;}
        number += to_string(num);
    }

    return number;
}

void runLargestNumberExampleReviewFri19Jan2024() {
    vector<int> nums1 = {3, 30, 34, 5, 9};

    cout << "Largest number = " << largestNumberReviewFri19Jan2024(nums1) << endl;
}
