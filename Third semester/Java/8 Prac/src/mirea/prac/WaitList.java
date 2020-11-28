package mirea.prac;

import java.util.ArrayList;
import java.util.Collection;

public class WaitList<E> implements IWaitList<E> {
    protected ArrayList<E> queue;

    public WaitList() {
        this.queue = new ArrayList<E>();
    }

    public WaitList(ArrayList<E> queue) {
        this.queue = queue;
    }

    @Override
    public String toString() {
        return "WaitList{" +
                "queue=" + queue +
                '}';
    }

    @Override
    public void add(E element) {
        this.queue.add(element);
    }

    @Override
    public E remove() {
        E result = this.queue.get(this.queue.size() - 1);
        this.queue.remove(result);

        return result;
    }

    @Override
    public boolean contains(E element) {
        for (Object cell : this.queue)
            if (cell == element)
                return true;
        return false;


    }

    @Override
    public boolean containsAll(Collection<E> collection) {
        for (var c_cell : collection)
            if (!this.contains(c_cell))
                return false;
        return true;
    }


    @Override
    public boolean isEmpty() {
        return this.queue.isEmpty();
    }
}
