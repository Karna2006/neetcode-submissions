class Solution {
public:
    vector<int> arr;
    int climbStairs(int n) {
        arr.resize(n,-1);
        return dfs(n,0);
    }
    int dfs(int n, int i){
        if(i>=n) return i==n;
        if(arr[i]!= -1) return arr[i];
        return arr[i]= dfs(n,i+1) + dfs(n,i+2);
    }
};
