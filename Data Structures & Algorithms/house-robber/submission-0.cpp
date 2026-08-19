class Solution {
public:
    vector<int> arr;
    int rob(vector<int>& nums) {
        arr.resize(nums.size(),-1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i){
        if(i>= nums.size()) return 0;
        
        if(arr[i]!= -1) return arr[i];

        arr[i]= max(dfs(nums, i+1), nums[i] + dfs(nums,i+2));

        return arr[i];
    }
};
