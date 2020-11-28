package mirea.prac.exception;

import mirea.prac.Client;

import javax.naming.InvalidNameException;

public class InvalidClientException extends RuntimeException{
    public InvalidClientException(Client client){
        super(String.format("Invalid Client %s passed", client.toString()), new InvalidNameException());
    }
    public InvalidClientException(String msg){
        super(msg, new InvalidNameException());
    }
}