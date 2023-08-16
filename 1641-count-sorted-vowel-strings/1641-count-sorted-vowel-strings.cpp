class Solution {
public:
    int count = 0;
    void countStrings(int index,vector<char>&vowels, vector<char>&temp,int n){
        if(temp.size() == n){
            count++;
            return;
        }
        for(int i= index; i<vowels.size(); ++i){
            temp.push_back(vowels[i]);
            countStrings(i,vowels,temp,n);
            temp.pop_back();
        }
        return;
        
    }
    int countVowelStrings(int n) {
        vector<char> vowels = {'a','e','i','o','u'};
        
        vector<char> temp;
        countStrings(0,vowels,temp,n);
        
        return count;
    }
};