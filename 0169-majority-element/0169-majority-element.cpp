class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int value = 0;
       int count = 0;

       for(int i = 0; i < nums.size(); i++){
           if(count == 0){
            value = nums[i];
            count = 1;
           }else if(value == nums[i]){
            count++;
           }else{
            count--;
           }
       } 
       return value;
    }
};
