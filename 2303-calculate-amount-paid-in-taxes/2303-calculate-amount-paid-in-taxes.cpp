class Solution {
public:
    double taxCal(int num,int per){
        double p = double(per/100.0);
        return num * p;
    }
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        int prev =0;
        double tax=0.0;
        for(int i=0; i<n; ++i){
            if(brackets[i][0] < income){
                int amt = brackets[i][0] - prev;
                tax += taxCal(amt,brackets[i][1]);
                prev = brackets[i][0];
            }
            else{
                int amt = income - prev;
                tax += taxCal(amt,brackets[i][1]);
                break;
            }
        }
        return tax;
    }
};