//https://leetcode.com/problems/image-overlap/

public class Solution {
    public int LargestOverlap(int[][] A, int[][] B) {
        int largest = 0;
        for (int xShift = 0; xShift < A.Length; ++xShift) 
            for (int yShift = 0; yShift < A[0].Length; ++yShift) {
                largest = Math.Max(largest, ShiftAndCountOverlap(xShift, yShift, A, B));
                largest = Math.Max(largest, ShiftAndCountOverlap(xShift, yShift, B, A));
            }
        return largest;
    }
    
    private int ShiftAndCountOverlap(int xShift, int yShift, int[][] A, int[][] B) {
        int count = 0;
        for (int i = xShift; i < A.Length; ++i) {
            for (int j = yShift; j < B.Length; ++j) {
                if (A[i][j] == 1 && B[i - xShift][j - yShift] == 1)
                    ++count;
            }
        }
        return count;
    }    
};
