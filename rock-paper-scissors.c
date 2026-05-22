#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int playerChoice, computerChoice;
    int score = 0, bonusPoints = 0, consecutiveWins = 0;
    int rounds, i;
    
    printf("=== ROCK-PAPER-SCISSORS GAME ===\n");
    printf("Choose: 1 = Rock, 2 = Paper, 3 = Scissors\n");
    printf("Get 3 wins in a row to earn 2 bonus points!\n");
    printf("Enter how many rounds you want to play: ");
    scanf("%d", &rounds);
    srand(time(0));
    for(i = 1; i <= rounds; i++) {
        printf("\n--- Round %d ---\n", i);
        do {
            printf("Enter your choice (1-3): ");
            scanf("%d", &playerChoice);
            if(playerChoice < 1 || playerChoice > 3)
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        } while (playerChoice < 1 || playerChoice > 3);
        computerChoice = (rand() % 3) + 1;
        printf("Computer chose: ");
        if(computerChoice == 1)
printf("Rock\n");
        else if(computerChoice == 2)
printf("Paper\n");
        else
printf("Scissors\n");
        if(playerChoice == computerChoice) {
            printf("It's a Draw!\n");
            consecutiveWins = 0;
        } else if((playerChoice == 1 && computerChoice == 3) ||
                  (playerChoice == 2 && computerChoice == 1) ||
                  (playerChoice == 3 && computerChoice == 2)) {
            printf("You Win!\n");
            score++;
            consecutiveWins++;
            if(consecutiveWins == 3) {
                bonusPoints += 2;
                printf("Congratulations! 3 Wins in a row. Bonus 2 points awarded!\n");
                consecutiveWins = 0;
            }
        } else {
            printf("You Lose!\n");
            consecutiveWins = 0;
        }
        printf("Score: %d, Bonus Points: %d, Total Points: %d\n", score, bonusPoints, score + bonusPoints);
    }
    printf("\n--- FINAL RESULTS ---\n");
    printf("Total Score: %d\n", score);
    printf("Bonus Points: %d\n", bonusPoints);
    printf("Total Points: %d\n", score + bonusPoints);
    printf("Thanks for playing Rock-Paper-Scissors!\n");
    
    return 0;
}