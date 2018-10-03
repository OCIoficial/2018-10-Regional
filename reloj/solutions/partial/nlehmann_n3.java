import java.util.*;
import java.io.*;

class reloj {
    static public void main(String[] args) throws IOException {
        StringTokenizer st;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(in.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        ArrayList<Integer> arr = new ArrayList<>();
        String[] values = in.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            arr.add(Integer.parseInt(values[i]));
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += arr.get(k);
                }
                if (sum >= M) {
                    res = Math.min(res, j - i + 1);
                }
            }
        }
        System.out.println(res);
    }
}
