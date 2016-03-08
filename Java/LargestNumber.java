// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

public class LargestNumber {
    public String largestNumber(int[] nums) {
        String s = Arrays.stream(nums)
                .mapToObj(Integer::toString)
                .sorted((String s1, String s2) -> (s2+s1).compareTo(s1+s2))
                .collect(Collectors.joining(""));
        return s.startsWith("0") ? "0" : s;
    }
}
