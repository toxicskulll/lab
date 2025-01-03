package bmsit;

class Shape {
    public void draw() {
        System.out.println("Drawing a shape!");
    }

    public void erase() {
        System.out.println("Erasing a shape!");
    }

    public double area() {
        return 0;
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public void draw() {
        System.out.println("Drawing a circle!");
    }

    public void erase() {
        System.out.println("Erasing a circle!");
    }

    public double area() {
        return Math.PI * radius * radius;
    }
}

class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public void draw() {
        System.out.println("Drawing a triangle!");
    }

    public void erase() {
        System.out.println("Erasing a triangle!");
    }

    public double area() {
        return 0.5 * base * height;
    }
}

class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public void draw() {
        System.out.println("Drawing a square!");
    }

    public void erase() {
        System.out.println("Erasing a square!");
    }

    public double area() {
        return side * side;
    }
}

public class print {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle(5);
        shapes[1] = new Triangle(4, 3);
        shapes[2] = new Square(2);

        for (Shape shape : shapes) {
            shape.draw();
            System.out.println("Area: " + shape.area());
            shape.erase();
            System.out.println();
        }
    }
}
