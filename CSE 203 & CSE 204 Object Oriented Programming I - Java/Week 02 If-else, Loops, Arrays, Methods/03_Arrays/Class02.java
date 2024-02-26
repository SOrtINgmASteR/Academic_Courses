//Each Element from user
import java.util.Scanner;
public class Class02 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int array[] = new int[5];

        System.out.print("Enter 5 numbers : ");
        array[0] = input.nextInt();
        array[1] = input.nextInt();
        array[2] = input.nextInt();
        array[3] = input.nextInt();
        array[4] = input.nextInt();

        System.out.print("You entered these 5 numbers : ");
        System.out.print(array[0]+" "+array[1]+" "+array[2]+" "+array[3]+" "+array[4]+"\n");
    }
}