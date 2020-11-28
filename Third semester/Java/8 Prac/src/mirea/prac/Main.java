package mirea.prac;

public class Main {

    public static void main(String[] args) {
        UnfairWaitList<Integer> test = new UnfairWaitList<>();
        test.add(1);
        test.add(2);
        test.add(3);
        test.add(4);
        test.moveToBack(4);
        System.out.println(test.toString());

    }
}
