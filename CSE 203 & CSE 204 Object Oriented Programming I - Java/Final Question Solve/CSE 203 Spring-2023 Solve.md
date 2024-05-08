<h1 style="text-align:center;">CSE 203 Spring - 23 Question Solve</h1>

<h3 style="text-align:center;">Answer to the Question no 1</h3>  

***(a)***  Polymorphism in Java is achieved through -   
- Method Overriding : Method overriding occurs when a subclass provides a specific implementation of a 
method that is already defined in its superclass. The method in the subclass has the same name and 
parameters as the method in the superclass.  


- Method Overloading : Method overloading occurs when a class has multiple methods with the same name 
but different parameter lists. The methods may have different numbers or types of parameters.  


- Subclass polymorphism : A parent class reference is used to refer to a child class object.


***(b)***  Difference between Abstract classes & Interfaces -  

| Abstract classes                                                | Interfaces                                                       |
|-----------------------------------------------------------------|------------------------------------------------------------------|
| 1. Can contain constructor, normal instance variables & method. | 1. Only can contain abstract method.                             |
| 2. `extends` is used to make a child class.                     | 2. `implements` is used to make a child class.                   |
| 3. Multiple inheritance can't be achieved.                      | 3. Multiple inheritance can be achieved.                         |
| 4. Necessary to give `abstract` keyword for abstract method.    | 4. Not necessary to give `abstract` keyword for abstract method. |


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

***(a)***  

```java
public class InvalidTemperatureRangeException extends Exception{
    public InvalidTemperatureRangeException(int minTemp, int maxTemp){
        super("Temperature should be between " + minTemp + " and " + maxTemp + " degrees.");
    }
}
```

***(b)***  
```java
public class RunAirCooler {
    public static void runAirCooler(int temp) throws InvalidTemperatureRangeException{
        if(temp > 10 && temp < 28){
            System.out.println("Running at " + temp);
        }
        else {
            throw new InvalidTemperatureRangeException(10, 28);
        }
    }

    public static void main(String[] args) {
        try {
            runAirCooler(11);
            runAirCooler(34);
        }
        catch (InvalidTemperatureRangeException e){
            System.out.println(e.getMessage());
        }
    }
}
```

<h3 style="text-align:center;">OR</h3>   

***(c)***   
Thread Class -  
```java
import java.util.Random;
public class GenerateRandomNumber implements Runnable {
    int n, max, min;
    public GenerateRandomNumber(int n, int min, int max){
        this.n = n;
        this.max = max;
        this.min = min;
    }
    @Override
    public void run() {
        for(int i = 0; i < n; i++){
            Random random = new Random();
            int randomNumber = min + random.nextInt(max - min + 1);
            System.out.println(randomNumber);
        }
    }
}
```  

Multithreaded Program to run 3 Threads -   
```java
public class MultiThreadedProgram {
    public static void main(String[] args) {
        Thread t1 = new Thread(new GenerateRandomNumber(10, 1, 100));
        Thread t2 = new Thread(new GenerateRandomNumber(5, 101, 200));
        Thread t3 = new Thread(new GenerateRandomNumber(8, 201, 300));

        t1.start();
        t2.start();
        t3.start();
    }
}
```

