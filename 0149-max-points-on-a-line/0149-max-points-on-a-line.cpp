class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     int n = points.size();
    int Max = INT_MIN;
     if(n == 1){
         return 1;
     }   
     for(int i=0; i<n; ++i){
            unordered_map<double,int> m;
          for(int j=0; j<n; ++j){
              if(i == j){
                  continue;
              }
              auto dy = (points[j][1]-points[i][1]);
              auto dx = (points[j][0] - points[i][0]);
              auto slope = atan2(dy,dx);
              m[slope]++;
          } 
      for(auto it : m){
         Max = max(Max,it.second+1); 
      }
         
     }
      return Max;  
        
    }
};