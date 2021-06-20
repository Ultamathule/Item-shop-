#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
// constant globals are ok, though you should avois globals when possable
const int numItems = 6;               // the compiler wants a constant number for the array so we put (const) in front of the int!
const string shopItemNames[numItems] = { "Boots","Swords","Helmets","Gauntlets","Poleaxes","Leggings" };// you cant modify a const later in prog.

//Prototypes
void printInventory(int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[numItems]);     // this should be by reference or with the (&) but arrays are always by reference!!

int main()
{
	// tell us when the game is over
	bool isDone = false;

	//stores the player inventory in an array
	int playerInventory[numItems] = { 0, 0, 0, 0, 0, 0 };

	cout << "*** Welcome to the item shop! ***\n";
	
	
	// this is the game loop!! with the bool isDone statement!!
	while(isDone == false)								
	{
		printShop();

		printInventory(playerInventory);

		// were passing it playerInventory here because it will need to change items.
		
		isDone =buyItems(playerInventory);					//another way is isDone =(buyItems(playerInventory) == true);
		
		cout << "\n\n\n";
	}
	
	system("PAUSE");
	return 0;
}

void printInventory(int playerInventory[numItems])
{
	cout << "Your inventory is: \n";
	for (int i = 0; i < numItems; i++)
	{
		if (playerInventory[i] > 0)
		{
			cout << playerInventory[i] << " x " << shopItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printShop()
{
	cout << "Shop Inventory: \n";

	for (int i = 0; i < numItems; i++)
	{
		cout << i + 1 << ". " << shopItemNames[i] << endl;  // the i + 1 is to number the items 1-6 not 0-5
	}
	cout << "************\n\n";
}

bool buyItems(int playerInventory[numItems])    // made this a bool so we can use the isDone or to end the game if needed
{
	int input;									// just need a local variable for this here for the input

	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;

	if (input == -1)
	{
		return true;  //the program is over
	}

	if (input < 1 || input > 6)
	{
		cout << "That was a bad input!\n";
		return false;		//keep going				// this will go back to continue the loop. to try again.
	}

	playerInventory[input - 1] ++;
	return false;						// anything that isnt a void function requires you to have a return value.
}