class Animal{
    String name;
    Animal(String name){
        this.name = name;
    }

    void sound(){
        System.out.println("General Animal Sound");
    }
    void sound(String Sound_String){
        System.out.println(Sound_String);
    }
    void habitat(){
        System.out.println(name + ":");
        System.out.println("Multiple Habitats");
    }
}

class Mammal extends Animal{
    Mammal(String name){
        super(name);
    }
    
    @Override
    void habitat(){
        System.out.println(name + ":");
        System.out.println("Mammals lives on land");
    }
}

class Bird extends Animal{
    Bird(String name){
        super(name);
    }

    @Override
    void habitat(){
        System.out.println(name + ":");
        System.out.println("Birds fly in air");
    }
}

class Fish extends Animal{
    Fish(String name){
        super(name);
    }
    
    @Override
    void habitat(){
        System.out.println(name + ":");
        System.out.println("Fishes lives underwater");
    }
}

public class Exp_7{
    public static void main(String[] args){
        Animal animal = new Animal("Animal");
        Mammal lion = new Mammal("Lion");
        Bird eagle = new Bird("Eagle");
        Fish salmon = new Fish("Salmon");

        System.out.println();
        animal.habitat();

        System.out.println();
        lion.sound();
        lion.sound("Roar!");

        System.out.println();
        lion.habitat();

        System.out.println();
        eagle.habitat();

        System.out.println();
        salmon.habitat();
        System.out.println();
    }
}
