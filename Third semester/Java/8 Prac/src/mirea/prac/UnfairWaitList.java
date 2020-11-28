package mirea.prac;


public class UnfairWaitList<E> extends WaitList<E> {

    public UnfairWaitList(){
    }

    public void remove(E element) {
        for (var cell : this.queue)
            if (cell == element){
                this.queue.remove(cell);
                break;
            }

    }

    public void moveToBack(E element){
        for (int i = 0; i < this.queue.size(); ++i)
            if (this.queue.get(i) == element){
                for (int j = i - 1; j >= 0; --j){
                    var temp = this.queue.get(j);
                    this.queue.set(j, this.queue.get(j + 1));
                    this.queue.set(j + 1, temp);
                }
                break;
            }
    }
}
