//Scanner class
import java.text.DecimalFormat;
import java.util.Scanner;
public class Class05 {
    public static void main(String[] args){
        //ClassName objectName = new ClassName(if parameter);
        Scanner input = new Scanner(System.in);
        DecimalFormat point = new DecimalFormat("0.00");

        int myInt;
        double myDouble;

        myInt = input.nextInt();
        myDouble = input.nextDouble();

        System.out.println("myInt = " + myInt);
        System.out.println("myDouble = " + point.format(myDouble));
    }
}
