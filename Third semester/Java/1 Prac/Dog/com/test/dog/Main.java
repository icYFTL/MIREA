package com.test.dog;


public class Main {

    public static void main(String[] args) {
	    Dog d1 = new Dog("Kek", 15);
        Dog d2 = new Dog("Lol", 7);
        Dog d3 = new Dog("KekLol", 1);
        Dog d4 = new Dog("Lolkek");


        System.out.println(d1.toString());
        System.out.println(d2.humanAge());
        d3.setAge(200);
        System.out.println(d3.humanAge());
        System.out.println(d4.toString());
    }
}
