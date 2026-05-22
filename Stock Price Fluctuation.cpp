// Problem link ---->
https://leetcode.com/problems/stock-price-fluctuation/description/

// Solution ---->
class StockPrice {
public:

    unordered_map<int, int> mp;
    multiset<int> prices;
    int latest = 0;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            int oldPrice = mp[timestamp];
            prices.erase(prices.find(oldPrice));
        }

        mp[timestamp] = price;
        prices.insert(price);
        latest = max(latest, timestamp);
    }
    
    int current() {
        return mp[latest];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */