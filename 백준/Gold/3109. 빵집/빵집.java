import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(System.in);
	static int R, C;
	static int ans;
	static int arr[][];
	
	public static void main(String[] args) throws Exception {
		String[] input = sc.nextLine().split(" ");
		R = Integer.parseInt(input[0]);
		C = Integer.parseInt(input[1]);
		arr = new int[R][C];
		for(int i = 0; i < R; i++) {
			String line = sc.nextLine();
			for(int j = 0; j < C; j++) {
				arr[i][j] = (line.charAt(j) == '.') ? 0 : 1;
			}
		}
//		for(int i = 0; i < R; i++) {
//			for(int j = 0; j < C; j++) {
//				System.out.print(arr[i][j]);
//			}
//			System.out.println();
//		}
		for(int i = 0; i < R; i++) {
			boolean found = solution(i, 0);
			if(found) ans++;
		}
		System.out.println(ans);
	}
	
	public static void init() throws Exception {
		
	}
	
	public static boolean checkValid(int y, int x) {
//		System.out.println("Range");
		if(y<0 || x < 0 || y>=R || x >= C) return false;
//		System.out.println("Wall");
		if(arr[y][x] == 1) return false;
		return true;
	}

	public static boolean solution(int y, int x) {
//		System.out.println(": "+y+", "+x);
//		System.out.println("V: " + checkValid(0,  0));
		arr[y][x] = 1;
		if(x == C-1) {
//			System.out.println("true");
			return true;
		}
		boolean found = false;
		if(checkValid(y-1, x+1)) {
			found = solution(y-1, x+1);
		}
		if(!found && checkValid(y, x+1)) {
			found = solution(y, x+1);
		}
		if(!found && checkValid(y+1, x+1)) {
			found = solution(y+1, x+1);
		}
		return found;
	}

}
