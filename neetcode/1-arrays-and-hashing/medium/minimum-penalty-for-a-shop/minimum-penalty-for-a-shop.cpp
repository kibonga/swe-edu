#include "minimum-penalty-for-a-shop.h"

int bestClosingTime(string &customers) {
    int n = customers.size();
    char c;
    // [OPEN][j][CLOSE]
    // keep in mind [open)(j)[close]
    vector<int> openPenalties(n+1, 0); // Penalties that are accumulated while open
    vector<int> closePenalties(n+1, 0); // Penalties that are accumulated while close

    // Penalties while open are only counted when store doesn't have any visitors
    // No visitors - N
    for(int i=1; i<n+1; i++) {
        c = customers[i-1];
        openPenalties[i] = openPenalties[i-1];
        if(c == 'N') {
            openPenalties[i]++;
        }
    }
    openPenalties[n] = openPenalties[n-1];

    for(int i=customers.size()-1; i>=0; i--) {
        c = customers[i];
        closePenalties[i] = closePenalties[i+1];
        if(c == 'Y') {
            closePenalties[i]++;
        }
    }

    int minPenalty = INT32_MAX;
    int index = -1;
    int currentPenalties;
    for(int j=0; j<n+1; j++) {
        currentPenalties = openPenalties[j] + closePenalties[j];
        if(currentPenalties < minPenalty) {
            minPenalty = currentPenalties;
            index = j;
        }
    }

    return index;
}

void runMinimumPenaltyForAShopExample() {
//    string c1 = "YYNY";
    string c1 = "YNYY";
    cout << "Minimum penalty = " << bestClosingTime(c1) << endl;
}
