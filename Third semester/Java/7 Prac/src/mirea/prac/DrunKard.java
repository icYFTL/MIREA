package mirea.prac;

public class DrunKard {
    private final Dymaxion<Integer> deck1;
    private final Dymaxion<Integer> deck2;

    public DrunKard(Dymaxion<Integer> deck1, Dymaxion<Integer> deck2) {
        this.deck1 = deck1;
        this.deck2 = deck2;
    }

    public void step_won(boolean player, int card1, int card2) {
        if (player) {
            this.deck2.push(card1);
            this.deck2.push(card2);
        } else {
            this.deck1.push(card1);
            this.deck1.push(card2);
        }
    }


    public void compute() {
        int counter = 0;
        do {
            int _step1 = deck1.pop();
            int _step2 = deck2.pop();

            if (_step1 == 9 && _step2 == 0) {
                this.step_won(false, _step1, _step2);
                counter++;
                continue;
            }
            if (_step1 == 0 && _step2 == 9) {
                this.step_won(true, _step1, _step2);
                counter++;
                continue;
            }
            this.step_won(_step1 > _step2, _step1, _step2);
            counter++;
        } while (!this.deck1.empty() && !this.deck2.empty() && counter != 106);

        if (counter == 106)
            System.out.println("botva");
        else
            if (this.deck1.empty())
                System.out.println("first " + counter);
            else
                System.out.println("second " + counter);
    }
}
