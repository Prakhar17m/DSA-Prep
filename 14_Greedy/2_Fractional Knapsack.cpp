//practice link = https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // Vector to store (value/weight ratio, weight, value)
        vector<pair<double, pair<int, int>>> items;
        
        for (int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {wt[i], val[i]}});
        }
        
        // Sort items by ratio in descending order
        sort(items.begin(), items.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        
        double maxValue = 0.0;
        
        for (auto &item : items) {
            double ratio = item.first;
            int weight = item.second.first;
            int value = item.second.second;
            
            if (capacity == 0) break;
            
            if (weight <= capacity) {
                // Take the whole item
                capacity -= weight;
                maxValue += value;
            } else {
                // Take fractional part
                maxValue += ratio * capacity;
                capacity = 0;
            }
        }
        
        return maxValue;
    }
};
