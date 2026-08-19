class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0; i<nums.size(); i++){
            hash.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(hash.contains(nums[i]-1) ){
                continue;
            }
            int maxi=1;
            int curr= nums[i];
            while(hash.contains(curr+1)){
                curr++;
                maxi++;
            }
            ans=max(maxi,ans);

        }
        return ans;
    }
};
