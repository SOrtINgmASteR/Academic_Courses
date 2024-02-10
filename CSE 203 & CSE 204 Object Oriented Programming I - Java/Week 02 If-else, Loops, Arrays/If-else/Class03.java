//If-else
import java.util.Scanner;

public class Class03 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        if(number > 0){
            System.out.print("Positive ");
            if(number % 2 == 0){
                System.out.println("Even");
            }
            else if(number % 2 != 0){
                System.out.println("Odd");
            }
        }
        else if(number < 0){
            System.out.print("Negative ");
            if(number % 2 == 0){
                System.out.println("Even");
            }
            else if(number % 2 != 0){
                System.out.println("Odd");
            }
        }
    }
}