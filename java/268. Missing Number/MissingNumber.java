import java.util.ArrayList;

public class MissingNumber {
    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n*(n+1)/2;

        for(var num : nums) {
            sum -= num;
        }

        return sum;
    }
    public static void main(String[] args) {
        int[] nums = {0,1,2,3,5,6};

        System.out.println(missingNumber(nums));
    }
}