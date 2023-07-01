class Solution {
public:
    int Min = INT_MAX;
    void distribution(vector<int>&cookies,int index,int n,int k,vector<int>&v){
        //base case
        if(index == n){
            //we will return max value of the v 
            int ans = *max_element(v.begin(),v.end());
            Min = min(ans,Min);
            return;
        }
        
        for(int i=0; i<k; ++i){
            v[i] += cookies[index];
            distribution(cookies,index+1,n,k,v);
            v[i] -= cookies[index];
            if(v[i] == 0){
                break;
            }
        }    
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> v(k,0);
        distribution(cookies,0,n,k,v);
        return Min;
    }
};