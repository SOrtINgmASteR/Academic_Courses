public class Student extends Human{
    String universityName;
    int id;
    double cgpa;
    public Student(){

    }
    public Student(String universityName, int id, double cgpa){
        this.universityName = universityName;
        this.id = id;
        this.cgpa = cgpa;
    }
    public Student(String name, int age, String universityName, int id, double cgpa){
        super(name, age);
        this.id = id;
        this.universityName = universityName;
        this.cgpa = cgpa;
    }
    public void printAllInformation(){
        System.out.println("Name : " + name);
        System.out.println("ID : " + id);
        System.out.println("cgpa : " + cgpa);
    }
    @Override
    public void grow() {
        age += 2;
    }
}
