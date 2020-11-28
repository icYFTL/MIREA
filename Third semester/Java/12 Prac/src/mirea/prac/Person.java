package mirea.prac;

public class Person {
    public String name = "?";
    public String surname = "?";
    public String patronymic = "?";

    public Person(String name, String surname, String patronymic) {
        this.name = name;
        this.surname = surname;
        this.patronymic = patronymic;
    }

    public Person() {

    }

    private void formatter() {

        char[] tmp = new char[this.name.length()];
        if (!this.name.equals("?")) {
            this.name.getChars(1, this.name.length(), tmp, 0);
            this.name = Character.toUpperCase(this.name.charAt(0)) + String.copyValueOf(tmp);
        }

        tmp = new char[this.surname.length()];
        if (!this.surname.equals("?")) {
            this.surname.getChars(1, this.surname.length(), tmp, 0);
            this.surname = Character.toUpperCase(this.surname.charAt(0)) + String.copyValueOf(tmp);
        }

        tmp = new char[this.surname.length()];
        if (!this.patronymic.equals("?")) {
            this.patronymic.getChars(1, this.patronymic.length(), tmp, 0);
            this.patronymic = Character.toUpperCase(this.patronymic.charAt(0)) + String.copyValueOf(tmp);
        }
    }

    public String result() {
        this.formatter();
        return String.format("%s %s.%s.",
                this.surname, this.name.charAt(0), this.patronymic.charAt(0)
                );
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", surname='" + surname + '\'' +
                ", patronymic='" + patronymic + '\'' +
                '}';
    }
}
