#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iterator>

//Bridge of destiny - Chapter 3 - Module 4 - Homework
//Alex Gregg 2/14/2019

//String array usages 
//Lines: 137-154 --adding items
//Line: 156-166 -- Checking items
//Acquire 2 or 3 items in Region 1 - Lines: 231-346
//Acquire 1 item max in Region 2 - Lines: 354-406
//Give up 1 item at the end of region 2 (bridge troll) - Lines: 410-440
//End game content -- Lines: 443 - 491

//Could not implement cleanly.
class Item{
    public:
        int value = 0;
        int durability = 20;
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
//Somewhat implemented
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

std::string GoToLocation(std::string locations[], int range){
    std::string inpt = "";
    //Displaying locations to visit
    std::cout << "\tWhere do you go now? (no spaces)" << std::endl;
    if(range == 1){
        for(int i = 6; i < 9; i++)
            std::cout << " " << locations[i] << std::endl;
    }else if(range == 0){
        for(int i = 1; i < 5; i++)
            std::cout << " " << locations[i] << std::endl;
    }
    Sleep(1000);
    //Getting input for the location to go to
    std::cout << "Go To: ";
    std::cin >> inpt;
    return inpt;
}
//Searches the inventory array for an opening to place an item in
int AddToInventory(int &lastItem, int numItemNames, std::string itemNames[]){
    int placeholder = -1;
    
    for(int i = lastItem; i < numItemNames; i++){
        if(itemNames[i] == ""){
            placeholder = i;
            lastItem += 1;
            break;
        }else if(i == numItemNames - 1 && itemNames[i] != ""){
            std::cout << "You have no room for this in your inventory" << std::endl;
            placeholder = -1;
            break;
        }else{
            continue;
        }
    }
    return placeholder;
}
//Searches the inventory for any items and displays what is there.
std::string CheckInventory(int numItemNames, std::string itemNames[]){
    //Check Inventory                               //Searches an array for the 
    std::cout << "\tInventory" << std::endl;
    for(int i = 0; i < numItemNames; i++){
        if(itemNames[i] != ""){
            std::cout << "--" << itemNames[i] << std::endl;
        }else{
            continue;
        }
    }
}
int main(){
    //Declare variables

    //Player input
    std::string input = "";
    std::string name = "";

    //Player inventory -- will be put into the players class if there is time
    int numItemNames = 10;
    int lastItem = 2;
    std::string itemNames[numItemNames];
    
    //Entities -- Always starts with player
    Player player;

    //Directions/places
    int numLocations = 10;
    std::string locations[numLocations];
    int locationsVisited = 0;

    bool region1_finished = false;
    bool region2_finished = false;
    int region = 0;;

    bool emporer_pleased = false;

    
    //Inventory assignments
    itemNames[0] = "Sword";
    itemNames[1] = "Chainmail";
    itemNames[2] = "Cheez-its";

    //Locations assignments
    locations[0] = "townsquare";    //Does not count as a visited location -- is a start location
    locations[1] = "citygates";     //Does not count as a visited location -- is a level transition
    locations[2] = "castle";
    locations[3] = "marketsquare";
    locations[4] = "arenadistrict";
    // Locations outside of town;
    locations[5] = "outsidetown";   //Does not count as a visited location  -- is a start location
    locations[6] = "horsebarn";
    locations[7] = "enchanters";
    locations[8] = "bridge";        //Does not coutn as a visited location -- is a level transition

    //Asks player for their name
    std::cout << "Welcome Adventurer, what is your name? (no spaces): ";
    std::cin >> input;
    
    //Assigns the players name to the player object
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
    std::cout << "You find yourself in the town square of Talkalth, there is an erie silence to the place.\n" << std::endl;
    input = GoToLocation(locations, region);
    
    //First half of the journey, can acquire 3 items(1 per location).
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
                int placeholder = -1;
                locationsVisited += 1;
                player.fullness -= 2;
                std::cout << "You see a dim reflection at the base of one of the stalls.\nPrepackaged food!, your in luck it was a (one word): ";
                std::cin >> input;
                placeholder = AddToInventory(lastItem,numItemNames,itemNames);
                if(placeholder >= 0){
                    itemNames[placeholder] = input; 
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
                int placeholder = -1;
                locationsVisited += 1;
                player.fullness -= 2;
                std::cout << "You find the kings quarters, his armor is still on its stand, he didnt even fight or he didnt have time to." << std::endl;
                std::cout << "A full set!, your in luck it was (one word): ";
                std::cin >> input;
                placeholder = AddToInventory(lastItem,numItemNames,itemNames);
                if(placeholder >= 0){
                    itemNames[placeholder] = input; 
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
        } else if(input == "check"){
            //Check Inventory                               //Searches an array for the 
            std::cout << "\tInventory" << std::endl;
            for(int i = 0; i < numItemNames; i++){
                if(itemNames[i] != ""){
                    std::cout << "--" << itemNames[i] << std::endl;
                }else{
                    continue;
                }
            }
        } else{
            std::cout << "I dont see any places like that." << std::endl;
        }

        input = GoToLocation(locations, region);
    }

    //Transitioning levels
    region++;
    std::cout << "you are standing outside the gates now, you can see a few more places to check." << std::endl;
    input = GoToLocation(locations,region);

    //Second half of the journey, can acquire 1 item(horse barn) and lose 1 item(troll).
    while(region2_finished == false){
        if(input == "bridge" && locationsVisited < 4){
            std::cout << "Im almost done here but i should visit a few more places before leaving\nI dont want to disapoint the emperor." << std::endl;
        }else if(input == "bridge" && locationsVisited >= 4){
            std::cout << "Time to head home then, im sure the emporer will be happy with what ive found.\n";
            break;    
        }else if(input == "horsebarn"){
            std::cout << "You arrive at the horse barn and there are bones all over the place.\nYou cant tell whats human and whats not but you get an erie feeling." << std::endl;
            std::cout << "Search the horse barn?(yes or no):" << std::endl;
            std::cin >> input;
            if(input == "yes"){
                int placeholder = -1;
                locationsVisited += 1;
                player.fullness -= 1;
                std::cout << "You find a letter that indicates the Talkalth king orderd for two of his spies to infiltrate the kingdom of Banvalza five years before the war was over." << std::endl;
                std::cin >> input;
                placeholder = AddToInventory(lastItem,numItemNames,itemNames);
                if(placeholder >= 0){
                    itemNames[placeholder] = "letter"; 
                }
                emporer_pleased = true;
            }else{
                std::cout << "I should probably dig deeper, theres bound to be some information somewhere." << std::endl;
            }
            
        }else if(input == "enchanters"){
            std::cout << "You enter the enchanters tent." << std::endl;
            Sleep(1500);
            std::cout << "The enchanter looks at you and continues what he was doing." << std::endl;
            Sleep(2000);
            std::cout << "You ask the enchanter what he knows about the region." << std::endl;
            Sleep(2000);
            std::cout << "The enchanter looks up and says: \nIf you know the candle light is fire, the meal was cooked long ago." << std::endl;
            Sleep(4000);
            std::cout << "You shrug and leave, he must be senile." << std::endl;
            locationsVisited += 1;
        }else if(input == "check"){
            //Check Inventory                               //Searches an array for the 
            std::cout << "\tInventory" << std::endl;
            for(int i = 0; i < numItemNames; i++){
                if(itemNames[i] != ""){
                    std::cout << "--" << itemNames[i] << std::endl;
                }else{
                    continue;
                }
            }
        }else{
            std::cout << "I dont see any locations like that." << std::endl;
        }

        input = GoToLocation(locations, region);

    }

    //Bridge troll takes 1 item
    bool trollSatisfied = false;
    while(trollSatisfied == false){
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
                std::cout << "That will do, but next time bring me a better snack!" << std::endl;
                trollSatisfied = true;
                break;
            }else if(i == numItemNames - 1 && input != itemNames[i]){
                std::cout << "There is nothing like that in this backpack..." << std::endl;
            }else{
                continue;
            }
        }
    }

    //Tests what items you kept for a end game condition
    bool letterKept = false;
    if(emporer_pleased == true){
        
        for(int i = 0; i < numItemNames; i++){
            if(itemNames[i] == "letter" ){
                letterKept = true;
                break;
            }else if(i == numItemNames - 1 && itemNames[i] != "letter"){
                std::cout << "Oh no, the letter! the Emporer wont be very happy about this.." << std::endl;
                letterKept = false;
                break;
            }else{
                continue;
            }
        }
    }
    //Level transition -- Returning home
    region++;

    //End game content lol.
    if(letterKept == false && emporer_pleased == true){
        std::cout << "\nThe journey might be over, but you lost the most important find, the letter!\n The Emporer will tolerate this one slip up but your reward has been cut down to a fourth of what it was originally." << std::endl;
        std::cout << "Your first two of your items will be taken to account for the cost of the journey." << std::endl;
        int itemsTaken = 0;
        for(int i = 0; i < numItemNames; i++){
            if(itemNames[i] != "" and itemsTaken < 2){
                std::cout << "The treasurer took the " << itemNames[i] << std::endl;
                itemNames[i] = "";
                itemsTaken += 1;
            }else if(itemsTaken >= 2){
                std::cout << "That will do as payment" << std::endl;
                break;
            }else{
                continue;
            }
            
        }
    }else if(letterKept == false && emporer_pleased == false){
        std::cout << "\nYou came back with nothing of interest" << std::endl;
        std::cout << "The Emporer was not pleased and has decreed that you will work in the mines for the next 40 years!" << std::endl;
        std::cout << "You lose all your items" << std::endl;
        for(int i = 0; i < numItemNames; i++){
            itemNames[i] = "";
        }
    }else{    
        std::cout << "\nThe journey is over and the Emporer is pleased with what you've found." << std::endl;
        std::cout << "Good job!" << std::endl;
    }
    
    std::cin >> input;

}

