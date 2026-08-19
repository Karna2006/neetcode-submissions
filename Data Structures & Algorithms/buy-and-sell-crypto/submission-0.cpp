class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int l=0;
        int r=1;
        while(r<prices.size()){
            if(prices[r]> prices[l]){
            maxi=max(maxi, prices[r]-prices[l]);
        }
        else l=r;
        r++;
        }
        return maxi;

    }
};
