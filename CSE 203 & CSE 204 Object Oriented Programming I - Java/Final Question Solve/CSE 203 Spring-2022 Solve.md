<h1 style="text-align:center;">CSE 203 Spring - 22 Question Solve</h1>

<h3 style="text-align:center;">Answer to the Question no 1</h3>  

***(a)*** Object-oriented programming is a programming paradigm based on the concept of objects, which can contain data and code, data in the form of fields, and code in the form of procedures or methods. A common feature of objects is that methods are attached to them and can access and modify the object's data fields. This approach to programming is well-suited for programs that are large, complex and actively updated or maintained.  

***(b)***  Inheritance is the concept in OOPs in which one class inherits the attributes and methods of another class. The class whose properties and methods are inherited is known as the Parent class or super class. And the class that inherits the properties from the parent class is the Child class or sub class.  

***(c)*** Life Cycle of Thread in Java is basically state transitions of a thread that starts from its birth and ends on its death. A thread is a path of execution in a program that enters any one of the following five states during its life cycle. The five states are as follows-  
**1.New :** That is when a thread is born, it enters into new state but the start() method has not been called yet on the instance.  
**2.Runnable :** Runnable state means a thread is ready for execution. When the start() method is called on a new thread, thread enters into a runnable state.  
**3.Running :** Running means Processor (CPU) has allocated time slot to thread for its execution. When thread scheduler selects a thread from the runnable state for execution, it goes into running state.   
**4.Blocked (Non-runnable state)** : A thread is considered to be in the blocked state when it is suspended, sleeping, or waiting for some time in order to satisfy some condition.    
**5.Terminated :** A thread dies or moves into dead state automatically when its run() method completes the execution of statements.    


<h3 style="text-align:center;">Answer to the Question no 2</h3> 

```java
import java.util.Scanner;
public class Class02 {

    //Method for prime detection
    public static boolean isPrime(int n){
        if(n == 0 || n == 1 ) return false;
        else if(n == 2) return true;
        for(int i = 2; i < n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i, a, b, number, sum = 0, count = 0;
        a = input.nextInt();
        b = input.nextInt();

        //If the first number is even
        if(a % 2 == 0){
            for(i = 0; i < 10; i++){
                number = input.nextInt();
                if(number % 2 == 0){
                    sum+=number;
                }
            }
            System.out.println("Sum = "+sum);
        }

        //If the second number is greater
        if(a < b){
            for(i = 0; count < 5; i++){
                if(isPrime(i) == true){
                    System.out.print(i + " ");
                    count++;
                }
            }
        }
    }
}
```


<h3 style="text-align:center;">Answer to the Question no 3</h3>

**(a)**

```java
public class Alligator {
    double length;
    int weight;
    String color;
    public Alligator(double length, int weight, String color){
        this.length = length;
        this.weight = weight;
        this.color = color;
    }
    public void incubateEgg(int temp){
        if(temp >= 34){
            System.out.println("mostly male baby alligator");
        }
        else if(temp <= 30){
            System.out.println("mostly female baby alligator");
        }
        else {
            System.out.println("Could be male or female baby alligator");
        }
    }
    public String toString(){
        String s = "Length : " + length + "\nWeight : " + weight + "\nColor : " + color;
        return s;
    }
}
```
**(b)**
```java
public class Zoo {
    public static void main(String[] args) {
        Alligator alligtr = new Alligator(11.6, 34, "Black");   //ID - 22101134
        alligtr.incubateEgg(34);                                //ID - 22101134
        String s = alligtr.toString();
        System.out.println(s);
    }
}
```
**Output :**   
`mostly male baby alligator`  
`Length : 11.6`  
`Weight : 34`  
`Color : Black`  

<h3 style="text-align:center;">OR</h3>  

**(c)**  
BanglaLinkCare -   
```java
public class BanglaLinkCare implements CustomerCare{
    @Override
    public void welcomeMsg() {
        System.out.println("Welcome to Bangla Link Customer care.");
    }
    @Override
    public void sayBye() {
        System.out.println("Have nice day.");
    }
}
```
ICPCVolunteer -
```java
public class ICPCVolunteer implements CustomerCare{
    @Override
    public void welcomeMsg() {
        System.out.println("Welcome to ICPC World Final 2021");
    }
    @Override
    public void sayBye() {
        System.out.println("Hope you enjoyed the final");
    }
}
```   

<h3 style="text-align:center;">Answer to the Question no 4</h3>  
<h3 style="text-align:center;">(a)</h3>   

***I)*** Here both the methods has same name & same parameters, so the methods are not Overloading. Adding an extra variable `int c` to the parameter of the second method & returning the value `a + b + c` will solve all the errors because then the methods will overload.   
**Code without errors -** 
```java
public class Calculator {
    public void sum(int a, int b){
        System.out.println(a + b);
    }
    public int sum(int a, int b, int c){
        return a + b + c;
    }
}
```  


***II)*** Here variable a & b should be static variable, so adding static keyword before the declaration of the variable would solve all the errors.  
**Code without errors -**
```java
public class FindError {
    static int a = 5;
    static int b = 7;
    public static void main(String[] args) {
        int sum = a + b;
        System.out.println(sum);
    }
}
```
<h3 style="text-align:center;">(b)</h3>   


<h3 style="text-align:center;">Answer to the Question no 5</h3>  

***(a)***  
```java
public class OuterClass {
    public int outerVar;
    public OuterClass(int outerVar){
        this.outerVar = outerVar;
    }
    public void outerMethod(){
        InnerClass innerClass = new InnerClass(25);
        System.out.println(innerClass.innerVar);
        innerClass.innerMethod();
    }
    public class InnerClass{
        public int innerVar;
        public InnerClass(int innerVar){
            this.innerVar = innerVar;
        }
        public void innerMethod(){
            System.out.println(innerVar);
        }
    }
    public static void main(String [] args){
        OuterClass outerClass = new OuterClass(60);
        OuterClass.InnerClass innerClass = outerClass.new InnerClass(100);
        innerClass.innerMethod();
    }
}
```
***(b)***  
As FileNotFoundException is a subclass of IOException, we catch FileNotFoundException in the first catch statement & IOException in the second catch statement.
```java
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
public class TestThread {
    public static void main(String[] args) {
        try{
            FileReader fileReader = new FileReader("test.txt");
        }
        catch (FileNotFoundException e){
            System.out.println("FileNotFoundException");
        }
        catch (IOException e){
            System.out.println("IOException.");
        }
    }
}
```  

<h3 style="text-align:center;">Answer to the Question no 6</h3>  

**(a)**  
```java
public class LowAttendanceException extends Exception{
    public LowAttendanceException(int minAtt){
        super("Need a minimum attendance of " + minAtt + " days to attend the final exam");
    }
}
```
**OR - (a)**  
We can do some changes in `Device` class to get rid of the errors - 
```java
public class Device implements Comparable<Device> {
    String name, category;
    int price;

    public Device(String name, String category, int price) {
        this.name = name;
        this.category = category;
        this.price = price;
    }

    public void display() {
        System.out.printf("%s:%s:%d\n", name, category, price);
    }

    @Override
    public int compareTo(Device otherDevice) {
        return Integer.compare(this.price, otherDevice.price);
    }
}
```

**(b)**  
Thread Class -
```java
import java.util.Random;
public class GenerateRandomNumber extends Thread {
    int max;
    int min;
    public GenerateRandomNumber(int min, int max){
        this.min = min;
        this.max = max;
    }
    @Override
    public void run() {
        Random random = new Random();
        for(int i = 1; i <=10; i++){
            int randomNumber = min + random.nextInt((max - min) + 1);
            System.out.print(randomNumber + " ");
        }
    }
}
```  

Multithreaded Program to run 3 Threads -
```Java
public class MultiThreadedProgram {
    public static void main(String[] args) {
        GenerateRandomNumber t1 = new GenerateRandomNumber(10, 20);
        GenerateRandomNumber t2 = new GenerateRandomNumber(50, 60);
        GenerateRandomNumber t3 = new GenerateRandomNumber(100, 120);
        
        t1.start();
        t2.start();
        t3.start();
    }
}
```

**OR - (b)**  
```java
import java.io.*;
public class Main {
    public static void main(String[] args) {
        try{
            FileReader fileReader = new FileReader("voters.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            int age;
            while (true){
                line = bufferedReader.readLine();
                if(line == null) break;
                String nameAge[] = line.split(" ");
                age = Integer.valueOf(nameAge[1]);
                if(age >= 18 && age <= 90){
                    System.out.println(line);
                }
            }
        }
        catch(Exception e){
            System.out.println("Unsuccessful Read.");
        }
    }
}
```