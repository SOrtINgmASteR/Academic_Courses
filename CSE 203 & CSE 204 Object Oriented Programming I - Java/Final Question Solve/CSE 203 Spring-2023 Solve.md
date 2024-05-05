<h1 style="text-align:center;">CSE 203 Spring - 23 Question Solve</h1>

<h3 style="text-align:center;">Answer to the Question no 1</h3>  

<h3 style="text-align:center;">Answer to the Question no 2</h3>  
***(a)***   
```java
import java.util.Scanner;
public class BMICalculation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double height, weight, bmi;
        String userName;

        userName = input.nextLine();
        height = input.nextDouble();
        weight = input.nextDouble();

        bmi = weight / (height * height);

        System.out.println("Welcome " + userName);
        System.out.print("Your BMI Range  : ");

        if(bmi < 18.5){
            System.out.println("Underweight.");
        }
        else if(bmi < 24.9){
            System.out.println("Normal Weight.");
        }
        else if(bmi < 29.9) {
            System.out.println("Overweight.");
        }
        else if(bmi < 34.9) {
            System.out.println("Obesity I.");
        }
        else if(bmi < 39.9) {
            System.out.println("Obesity II.");
        }
        else if(bmi >= 40) {
            System.out.println("Obesity III (Morbidly obese).");
        }
    }
}
```   

***(b)***    
```java
import java.util.Scanner;
public class ArraySumAndAverage {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, array[] = new int[100], sum = 0;
        double avg;
        System.out.print("Enter Number of Elements : ");
        n = input.nextInt();
        System.out.print("Enter Array Elements : ");
        for(int i = 0; i < n; i++){
            array[i] = input.nextInt();
            sum += array[i];
        }
        avg = (double) sum / n;
        System.out.println("Sum = " + sum);
        System.out.println("Average = " + avg);
    }
}
```

<h3 style="text-align:center;">Answer to the Question no 3</h3>  
***(a)***  
```java
public abstract class Phone {
    String manufacturer;
    int storage;
    int batteryPower;
    public Phone(String manufacturer, int storage, int batteryPower){
        this.manufacturer = manufacturer;
        this.storage = storage;
        this.batteryPower = batteryPower;
    }
    public void call(String toPhnNum){
        System.out.println("Calling to " + toPhnNum);
    }
    public void sendMassage(String toPhnNum, String msg) {
        System.out.println(msg);
        System.out.println("Massage sent to " + toPhnNum);
    }
}
```

***(b)***  
```java
public interface SmartDevice {
    void runApp(String appName);
}
```

```java
public class SmartPhone extends Phone implements SmartDevice{
    String os;
    public SmartPhone(String manufacturer, int storage, int batteryPower, String os) {
        super(manufacturer, storage, batteryPower);
        this.os = os;
    }

    @Override
    public void runApp(String appName) {
        System.out.println("Using App " + appName);
    }

    public void call(String toPhnNum, String usingApp){
        runApp(usingApp);
        super.call(toPhnNum);
    }
}

```


<h3 style="text-align:center;">Answer to the Question no 4</h3>  

<h3 style="text-align:center;">Answer to the Question no 5</h3>  

<h3 style="text-align:center;">Answer to the Question no 6</h3>  