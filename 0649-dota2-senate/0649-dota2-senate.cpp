class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> dq;
        queue<int> rq;
        
        for(int i=0; i<n; ++i){
            if(senate[i] == 'R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }
        while(!rq.empty() && !dq.empty()){
            int index1 = rq.front();
            int index2 = dq.front();
            
            //remove both the elements
            rq.pop();
            dq.pop();
            
            if(index1 < index2){
                rq.push(index1 + n);
            }            
            else{
                dq.push(index2 + n);
            }
        }
        
        return (rq.empty() ==  true) ? "Dire" : "Radiant";
    }
};