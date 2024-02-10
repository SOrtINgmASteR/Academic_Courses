//Fibonacci with Loops
import java.util.Scanner;
public class Loops05 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, n, firstTerm = 0, secondTerm = 1, thirdTerm;
        System.out.print("Enter the number of Fibonacci : ");
        n = input.nextInt();
        System.out.println("The first " + n +"th Fibonacci numbers : ");
        if(n == 1) System.out.println(firstTerm);
        else if(n == 2) System.out.println(firstTerm + " " + secondTerm);
        else if(n >= 3){
            System.out.print(firstTerm + " " + secondTerm);
            for(i = 3; i <= n; i++){
                thirdTerm = firstTerm + secondTerm;
                System.out.print(" " + thirdTerm);
                firstTerm = secondTerm;
                secondTerm = thirdTerm;
            }
        }
    }
}