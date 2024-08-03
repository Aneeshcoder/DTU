class Counter {
    // Step 2: Static and non-static data members
    static int totalCount = 0;  // Static data member
    int objectCount = 0;        // Non-static data member

    Counter() {
        totalCount++;  // Increment the static data member
        objectCount++; // Increment the non-static data member
    }

    // Step 3: Static method using static data member
    static void displayTotalCount() {
        System.out.println("Total objects created: " + totalCount);
    }

    // Non-static method using non-static data member
    void displayObjectCount() {
        System.out.println("Object count: " + objectCount);
    }
}

public class Exp_10 {
    public static void main(String[] args) {
        // Step 4: Create object and call static and non-static methods
        Counter obj1 = new Counter();
        obj1.displayObjectCount();
        Counter.displayTotalCount();  // Static method called using class name

        // Create another object
        Counter obj2 = new Counter();
        obj2.displayObjectCount();
        Counter.displayTotalCount(); 

        // Step 5: Observe behavior of static data member
        // Changing value of static member using obj1
        obj1.totalCount = 5;

        System.out.println("Total count from obj1: " + obj1.totalCount);
        System.out.println("Total count from obj2: " + obj2.totalCount);
    }
}
