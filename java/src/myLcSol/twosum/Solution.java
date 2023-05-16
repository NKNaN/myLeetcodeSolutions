package myLcSol.twosum;

import java.util.Arrays;

public class Solution {
	public static void main(String[] args) {
		int[] t1 = {2,7,11,15};
		int[] t2 = {3,2,4};
		int[] t3 = {3,3};
		
		int[] res1 = twoSum(t1,9);
		int[] res2 = twoSum(t2,6);
		int[] res3 = twoSum(t3,6);
		System.out.println(Arrays.toString(res1));
		System.out.println(Arrays.toString(res2));
		System.out.println(Arrays.toString(res3));
	}
	
	public static int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        int n = nums.length;
        int i = 0;
        while(i<n){
            for(int j=i+1;j<n;j++){
                if((nums[i]+nums[j]) == target){
                    ret[0] = i;
                    ret[1] = j;
                    break;
                }
            }
            i++;
        }
        return ret;
    }
}
