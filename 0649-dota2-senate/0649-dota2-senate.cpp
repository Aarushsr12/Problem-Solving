class Solution {
public:
    void ban(string &senate,vector<bool> &banned,char ban,int start){
        while(true){
            if(senate[start]==ban && !banned[start]){
                banned[start] = true;
                break;
            }
            start = (start + 1 ) % senate.size();
        }
    }
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<bool> banned(n, false);
        int rCount = 0;
        int dCount = 0;
        //count of senates
        for(int i=0;  i<n; ++i){
            if(senate[i] == 'R'){
                rCount++;
            }
            else{
                dCount++;
            }
        }
        //now at last only one senate members should remain
        int i = 0;
        while(rCount > 0 && dCount > 0){
            if(banned[i] == false){
                if(senate[i] == 'R'){
                    ban(senate,banned,'D',(i+1) % n);
                    dCount--;
                }
                else{
                    ban(senate,banned,'R',(i+1) % n);
                    rCount--;
                }
            }
            i = (i+1) % n;
        }
        return (rCount == 0) ? "Dire" : "Radiant";
    }
};