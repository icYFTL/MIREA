package mirea.prac;

import java.util.Scanner;

public class Fifth {
    public static void fifth_task(){
        System.out.println("## Fifth task ##");
        Scanner sc = new Scanner(System.in);
        System.out.print("Type N: ");
        System.out.println(Firth.decomposition(sc.nextInt(), 0));
    }
}
