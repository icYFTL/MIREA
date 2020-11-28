public class Hand {
    public int size;
    public int beauty;

    public Hand(int size, int beauty){
        this.size = size;
        this.beauty = beauty;
    }

    @Override
    public String toString() {
        return "Hand{" +
                "size=" + size +
                ", beauty=" + beauty +
                '}';
    }
}
