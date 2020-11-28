package mirea.prac;

import java.util.ArrayList;

public class Dymaxion<T> {
    private final ArrayList<T> array;

    public Dymaxion(){
        this.array = new ArrayList<T>();
    }

    public void push(T value) {
        array.add(value);
        for (int i = this.array.size() - 1; i > 0; --i) {
            T temp = array.get(i - 1);
            array.set(i - 1, array.get(i));
            array.set(i, temp);
        }
    }

    public T pop() {
        T val = array.get(array.size() - 1);
        array.remove(array.size() - 1);
        return val;
    }

    public boolean empty(){
        return array.isEmpty();
    }


}
