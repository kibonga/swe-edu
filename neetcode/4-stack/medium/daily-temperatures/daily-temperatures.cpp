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

string removeKdigitsMedium(string num, int k) {
    if (num.size() == k) {
        return "0";
    }

    stack<char> st;
    int i = 0;

    while (i < num.size()) {
        while (!st.empty() && st.top() > num[i] && k > 0) {
            st.pop();
            k--;
        }
        if (st.empty() && num[i] == '0') {
            i++;
            continue;
        }
        st.push(num[i++]);
    }


    while (k > 0 && !st.empty()) {
        k--;
        st.pop();
    }

    if (st.empty()) { return "0"; }

    string r = "";
    while (!st.empty()) {
        r += st.top();
        st.pop();
    }

    reverse(r.begin(), r.end());

    return r;
}

string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st;

    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.back().first != s[i]) {
            st.push_back({s[i], 1});
            continue;
        }
        if (st.back().second < k) {
            st.push_back({s[i], st.back().second + 1});
            continue;
        }
        int m = k;
        while (m) {
            m--;
            st.pop_back();
        }
        m = k;
    }

    string r = "";
    for (auto &p: st) {
        r += p.first;
    }

    return r;

}

bool find132pattern(vector<int>& nums) {
    int maxNum = INT32_MIN;
    int idx = -1;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > maxNum) {
            idx = i;
        }
        maxNum = max(maxNum, nums[i]);
    }

    vector<int> left;
    vector<int> right;

    for(int i=0; i<idx; i++) {
        left.push_back(nums[i]);
    }

    for(int i=idx+1; i<nums.size(); i++) {
        right.push_back(nums[i]);
    }

    if(left.empty() || right.empty()) {return false;}

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    return left.front() < right.back();
}

void runDailyTemperaturesMediumExample() {
//    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
//    dailyTemperaturesMedium(t1);
//
//    string r = simplifyPath("/../");
//    cout << "Result = " << r << endl;

    string s1 = "1432219";
    int k1 = 3;

    string s2 = "10200";
    int k2 = 1;

    string s3 = "10001";
    int k3 = 4;

//    cout << "Result = " << removeKdigitsMedium(s1, k1) << endl;
//    cout << "Result = " << removeKdigitsMedium(s3, k3) << endl;
//    cout << "Result = " << removeKdigitsMedium(s3, k3) << endl;


//    cout << "Result = " << removeDuplicates("deeedbbcccbdaa", 3) << endl;

    vector<int> n1 = {1, 2, 3, 4};
    vector<int> n2 = {3, 1, 4, 2};
    vector<int> n3 = {-1, 3, 2, 0};

    cout << "Result = " << find132pattern(n1) << endl;
    cout << "Result = " << find132pattern(n2) << endl;
    cout << "Result = " << find132pattern(n3) << endl;
}
