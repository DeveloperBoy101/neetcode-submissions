class Solution {
public:
     
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        //
            for(int&num :nums){
                mp[num]++;
            }
        
        //define min heap :
        priority_queue<P, vector<P>, greater<P>> pq;
        //push element in min heap
        //maintain size k only
        for(auto &it : mp){
            int val = it.first;
            int freq = it.second;

            pq.push({freq,val});
            if(pq.size() >k){
                pq.pop();
            }
        }
    //result:
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
    }
};
