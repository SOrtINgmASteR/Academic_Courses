//Operators
import java.text.DecimalFormat;
import java.util.Scanner;

public class Class07 {
    public static void main(String[] args) {
        DecimalFormat point = new DecimalFormat("0.00");
        Scanner input = new Scanner(System.in);
        int number1, number2, result;
        double floatDivision;
        System.out.print("Enter Number 1 : ");
        number1 = input.nextInt();
        System.out.print("Enter Number 2 : ");
        number2 = input.nextInt();
        result = number1 + number2;
        System.out.println(number1 + " + " + number2 + " = " + result);
        result = number1 - number2;
        System.out.println(number1 + " - " + number2 + " = " + result);
        result = number1 * number2;
        System.out.println(number1 + " * " + number2 + " = " + result);
        result = number1 % number2;
        System.out.println(number1 + " % " + number2 + " = " + result);
        result = number1 / number2;
        System.out.println(number1 + " / " + number2 + " = " + result);
        floatDivision = number1 / (double) number2;
        System.out.println(number1 + " / " + number2 + " = " + point.format(floatDivision));
        System.out.printf("%d / %d = %.2f\n", number1, number2, floatDivision);
    }
}