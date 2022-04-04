# Evive Engineering Test

## Submitted by: John West

### Contents

- Makefile
- Restaurant.cpp
- Restaurant-Test.txt
- Restaurant-Test.correct

### Deployment

This program is made using C++ and includes the following built in C++ packages:
- <string>
- <iostream>
- <exception>

Note: These deployment steps are intended for Unix based operating systems.

To build the program, use the following command:
```
make
```
or
```
make restaurant
```

To run the program, use the following command:
```
./restaurant
```
The user will then be prompted to input information for ordering a meal.
Valid user input will be in the form:
```
[meal] [order]
```
Where \[meal\] can be one of the following:

- Breakfast
- Lunch
- Dinner

And \[order\] is a comma separated string of numbers, such as:
```
1,2,3
```

The following table details the items that can be ordered for each meal, where each item in the \[order\] string corresponds to the number at the top of the table:
| 			| 1. \(Main\)	| 2. \(Side\)	| 3. \(Drink\)	| 4. \(Dessert\) 	|
| ---		| --- 			| --- 			| --- 			| --- 				|
| Breakfast | Eggs 			| Toast 		| Coffee 		| 					|
| Lunch		| Sandwich 		| Chips 		| Soda 			| 					|
| Dinner	| Steak 		| Potatoes 		| Wine 			| Cake 				| 

Valid user input for an order follows these rules:
1. Each order must contain a main and a side \(drinks are optional\).
	- Additionally, at Dinner, dessert must be ordered.
2. Each type of item may only be ordered once per meal, excluding the following exceptions:
	1. At Breakfast, Coffee may be ordered an unlimited number of times per meal.
	2. At Lunch, Chips may be ordered an unlimited number of times per meal.

The program will continue to prompt for user input until the program is closed.

To exit the program, use the quit command:
```
q
```

### Testing

Restaurant-Test.txt contains 85 different test cases.

Using the following command:
```
make test
```
Restaurant-Test.txt will be funneled into restaurant and Restaurant-Test.out will be created with the output.
Then a check of the output from Restaurant-Test.out compared to Restaurant-Test.correct will be performed.
The user will be notified if there is a difference in the two files, otherwise the program has passed all the test cases.

For a side by side comparison of Restaurant-Test.correct and Restaurant-Test.out, use:
```
make testD
```
Which will give a more verbose understanding if there are any issues passing the test cases.

### Directory Clean-up

The following command will remove executable and output files from the directory:
```
make clean
```
