class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq_map;
        for(char task:tasks){
            freq_map[task]++;
        }

        priority_queue<int> maxheap;
        for(auto& pair: freq_map){
            maxheap.push(pair.second);
        }

        queue<pair<int,int>> cool_down;
        int time=0;

        while(!maxheap.empty() || !cool_down.empty()){
            time++;

            if(!cool_down.empty() && cool_down.front().second==time){
                maxheap.push(cool_down.front().first);
                cool_down.pop();
            }

            if(!maxheap.empty()){
                int count= maxheap.top()-1;
                maxheap.pop();
                if(count>0){
                    cool_down.push({count, time+n+1});
                }
            }
        }
        return time;
    }
};
