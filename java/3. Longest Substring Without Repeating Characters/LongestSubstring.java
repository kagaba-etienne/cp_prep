import java.util.HashMap;

public class LongestSubstring {

    static int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> window = new HashMap<Character, Integer>();
        Integer tempLen = 0, maxLen = 0, start = 0;

        for(int i = 0; i < s.length(); i++) {
            if (window.containsKey(s.charAt(i))) {
                for(int j = start; j < window.get(s.charAt(i)); j++) window.remove(s.charAt(j));

                tempLen += start - window.get(s.charAt(i));
                start = window.get(s.charAt(i)) + 1;
                window.replace(s.charAt(i), i);
            } else {
                tempLen++;
                maxLen = Math.max(maxLen, tempLen);
                window.put(s.charAt(i), i);
            }
        }

        return maxLen;
    }
    public static void main(String[] args) {
        String s = "hello world!";

        System.out.println(lengthOfLongestSubstring(s));
    }
}