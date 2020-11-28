package mirea.prac;

public class Client {
    public final String snp;
    public final int inn;

    public Client (String snp, int inn){
        this.snp = snp;
        this.inn = inn;
    }

    @Override
    public String toString() {
        return "Client{" +
                "snp='" + snp + '\'' +
                ", inn=" + inn +
                '}';
    }
}
