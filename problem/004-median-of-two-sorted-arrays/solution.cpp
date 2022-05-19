func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    //make sure lens of first less than lens of secnd  
    if len(nums1) > len(nums2){
        return findMedianSortedArrays(nums2, nums1)
    }
    
    low, high, Mid_1, Mid_2, k := 0, len(nums1), 0, 0, (len(nums1) + len(nums2) +1 ) >> 1
    
    for low <= high {
        Mid_1 = low + (high - low) >> 1
        Mid_2 = k - Mid_1                                  // num2Mid  = len(nums1 + nums2)Mid - len(nums1)Mid
        if Mid_1 > 0 && nums1[Mid_1 -1 ] > nums2[Mid_2] {    
            high = Mid_1 - 1
        } else if Mid_1 != len(nums1) && nums1[Mid_1] < nums2[Mid_2 - 1] {  
            low = Mid_1 + 1
        } else {
            break
        }
        
    }
    
    midLeft, midRight := 0, 0
    
    if Mid_1 == 0 {
        midLeft = nums2[Mid_2 - 1]
    } else if Mid_2 == 0 {
        midLeft = nums1[Mid_1 - 1]
    } else {
        midLeft = max(nums1[Mid_1 - 1], nums2[Mid_2 - 1])
    }
    
    if (len(nums1)+len(nums2))&1 == 1 {
		return float64(midLeft)
	}
    
    if Mid_1 == len(nums1) {
        midRight = nums2[Mid_2]
    } else if Mid_2 == len(nums2) {
        midRight = nums1[Mid_1]
    } else {
        midRight = min(nums1[Mid_1], nums2[Mid_2])
    }
    
    return float64(midLeft + midRight) / 2
    
}

func max (a int, b int) int{
    if a > b {
        return a
    }
    return b
}

func min (a int, b int) int{
    if a > b {
        return b
    }
    return a
}
