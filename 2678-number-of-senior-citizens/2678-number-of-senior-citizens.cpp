class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;
        for(int i=0; i<n; ++i){
            // string str = details[i][11] + details[i][12];
            int a = details[i][11]-'0';
            int b = details[i][12]-'0';
            
            string str = to_string(a) + to_string(b);
         
            int age = stoi(str);
            if(age > 60){
                count++;
            }
        }
        return count;
    }
};