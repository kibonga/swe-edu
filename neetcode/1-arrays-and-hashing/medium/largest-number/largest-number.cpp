#include "largest-number.h"

string largestNumber(vector<int> &nums) {
    string result;

    sort(nums.begin(), nums.end(), [](int num1, int num2) {
        string a = to_string(num1);
        string b = to_string(num2);
        string ab = a + b;
        string ba = b + a;

        return ab > ba;
    });

//    bool onlyZero = true;
//    for(int n : nums) {
//        if(onlyZero && n != 0) {
//            onlyZero =  false;
//        }
//        result += to_string(n);
//    }
//
//    if(result.empty() || onlyZero) {return "0";}

    for(int n : nums) {
        result += to_string(n);
    }

    return (result[0] == '0') ? "0" : result;
}

void runLargestNumberExample() {
    vector<int> nums1 = {3, 30, 34, 5, 9};
    vector<int> nums2 = {1,2,3,4,5,6, 0, 7,8,9,0};
    string result = largestNumber(nums2);
    cout << "Largest number = " << largestNumber(nums2) << endl;
}
