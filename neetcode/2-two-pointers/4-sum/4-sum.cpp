#include "4-sum.h"

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size()-1;
    int low, high, i, j, sum;

    for(i=0, j=n; i<n-1 && j > i; i++, j--) {
            low = i + 1;
            high = j - 1;
            while(low < high) {
                sum = nums[low] + nums[high] + nums[i] + nums[j];
                if(sum == target) {
                    result.push_back({nums[low], nums[high], nums[i], nums[j]});
                    low++;
                    high--;
                    continue;
                }else if(sum > target) {
                    high--;
                }else {
                    low++;
                }
            }
    }

    return result;
}

void run4SumExample() {
    int target = 0;
    vector<int> nums = {1, 0, -1, 0, -2, 2};

    vector<vector<int>> result = fourSum(nums, target);
    cout << "Result" << endl;
    for(auto &res : result) {
        cout << "vector = [ ";
        for(int r : res) {
            cout << r << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}
