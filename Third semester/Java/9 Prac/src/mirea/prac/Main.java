package mirea.prac;

import mirea.prac.exception.ClientExistsException;
import mirea.prac.exception.InvalidClientException;

public class Main {
    public static void main(String[] args) {
        Methods methods = new Methods();
        methods.addClient(new Client("Lol kek cheburek", 123456)); // OK
        methods.addClient(new Client("Lol kek cheburekov", 123457)); // OK
        methods.addClient(new Client("Lol kek cheburekovich", 123458)); // OK
        try {
            methods.addClient(new Client("Lol kek cheburekerrerge", 123456));
        } catch (ClientExistsException ignored) {
            System.out.println("ClientExistsException handled");
        }

        methods.client = methods.getClient(123456);
        methods.buy("smth"); // OK

        methods.client = new Client("123", 0);
        try {
            methods.buy("smth");
        } catch (InvalidClientException ignored) {
            System.out.println("InvalidClientException handled");
        }


    }
}
