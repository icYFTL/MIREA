package mirea.prac;

public class Student {
    public int id;
    public double gpt;

    public Student(int id, double gpt) {
        this.id = id;
        this.gpt = gpt;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", summary_score=" + gpt +
                '}';
    }
}
