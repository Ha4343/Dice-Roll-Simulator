#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6  // Dice has 6 sides

int rollDice() {
    return (rand() % SIDES) + 1;  // Generates a number between 1-6
}

void displayStats(int rolls[], int totalRolls, int longestStreak, int streakNumber) {
    printf("\n🎲 Dice Roll Statistics 🎲\n");
    printf("--------------------------\n");
    for (int i = 1; i <= SIDES; i++) {
        printf("Number %d: %d times\n", i, rolls[i]);
    }
    printf("Total Rolls: %d\n", totalRolls);
    printf("Longest Streak: %d times (Number: %d)\n", longestStreak, streakNumber);
}

int main() {
    int totalRolls = 0;
    int rolls[SIDES + 1] = {0};  // Stores occurrences of numbers (1-6)
    int prevRoll = 0, currentStreak = 0, longestStreak = 0, streakNumber = 0;
    
    srand(time(0)); // Seed for random number generation
    
    printf("🎲 Dice Roll Simulator 🎲\n");
    printf("Type 'r' to roll the dice, 's' to see stats, 'q' to quit.\n");

    char choice;
    while (1) {
        printf("\nEnter choice (r/s/q): ");
        scanf(" %c", &choice);

        if (choice == 'r') {
            int roll = rollDice();
            rolls[roll]++;
            totalRolls++;

            // Check for streaks
            if (roll == prevRoll) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }

            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
                streakNumber = roll;
            }

            prevRoll = roll;

            printf("🎲 You rolled: %d\n", roll);

        } else if (choice == 's') {
            displayStats(rolls, totalRolls, longestStreak, streakNumber);
        } else if (choice == 'q') {
            printf("Exiting Dice Roll Simulator...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
