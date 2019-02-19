#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <locale>
//#include <array>

//Bridge of destiny - Chapter 3 - Module 4 - Homework
//Alex Gregg 2/14/2019

class Item{
    public:
        int value = 0;
        std::string type = "";
        bool consumable = false;
        std::string Name = "";
        Item(){
            Name = "null";
            type = "item";
            value = 0;
            consumable = false;
        }
        Item(std::string item_name){
            Name = item_name;
            type = "item";
        }
};
class Consumable : public Item{
    public:
        Consumable(){
            consumable = true;
            type = "consumable";
        }
        Consumable(std::string item_name){
            consumable = true;
            Name = item_name;
            type = "consumable";
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
            type = "weapon";
        }
        Weapon(std::string sword_name){
            Name = sword_name;
            type = "weapon";
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
            type = "armor";
        }
        Armor(std::string armor_name){
            Name = armor_name;
            type = "armor";
        }
        int WearArmor(){
            return defense;
        }
};
class Entity{
    public:
        std::string Name = "";
        std::string type = "entity";
        int defense = 0;
        int attack = 0;
        int health = 50;
        Entity(){
            Name = "null";
        }
};
class Player : public Entity{
    public:
        int fullness = 10;
        Player(){
            Name = "NoOneElse";
            defense = 1;
            attack = 1;
            health = 100;
            type = "player";
        }
        Player(std::string player_name){
            Name = player_name;
            attack = 2;
            defense = 2;
            health = 100;
            type = "player";
        }
};
class NPC : public Entity{
    public:
        NPC(){
            Name = "NPC";
            type = "npc";
        }
        NPC(std::string name){
            Name = name;
            type = "npc";
        }
};
class Enemy : public NPC{
    public:
        Enemy(){
            Name = "Enemy";
            defense = 1;
            attack = 1;
            health = 75;
            type = "enemy";
        }
        Enemy(std::string name){
            Name = name;
            defense = 1;
            attack = 1;
            health = 75;
            type = "enemy";
        }
};

int main(){
    //Declare variables

    //Player input
    std::string input = "";
    std::string name = "";
    //Player inventory -- will be put into the players class if there is time
    //int spacesInventory = 10;
    //Item Inventory[spacesInventory]; 
    //Player inventory mask
    int numItemNames = 10;
    int lastItem = 2;
    std::string itemNames[numItemNames];
    //Entities -- Always starts with player
    //int numEntities = 10;
    //Entity Entities[numEntities];
    Player player;

    //Directions/places
    int numLocations = 10;
    std::string locations[numLocations];
    int locationsVisited = 0;

    bool region1_finished = false;
    bool region2_finished = false;

    //If i have time
    //bool visited[];

    //Names(masks) assignments
    itemNames[0] = "Sword";
    itemNames[1] = "Chainmail";
    itemNames[2] = "Cheez-its";


    //Inventory assignments     //Tries using polymorphism in c++, doesnt realize c++ doesnt like polymorphism... fails to use polymorphism...
    //Inventory[0] = Weapon(itemNames[0]);
    //Inventory[1] = Armor(itemNames[1]);
    //Inventory[2] = Consumable(itemNames[2]);

    //Locations assignments
    locations[0] = "townsquare";    //Does not count as a visited location -- atleast not yet
    locations[1] = "citygates";     //Does not count as a visited location
    locations[2] = "castle";
    locations[3] = "marketsquare";
    locations[4] = "arenadistrict";
    // Locations outside of town;
    locations[5] = "outsidetown";   //Does not count as a visited location
    locations[6] = "horsebarn";
    locations[7] = "enchanters";
    locations[8] = "bridge";        //Does not coutn as a visited location

    //Asks player for their name
    std::cout << "Welcome Adventurer, what is your name? (no spaces): ";
    std::cin >> input;
    //Entities[0] = Player(input);
    player = Player(input);
    
    //Begin adventure
    std::cout << "Well, " << player.Name << " You have been selected for a once in a lifetime journey." << std::endl;
    std::cout << "This journey will take you to a land called Talkalth, the once home of our enemies.\nYou are to evaluate the land and report back to the Great Emporer of Banvalza." << std::endl;
    std::cout << "But before you go, heres a " << itemNames[0] << ", " << itemNames[1] << ", and some " << itemNames[2] << ". Have a safe journey." << std::endl;
    Sleep(4000);
    std::cout << "\n*whizzing and whirling magical aura surrounds you*\n" <<std::endl;
    Sleep(2500);
    std::cout << "\tTalkalth: 25 years post war.\n" << std::endl;
    Sleep(1500);
    std::cout << "You find yourself in the town square of Talkalth, there is an erie silence to the place.\n\tWhere do you go? (no spaces)" << std::endl;
    for(int i = 1; i < 5; i++)
        std::cout << " " << locations[i] << std::endl;
    
    Sleep(1000);
    input = "";
    //Getting input for the location to go to
    std::cout << "Go To: ";
    std::cin >> input;
    std::locale loc;
    while(region1_finished == false){
        if(input == "citygates" and locationsVisited < 2){
            //Preventing the player from leaving before they have searched the city
            std::cout << "the emperor will not be pleased if i leave without checking out the city." << std::endl;
        } else if(input == "citygates" && locationsVisited >= 2){
            std::cout << "*You leave through the gates*" << std::endl;
            region1_finished = true;
            break;
        } else if(locationsVisited >= 2 && player.fullness <= 5){
            //Requiring the player to eat before continuing.
            std::cout << "I should probably eat something before i move on." << std::endl;
            std::cout << "\tInventory" << std::endl;
            for(int i = 0; i < numItemNames; i++){
                if(itemNames[i] != ""){
                    std::cout << "--" << itemNames[i] << std::endl;
                }else{
                    continue;
                }
                
            }
            std::cout << "You chose to eat the: ";
            std::cin >> input;
            for(int i = 0; i < numItemNames; i++){
                if(input == itemNames[i]){
                    std::cout << "You gobble down the " << input << std::endl;
                    itemNames[i] = "";
                    player.fullness = 10;
                    break;
                }else if(i == numItemNames - 1 && input != itemNames[i]){
                    std::cout << "There is nothing like that in this backpack..." << std::endl;
                }else{
                    continue;
                }
            }
        } else if(input == locations[3]){
            //Visiting the market square
            std::cout << "The stalls are smashed and the fountain is empty.\nSearch the market? (yes or no)" << std::endl;
            std::cin >> input;
            player.fullness -= 1;
            if(input == "yes"){
                locationsVisited += 1;
                player.fullness -= 2;
                std::cout << "You see a dim reflection at the base of one of the stalls.\nPrepackaged food!, your in luck it was a (one word): ";
                std::cin >> input;
                for(int i = lastItem; i < numItemNames; i++){
                    if(itemNames[i] == ""){
                        itemNames[i] = input;
                        //Inventory[i] = Consumable(itemNames[i]);
                        lastItem += 1;
                        break;
                    }else if(i == numItemNames - 1 && itemNames[i] != ""){
                        std::cout << "You have no room for this in your inventory" << std::endl;
                        break;
                    }else{
                        continue;
                    }
                }
            }else{
                std::cout << "I guess ill have to come back later and check it out closer" << std::endl;
            }
        } else if(input == locations[2]){
            //Visiting the castle
            std::cout << "The castle is in shambles, torn apart by war.\nSearch the kings quarters? (yes or no)" << std::endl;
            std::cin >> input;
            player.fullness -= 2;
            locationsVisited += 1;
            if(input == "yes"){
                locationsVisited += 1;
                player.fullness -= 2;
                std::cout << "You find the kings quarters, his armor is still on its stand, he didnt even fight or he didnt have time to." << std::endl;
                std::cout << "A full set!, your in luck it was (one word): ";
                std::cin >> input;
                for(int i = lastItem; i < numItemNames; i++){
                    if(itemNames[i] == ""){
                        itemNames[i] = input;
                        //Inventory[i] = Consumable(itemNames[i]);
                        lastItem += 1;
                        break;
                    }else if(i == numItemNames - 1 && itemNames[i] != ""){
                        std::cout << "You have no room for this in your inventory" << std::endl;
                        break;
                    }else{
                        continue;
                    }
                }
            }else{
                std::cout << "I guess ill have to come back later and check it out closer" << std::endl;
            }
        } else if(input == locations[4]){
            //Visiting the arena
            std::cout << "The arena is closed.\nSearch the perimeter? (yes or no)" << std::endl;
            std::cin >> input;
            player.fullness -= 1;
            if(input == "yes"){
                locationsVisited += 1;
                player.fullness -= 2;
                std::cout << "One of the dead gaurds came back to life!!\nYou fight him.\nThankfully he already lost an arm so he wasnt much of a threat." << std::endl;
                std::cout << "His weapon gleams with its enchanted power, how he lost his arm with that kind of weapon you'll never know." << std::endl;
                std::cout << "You pick up the weapon, it's a (one word): ";
                player.fullness -= 1;
                std::cin >> input;
                for(int i = lastItem; i < numItemNames; i++){
                    if(itemNames[i] == ""){
                        itemNames[i] = input;
                        //Inventory[i] = Consumable(itemNames[i]);
                        break;
                    }else if(i == numItemNames - 1 && itemNames[i] != ""){
                        std::cout << "You have no room for this in your inventory" << std::endl;
                        break;
                    }else{
                        continue;
                    }
                }
            }else{
                std::cout << "I guess ill have to come back later and check it out closer" << std::endl;
            }
        } else{
            std::cout << "I dont see any places like that." << std::endl;
        }

        //Displaying locations to visit
        std::cout << "\tWhere do you go now? (no spaces)" << std::endl;
        for(int i = 1; i < 5; i++)
            std::cout << " " << locations[i] << std::endl;
        Sleep(1000);
        input = "";
        //Getting input for the location to go to
        std::cout << "Go To: ";
        std::cin >> input;
    }
    std::cout << "you are standing outside the gates now, you can see a few more places to check." << std::endl;
    for(int i = 6; i < 9; i++)
            std::cout << " " << locations[i] << std::endl;
    while(region2_finished == false){
        if(input == "bridge" && locationsVisited < 4){
            std::cout << "Im almost done here but i should visit a few more places before leaving\nI dont want to disapoint the emperor." << std::endl;
        }else if(input == "bridge" && locationsVisited >= 4){
            std::cout << "welp, on my way home then.";
            break;    
        }else if(input == "horsebarn"){
            std::cout << "blah blah blah" << std::endl;
            locationsVisited += 1;
        }else if(input == "enchanters"){
            std::cout << "blah blah blah" << std::endl;
            locationsVisited += 1;
        } else{
            std::cout << "I dont see any locations like that." << std::endl;
        }

        //Displaying locations to visit
        std::cout << "\tWhere do you go now? (no spaces)" << std::endl;
        for(int i = 6; i < 9; i++)
            std::cout << " " << locations[i] << std::endl;
        Sleep(1000);
        input = "";
        //Getting input for the location to go to
        std::cout << "Go To: ";
        std::cin >> input;

    }

    std::cout << "A bridge troll appears blocking your way." << std::endl;
    std::cout << "He asks you to give him your most valuable item and he will let you pass" << std::endl;
    //Meets the bridge troll who takes the most valuable item.
    //Heads back home.
     //Requiring the player to eat before continuing.
    std::cout << "What do i choose?" << std::endl;
    std::cout << "\tInventory" << std::endl;
    for(int i = 0; i < numItemNames; i++){
        if(itemNames[i] != ""){
            std::cout << "--" << itemNames[i] << std::endl;
        }else{
            continue;
        }
    }
    std::cout << "You chose to give up the: ";
    std::cin >> input;
    for(int i = 0; i < numItemNames; i++){
        if(input == itemNames[i]){
            std::cout << "The troll snatches the item from your hands.\nWith a smug face he swallows the " << input << " whole." << std::endl;
            itemNames[i] = "";
            std::cout << "Your free to go, he says." << std::endl;
            break;
        }else if(i == numItemNames - 1 && input != itemNames[i]){
            std::cout << "There is nothing like that in this backpack..." << std::endl;
        }else{
            continue;
        }
    }

    std::cout << "The journey is over and the king is pleased with what youve found. Good job!" << std::endl;
    std::cin >> input;

}

