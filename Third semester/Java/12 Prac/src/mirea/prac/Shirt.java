package mirea.prac;

public class Shirt {
    public String id;
    public String name;
    public String color;
    public String size;

    public Shirt(String id, String name, String color, String size) {
        this.id = id;
        this.name = name;
        this.color = color;
        this.size = size;
    }

    public Shirt(String raw, String separator){
        if (separator == null)
            separator = ",";
        parse(raw, separator);
    }

    public Shirt() {

    }

    private void parse(String raw, String separator){
        String [] temp;
        raw = raw.strip();

        temp = raw.split(separator);
        this.id = temp[0];
        this.name = temp[1];
        this.color = temp[2];
        this.size = temp[3];

    }


    @Override
    public String toString() {
        return "Shirt{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", color='" + color + '\'' +
                ", size='" + size + '\'' +
                '}';
    }
}
