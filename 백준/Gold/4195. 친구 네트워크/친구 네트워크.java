import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	static final int MAX_N_FREIEDNS = 200001;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static int[] arr;
	static int[] cntArr;
	static Map<String, Integer> map;
	static int cnt;
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++) {
			init();
			solution();
		}
	}
	
	static int getParent(int a) {
		if(a != arr[a]) return arr[a] = getParent(arr[a]);
		return a;
	}
	
	static void union(int a, int b) {
		int pa = getParent(a);
		int pb = getParent(b);
		if(pa != pb) {
			cntArr[pa] += cntArr[pb];
			arr[pb] = pa;
		}
	}
	
	static void init() throws Exception {
		N = Integer.parseInt(br.readLine());
		
		arr = new int[MAX_N_FREIEDNS];
		cntArr = new int[MAX_N_FREIEDNS];
		map = new HashMap<>();
		cnt = 0;
		
		for(int i = 0; i < MAX_N_FREIEDNS; i++) {
			arr[i] = i;
			cntArr[i] = 1;
		}
		
		for(int i = 0 ; i < N; i++) {
			String[] line = br.readLine().split(" ");
			Integer a = map.get(line[0]);
			if(a == null) {
				a = cnt;
				map.put(line[0], cnt++);
			}
			Integer b = map.get(line[1]);
			if(b == null) {
				b = cnt;
				map.put(line[1], cnt++);
			}

			if(a>b) {
				int t = a; a = b; b = t;
			} else if (a==b) continue;
			
			union(a, b);
			System.out.println(cntArr[getParent(a)]);
		}
	}
	
	static void solution() {
		
	}
}
