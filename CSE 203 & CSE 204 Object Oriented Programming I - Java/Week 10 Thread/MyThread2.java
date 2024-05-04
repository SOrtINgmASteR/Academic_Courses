public class MyThread2 implements Runnable{
    int limit;
    int start;
    public MyThread2(int start, int limit){
        this.start = start;
        this.limit = limit;
    }
    @Override
    public void run(){
        int limit = 10;
        for(int i = 0; i < limit; i++){
            System.out.println(i);
        }
    }
}