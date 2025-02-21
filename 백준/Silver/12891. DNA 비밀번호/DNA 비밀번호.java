
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] condition;
    static int[][] sum;
    static String dna;
    static int N, M, ans;
    static final char[] dnaChar = {'A', 'C', 'G', 'T'};

    public static void main(String[] args) throws IOException {
        init();
        System.out.println(ans);
    }

    static void init() throws IOException {
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        ans = 0;
        condition = new int[4];
        sum = new int[N+1][4];
        dna = br.readLine();
        String[] cons = br.readLine().split(" ");
        for (int i = 0; i < 4; i++) {
            condition[i] = Integer.parseInt(cons[i]);
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < N; j++) {
                sum[j+1][i] = sum[j][i] + ((dnaChar[i] == dna.charAt(j))?1:0);
            }
        }
        for(int i = M; i <= N; i++) {
            boolean valid = true;
            for(int j = 0; j < 4; j++) {
                if(condition[j] > sum[i][j]-sum[i-M][j]) valid = false;
            }
            if(valid) {
                ans++;
            }
        }
    }
}
