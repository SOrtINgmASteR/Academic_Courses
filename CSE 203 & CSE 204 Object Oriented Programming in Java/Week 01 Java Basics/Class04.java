//Floating datatype preciption
import java.text.DecimalFormat;
public class Class04 {
    public static void main(String[] args) {
        DecimalFormat point = new DecimalFormat("0.000");
        float myFloat = 34.3486f;
        double myDouble = 34.594989;

        System.out.println(myFloat);
        System.out.println(myDouble);

        System.out.printf("myFloat = %.3f\n", myFloat);
        System.out.println("myFloat = "+point.format(myFloat));
        System.out.printf("myDouble = %.3f\n", myDouble);
        System.out.println("myDouble = " + point.format(myDouble));
    }
}