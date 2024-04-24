import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int array[] = new int[5];
        int a;
        try{
            a = scan.nextInt();
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index Out of Bound!");
        }
        catch (InputMismatchException e){
            System.out.println("Input Mismatch Exception!");
        }
        System.out.println("Finish!");
    }
}