def nextPermutation(nums: 'List[int]') -> 'None':
    """
    Do not return anything, modify nums in-place instead.
    """
    k = None
    for i in range(len(nums) - 1, 0, -1):
        if nums[i] > nums[i - 1]:
            k = i
            break
    else:
        k = 0
    
    if k:
        swap = k - 1
        pre = nums[swap]
        
        pivot = k
        for i in range(k + 1, len(nums)):
            if nums[i] <= pre:
                break
            else:
                pivot = i
        
        nums[swap], nums[pivot] = nums[pivot], nums[swap]
    
    nums[k:] = nums[k:][::-1]

if __name__ == "__main__":
    # l = [2,2,3,4,2,3,1,1,2]
    # l = [1, 2, 4, 3]
    # l = [4, 2, 3, 1]
    l = [4, 3, 2, 1]
    # l = [1, 2, 3]
    nextPermutation(l)
    print(l)