// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

public class CountAndSay {
    public String countAndSay(int n) {
        if (n <= 1) {
            return "1";
        }
        StringBuilder res = new StringBuilder();
        res.append(1);
        for (int i = 2; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            int count = 1;
            for (int j = 0; j < res.length(); j++) {
                if (j+1 < res.length() && res.charAt(j) == res.charAt(j+1)) {
                    count++;
                } else {
                    sb.append(count);
                    sb.append(res.charAt(j));
                    count = 1;
                }
            }
            res = sb;
        }
        return res.toString();
    }
}
