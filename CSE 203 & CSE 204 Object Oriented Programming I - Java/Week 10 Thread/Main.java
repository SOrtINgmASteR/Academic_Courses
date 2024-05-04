public class Main {
    public static void main(String[] args) {
        System.out.println("Begin");
        MyThread1 t1 = new MyThread1(10, 20);
        MyThread1 t2 = new MyThread1(20, 30);
        MyThread1 t3 = new MyThread1(30, 40);

        t1.start();
        t2.start();
        t3.start();

        Thread t4 =new Thread(new MyThread2(10, 20));
        Thread t5 =new Thread(new MyThread2(20, 30));
        Thread t6 =new Thread(new MyThread2(30, 40));

        t4.start();
        t5.start();
        t6.start();
        
        System.out.println("Finish");
    }
}