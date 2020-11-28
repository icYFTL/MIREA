package test;

abstract class Shape {
    protected String color;
    protected boolean filled;

    public Shape(){

    }

    public Shape(String color, boolean filled){
        this.filled = filled;
        this.color = color;
    }

    public String getColor() {
        return this.color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return this.filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    abstract double getArea();
    abstract double getPerimeter();
    abstract public String toString();
}
