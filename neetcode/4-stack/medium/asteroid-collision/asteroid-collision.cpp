#include "asteroid-collision.h"

vector<int> asteroidCollisionMedium(vector<int> &a) {
    vector<int> v;
    int n = a.size();
    int curr;

    for (int i = n - 1; i >= 0; i--) {
        curr = a[i];
        if (v.empty() || curr < 0 || (curr > 0 && v.back() > 0)) {
            v.push_back(curr);
            continue;
        }

        // Collision (curr is greater than 0)
        int x = v.back(); // smaller than 0
        while(!v.empty() && curr > abs(x)) {
            v.pop_back();
            x = v.back();
        }
        if(curr == abs(x)) {
            v.pop_back();
            continue;
        }
        if(curr > abs(x)) {
            v.push_back(curr);
        }
    }

    reverse(v.begin(), v.end());

    return v;
}

void runAsteroidCollisionMediumExample() {
    vector<int> a1 = {5, 10, -5};
    vector<int> a2 = {8, -8};
    vector<int> a3 = {10, 2, -5};
    auto r1= asteroidCollisionMedium(a1);
    auto r2= asteroidCollisionMedium(a2);
    auto r3= asteroidCollisionMedium(a3);
    int a = 1;
}
