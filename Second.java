import java.util.*;
public class Second {
    public static void  printSumOdd(int n)
    {
        int sum =0;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
            {
                
             
                sum=sum+i;
            }
        }
        System.out.println("Sum of all odd number" + sum);
        return;
    }
    public static void main (String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        printSumOdd(n);
        return;
    }
    
}
