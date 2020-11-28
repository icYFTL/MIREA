package mirea.prac;

import javax.xml.crypto.AlgorithmMethod;
import java.util.List;

public class SortingStudentsByGPA {
    public static void sort_gpt(List<Student> students, int low, int high) {
        int lowMarker = low;
        int highMarker = high;

        double pivot = students.get((lowMarker + highMarker) / 2).gpt;
        do {
            while (students.get(lowMarker).gpt < pivot)
                lowMarker++;

            while (students.get(highMarker).gpt > pivot)
                highMarker--;

            if (lowMarker <= highMarker) {
                if (lowMarker < highMarker) {
                    Student tmp = students.get(lowMarker);
                    students.set(lowMarker, students.get(highMarker));
                    students.set(highMarker, tmp);
                }
                lowMarker++;
                highMarker--;
            }
        } while (lowMarker <= highMarker);

        if (lowMarker < high)
            sort_gpt(students, lowMarker, high);

        if (low < highMarker)
            sort_gpt(students, low, highMarker);

    }
}
