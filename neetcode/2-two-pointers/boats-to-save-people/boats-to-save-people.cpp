#include "boats-to-save-people.h"

int numOfRescueBoats(vector<int> people, int limit) {
    int numOfBoats = 0;
    int i=0, j=people.size()-1, w;

    sort(people.begin(), people.end());

    while(i <= j) {
        numOfBoats++;
        w = people[i] + people[j];
        if(w > limit) {
            j--;
            continue;
        }
        i++, j--;
    }

    return numOfBoats;
}

void runBoatsToSavePeopleExample() {
    vector<int> people1 = {1, 2};
    int limit1 = 3;
    vector<int> people2 = {3, 2, 2, 1};
    int limit2 = 3;
    vector<int> people3 = {3, 5, 3, 4};
    int limit3 = 5;

    cout << "Number of boats required = " << numOfRescueBoats(people1, limit1) << endl;
    cout << "Number of boats required = " << numOfRescueBoats(people2, limit2) << endl;
    cout << "Number of boats required = " << numOfRescueBoats(people3, limit3) << endl;

}
