#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
//#include <array>

//Bridge of destiny - Chapter 3 - Module 4 - Homework
//Alex Gregg 2/14/2019

class Item{
    public:
        int value = 0;
        bool consumable = false;
        std::string Name = "";
        Item(){
            Name = "";
            value = 0;
            consumable = false;
        }
        Item(std::string item_name){
            Name = item_name;
        }
};
class Consumable : public Item{
    public:
        Consumable(){
            consumable = true;
        }
        Consumable(std::string item_name){
            consumable = true;
            Name = item_name;
        }
        int EatItem(){
            int quench = value;
            value = 0;
            return quench;
        }
};
class Weapon : public Item{
    public:
        int damage = 5;
        int durability = 15;
        Weapon(){
            Name = "sword";
        }
        Weapon(std::string sword_name){
            Name = sword_name;
        }
        int UseWeapon(){
            return damage;
        }
};
class Armor : public Item{
    public:
        int defense = 5;
        int durability = 20;
        Armor(){
            Name = "armor";
        }
        Armor(std::string armor_name){
            Name = armor_name;
        }
        int WearArmor(){
            return defense;
        }
};
class Entity{
    public:
        std::string Name = "";
        int defense = 0;
        int attack = 0;
        int health = 50;
        Entity(){
            Name = "NPC";
        }
};
class Player : public Entity{
    public:
        int fullness = 10;
        Player(){
            Name = "Nobody";
            defense = 1;
            attack = 1;
            health = 100;
        }
        Player(std::string player_name){
            Name = player_name;
            attack = 2;
            defense = 2;
            health = 100;
        }
};

int main(){
    //Declare variables

    //Player input
    std::string input;
    std::string name = "";
    std::string phrase = "Search your feelings";
    //Player inventory
    int numItems = 10;
    Item items[numItems]; 
    
    items[0] = Weapon("Sword");
    items[1] = Armor("Chainmail");
    items[2] = Consumable("Cheezits");
    //Begin adventure
    //std::cout << "Start of adventure" << std::endl;
    std::cout << "Welcome Adventurer, what is your name? ";
    std::cin >> input;
    std::cout << "";
    
    //Wizard offers to echant your items -- IE the naming stage
    //tell player to name the items
    for (int i =0; i < sizeof(items) / sizeof(items[0]); i++)
        std::cout << items[i].Name << " :ITEM " << i << std::endl;

    
    std::cin >> input;

}

