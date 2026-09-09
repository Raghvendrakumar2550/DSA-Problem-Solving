import java.io.*;
import java.util.*;

class R {
    static ArrayList<Integer>[] graph;
    static int[] parent, state;
    static int cycleStart = -1, cycleEnd = -1;

    static boolean dfs(int node, int par) {
        state[node] = 1;

        for (int next : graph[node]) {
            if (next == par) continue;

            if (state[next] == 0) {
                parent[next] = node;

                if (dfs(next, node)) {
                    return true;
                }
            } else if (state[next] == 1) {
                cycleStart = next;
                cycleEnd = node;
                return true;
            }
        }

        state[node] = 2;
        return false;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        int n = fs.nextInt();
        int m = fs.nextInt();

        graph = new ArrayList[n + 1];
        parent = new int[n + 1];
        state = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = fs.nextInt();
            int b = fs.nextInt();

            graph[a].add(b);
            graph[b].add(a);
        }

        for (int i = 1; i <= n; i++) {
            if (state[i] == 0 && dfs(i, 0)) {
                break;
            }
        }

        if (cycleStart == -1) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        ArrayList<Integer> cycle = new ArrayList<>();
        cycle.add(cycleStart);

        int current = cycleEnd;

        while (current != cycleStart) {
            cycle.add(current);
            current = parent[current];
        }

        cycle.add(cycleStart);

        StringBuilder sb = new StringBuilder();
        sb.append(cycle.size()).append('\n');

        for (int node : cycle) {
            sb.append(node).append(' ');
        }

        System.out.println(sb);
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;

                if (len <= 0) {
                    return -1;
                }
            }

            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;

            do {
                c = read();
            } while (c <= ' ');

            int sign = 1;

            if (c == '-') {
                sign = -1;
                c = read();
            }

            int value = 0;

            while (c > ' ') {
                value = value * 10 + c - '0';
                c = read();
            }

            return value * sign;
        }
    }
}