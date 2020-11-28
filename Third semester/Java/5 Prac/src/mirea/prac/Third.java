package mirea.prac;

import java.util.Scanner;

public class Third {
    public static void third_task(int a, int b, int i, boolean flow) {
        if (flow) {
            if (a + i > b)
                return;
            System.out.println(a + i);
            i++;
            third_task(a, b, i, flow);
        } else {
            if (b + i > a)
                return;
            System.out.println(b + i);
            i++;
            third_task(a, b, i, flow);
        }
    }

    public static void third_task() {
        System.out.println("## Third task ##");
        Scanner sc = new Scanner(System.in);
        System.out.print("Type A: ");
        int a = sc.nextInt();
        System.out.print("Type B: ");
        int b = sc.nextInt();
        third_task(a, b, 0, a < b);
    }
}
