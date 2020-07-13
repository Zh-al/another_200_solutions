public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int[] result = new int[nums.Length];
        int product = 1;
        result[0] = 1;
        for (int i = 1; i < nums.Length; ++i) {
            product *= nums[i - 1];
            result[i] = product;
        }
        product = 1;
        for (int i = nums.Length - 2; i >= 0; --i) {
            product *= nums[i + 1];
            result[i] *= product;
        }
        return result;
    }
}
