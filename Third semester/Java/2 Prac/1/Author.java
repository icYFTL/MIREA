public class Author {
    private final String name;
    private String email;
    private final char gender; // Why not boolean?

    public Author(String name, String email, char gender) {
        this.name = name;
        this.email = email;
        this.gender = gender;
    }

    public String getName() {
        return this.name;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public char getGender() {
        return this.gender;
    }

    public String toString() {
        return String.format("Name: %s | Email: %s | Gender: %c",
                this.name,
                this.email,
                this.gender);
    }
}
