package mirea.prac;

import java.util.Scanner;

public class Second {
    public static void second_task(int n, int i) {
        if (i > n)
            return;
        System.out.println(i);
        i++;
        second_task(n, i);
    }

    public static void second_task() {
        System.out.println("## Second task ##");
        Scanner sc = new Scanner(System.in);
        System.out.print("Type N: ");
        second_task(sc.nextInt(), 0);
    }
}
