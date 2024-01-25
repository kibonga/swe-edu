#include "arr-with-elems-not-equal-to-avg-of-neighbors.h"

vector<int> rearrangeArrayMedium(vector<int> &nums) {


    return nums;
}

void runArrayWithElementsNotEqualToAverageOfNeighborsMediumExample() {
    vector<int> n1 = {1, 2, 3, 4, 5};
    rearrangeArrayMedium(n1);

    cout << "Rearranged = [ ";
    for(int n : n1) {
        cout << n << " ";
    }
    cout << "]" << endl;
}
