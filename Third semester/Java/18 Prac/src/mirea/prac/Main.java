package mirea.prac;

import java.util.ArrayList;
import java.util.Collections;
import java.util.concurrent.ThreadLocalRandom;

public class Main {
    public static void main(String[] args) {
        for (var arg : args)
            System.out.println(arg);

        int size = 10;
        int min = 0;
        int max = 100;
        ArrayList<Integer> mas = new ArrayList<>(size);

        for (int i = 0; i < size; ++i)
            mas.add(ThreadLocalRandom.current().nextInt(min, max + 1));

        for (var i : mas)
            System.out.print(i.toString() + " ");

        System.out.println();

        Collections.sort(mas);

        for (var i : mas)
            System.out.print(i.toString() + " ");

        System.out.println();

    }

}
