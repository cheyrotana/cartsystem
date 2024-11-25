#include <string>
class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int pid, const std::string& pname, double pprice, int pquantity)
        : id(pid), name(pname), price(pprice), quantity(pquantity) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }
};
