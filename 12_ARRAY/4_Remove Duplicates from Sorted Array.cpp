// problem solving = https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (int i =0;i<nums.size();i++){
            if (nums[j] != nums[i]){
                nums[++j]=nums[i];
            }
        }
        return j+1 ;
    }
};


// python code 

// class Solution:
//     def removeDuplicates(self, nums: List[int]) -> int:
//         j = 0
//         for i in  range(1,len(nums)):
//             if(nums[j] != nums[i]):
//                 j = j+1
//                 nums[j] = nums[i]
//         return j+1

