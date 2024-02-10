//Digit Count
import java.util.Scanner;
public class Loops03 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number, count = 0;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        while(number != 0){
            number /= 10;
            count++;
        }
        System.out.println("The number has "+count+" digits");
    }
}