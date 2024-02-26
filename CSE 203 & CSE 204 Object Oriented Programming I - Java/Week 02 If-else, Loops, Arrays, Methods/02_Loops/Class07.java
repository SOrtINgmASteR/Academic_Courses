//Prime Divisors using Loops
import java.util.Scanner;
public class Class07 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number, i;
        System.out.print("Enter Number : ");
        number = input.nextInt();
        System.out.print("Prime divisors of "+ number +" : ");
        while(number % 2 == 0){
            System.out.print(2 + " ");
            number /= 2;
        }
        for(i = 3; i <= number; i+=2 ){

            while(number % i == 0){
                System.out.print(i + " ");
                number /= i;
            }
        }
    }
}