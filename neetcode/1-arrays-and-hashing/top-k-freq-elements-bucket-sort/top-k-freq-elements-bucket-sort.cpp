#include "top-k-freq-elements-bucket-sort.h"

vector<int> topKFreqElementsBucketSort(vector<int> &nums, int k) {
    vector<int> result;
    vector<vector<int>> temp(nums.size());
    map<int, int> map;

    for (int n: nums) {
        map[n]++;
    }

    for (auto &m: map) {
        temp[m.second].push_back(m.first);
    }

    int n = nums.size() - 1;
    for(int i = n; i >= 0; i--) {
        if(result.size() >= k) {
            break;
        }
        while(!temp[i].empty()) {
            result.push_back(temp[i][temp[i].size()-1]);
            temp[i].pop_back();
        }
    }

    return result;
}

void runTopKFreqElementsBucketSortExample() {
    vector<int> input = {1, 1, 1, 2, 2, 3, 5, 5, 5, 5, 5};
    int k = 2;

    vector<int> result = topKFreqElementsBucketSort(input, k);
    cout << "Result = [ ";
    for (int r: result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
