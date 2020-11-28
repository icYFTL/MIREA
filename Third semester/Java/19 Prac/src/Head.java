public class Head {
    public int size;
    public boolean hair;
    public int beauty;

    public Head(int size, boolean hair, int beauty){
        this.size = size;
        this.hair = hair;
        this.beauty = beauty;
    }

    @Override
    public String toString() {
        return "Head{" +
                "size=" + size +
                ", hair=" + hair +
                ", beauty=" + beauty +
                '}';
    }
}
