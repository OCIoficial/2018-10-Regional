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
            for (int j = i; j < N; ++j) {
                if (accum[j+1] - accum[i] >= M) {
                    res = Math.min(res, j - i + 1);
                }
            }
        }
        System.out.println(res);
    }
}
