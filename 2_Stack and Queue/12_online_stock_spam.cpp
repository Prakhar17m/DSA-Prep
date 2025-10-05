#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> s; // pair<price, span>
    
public:
    StockSpanner() {
        // Stack is initialized empty
    }
    
    int next(int price) {
        int span = 1;
        
        // While current price is higher than or equal to the price on top of the stack
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second; // accumulate span
            s.pop();
        }
        
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */