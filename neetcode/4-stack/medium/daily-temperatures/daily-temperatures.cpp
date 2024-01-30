#include "daily-temperatures.h"

vector<int> dailyTemperaturesMedium(vector<int> &temps) {
    vector<pair<int, int>> ts;
    vector<int> r;

    for (int i = temps.size() - 1; i >= 0; i--) {
        while (!ts.empty() && ts.back().first < temps[i]) {
            ts.pop_back();
        }


        if (ts.empty()) {
            ts.push_back(make_pair(temps[i], i));
            r.push_back(0);
            continue;
        }

        ts.push_back(make_pair(temps[i], i));
        r.push_back(ts.back().second - i);
    }

    sort(r.begin(), r.end());

    return r;
}

string simplifyPath(string path) {
    vector<string> v;
    string s;

    for (int i = 1; i < path.size(); i++) {
        s = "";
        while (i < path.size() && path[i] != '/') {
            s += path[i++];
        }

        if (s.empty() || s == ".") {
            continue;
        }
        if (s == "..") {
            if (v.empty()) {
                continue;
            }
            v.pop_back();
            continue;
        }

        v.push_back(s);
    }

    s = "";
    for (string &r: v) {
        s += "/" + r;
    }

    return s.empty() ? "/" : s;
}

void runDailyTemperaturesMediumExample() {
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTemperaturesMedium(t1);

    string r = simplifyPath("/../");
    cout << "Result = " << r << endl;
}
