def move_zeroes(nums):
    non_zero_index = 0 
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[non_zero_index] = nums[i]
            non_zero_index += 1
    while non_zero_index < len(nums):
        nums[non_zero_index] = 0
        non_zero_index += 1