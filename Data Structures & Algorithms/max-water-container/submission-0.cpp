class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi= 0;
        int l=0;
        int r= heights.size()-1;
        while(l<r){
            int area= min(heights[l],heights[r])* (r-l);
            maxi= max(maxi, area);
            if(heights[l]<=heights[r]) l++;
            else r--;
        }
        return maxi;
    }
};
