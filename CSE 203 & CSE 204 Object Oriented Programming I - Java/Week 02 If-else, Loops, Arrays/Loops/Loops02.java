//Number Reverse
import java.util.Scanner;
public class Loops02 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number, reverseNumber = 0, lastDigit;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        while(number != 0){
            lastDigit = number % 10;
            reverseNumber *= 10;
            reverseNumber += lastDigit;
            number /= 10;
        }
        System.out.println("Reverse Number : "+reverseNumber);
    }
}