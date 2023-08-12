class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        for(auto it : roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        long long count=1;
        long long sum = 0;
        for(auto i : indegree){
            sum += i * count++;
        }
        return sum;
    }
};