package mirea.prac;

import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Main {

    public static List<Student> generate_students() {

        List<Integer> ids = new ArrayList<>();
        int size = 20;//ThreadLocalRandom.current().nextInt(1000, 10000);
        for (int i = 0; i < size; ++i)
            ids.add(i);

        Collections.shuffle(ids);

        List<Student> students = new ArrayList<>();
        for (int i : ids)
            students.add(new Student(i, ThreadLocalRandom.current().nextDouble(1.0, 5.0)));

        return students;
    }


    public static void main(String[] args) {
        List<Student> students = generate_students();
        List<Student> sorted_by_id = SortingStudentsByIDS.sort_ids(students);
        SortingStudentsByGPA.sort_gpt(students, 0, students.size() - 1);
        for (Student s : sorted_by_id)
            System.out.println(s.toString());

    }
}
