//Digit Sum
import java.util.Scanner;
public class Loops01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number, digitSum = 0, lastDigit;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        while(number != 0){
            lastDigit = number % 10;
            digitSum += lastDigit;
            number /= 10;
        }
        System.out.println("Digit Sum  : "+ digitSum);
    }
}