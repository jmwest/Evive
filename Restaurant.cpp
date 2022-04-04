//
//  Restaurant.cpp
//  Evive
//
//  Created by John West on 4/1/22.
//

#include <string>
#include <iostream>

using namespace std;

// Global Strings

// These strings are used for invalid orders to create the error output string.
static const string g_order_error_str = "Unable to process:";
static const string g_invalid_input_str = "Ordered non-existant item.";
static const string g_missing_item_str = " is missing.";
static const string g_over_ordered_str = " cannot be ordered more than once.";

// Function Declarations

// error messages for the user./ Purpose: mealLogicFuntion is a multipurpose function
// Input: 	is_dinner: is boolean that is true if the current meal is dinner,
//				false otherwise
//			numberAllowed: is an int array of length 4. Each index will be of the value
//				0 if the corresponding dish cannot be ordered, 1 if only one of the
//				corresponding dish can be ordered, and 2 if an unlimited number of
//				the corresponding dish can be ordered.
//			dishRequired: is a boolean array of length 4. True if the corresponding dish
//				must be included in the order, false otherwise.
//			meal: is a string array of length 4. This array will contain the names of the
//				items for the corresponding meal (breakfast, lunch, or dinner).
//			order: is an int array of length 4. This array is created from user input.
//				Each index of the array contains the number of items to be ordered for
//				the meal.
//			menu_items: is a string array of length 4. This array is used for creating the
//				output string for invalid orders.
// Output:	A string of the form '[Main], [Side], [Drink], [Dessert]' if given valid input,
//				otherwise the string will contain an error message.
string mealLogicFunction(bool is_dinner, int numberAllowed [4], bool dishRequired [4],
						 string meal [4], int order [4], string menu_items [4]);

// Main
int main()
{
	string meal_items [4] = {"Main", "Side", "Drink", "Dessert"};
	string breakfast [4] = {"Eggs", "Toast", "Coffee", ""};
	string lunch [4] = {"Sandwich", "Chips", "Soda", ""};
	string dinner [4] = {"Steak", "Potatoes", "Wine", "Cake"};

	string input = "";
	string meal = "";
	string order = "";
	
	// This while loop continues until the user inputs the exit command, 'q'.
	while (input.compare("q") != 0) {
		
		// 1. Take user input
		cout << "Enter an order: ";
		getline(cin, input);
		
		// 2. Parse user input
		bool valid_input = true;
		
		size_t found = input.find(" ");
		if (found != string::npos ) {
			meal = input.substr(0, found);
			order = input.substr(found + 1);
		}
		else {
			meal = input;
			order = "";
		}
		
		if (meal.compare("q") == 0) {
			cout << endl;
			break;
		}
		
		int order_array [4] = {0, 0, 0, 0};
		
		// Try/Catch block used here due to potential exceptions from converting user input
		//		from string to int. Exceptions are ignored and an error message is output
		//		to the user before restarting the outer while loop.
		try {
			for (int i = 0; i < order.length(); ) {
				
				found = order.find(",", i);
				int ord_num = stoi(order.substr(i, found - i));
				
				if (ord_num > 4 || ord_num < 1) {
					valid_input = false;
					break;
				}
				else {
					order_array[ord_num - 1]++;
				}
				
				if (found != string::npos ) {
					i = found + 1;
				}
				else {
					i = order.length();
				}
			}
		} catch (int n) {
			valid_input = false;
		}
		
		
		if (!valid_input) {
			cout << g_order_error_str + " " + g_invalid_input_str << endl;
			continue;
		}
		
		// 3. Deal with meal logic
		string output = "";
		
		// Breakfast - 1,2  required, can have multiple 3
		// Lunch - 1,2 required, can have multiple 2
		// Dinner - 1,2,4 required
		if (meal.compare("Breakfast") == 0) {
			
			int number_allowed [4] = {1, 1, 2, 0};
			bool dish_required [4] = {true, true, false, false};
			output = mealLogicFunction(false, number_allowed, dish_required,
							  breakfast, order_array, meal_items);
		}
		else if (meal.compare("Lunch") == 0) {
			
			int number_allowed [4] = {1, 2, 1, 0};
			bool dish_required [4] = {true, true, false, false};
			output = mealLogicFunction(false, number_allowed, dish_required,
							  lunch, order_array, meal_items);
		}
		else if (meal.compare("Dinner") == 0) {
			
			int number_allowed [4] = {1, 1, 1, 1};
			bool dish_required [4] = {true, true, false, true};
			output = mealLogicFunction(true, number_allowed, dish_required,
							  dinner, order_array, meal_items);
		}
		else {
			output = g_order_error_str + " " + g_invalid_input_str;
		}
		
		// 4. Output result
		cout << output << endl;
	}
	
	return 0;
}

// Implementation of mealLogicFuntion. See function declaration for detailed explanation
//		of the function.
string mealLogicFunction(bool is_dinner, int numberAllowed [4], bool dishRequired [4],
						 string meal [4], int order [4], string menu_items [4]) {
	
	string output = "";
	bool validOrder = true;
	
	// This for loop constructs the output string assuming user input was valid.
	//		If an invalid order is detected, this loop is exited.
	for (int i = 0; i < 4; ++i) {
		
		if (order[i] > 0) {
			
			if (numberAllowed[i] == 0) {
				validOrder = false;
				break;
			}
			else if (numberAllowed[i] == 1) {
				
				if (order[i] > 1) {
					validOrder = false;
					break;
				}
				else {
					output = output + meal[i] + ", ";
				}
			}
			else {
				
				output += meal[i];
				
				if (order[i] > 1) {
					output += "(" + to_string(order[i]) + ")";
				}
				
				output = output + ", ";
			}
		}
		else {
			
			if (dishRequired[i]) {
				validOrder = false;
				break;
			}
			else if (i == 2) {
				output += "Water, ";
			}
		}
		
		if (is_dinner && i == 2 && order[2] != 0) {
			output += "Water, ";
		}
	}
	
	// If an invalid order was discovered, the following for loop builds
	//		the proper error message to be output to the user.
	if (!validOrder) {
		
		output = "";
		for (int j = 0; j < 4; ++j) {
			
			if (order[j] > 0) {
				
				if (numberAllowed[j] == 0) {
					output += " " + g_invalid_input_str;
				}
				else if (numberAllowed[j] == 1) {
					
					if (order[j] > 1) {
						output += " " + meal[j] + g_over_ordered_str;
					}
				}
			}
			else {
				
				if (dishRequired[j]) {
					output += " " + menu_items[j] + g_missing_item_str;
				}
			}
		}
		
		output = g_order_error_str + output;
	}
	else {
		// The output will have an extra ', ' at the end of the string at
		// 		this point. This line removes the extra characters.
		output = output.substr(0, output.length() - 2);
	}
	
	return output;
}
