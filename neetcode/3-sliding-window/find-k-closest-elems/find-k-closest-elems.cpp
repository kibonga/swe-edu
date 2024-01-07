#include "find-k-closest-elems.h"

vector<int> findKClosestElems(vector<int> &arr, int k, int x) {
    vector<int> result;
    vector<int> largerVals;
    int i, j, index = 0, m;

    for(i=0; i<arr.size(); i++) {
        if(arr[i] == x) {
            index = i;
            break;
        }
    }

//    if(index == -1) {
//        for(i=0; i<k; i++) {
//            result.push_back(arr[i]);
//        }
//        return result;
//    }

    i = index;
    j = index + 1;
    m = k;

    if(i < 0) {
        while(m > 0 && j < arr.size()) {
            result.push_back(arr[j]);
            m--;
            j++;
        }
        return result;
    }

    if(j >= arr.size()) {
        while(m > 0 && i >= 0) {
            result.push_back(arr[i]);
            m--;
            i++;
        }
        return result;
    }

    int left, right;
    while(m > 0 && ((i >= 0) || (j < arr.size()))) {
        if(i < 0) {
            largerVals.push_back(arr[j]);
            j++;
            m--;
            continue;
        }
        if(j >= arr.size()) {
            result.push_back(arr[i]);
            i--;
            m--;
            continue;
        }

        left = arr[i];
        right = arr[j];
        if(x-left <= abs(x-right)) {
            result.push_back(left);
            i--;
            m--;
            continue;
        }
        if(x-left > abs(x-right)) {
            largerVals.push_back(right);
            j++;
            m--;
            continue;
        }
    }

    sort(result.begin(), result.end());

    for(int lv : largerVals) {
        result.push_back(lv);
    }

    return result;
}

void runFindKClosestElementsExample() {
//    vector<int> nums = {1, 2, 3, 4, 5};
//    int k = 4;
//    int x = 3;
    vector<int> nums = {1, 1, 1, 10, 10, 10};
    int k = 1;
    int x = 9;

    vector<int> result = findKClosestElems(nums, k, x);
    cout << "K Closest elems = [ ";
    for(int r : result) {
        cout << r << " ";
    }
    cout << "]" << endl;
}
