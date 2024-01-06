#include "fruit-into-baskets.h"

int totalFruit(vector<int> &fruits) {
    set<int> set;
    int i, j, k, maxFruits = 0;

    for(i=0, j=0; j<fruits.size(); j++) {
        if(fruits[j] == 2) {
            int a = 1;
        }
        if(set.find(fruits[j]) == set.end()) {
            if(set.size() < 2) {
                set.insert(fruits[j]);
            }else {
                maxFruits = max(maxFruits, j-i);
                int prevFruit = fruits[j-1];
                i = j-1;
                while(fruits[i] == prevFruit) {
                    i--;
                }
                set.insert(fruits[j]);
                set.erase(fruits[i++]);
            }
        }
    }

    return max(maxFruits, j-i);
}

void runFruitIntoBasketsExample() {
//    vector<int> fruits = {1, 2, 1};
//    vector<int> fruits = {1, 2, 3, 2, 2};
//    vector<int> fruits = {0, 1, 2, 3};
//    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
        vector<int> fruits = {1,0,1,4,1,4,1,2,3};
    cout << "Max number of fruit trees = " << totalFruit(fruits);
}
