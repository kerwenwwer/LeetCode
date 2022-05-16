func twoSum(nums []int, target int) []int {
    Mymap := make(map[int]int);
    for i:= 0; i < len(nums); i++ {
        j, ok := Mymap[target - nums[i]];
        if ok {
            sum := []int{j, i};
            return sum;
        }
        Mymap[nums[i]] = i
    }
    sum := []int{-1, -1}
    return sum
}
