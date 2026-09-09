import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int n = (int)in.nval;

        long[] prefix = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            in.nextToken();
            prefix[i] = prefix[i-1] + (long)in.nval;
        }

        // min_t = max over i of ceil(prefix[i] / i)
        long minT = 0;
        for (int i = 1; i <= n; i++) {
            long required = (prefix[i] + i - 1) / i; // ceil(prefix[i] / i)
            minT = Math.max(minT, required);
        }

        long totalSum = prefix[n];

        in.nextToken(); int q = (int)in.nval;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            in.nextToken();
            long t = (long)in.nval;
            if (t < minT) {
                sb.append(-1).append('\n');
            } else {
                sb.append((totalSum + t - 1) / t).append('\n');
            }
        }
        System.out.print(sb);


    }
}