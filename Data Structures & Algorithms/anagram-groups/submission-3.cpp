class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for (const auto& s : strs ){
            vector<int> count(26,0);
            for(char c : s){
                count[c- 'a']++;
            }
            string key = "";            for(int i=0; i<26 ; i++){
                key+= ','+ count[i];
            }
            res[key].push_back(s);
        
        }
        vector<vector<string>> result;
        for( auto& pair : res){
            result.push_back(pair.second);
        }
        return result;
    }
};
