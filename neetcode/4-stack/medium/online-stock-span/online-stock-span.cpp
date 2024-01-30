#include "online-stock-span.h"

class StockSpanner {
public:
    vector<pair<int, int>> v;

    StockSpanner() {
    }

    int next(int price) {
        int d = 1;
        int i = v.size() - 1;

        while (i >= 0 && v[i].second <= price) {
            d += v[i].first;
            i -= v[i].first;
        }

        v.push_back(make_pair(d, price));

        return d;
    }
};

void runOnlineStockSpanMediumExample() {
    StockSpanner stockSpanner = StockSpanner();
    stockSpanner.next(100); // return 1
    stockSpanner.next(80);  // return 1
    stockSpanner.next(60);  // return 1
    stockSpanner.next(70);  // return 2
    stockSpanner.next(60);  // return 1
    stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price
}
