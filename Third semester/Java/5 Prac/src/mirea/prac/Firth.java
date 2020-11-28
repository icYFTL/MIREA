package mirea.prac;

import java.util.Scanner;

public class Firth {

    public static int decomposition(int value, int sum) {
        if (value == 0)
            return sum;
        sum += value % 10;
        value /= 10;
        return decomposition(value, sum);
    }

    public static void firth_task(int start, int val, int s, int counter) {
        if (val == start * 10){
            System.out.println(counter);
            return;
        }
        if (decomposition(val, 0) == s)
            counter++;

        val++;
        firth_task(start, val, s, counter);
    }

    public static void firth_task(){
        System.out.println("## Firth task ##");
        Scanner sc = new Scanner(System.in);
        System.out.print("Type k: ");
        int k = sc.nextInt();
        System.out.print("Type s: ");
        int s = sc.nextInt();


        int start = 1;
        for (int i = 0; i < k - 1; i++)
            start *= 10;

        firth_task(start, start, s, 0);
    }
}
