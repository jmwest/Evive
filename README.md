# Evive Engineering Test

## Submitted by: John West

### Contents
```
- Makefile
- Restaurant.cpp
- Restaurant-Test.txt
- Restaurant-Test.correct
```

### Deployment
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

The program will continue to prompt for using input until the program is closed.

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
