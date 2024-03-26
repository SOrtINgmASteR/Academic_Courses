public class Main2 {
    public static void method(Human h){
        if(h instanceof Student){
            ((Student)h).printAllInformation();
        }
        else if(h instanceof Employee){
            ((Employee)h).printAllData();
        }
    }

    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Student 1";
        s1.age = 24;
        s1.id = 101;
        s1.cgpa = 3.50;
        s1.universityName = "SUST";
        Employee e1 = new Employee();
        e1.name = "Employee 1";
        e1.age = 23;
        e1.salary = 25000;
        e1.workerID = 601;
        e1.designation = "Category 1";

        Human s2 = new Student();
        s2.name = "Student 2";
        s2.age = 23;
        ((Student)s2).id = 102;
        ((Student)s2).universityName = "SUST";
        ((Student)s2).cgpa = 3.6;

        Human e2 = new Employee();
        e2.name = "Employee - 2";
        e2.age = 25;
        ((Employee)e2).salary = 25000;
        ((Employee)e2).designation = "Category 2";
        ((Employee)e2).workerID = 602;

        method(s1);
        method(e1);
        method(s2);
        method(e2);
    }
}