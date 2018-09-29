import java.util.*;
import java.io.*;

class bus {
    static public void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            int a = Integer.parseInt(in.readLine());
            if (a%2 != 0 && a > 1)
                sum += 1;
        }
        System.out.println(sum);
    }
}
