import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class ocio{

//esto está programado de manera bien ineficiente, con dos strings y muchas operaciones (costosas) de Strings. Un arreglo de char (o byte) es muuuucho mejor.


	public static void rec(){
		k = s.length();
		aux="";
		while(k>0){
			t = true;
			if(k >= 3 && t && s.substring(0,3).equals("111")){aux+="31"; t = false; s = s.substring(3); k-=3;}
			if(k >= 3 && t && s.substring(0,3).equals("222")){aux+="32"; t = false; s = s.substring(3); k-=3;}
			if(k >= 3 && t && s.substring(0,3).equals("333")){aux+="33"; t = false; s = s.substring(3); k-=3;}
			if(k >= 2 && t && s.substring(0,2).equals("11")){aux+="21"; t = false; s = s.substring(2); k-=2;}
			if(k >= 2 && t && s.substring(0,2).equals("22")){aux+="22"; t = false; s = s.substring(2); k-=2;}
			if(k >= 2 && t && s.substring(0,2).equals("33")){aux+="23"; t = false; s = s.substring(2); k-=2;}
			if(k >= 1 && t && s.substring(0,1).equals("1")){aux+="11"; t = false; s = s.substring(1); k--;}
			if(k >= 1 && t && s.substring(0,1).equals("2")){aux+="12"; t = false; s = s.substring(1); k--;}
			if(k >= 1 && t && s.substring(0,1).equals("3")){aux+="13"; t = false; s = s.substring(1); k--;}
		}
		s = aux;
	}
	public static boolean t;
	public static String s,aux;
	public static int M,sum,ans,k;


	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		M = in.nextInt();
		ans = 0;
		sum = 0;
		s = "1";
		while(sum < M){
			sum+=s.length();
			if(sum <= M){
				sum++;
				ans++;
				rec();
			}
		}
		System.out.println(ans);
	}
}
