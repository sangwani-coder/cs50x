//Greedy algorith program

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define COINS 4
#define MAX 100
#include <unistd.h>


//Availabble coins

int coins[COINS] = {1, 5, 10, 25};

//function to calculate minimum number of coins

void findMin(int cost)
{
	int coinList[MAX] = { 0 };
	int i, k = 0, l=0;

	for (i = COINS - 1; i >= 0; i--) {
		while (cost >= coins[i]) {
			cost -= coins[i];
			// Add coin in the list
			coinList[k++] = coins[i];
			l++;
		}
	}
// printing the number of possible coins

		printf("%d\n",l);

	return;
}


int main(void)
{
	float d;
	int n;

	// loop prompting user for input

	do
	{

	d = get_float("change owed:");
	n = round(d * 100);
	}
	while (n < 0);

//calling the function
	findMin(n);

	return 0;
}
// Code by Peter Zyambo
