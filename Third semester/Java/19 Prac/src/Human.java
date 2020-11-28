import java.util.ArrayList;

public class Human {
    public ArrayList<Hand> hands;
    public Head head;
    public ArrayList<Leg> legs;

    public Human(ArrayList<Hand> hands, Head head, ArrayList<Leg> legs) {
        this.hands = hands;
        this.head = head;
        this.legs = legs;
    }

    @Override
    public String toString() {
        return "Human{" +
                "hands=" + hands +
                ", head=" + head +
                ", legs=" + legs +
                '}';
    }
}
