#include "find-k-closest-elements.h"

vector<int> findClosestElementsMedium(vector<int> &arr, int k, int x) {
    vector<int> smaller;
    vector<int> larger;
    vector<int> r;
    int n = arr.size();
    int idx = -1;

    if(x < arr[0] || x > arr[n-1]) {
        for(int i=0; i < k; i++) {
            r.push_back(arr[i]);
        }
        return r;
    }

    for(int i=n-1; i>=0; i--) {
        if(arr[i] < x) {
            break;
        }
        idx = i;
        if(arr[i] == x) {
            break;
        }
    }
    if(idx == -1) {return {};}

    int i = idx - 1;
    int j = idx + 1;
    int a, b;
    while(i >= 0 && j < n && k > 1) {
        a = abs(arr[i] - x);
        b = abs(arr[j] - x);
        if(a <= b) {
            smaller.push_back(arr[i--]);
        }else {
            larger.push_back(arr[j++]);
        }
        k--;
    }

    while(k > 1 && i >= 0) {
        smaller.push_back(arr[i--]);
        k--;
    }

    while(k > 1 && j < n) {
        larger.push_back(arr[j++]);
        k--;
    }

    reverse(smaller.begin(), smaller.end());

    for(int s : smaller) {
        r.push_back(s);
    }
    r.push_back(arr[idx]);
    for(int l : larger) {
        r.push_back(l);
    }

    return r;
}

void displayFindClosestElementsMedium(vector<int> &nums) {
    cout << "Result = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

void runFindClosestElementsMediumExample() {
    vector<int> n1 = {0,0,1,2,3,3,4,7,7,8};
    int k1 = 3;
    int x1 = 5;

    vector<int> r1 = findClosestElementsMedium(n1, k1, x1);
    displayFindClosestElementsMedium(r1);
}
