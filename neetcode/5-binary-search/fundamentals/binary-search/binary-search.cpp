#include "binary-search.h"

int binarySearchFundamentals(vector<int> &nums, int target) {
    int l = 0, h = nums.size() - 1, m;

    while (l < h) {
        m = l + (h - l) / 2;

        // VALID
        if (target < nums[m]) {
            h = m;
        } else {
            l = m + 1;
        }

        // NOT VALID
        // if(target > nums[m]) {
        //     l = m + 1;
        // }else {
        //     h = m;
        // }
    }

    return target == nums[l] ? l : -1;
}

bool isOdd(int l, int h) {
    return ((h - l) + 1) % 2 != 0;
}

int singleNonDuplicate(vector<int> &nums) {
    int l = 0, h = nums.size() - 1, m;

    // Side which has odd num of values, remove both duplicates for calculation

    while (l < h) {
        m = l + (h - l) / 2;

        if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
            return nums[m];
        }

        if (nums[m] == nums[m + 1] && isOdd(m + 2, h)) {
            l = m + 2;
        } else if (nums[m] != nums[m + 1] && isOdd(m + 1, h)) {
            l = m + 1;
        } else if (nums[m] == nums[m - 1] && isOdd(l, m - 2)) {
            h = m - 1;
        } else {
            h = m;
        }
    }

    return nums[l];
}

int calcDays(vector<int> &ws, int cap) {
    int days = 1;
    int currCap = 0;
    for(int w : ws) {
       currCap += w;
       if(currCap > cap) {
           days++;
           currCap = w;
           continue;
       }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int l = *max_element(begin(weights), end(weights));
    int h = accumulate(begin(weights), end(weights), 0);
    int cap, d;

    while(l < h) {
        cap = l + (h - l) / 2;

        // Fewer days actually means more capacity, and we want to shrink capacity as much
        // as possible
        if(calcDays(weights, cap) <= days) {
            // Valid number of days, shrink the window to see if there is anything smaller and still valid
            h = cap;
        }else {
            // Not valid, extend the window, we must find the valid one
            l = cap + 1;
        }
    }

    return l;
}


int countPairs(vector<int> &potions, int sp, int t) {
    int l = 0, h = potions.size() - 1, m;

    while(l <= h) {
        m = l + (h - l) / 2;

        if(t >= potions[m] * sp) {
            l = m + 1;
        }else {
            h = m - 1;
        }
    }

    return potions.size() - l;
}
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> r;
    sort(begin(potions), end(potions));

    for(int s : spells) {
        r.push_back(countPairs(potions, s, success));
    }

    return r;
}

void testMatrix(vector<int> &m) {

}

void runBinarySearchFundamentalsExample() {
//    vector<int> n1 = {-1,0,3,5,9,12};
//    int t1 = 9;
//
//    vector<int> n2 = {-1, 0, 3, 5, 9, 12};
//    int t2 = 2;
//
//    cout << "Result = " << binarySearchFundamentals(n1, t1) << endl;
//    cout << "Result = " << binarySearchFundamentals(n2, t2) << endl;

//    vector<int> n1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
//    cout << "Result = " << singleNonDuplicate(n1) << endl;
//    vector<int> n2 = {3,3,7,7,10,11,11};
//    cout << "Result = " << singleNonDuplicate(n2) << endl;

//    vector<int> w1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int d1 = 5;
//    vector<int> w1 = {1, 2, 3, 4, 5};
//    int d1 = 2;
//    vector<int> w1 = {1, 2, 3, 1, 1};
//    int d1 = 4;
//    cout << "Result = " << shipWithinDays(w1, d1) << endl;


    std::vector<int> spells = {5, 1, 3};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    int success = 7;
    auto res = successfulPairs(spells, potions, success);

    vector<vector<int>> matrix;
    testMatrix(matrix.front());

    int m = *max_element(begin(spells), end(spells));
}
