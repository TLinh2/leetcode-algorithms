"""
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
"""


# Solution 1: Brute Force
def solve_two_sum1(nums, target):
    i = 0
    while i < len(nums):
        j = i + 1
        while j < len(nums):
            if nums[i] + nums[j] == target:
                return [i, j]
            j += 1
        i += 1
    return False

print(solve_two_sum1([2,7,11,15], 9))

# Solution 2: Two Pointers
def solve_two_sum2(nums, target):
    nums_with_index = [(number, index) for index, number in enumerate(nums)]
    nums_with_index.sort()
    print(nums_with_index)

    print(nums)
    i = 0
    j = len(nums) - 1
    while i < j:
        if nums_with_index[i][0] + nums_with_index[j][0] > target:
            if i + 1 == j:
                return False
            j -= 1
        if nums_with_index[i][0] + nums_with_index[j][0] < target:
            if i + 1 == j:
                return False
            i += 1
        if nums_with_index[i][0] + nums_with_index[j][0] == target:
            return [nums_with_index[i][1], nums_with_index[j][1]]
    
print(solve_two_sum2([3,2,4], 6))