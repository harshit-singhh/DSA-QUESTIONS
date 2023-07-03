class StockSpanner {
public:
    vector<int> prices;
    stack<int> s;
    StockSpanner() {
        //Day #0 has the highest stock price (to ease implementation)
        
        prices.push_back(1e6);
        s.push(0);
    }
    
    int next(int price) {
        while(price >= prices[s.top()]){
            s.pop();
        }
        int ans = prices.size() - s.top();
        s.push(prices.size());
        prices.push_back(price);
        return ans;
    }
};