import java.util.*;
import java.io.*;

class megawoman {
    static public void main(String[] args) throws IOException {
        StringTokenizer st;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(in.readLine());

        st = new StringTokenizer(in.readLine());
        long w = Long.parseLong(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        int R = Integer.parseInt(st.nextToken());
        for (int i = 0; i < R; ++i) {
            // w + v*t = r + u*t
            // t = (r-w)/(v-u)
            st = new StringTokenizer(in.readLine());
            long r = Long.parseLong(st.nextToken());
            int u = Integer.parseInt(st.nextToken());
            long a = r - w;
            int b = v - u;
            if (a == 0) {
                System.out.println("NO");
                System.exit(0);
            }
            if (b != 0 && a % b == 0 && a/b >= 0 && w+v*a/b < N) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("SI");
    }
}
