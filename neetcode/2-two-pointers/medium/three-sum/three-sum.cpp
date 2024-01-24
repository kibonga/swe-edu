#include "three-sum.h"

vector<vector<int>> threeSumMedium2(vector<int> &nums) {
    int target = 9;
    sort(nums.begin(), nums.end());
    int i=0, j=nums.size()-1, k=1;
    int sum;
    vector<vector<int>> result;

    while(i + 1 < j) {
        sum = nums[i] + nums[j];
        if(sum > target) {
            j--;
            continue;
        }
        k = i+1;
        while(sum + nums[k] < target) {
            k++;
        }
        if(sum + nums[k] == target) {
            result.push_back({nums[i], nums[k], nums[j]});
        }
        j--;
        i=0;
    }
    return result;
}

vector<vector<int>> threeSumMedium(vector<int> &nums) {
    int i=0, j=nums.size()-1, k=1;
    int sum;
    vector<vector<int>> r;

    sort(nums.begin(), nums.end());
    while(i + 1 < j) {
        sum = nums[i] + nums[j];
        if(sum > 0) {
            j--;
            i=0;
            continue;
        }
        k = i+1;
        while(k<j) {
            if(sum + nums[k] == 0) {
                r.push_back({nums[i], nums[k], nums[j]});
                break;
            }
            k++;
        }
        i=0;
        j--;
    }

    return r;
}

vector<vector<int>> threeSum3(vector<int>& nums) {
    int i = 0, j = nums.size() - 1, k = i + 1;
    vector<vector<int>> r;
    set<vector<int>> s;
    int sum;

    sort(nums.begin(), nums.end());
    while (i + 1 < j) {
        while (k < j) {
            sum = nums[i] + nums[k] + nums[j];
            if (sum == 0) {
                s.insert({nums[i], nums[k++], nums[j--]});
            }else if(sum < 0) {
                k++;
            }else if(sum > 0) {
                j--;
            }
        }
        i++;
        k = i+1;
        j = nums.size()-1;
    }

    for(auto &v : s) {
        r.push_back(v);
    }

    return r;
}


void displayThreeSumMedium(vector<vector<int>> &nums) {
    cout << "Result" << endl;
    for(auto &num : nums) {
        cout << "[ ";
        for(int n : num) {
            cout << n << " ";
        }
        cout << "]" << endl;
    }
}

void runThreeSumMediumExample() {
//    vector<int> n1 {-1, 0, 2, 3, 4, 6, 7, 9, 11};
//    vector<int> n1 = {-1, 0, 1, 2};
//    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    vector<int> n1 = {-2, 0, 1, 1, 2};
    vector<vector<int>> r1 = threeSum3(n1);
    displayThreeSumMedium(r1);
}
