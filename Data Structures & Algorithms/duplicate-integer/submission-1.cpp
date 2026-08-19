class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> dup;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(dup.count(nums[i])){
            return true;
        }
        dup.insert(nums[i]);
    }
    return false;
    } 
};