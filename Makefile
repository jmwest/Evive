CC     := g++
CFLAGS := -Wall -Werror -pedantic -g

restaurant : Restaurant.cpp
	$(CC) $(CFLAGS) Restaurant.cpp -o restaurant

test : restaurant
	./restaurant < Restaurant-Test.txt > Restaurant-Test.out
	diff -q Restaurant-Test.correct Restaurant-Test.out

clean :
	rm -vf Restaurant-Test*.out
	rm -vf restaurant
