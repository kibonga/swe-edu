#include "car-fleet.h"

int carFleetMedium(int target, vector<int> &p, vector<int> &s) {
    vector<pair<int, double>> t;
    int n = p.size();

    for (int i = 0; i < n; i++) {
        t.push_back(make_pair(p[i], (double) (target - p[i]) / s[i]));
    }

    sort(t.begin(), t.end(),
         [](const pair<int, double> &a, pair<int, double> &b) {
             return a.first < b.first;
         });

    int cnt = 0;
    double maxTime = 0;
    double currTime = 0;
    for (int i = n - 1; i >= 0; i--) {
        currTime = t[i].second;
        if (currTime > maxTime) {
            cnt++;
            maxTime = currTime;
        }
    }

    return cnt;
}

void runCarFleetMediumExample() {
    int t1 = 12;
    vector<int> p1 = {10, 8, 0, 5, 3};
    vector<int> s1 = {2, 4, 1, 1, 3};

    cout << "Result = " << carFleetMedium(t1, p1, s1) << endl;
}
