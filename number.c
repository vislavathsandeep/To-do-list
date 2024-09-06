#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

void play_game(int lower_bound, int upper_bound);

int main() {
    int lower_bound = 1;
    int upper_bound = 100;
    
    // Seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between %d and %d.\n", lower_bound, upper_bound);

    play_game(lower_bound, upper_bound);

    return 0;
}

void play_game(int lower_bound, int upper_bound) {
    int number_to_guess = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
    int guess;
    int tries = 0;
    
    while (tries < MAX_TRIES) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if (guess < lower_bound || guess > upper_bound) {
            printf("Please enter a number between %d and %d.\n", lower_bound, upper_bound);
        } else if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries + 1);
            return;
        }

        tries++;
        printf("You have %d tries left.\n", MAX_TRIES - tries);
    }
    
    printf("Sorry, you've used all your tries. The number was %d.\n", number_to_guess);
}

