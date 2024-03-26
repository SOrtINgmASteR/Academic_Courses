public class Human {
    String name;
    int age;
    public Human(){

    }
    public Human(String name, int age){
        this.name = name;
        this.age = age;
    }
    public void grow(){
        age += 1;
    }
}
