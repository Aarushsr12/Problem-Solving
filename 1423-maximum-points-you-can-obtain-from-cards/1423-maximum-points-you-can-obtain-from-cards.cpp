class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> Sum(cardPoints.size(),0);
        int sum =0;
        //precalculated sum
        for(int i=0; i<n; ++i){
            sum += cardPoints[i];
            Sum[i] = sum;
        }
        //sliding window technique
        if(n == k){
            return sum;
        }
        int ans = 0;
        int score = 0;
        for(int i=0; i<=k; ++i){
            int j = i + (n - k - 1);
            if(i == 0){
                ans = Sum[j];
            }
            else{
                ans = Sum[j] - Sum[i-1];
            }
            score = max(score, sum - ans);
        }
        return score;
    }
};