package mirea.prac.exception;

import javax.naming.NameAlreadyBoundException;
import mirea.prac.Client;


public class ClientExistsException extends RuntimeException{
    public ClientExistsException(Client client){
        super(String.format("Client %s already exists", client.toString()), new NameAlreadyBoundException());
    }
    public ClientExistsException(String msg){
        super(msg, new NameAlreadyBoundException());
    }
}
