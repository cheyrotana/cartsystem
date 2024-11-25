#ifndef CARTSYSTEM_HPP
#define CARTSYSTEM_HPP

#include "product.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class addtocart
{
    private:
        vector<Product> cart;
        double total=0.00;
        int quantity;
    public:
        void addproducttocart(Product p, int quantity)
        {
            p.setQuantity(quantity);
            cart.push_back(p);
        }
        void removeproductfromcart(int id)
        {
            for(int i=0;i<cart.size();i++)
            {
                if(cart[i].getId() == id)
                {
                    cart.erase(cart.begin()+i);//removing the product from the cart
                }
                else {
                    cout << "Product not found in the cart."<<endl;
                }
            }
        }
        void updateproductquantity(int id, int newQuantity)
        {
            for(int i=0;i<cart.size();i++)
            {
                if(newQuantity > 0)
                {
                    cart[i].setQuantity(newQuantity);
                }
                else 
                {
                    removeproductfromcart(id);
                }
            }
            if(newQuantity == 0) 
            {
                cout << "Invalid quantity. Please try again."<<endl;
            }
        }
        double calculatetotalprice()
        {
            for(int i=0;i<cart.size();i++)
            {
                total =cart[i].getPrice() * cart[i].getQuantity();
            }
        }
        void removellproducts()
        {
            cart.clear();//removing all products from the cart
            total = 0.00;
        }
        void displaycart()
        {   
            if(cart.size() == 0)
            {
                cout << "Your cart is empty."<<endl;
            }
            cout <<"Your cart:"<<endl;
            for(int i=0;i<cart.size();i++)
            {
                cout<< "Product Name: " << cart[i].getName() <<endl;
                cout << " Price: " << " $" << cart[i].getPrice() <<endl;
                cout<< " Quantity: " << cart[i].getQuantity() <<endl;
            }
        }
        void checkout()
        {
            displaycart();
            cout << "Total price: " << total << " $" <<endl;
            removellproducts();
        }
        void savecart()
        {
            ofstream file("cart.txt");
            if(file.is_open())
            {
                for(int i=0;i<cart.size();i++)
                {
                    file << cart[i].getId() << " " << cart[i].getName() << " " << cart[i].getPrice() << " " << cart[i].getQuantity() <<endl;
                }
                file.close();
            }
            else
            {
                cout << "Unable to open file."<<endl;
            }
        }
};
#endif // CARTSYSTEM_HPP