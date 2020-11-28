package mirea.prac;

import mirea.prac.exception.ClientExistsException;
import mirea.prac.exception.InvalidClientException;
import mirea.prac.shop.Shop;

public class Methods {
    public Client client = null;

    public Methods(Client client) {
        this.client = client;
    }

    public Methods(){

    }

    public boolean isValidClient(){
        return Static.clients.contains(this.client);
    }

    public static boolean isClientExists(Client client){
        for (var i : Static.clients)
            if (i.inn == client.inn)
                return true;
        return false;
    }

    public Client getClient(String snp) {
        for (var client : Static.clients)
            if (client.snp.equals(snp))
                return client;
        return null;
    }

    public Client getClient(int inn) {
        for (var client : Static.clients)
            if (client.inn == inn)
                return client;
        return null;
    }

    public void addClient(Client client) {
        if (isClientExists(client))
            throw new ClientExistsException(client);
        Static.clients.add(client);
        this.client = client;
    }

    public void buy(Object item){
        Shop shop = new Shop(this.client);
        if (!this.isValidClient())
            throw new InvalidClientException(this.client);
        shop.doPurchase();
    }




}
