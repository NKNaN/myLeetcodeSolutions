package myLcSol.twosum;

import java.util.Arrays;
import java.util.HashMap;

public class Solution2 {
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
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],i);
        }
        for(int i=0;i<nums.length;i++){
        	Integer num = target-nums[i];
        	if(map.containsKey(num)&&((map.get(num)) != i)){
        		return new int[]{i,map.get(num)};
        	}
        }
        return new int[2];
    }
}
