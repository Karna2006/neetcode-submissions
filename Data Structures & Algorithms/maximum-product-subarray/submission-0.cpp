class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();

        vector<int> dpmax(n);
        vector<int>dpmin(n);

        dpmax[0]= nums[0];
        dpmin[0]= nums[0];

        int res= nums[0];

        for(int i=1; i<n;i++){
            int prod1= nums[i]*dpmax[i-1];
            int prod2= nums[i]*dpmin[i-1];

            dpmax[i]= std::max({nums[i], prod1,prod2});
            dpmin[i]= std:: min({nums[i],prod1,prod2});

            res= max(res,dpmax[i]);
        }

        return res;
    }
};
