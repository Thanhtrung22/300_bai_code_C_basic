#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef enum
{
    GIAY,
    BUA,
    KEO
}Game;
typedef struct
{
    Game playerChoice;
    int goalScore;
}Player;

void convert_selection(char select, Player *player);
int  Play_Game(Player *player1, Player *player2);
bool check_selection_wrong(Player *player1, Player *player2);
void main_menu();


int main()
{
    srand(time(NULL));
    char selection[3] = {'b', 'k', 'g'};
    Player player1, player2, computer;
    char sel = '\0';
    char mode_game = '\0';
    while(1)
    {

        system("cls");
        main_menu();
        printf("\nEnter mode game: ");
        mode_game = getche();
        switch(mode_game)
        {
            case '1':
            {
                char answer = '\0';
                int index = 0;
                char computer_sel = '\0';
                player1.goalScore = 0;
                computer.goalScore = 0;
                while(answer != 'n')
                {
                    printf("\n\tGAME %d\n", ++index);
                    printf("----------------------------------\n");
                    printf("\nPlayer enter selection: ");
                    fflush(stdin);
                    sel = getche();
                    printf("\n*");
                    convert_selection(sel, &player1);
                    if(check_selection_wrong(&player1, &computer))
                    {
                        printf("\nYou lose!");
                        printf("\nGoal: You %d - Computer %d\n", player1.goalScore, computer.goalScore);
                        continue;
                    }
                    computer_sel = selection[rand() % 3];
                    convert_selection(computer_sel, &computer);
                    printf("\nComputer enter selection: ");
                    printf("\n*");

                    int result = Play_Game(&player1, &computer);
                    if(result == 1)
                    {
                        printf("\nYou win");
                        player1.goalScore++;
                    }
                    else if(result == -1)
                    {
                        printf("\nComputer win");
                        computer.goalScore++;
                    }
                    else
                    {
                        printf("\nDrawn!");
                    }
                    printf("\nGoal: You %d - Computer %d\n", player1.goalScore, computer.goalScore);
                    printf("\nDo you wanna play game?(y/n)");
                    fflush(stdin);
                    answer = getche();

                    
                }
                if(computer.goalScore > player1.goalScore)
                {
                    printf("\nEnd game! Computer win");
                }
                else if(computer.goalScore < player1.goalScore)
                {
                    printf("\nEnd game! You win");
                }
                else
                {
                    printf("\nEnd game! Draw!");
                }
                getch();
                break;
            }
            case '2':
            {
                char answer = '\0';
                int index = 0;

                player1.goalScore = 0;
                player2.goalScore = 0;
                while(answer != 'n')
                {
                    printf("\n\tGAME %d\n", ++index);
                    printf("----------------------------------\n");
                    printf("\nPlayer1 enter selection: ");
                    fflush(stdin);
                    sel = getche();
                    printf("\n*");
                    convert_selection(sel, &player1);
                    if(check_selection_wrong(&player1, &player2))
                    {
                        printf("\nPlayer1 lose!");
                        printf("\nGoal: Player1 %d - %d Player2\n", player1.goalScore, player2.goalScore);
                        continue;
                    }
                    printf("\nPlayer2 enter selection: ");
                    fflush(stdin);
                    sel = getche();
                    printf("\n*");
                    convert_selection(sel, &player2);
                    if(check_selection_wrong(&player2, &player1))
                    {
                        printf("\nPlayer2 lose!");
                        printf("\nGoal: Player1 %d - %d Player2\n", player1.goalScore, player2.goalScore);
                        continue;
                    }

                    int result = 0;
                    result = Play_Game(&player1, &player2);
                    if(result == 1)
                    {
                        printf("\nPlayer1 win!");
                        player1.goalScore++;
                    }
                    else if(result == -1)
                    {
                        printf("\nPlayer2 win!");
                        player2.goalScore++;
                    }
                    else
                    {
                        printf("\nDrawn!");
                    }
                    printf("\nGoal: Player1 %d - %d Player2\n", player1.goalScore, player2.goalScore);
                    printf("\nDo you wanna continue the game?(y/n)");
                    fflush(stdin);
                    answer = getche();
                }
                if(player1.goalScore > player2.goalScore)
                {
                    printf("\nEnd game! Player1 wins!");
                }
                else if(player1.goalScore < player2.goalScore)
                {
                    printf("\nEnd game! Player2 wins!");
                }
                else
                {
                    printf("\nEnd game! Both players draw!\n");
                }
                getch();
                
                break;
            }
            case '3':
            {
                printf("\nSee you again!\n");
                return 0;
            }
            
            
            
        }
        

        
        
    }
    return 0;
}

void convert_selection(char select, Player *player)
{
    switch(select)
    {
        case 'k':
        {
            player->playerChoice = KEO;
            break;
        }
        case 'b':
        {
            player->playerChoice = BUA;
            break;
        }
        case 'g':
        {
            player->playerChoice = GIAY;
            break;
        }
        default: 
        {
            player->playerChoice = -1;
            printf("\nInvalid selection!");
            break;
        }
    }
}

int  Play_Game(Player *player1, Player *player2)
{
    int result = 0;
    if(player1->playerChoice == BUA && player2->playerChoice == KEO
    || player1->playerChoice == GIAY && player2->playerChoice == BUA
    || player1->playerChoice == KEO && player2->playerChoice == GIAY)
    {
        result = 1;
    }
    else if(player1->playerChoice == GIAY && player2->playerChoice == KEO
        ||  player1->playerChoice == BUA && player2->playerChoice == GIAY
        ||  player1->playerChoice == KEO && player2->playerChoice == BUA)
     {
        result = -1;
     }
     else
     {
        result = 0;
     }
     return result;   
}
bool check_selection_wrong(Player *player1, Player *player2)
{
    int flag = 0;
    if(player1->playerChoice == -1)
    {
        flag = 1;
        player2->goalScore++;
    }
    return flag;
}
void main_menu()
{
    printf("\n\t\tGAME TIC TAC TOE\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Play with computer\n");
    printf("2.Play with person\n");
    printf("3.Exit\n");
}