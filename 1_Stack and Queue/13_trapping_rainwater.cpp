class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n), maxr(n), water(n);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        for(int i=1;i< n; i++){
            maxl[i] = max(maxl[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxr[i]= max(maxr[i+1],height[i]);
        }
        for(int i=0;i< n; i++){
            water[i] = min(maxl[i],maxr[i])-height[i];
        }
        int sum =0;
        for(int i=0;i< n; i++){
            sum = sum + water[i];
        }
        return sum;

    }
};