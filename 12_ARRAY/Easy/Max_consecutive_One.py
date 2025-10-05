def find_max_consecutive_ones(nums):
    count =0
    max_count = 0
    for number in nums:
        if number == 1:
            count += 1
            max_count = max(max_count, count)
        else:
            count = 0
    return max_count