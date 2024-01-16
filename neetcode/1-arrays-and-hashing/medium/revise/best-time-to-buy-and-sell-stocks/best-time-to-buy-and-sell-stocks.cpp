#include "best-time-to-buy-and-sell-stocks.h"

int maxProfitReview(vector<int> &prices) {
    // Whole point is to have as many transactions as possible while
    // finding local min and selling at local max
    int profit = 0;

    int i = 0;
    int localMin;
    int localMax;
    // This will find local min and max and only then do calculations
    // Time is O(n), but contains three while loops, which makes it harder to read
    // Profit will be applied only when local MIN and MAX are found
    while(i < prices.size()) {
        localMin = prices[i];
        while(i+1 < prices.size() && prices[i+1] < prices[i]) {
            localMin = prices[i+1];
            i++;
        }
        localMax = prices[i];
        while(i+1 < prices.size() && prices[i+1] > prices[i]) {
            localMax = prices[i+1];
            i++;
        }
        profit += localMax - localMin;
        i++;
    }

    return profit;
}

int maxProfitReviewSellImmediately(vector<int> &prices) {
    int profit = 0;
    int minPrice = INT32_MAX;

    // This will only try to find local min, and after that it will always sell and buy
    // immediately while the price is going up
    // It will adjust the current min price based on previous profit calculation
    // Takeaway is that it will ALWAYS calculate profit if it can (price is going up)
    // Time complexity is O(n)
    for(int p : prices) {
        if(p < minPrice) {
            minPrice = p;
            continue;
        }
        profit += p - minPrice;
        minPrice = p;
    }

    return profit;
}

void runBestTimeToBuyAndSellStocksIIExampleReview() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit = " << maxProfitReview(prices) << endl;
}
