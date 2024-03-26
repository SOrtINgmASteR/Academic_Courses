public class Employee extends Human {
    int workerID;
    String designation;
    int salary;
    public Employee(){

    }
    public Employee(int workerID, String designation, int salary){
        this.designation = designation;
        this.workerID = workerID;
        this.salary = salary;
    }
    public Employee(String name, int age, int workerID, String designation, int salary){
        super(name, age);
        this.designation = designation;
        this.workerID = workerID;
        this.salary = salary;
    }
    public void printAllData(){
        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
        System.out.println("Salary : " + salary);
    }
}