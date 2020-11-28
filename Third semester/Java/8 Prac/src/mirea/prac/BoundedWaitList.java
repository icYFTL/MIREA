package mirea.prac;

import java.util.ArrayList;

public class BoundedWaitList<E> extends WaitList<E> {
    private final int capacity;

    public BoundedWaitList(int capacity) {
        this.capacity = capacity;
        this.queue = new ArrayList<E>();
    }

    public int getCapacity() {
        return this.capacity;
    }

    public void add(E element) {
        this.queue.add(element);
    }

    @Override
    public String toString() {
        return "BoundedWaitList{" +
                "capacity=" + capacity +
                ", queue=" + queue +
                '}';
    }
}
