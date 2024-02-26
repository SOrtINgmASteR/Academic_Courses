//If-else
import java.util.Scanner;

public class Class01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        if(number % 2 == 0){
            System.out.println("The Number is Even");
        }
        else if(number % 2 != 0){
            System.out.println("The Number is Odd");
        }
    }
}