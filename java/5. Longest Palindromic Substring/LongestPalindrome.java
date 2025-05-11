import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

class LongestPalindrome {
    public static List<Integer> longestPalindrome(String s) {
        Boolean success = false, found = false;
        Integer cntr = 0, rd = 0;
        Integer mx_cntr = 0, mx_rd = 0;
        Integer n = s.length();
        List<Integer> pldrm = new ArrayList<Integer>(Collections.nCopies(n, 1));

        for(int i = 0; i < n; i++) {
            if(success && cntr-rd-1 >= 0 && s.charAt(cntr-rd-1) == s.charAt(cntr+rd+1)) {
                ++rd;

                if(rd >= mx_rd) {
                    mx_rd = rd;
                    mx_cntr = cntr;
                }

                pldrm.set(cntr, 2*rd+1);
            } else {
                success = false;
                found = false;

                //find new center
                for(int j = 0; j < rd; j++) {
                    Integer prv_cntr = cntr-j-1;
                    Integer prv_rd = pldrm.get(prv_cntr)/2;
                    if(prv_cntr-prv_rd >= cntr-rd) pldrm.set(i, 2*prv_rd+1);

                    if(prv_cntr-prv_rd == cntr-rd) {
                        cntr += j+1;
                        rd = prv_rd;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cntr = i;
                    rd = 0;
                }
            }

            if(!success && cntr-rd-1 >= 0 && cntr+rd+1 < n && s.charAt(cntr-rd-1) == s.charAt(cntr+rd+1)) {
                success = true;

                ++rd;

                if(rd >= mx_rd) {
                    mx_rd = rd;
                    mx_cntr = cntr;
                }

                pldrm.set(cntr, 2*rd+1);
            }

            if(cntr+rd+1 == n) break;
        }

        return new ArrayList<Integer>(java.util.Arrays.asList(mx_cntr-mx_rd, 2*mx_rd+1));
    }


    public static String solve(String s) {
        StringBuilder b = new StringBuilder();

        b.append("$");
        for(int i=0; i<s.length(); i++) {
            b.append(String.valueOf(s.charAt(i)));
            b.append("$");
        }

        String c = b.toString();

        List<Integer> even = longestPalindrome(c);
        List<Integer> odd = longestPalindrome(s);


        if(even.get(1)/2 >= odd.get(1)) {
            StringBuilder d = new StringBuilder();
            for(int k=even.get(0); k<even.get(0)+even.get(1); k++) {
                if(k%2 != 0) d.append(String.valueOf(c.charAt(k)));
            }

            return d.toString();
        } else {
            return s.substring(odd.get(0), odd.get(0)+odd.get(1));
        }
    }


    public static void main(String[] args) {
        String s = "cbbd";
        System.out.println(solve(s));
    }
}