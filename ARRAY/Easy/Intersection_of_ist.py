def intersection(nums1, nums2):
    nums1 = set(nums1)
    nums2= set(nums2)
    return list(nums1 & nums2)