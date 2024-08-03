class Vehicle {
    String brand;
    Vehicle(String brand) {
        this.brand = brand;
        System.out.println("Superclass Constructor: Vehicle of brand " + brand + " is created.");
    }
    void displayBrand() {
        System.out.println("Vehicle brand: " + brand);
    }
}

class Car extends Vehicle {
    String carType;
    Car(String brand, String carType) {
        super(brand); 
        this.carType = carType;
        System.out.println("Subclass Constructor: It's a " + carType + ".");
    }
    void displayDetails() {
        System.out.println("It's a " + brand + " " + carType + ".");
    }
}

public class Exp_8 {
    public static void main(String[] args) {
        Car sedanCar = new Car("Toyota", "Sedan");
        sedanCar.displayBrand();
        sedanCar.displayDetails();
    }
}
