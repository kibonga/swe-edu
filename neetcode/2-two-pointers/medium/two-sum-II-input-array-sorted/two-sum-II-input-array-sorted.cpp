#include "two-sum-II-input-array-sorted.h"

vector<int> twoSumIIInputArraySorted(vector<int> &numbers, int target) {
    int i=0, j=numbers.size()-1;
    int sum;

    while(i < j) {
        sum = numbers[i] + numbers[j];
        if(sum > target) {
            j--;
            continue;
        }
        if(sum < target) {
            i++;
            continue;
        }
        break;
    }

    return {i+1, j+1};
}

void displayTwoSumIIInputArraySorted(vector<int> &nums) {
    cout << "Result = [ ";
    for(int n : nums) {
        cout << n << " ";
    }
    cout << "]" << endl;
}

void runTwoSumIIInputArraySortedExample() {
    vector<int> n1 = {2, 7, 11, 15};
    int t1 = 9;

    vector<int> v1 = twoSumIIInputArraySorted(n1, t1);
    displayTwoSumIIInputArraySorted(v1);
}
