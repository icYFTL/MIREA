package mirea.prac;

import java.util.List;

public class SortingStudentsByIDS {
    public static List<Student> sort_ids(List<Student> students) {
        long m = System.currentTimeMillis();
        for (int left = 0; left < students.size(); left++) {
            Student value = students.get(left);
            int i = left - 1;
            for (; i >= 0; i--)
                if (value.id < students.get(i).id)
                    students.set(i + 1, students.get(i));
                else
                    break;
            students.set(i + 1, value);
        }
        System.out.println(String.format(
                "Insertion sort done.\n" +
                        "EST: %f s\n\n",
                (double) (System.currentTimeMillis() - m) / 1000.0
        ));

        return students;
    }

}
