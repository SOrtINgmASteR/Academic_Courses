public class MyThread1 extends Thread{
    int limit;
    int start;
    public MyThread1(int start, int limit){
        this.start = start;
        this.limit = limit;
    }

    @Override
    public void run(){
        for(int i = 0; i < limit; i++){
            System.out.println(i);
        }
    }
}