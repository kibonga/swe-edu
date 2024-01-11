#include "best-time-to-buy-sell-sotck-II.h"

int maxProfit(vector<int> &prices) {
    // Buy low sell high
    // Find local min and then buy
    // Find local max and then sell
    int profit = 0;
    int minPrice = 0;

    // It's only important to sell when prices stop increasing and start decreasing
    // That means we've reached local max
    // It doesn't matter if from then on prices start increasing again, we sold then at local max and can buy them again at new local min
    minPrice = prices[0];
    for(int i=1; i<prices.size(); i++) {
        if(prices[i] <= minPrice) {
            minPrice = prices[i];
            continue;
        }
        profit += prices[i] - minPrice;
        minPrice = prices[i];
    }

    return profit;
}

void runBestTimeToBuyAndSellStocksII() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit = " << maxProfit(prices) << endl;
}
