#include "best-time-to-buy-and-sell-stock.h"

int maxProfitFundamentals(vector<int> &prices) {
    int p = 0;
    int sp = prices[0];

    for(int i=1; i< prices.size(); i++) {
        if(prices[i] > sp) {
            p = max(p, prices[i] - sp);
            continue;
        }
        sp = prices[i];
    }

    return p;
}

void runBestTimeToBuyAndSellStockFundamentalsExample() {
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    cout << "Max profit = " << maxProfitFundamentals(p1) << endl;
}
