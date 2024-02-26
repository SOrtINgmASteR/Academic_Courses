//Taking input from user using Loops
import java.util.Scanner;
public class Class03 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int i, array[] = new int[5];

        System.out.print("Enter array elements : ");
        for(i = 0; i < 5; i++){
            array[i] = input.nextInt();
        }

        System.out.print("The Elements are : ");
        for(i = 0; i < 5; i++){
            System.out.print(array[i] + " ");
        }
    }
}