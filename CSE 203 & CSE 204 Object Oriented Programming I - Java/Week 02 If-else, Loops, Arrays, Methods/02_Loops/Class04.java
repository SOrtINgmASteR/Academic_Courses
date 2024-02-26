//Prime Number with Loops
import java.util.Scanner;
public class Class04 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, number;
        boolean flag = true;

        System.out.print("Enter Number : ");
        number = input.nextInt();

        if(number == 0 || number == 1) flag = false;
        else if(number == 2) flag = true;
        for(i = 2; i < number; i++){
            if(number % i == 0){
                flag = false;
                break;
            }
        }
        if(flag == true) System.out.println(number + " is Prime");
        else if(flag == false) System.out.println(number + " is not Prime");
    }
}