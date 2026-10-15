class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff;
        for(int i=0;i<nums.size();i++){
            int comp= target-nums[i];
            if(diff.find(comp) != diff.end()){
                return {diff[comp],i};

            }
            diff[nums[i]]=i;

        }
        return {};
    }
};
