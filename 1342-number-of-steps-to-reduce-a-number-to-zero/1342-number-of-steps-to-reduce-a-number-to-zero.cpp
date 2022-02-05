class Solution {
public:
    int numberOfSteps(int num,int count){
        //base case
        if(num == 0){
            return 0;
        }
        if(num % 2 == 0){
            count += 1 + numberOfSteps(num/2,count);
        }
        if(num %2 == 1){
            count += 1 + numberOfSteps(num-1,count);
        }
        return count;
    }
    int numberOfSteps(int num) {
        return numberOfSteps(num,0);
    }
};