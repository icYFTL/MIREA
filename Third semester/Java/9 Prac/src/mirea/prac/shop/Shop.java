package mirea.prac.shop;

import mirea.prac.Client;

public class Shop {
    public enum items {
        pen, pencil, rubber, apple, grenade, diploma
    }
    private final Client client;

    public Shop(Client client){
        this.client = client;
    }

    public boolean doPurchase(){
        // ...
        return true;
    }

}
