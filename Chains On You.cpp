#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product() : name(""), price(0.0) {} 

    Product(string _name, double _price) : name(_name), price(_price) {}

    // Геттери та сеттери
    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double _price) {
        price = _price;
    }
};

class Dish {
private:
    string name;
    Product* products;
    int productCount;

public:
    Dish() : name(""), productCount(0) {
        products = new Product[100];
    }

    Dish(string _name) : name(_name), productCount(0) {
        products = new Product[100];
    }

    void addProduct(Product product) {
        products[productCount++] = product;
    }

    double calculateTotalPrice() const {
        double totalPrice = 0;
        for (int i = 0; i < productCount; i++) {
            totalPrice += products[i].getPrice();
        }
        return totalPrice;
    }
};

class Order {
private:
    int tableNumber;
    Dish* dishes;
    int dishCount;

public:
    Order(int _tableNumber) : tableNumber(_tableNumber), dishCount(0) {
        dishes = new Dish[100];
    }

    void addDish(Dish dish) {
        dishes[dishCount++] = dish;
    }

    double calculateTotalPrice() const {
        double totalPrice = 0;
        for (int i = 0; i < dishCount; i++) {
            totalPrice += dishes[i].calculateTotalPrice();
        }
        return totalPrice;
    }
};

int main() {
    Product cheese("Cheese", 17.67);
    Product tomato("Tomato", 1.0);
    Product bread("Bread", 1.2);

    Dish sandwich("Sandwich");

    sandwich.addProduct(cheese);
    sandwich.addProduct(tomato);
    sandwich.addProduct(bread);

    Order order(10);

    order.addDish(sandwich);

    cout << "Total price of the order: $" << order.calculateTotalPrice() << endl;
}