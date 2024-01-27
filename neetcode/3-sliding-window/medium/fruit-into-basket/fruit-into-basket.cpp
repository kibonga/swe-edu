#include "fruit-into-basket.h"

int totalFruitMedium(vector<int> &fruits) {
    if(fruits.size() < 2) {return (int)fruits.size();}
    unordered_set<int> s;
    int maxFruits = 1;
    int i = 0, j = 0;

    for(; j<fruits.size(); j++) {
        if(s.size() < 2) {s.insert(fruits[j]);}
        if(s.count(fruits[j])) { continue;}
        maxFruits = max(maxFruits, (j - i));
        int f = fruits[j - 1];
        i = j - 1;
        while(fruits[i] == f) {
            i--;
        }
        s.erase(fruits[i++]);
        s.insert(fruits[j]);
    }

    return max(maxFruits, (j-i));
}

void runFruitIntoBasketMediumExample() {
    vector<int> f1 = {1, 2, 1};
    vector<int> f2 = {0, 1, 2, 2};
    vector<int> f3 = {3,3,3,1,2,1,1,2,3,3,4};

    cout << "Max fruits = " << totalFruitMedium(f1) << endl;
    cout << "Max fruits = " << totalFruitMedium(f2) << endl;
    cout << "Max fruits = " << totalFruitMedium(f3) << endl;
}
