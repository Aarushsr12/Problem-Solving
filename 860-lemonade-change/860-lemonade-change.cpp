class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five=0;
        int ten=0;
        
        for(int i=0; i<n; ++i){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                ten++;
                if(five>0){
                    five--;
                }
                else{
                    return false;
                }
            }
            else if(bills[i] == 20){
                
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};