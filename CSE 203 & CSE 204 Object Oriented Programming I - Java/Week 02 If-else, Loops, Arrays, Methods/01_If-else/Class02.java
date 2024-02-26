//If-else
import java.util.Scanner;

public class Class02 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        if(number > 0){
            System.out.println("The Number is Positive");
        }
        else if(number < 0){
            System.out.println("The Number is Negative");
        }
    }
}