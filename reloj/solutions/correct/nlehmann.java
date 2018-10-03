import java.util.*;
import java.io.*;

class reloj {
    static public void main(String[] args) throws IOException {
        StringTokenizer st;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(in.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[] accum = new int[N + 1];
        String[] values = in.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            accum[i + 1] = accum[i] + Integer.parseInt(values[i]);
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            int l = i, r = N;
            while (l < r) {
                int m = l + (r - l)/2;
                int val = accum[m+1] - accum[i];
                if (val >= M) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            if (l >= N) {
                break;
            }
            res = Math.min(res, l - i + 1);
        }
        System.out.println(res);
    }
}
