package com.test.dog;

import java.lang.*;

public class Dog {
    private String name;
    private int age;

    public Dog(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Dog(String name) {
        this.name = name;
        this.age = -1;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return this.name;
    }

    public int getAge() {
        return this.age;
    }

    public int humanAge() {
        return this.age > 0 ? this.age * 7 : -1;
    }

    public String toString() {
        return String.format("Name: %s | Age: %d", this.name, this.age);
    }

}
