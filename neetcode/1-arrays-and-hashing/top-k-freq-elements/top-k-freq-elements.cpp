#include "top-k-freq-elements.h"

bool valueCmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> topKFrequentElements(vector<int> &nums, int k) {
    vector<int> result(k);
    vector<pair<int, int>> temp;
    map<int, int> map;

    for(int n : nums) {
        map[n]++;
    }

    for(auto &m : map) {
       temp.push_back(m);
    }


    sort(temp.begin(), temp.end(), valueCmp);

    for(int i=0; i<k; i++) {
        result.push_back(temp[i].first);
    }

    return result;
}

void runTopKFreqElementsExample() {
    vector<int> input = {1, 1, 1, 2, 2, 3, 3, 3};
    int k = 2;

    vector<int> result = topKFrequentElements(input, k);
    cout << "Result = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
