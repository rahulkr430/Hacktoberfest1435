import java.util.*;
public class Thrid {
    public static void  comPare(int a, int b){
        if(a>b)
        {
            System.out.println("Greatest number is"+a);

        }
        else
        {
            System.out.println("GREATEST NUMBER IS "+b);
        }
        return;
    }
    public static void main (String args[]){
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b =sc.nextInt();
        comPare(a,b);
        return;
    }
   
    
}
