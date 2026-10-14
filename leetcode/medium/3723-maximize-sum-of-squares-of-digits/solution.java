class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9L * num) return "";

        StringBuilder sb = new StringBuilder();
        int q = sum / 9;
        int r = sum % 9;

        for (int i = 0; i < q; i++) {
            sb.append('9');
        }
        if (r > 0) {
            sb.append((char) ('0' + r));
        }
        while (sb.length() < num) {
            sb.append('0');
        }
        return sb.toString();
    }
}