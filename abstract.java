package bmsit;
abstract class Shape {
    abstract double area(); 
    abstract double perimeter(); 
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    double area() {
        return Math.PI * radius * radius;
    }

    double perimeter() {
        return 2 * Math.PI * radius;
    }
}

class Triangle extends Shape {
    private double a, b, c, height;

    public Triangle(double a, double b, double c, double height) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.height = height;
    }

    double area() {
        return (b * height) / 2;
    }

    double perimeter() {
        return a + b + c;
    }
}

public class print {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);
        System.out.println("Area of Circle: " + circle.area());
        System.out.println("Perimeter of Circle: " + circle.perimeter());

        Shape triangle = new Triangle(2.0, 4.0, 3.0, 5.0);
        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("Perimeter of Triangle: " + triangle.perimeter());
    }
}
