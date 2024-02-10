//Factorial with Loops
import java.util.Scanner;
public class Loops06 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, number;
        long factorial = 1;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        for(i = 1; i <= number; i++){
            factorial *= i;
        }
        System.out.println("Factorial of "+ number +" is : "+factorial);
    }
}
