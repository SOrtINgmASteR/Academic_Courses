import java.util.*;
public class Main2 {
    public static void method() throws ArrayIndexOutOfBoundsException{
        Scanner scan = new Scanner(System.in);
        int array[] = new int[5];
        int a;
        System.out.println(array[4]);
    }

    public static void main(String[] args) {
        try {
            method();
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index out of Bound");
        }
    }
}