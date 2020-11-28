package mirea.prac;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Wait for first deck:\n> ");
        int[] _deck1 = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.print("Wait for second deck:\n> ");
        int[] _deck2 = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        Dymaxion<Integer> deck1 = new Dymaxion<Integer>();
        Dymaxion<Integer> deck2 = new Dymaxion<Integer>();

        for (int x : _deck1)
            deck1.push(x);

        for (int x : _deck2)
            deck2.push(x);

        DrunKard DK = new DrunKard(deck1, deck2);
        DK.compute();

    }
}
