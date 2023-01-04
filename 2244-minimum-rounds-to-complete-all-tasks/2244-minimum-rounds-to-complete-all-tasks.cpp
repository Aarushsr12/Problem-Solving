class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(int i=0; i<tasks.size(); ++i){
            m[tasks[i]]++;
        }
        int count = 0;
        for(auto it : m){
            if(it.second == 1){
                return -1;
            }
            if(it.second == 2 ||  it.second == 3){
                count += 1;
            }
            else{
                count += it.second/3;
                if(it.second % 3 == 2 || it.second % 3 == 1){
                    count += 1;
                }
            }
        }
        return count;
    }
};