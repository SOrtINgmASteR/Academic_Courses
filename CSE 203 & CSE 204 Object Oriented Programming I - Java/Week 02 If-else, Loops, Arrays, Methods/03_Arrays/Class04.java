//Sum & Average of element
import java.util.Scanner;
public class Class04 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, array[] = new int[10], sum = 0;
        double avg;

        System.out.print("Enter 10 numbers : ");
        for(i = 0; i < 10; i++) {
            array[i] = input.nextInt();
        }

        for(i = 0; i < 10; i++) {
            sum += array[i];
        }
        avg = (double) sum / 10;

        System.out.println("The Summation is : " + sum);
        System.out.println("The Average is : " + avg);
    }
}