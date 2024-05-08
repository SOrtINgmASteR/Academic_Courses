<h1 style="text-align:center;">CSE 203 Fall - 22 Question Solve</h1>  

<h3 style="text-align:center;">Answer to the Question no 1</h3>  

***(a)***   A Java identifier is a name given to a package, class, interface, method, or variable.
All Java variables must be identified with unique names.Identifiers can be short names (like x and y) or more descriptive names (age, sum, totalVolume).
The general rules for naming variables are:

**1.** Names can contain letters, digits, underscores, and dollar signs & can begin with letters, $ and _.  
**2.** Names should start with a lowercase letter and it cannot contain whitespace.   
**3.** Names are case-sensitive ("myVar" and "myvar" are different variables).  
**4.** Reserved words (like Java keywords, such as int or boolean) cannot be used as names.  

***(b)***  
**Array Size:**  
An array in Java is an object (i.e., an instance of an unnamed class), so, like any object, it may have instance fields. Every Java array has a field defined as public int length; that stores the size of (or the number of elements in) the array. An array in C++ is a primitive, unstructured data type - it is an address that is incapable of storing additional data. C++ programmers must maintain a separate, distinct variable to track the size of an array.  
**Bounds Checking:**  
Java detects and notifies a programmer when the program indexes an array out of bounds, C++ does not.   

***(c)***  
Garbage collection in Java is the automated process of deleting code that’s no longer needed or used. This automatically frees up memory space and ideally makes coding Java apps easier for developers. Automatic garbage collection means you don’t have control over whether and when objects are deleted.   


<h3 style="text-align:center;">Answer to the Question no 2</h3>  

```java
import java.util.Scanner;
public class Main {
    //Method to detect prime number
    public static int isPrime(int n){
        if(n == 0 || n == 1 ) return 0;
        else if(n == 2) return 1;
        for(int i = 2; i < n; i++){
            if(n % i == 0) return 0;
        }
        return 1;
    }

    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        int i, number, sum = 0, primeSum = 0;
        //Answer (a)
        System.out.print("Enter 5 Numbers : ");
        for(i = 0; i < 5; i++){
            number = input.nextInt();
            if(number % 2 != 0){
                sum += number;
            }
        }
        System.out.println("Sum = "+sum);

        //Answer (b)
        System.out.print("Enter 6 Numbers : ");
        for(i = 0; i < 6; i++){
            number = input.nextInt();
            if(isPrime(number) == 1){
                primeSum += number;
            }
        }
        System.out.println("Prime Sum = "+primeSum);
    }
}

```

<h3 style="text-align:center;">Answer to the Question no 3</h3>  

**(a)**
```java
public abstract class Professional {
    String name;
    int age;
    String specialty;
    String designation;
    double salary;

    public Professional(String name, int age, String speciality, String designation, double salary) {
        this.name = name;
        this.age = age;
        this.specialty = speciality;
        this.designation = designation;
        this.salary = salary;
    }

    public void promotion(String newDesignation, double newSalary) {
        this.designation = newDesignation;
        this.salary = newSalary;
    }

    public abstract void jobDescription();

    @Override
    public String toString() {
        String s;
        s = "Name: " + name + " Age: " + age + " Specialty: " + specialty;
        return s;
    }
}
```
**(b)**  
```java
public class Programmer extends Professional {
    int rank;

    public Programmer(String name, int age, String designation, double salary, int rank) {
        super(name, age, "ICT", designation, salary);
        this.rank = rank;
    }

    @Override
    public void jobDescription() {
        System.out.println("Do professional programming");
    }
}
```
<h3 style="text-align:center;">Answer to the Question no 3 (OR)</h3>   

**(a)**  
```java
public interface Engine {
    void start();
    void running(int min);
    void stop();
}
```  
**(b)**  
```java
public class Car implements Engine {
    String model;
    int speed;

    public Car(String model, int speed) {
        this.model = model;
        this.speed = speed;
    }

    @Override
    public void start() {
        System.out.println(model + " started at speed=" + speed + ".");
    }

    @Override
    public void running(int min) {
        System.out.println("Running at speed=" + speed);
        System.out.println("Distance covered=" + speed * min + ".");
    }

    @Override
    public void stop() {
        System.out.println("Stopped.");
    }
}
```

<h3 style="text-align:center;">Answer to the Question no 4</h3>
<h3 style="text-align:center;">Answer to the Question no 5</h3>
<h3 style="text-align:center;">Answer to the Question no 6</h3>  

***(a)***

```java
public class MultilevelTryCatch{
    public static void main(String[] args) {
        try{
            try{
                int a[] = new int[5];
                System.out.println(a[10]);
            }
            catch(ArithmeticException e){
                System.out.println("Arithmetic Exception");
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index out of Bound");
        }
    }
}
``` 

***OR - (a)***  

Thread Class -
```java
public class AddEvenNumbersToArray extends Thread{
    public static int array[] = new int[1000];
    public static int index = 0;
    int min, max;
    public AddEvenNumbersToArray(int min, int max){
        this.min = min;
        this.max = max;
    }

    @Override
    public void run(){
        for(int i = min; i <= max; i++){
            if(i % 2 == 0){
                synchronized(array){
                    array[index] = i;
                    index++;
                }
            }
        }
    }
}
```  

Multithreaded Program to run 4 Threads -
```java
public class MultiThreadedProgram {
    public static void main(String[] args) {
        AddEvenNumbersToArray t1 = new AddEvenNumbersToArray(20, 30);
        AddEvenNumbersToArray t2 = new AddEvenNumbersToArray(40, 50);
        AddEvenNumbersToArray t3 = new AddEvenNumbersToArray(60, 70);
        AddEvenNumbersToArray t4 = new AddEvenNumbersToArray(80, 90);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}
```

***(b)***  

```java
public class InvalidCGPAException extends Exception{
    public InvalidCGPAException(double minCGPA, double maxCGPA){
        super("Valid CGPA should be between " + minCGPA + " and " + maxCGPA);
    }
}
```

***OR - (b)***   
Thread Class -   
```java
public class AddPrimeNumbersToArray extends Thread{
    public static int array[] = new int[1000];
    public static int index = 0;

    int n, min, max;
    public static int isPrime(int n){
        if(n == 0 || n == 1 ) return 0;
        else if(n == 2) return 1;
        for(int i = 2; i < n; i++){
            if(n % i == 0) return 0;
        }
        return 1;
    }
    public AddPrimeNumbersToArray(int n, int min, int max){
        this.n = n;
        this.min = min;
        this.max = max;
    }
    @Override
    public void run(){
        for(int i = 0, j = min; i < n && j <= max; i++, j++){
            if(isPrime(j) == 1){
                synchronized (array){
                    array[index] = j;
                    index++;
                }
            }
        }
    }
}
```
Multithreaded Program to run thread -   
```java
public class MultiThreadedProgram {
    public static void main(String[] args) {
        AddPrimeNumbersToArray t1 = new AddPrimeNumbersToArray(5, 50, 80);
        AddPrimeNumbersToArray t2 = new AddPrimeNumbersToArray(5, 50, 80);
        AddPrimeNumbersToArray t3 = new AddPrimeNumbersToArray(5, 50, 80);

        t1.start();
        t2.start();
        t3.start();
    }
}
```


