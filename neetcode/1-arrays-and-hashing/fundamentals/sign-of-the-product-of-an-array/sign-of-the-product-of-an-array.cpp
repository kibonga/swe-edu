#include "sign-of-the-product-of-an-array.h"

int arraySign(vector<int> &nums) {
   int count = 0;
   for(int n : nums) {
       if(n == 0) {return 0;}
       if(n >= 1) { continue;}
       count++;
   }
   return (count % 2 == 0) ? 1 : -1;
}

void runSignOfTheProductOfAnArrayExample() {
    vector<int> nums = {-1,-2,-3,-4,3,2,1};
    cout << "Sign of array = " << arraySign(nums) << endl;
}
