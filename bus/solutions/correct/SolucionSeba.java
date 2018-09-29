import java.util.Scanner;
public class Program
{

	public static void main(String[] args) {
	int n, g, s=0;
	Scanner a = new Scanner(System.in);
    n = a.nextInt();
    for(int i=0;i<n;i++){
        g= a.nextInt();
        if((g%2==1)&&(g>2))
        s++;
    }
    
	System.out.println(s);
		
	}
}
