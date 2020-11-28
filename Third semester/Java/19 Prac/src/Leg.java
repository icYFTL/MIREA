public class Leg {
    public int size;
    public int beauty;

    public Leg(int size, int beauty){
        this.size = size;
        this.beauty = beauty;
    }

    @Override
    public String toString() {
        return "Leg{" +
                "size=" + size +
                ", beauty=" + beauty +
                '}';
    }
}
