class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int count = 1; 
        string s = "";
        int k=0;
        
        while( i<n-1 ){
        if(chars[i] != chars[i+1]){
            k=i+1;
            s+=chars[i];
            if(count==1)
            {
                i++;
                continue;
            }
            
            else
            {
                s+=to_string(count);
                count=1;
                i++;
            }
            
            
         }
            
            
            else
            {
                // if(count==1)
                // {
                //     s+=chars[i];
                // }
                
                count++;
                i++;
            }
        } 
        
        
        s+=chars[k];
        
        if(count==1)
        {
            int j=0;
            for(auto x: s)
            {
                chars[j++]=x;
            }
            
            return j;
        }
        
        else
        {
           s+=to_string(count);
              int j=0;
            for(auto x: s)
            {
                chars[j++]=x;
            }
            
            return j;
        }
        
        
        
        
    }
};