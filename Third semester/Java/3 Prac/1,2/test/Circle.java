package test;

public class Circle extends Shape {
    private double radius;

    public Circle(){}

    public Circle(double radius){
        this.radius = radius;
    }

    public Circle(double radius, String color, boolean filled){
        super(color, filled);
        this.radius = radius;

        setColor(color);
        setFilled(filled);
    }

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    @Override
    public double getPerimeter() {
        return 2.0 * Math.PI * this.radius;
    }

    @Override
    public String toString() {
        return String.format("Circle {Radius: %f, Color: %s, Filled: %s}",
                this.radius,
                this.getColor(),
                this.isFilled());
    }
}
