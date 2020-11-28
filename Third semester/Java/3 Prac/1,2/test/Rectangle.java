package test;

public class Rectangle extends Shape{
    private double width;
    private double length;

    public Rectangle(){

    }

    public Rectangle(double width, double length){
        this.width = width;
        this.length = length;
    }

    public Rectangle(double width, double length, String color, boolean filled){
        super(color, filled);

        this.width = width;
        this.length = length;
        this.setColor(color);
        this.setFilled(filled);
    }

    public double getWidth() {
        return this.width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getLength() {
        return this.length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    @Override
    public double getArea() {
        return this.width * this.length;
    }

    @Override
    public double getPerimeter() {
        return (this.width + this.length) * 2.0;
    }

    @Override
    public String toString() {
        return String.format("Rectangle {Width: %.2f, Length: %.2f, Color: %s, Filled: %s}",
                this.width,
                this.length,
                this.getColor(),
                this.isFilled());
    }

}
