abstract public class Dog {
    public String kind;
    public int size;
    public int angriness;
    public boolean like_cat;
    public boolean sex;

    public boolean is_good_boy(){
        return !(this.angriness > 0);
    }

    public boolean is_cute_boy(){
        return like_cat;
    }

    public boolean is_boy(){
        return sex;
    }

    @Override
    public String toString() {
        return "Dog{" +
                "kind='" + kind + '\'' +
                ", size=" + size +
                ", angriness=" + angriness +
                ", like_cat=" + like_cat +
                ", sex=" + sex +
                '}';
    }
}
