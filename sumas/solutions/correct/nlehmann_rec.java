import java.io.*;
import java.util.*;

class sumas {
    static String s;
    static ArrayList<Integer> vec;

    static public boolean check() {
        int sum = 0;
        for (int i = 0; i < vec.size() - 1; ++i)
            sum += vec.get(i);
        return sum == vec.get(vec.size() - 1);
    }

    static public boolean sol(int n, int i) {
        if (n == 0) {
            if (s.length() - i > 9)
                return false;
            vec.add(Integer.parseInt(s.substring(i)));
            if (check())
                return true;
            vec.remove(vec.size() - 1);
        }
        for (int j = 1; j <= Math.min(9, s.length() - i - 1); ++j) {
            vec.add(Integer.parseInt(s.substring(i, i + j)));
            if (sol(n-1, i + j))
                return true;
            vec.remove(vec.size() - 1);
        }
        return false;
    }
    static public void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        s = in.readLine();
        vec = new ArrayList<>();

        for (int i = 1; i <= 2; ++i) {
            int n = Integer.parseInt(s.substring(0, i));
            if (sol(n, i)) {
                System.out.print(n);
                for (int j = 0; j < vec.size(); ++j) {
                    System.out.print(" " + vec.get(j));
                }
                System.out.println();
                break;
            }
        }
    }
}
