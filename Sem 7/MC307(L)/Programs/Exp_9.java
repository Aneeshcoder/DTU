abstract class Shape {
    String color;
    Shape(String color) {
        this.color = color;
    }
    abstract double area();
    void displayColor() {
        System.out.println("Color: " + color);
    }
}

class Circle extends Shape {
    double radius;
    Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

abstract class Polygon extends Shape {
    Polygon(String color) {
        super(color);
    }
}

public class Exp_9 {
    public static void main(String[] args) {
        Circle circle = new Circle("Red", 5);
        circle.displayColor();
        System.out.println("Area of circle: " + circle.area() + " square units");
    }
}
