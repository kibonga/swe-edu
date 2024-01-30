#include "asteroid-collision.h"

vector<int> asteroidCollisionMedium(vector<int> &a) {
    vector<int> r;
    int l;

    for(int i=0; i<a.size(); i++) {
        if(r.empty() || a[i] > 0) {
            r.push_back(a[i]);
            continue;
        }

        while(!r.empty() && r.back() > 0 && r.back() < abs(a[i])) {
            r.pop_back();
        }

        if(r.empty() || r.back() < 0) {
            r.push_back(a[i]);
            continue;
        }

        if(r.back() == abs(a[i])) {
            r.pop_back();
            continue;
        }

    }

    return r;
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
