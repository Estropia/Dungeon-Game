/* Dungeon Barge Prototype 1 */
/* This is a test bed of the battle system using random integer */
/* 04-02-2024 */
/* Written by High Bar Games (Group name still pending) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    //Variable Declaration 
    int end = 0; //End and Winning conditions
    float playerHP = 20, goblinHP = 15; //HPs of characters
    int playerDie, goblinDie; //Dices of characters
    float playerATK, goblinATK; //Respective Damages 
    int player, playerTurn; //Player input stuff
    int playerBlock = 0, playerDodge = 0; // Player move conditions

    //Ranges of Dices
    const int MIN = 1; 
    const int MAX = 6;
    srand(time(0)); //Use current time as seed
    
    //ENemy encounter
    printf("A GOBLIN Appears!!!\n\n");

    //Battle Loop
    while (end != 1) {
        //Stats
        printf("\t<HERO>\t<GOBLIN>\n");
        printf("HP:\t%.1f\t%.1f\n\n", playerHP, goblinHP);

        //If player is still standing, do the following
        if (playerHP > 0 && end != 1) {
            printf("|HERO's TURN!|\n\n");
            printf("MOVES\t\tDESCRIPTION\n");
            printf("[0] Sword\tDeal half of die roll DMG (Need to roll 10 or LESS)\n");
            printf("[1] Shield\tBlock 3 DMG (Need to roll an EVEN)\n");
            printf("[2] Dodge\tDodge next attack (Need to roll 16 or MORE)\n\n");
    
            playerTurn = 1;

            while (playerTurn != 0) {
                //Player input
                printf("> ");
                scanf("%d", &player);
                printf("\n");

                //Roll Player Die
                playerDie = (rand() % MAX) + MIN;

                //If sword
                if (player == 0) {
                    //State their roll
                    printf("You rolled a %d\n\n", playerDie);

                    //If roll meets the move condition
                    if (playerDie <= 6) {
                        //Deal respective damages
                        playerATK = playerDie / 2;
                        goblinHP = goblinHP - playerATK;
                        playerTurn--;

                        printf("ROLL SUCCESSFUL!\n");
                        printf("(GOBLIN receives %.f DMG)\n\n", playerATK);
                        
                    }

                    //Else, roll failed
                    else {
                        printf("ROLL FAILED!\n\n");
                        playerTurn--;

                    }

                }

                //Else if shield
                else if (player == 1) {
                    //State their roll
                    printf("You rolled a %d\n\n", playerDie);

                    //If roll meets the move condition
                    if (playerDie % 2 == 0) {
                        //Blocking is True
                        playerBlock++;
                        playerTurn--;

                        printf("ROLL SUCCESSFUL!\n");
                        printf("(You will Block 3 DMG)\n\n");
                        
                    }

                    //Else, roll failed
                    else {
                        printf("ROLL FAILED!\n\n");
                        playerTurn--;

                    }

                }

                //Else if dodge
                else if (player == 2) {
                    //State their roll
                    printf("You rolled a %d\n\n", playerDie);

                    //If roll meets the move condition
                    if (playerDie >= 3) {
                        //Dodging is True
                        playerDodge++;
                        playerTurn--;

                        printf("ROLL SUCCESSFUL!\n");
                        printf("(You will Dodge the next attack)\n\n");
                        
                    }

                    //Else, roll failed
                    else {
                        printf("ROLL FAILED!\n\n");
                        playerTurn--;

                    }

                }

                //Else, tell player to input again
                else {
                    printf("[INVALID INPUT]\n\n");

                }

            }

        }

        //Else, player ded
        else {
            printf("[You DED]\n\n");
            end++;

        }
        

        //Update Stats
        printf("\t<HERO>\t<GOBLIN>\n");
        printf("HP:\t%.1f\t%.1f\n\n", playerHP, goblinHP);
        
        //If goblin is still standing, do the following
        if (goblinHP > 0 && end != 1) {
            printf("|GOBLIN's TURN!|\n\n");
            printf("MOVES\t\tDESCRIPTION\n");
            printf("[0] Stick\tDeal 3 DMG (Need to roll 10 or LESS)\n");
            printf("[1] Rock Throw\tDeal 5 DMG (Need to roll 16 or MORE)\n\n");

            //Roll Goblin Die
            goblinDie = (rand() % MAX) + MIN;

            //State their roll
            printf("GOBLIN rolled a %d\n\n", goblinDie);

            //If goblinDie meets stick condtion
            if (goblinDie <= 4) {
                goblinATK = 3;

                printf("ROLL SUCCESSFUL!\n");
                
                //If player did not block and dogde
                if (playerBlock == 0 && playerDodge == 0) {
                    playerHP = playerHP - goblinATK;

                    printf("(HERO receives %.1f DMG!)\n\n", goblinATK);

                }

                //ELse if player did block
                else if (playerBlock == 1 && playerDodge == 0) {
                    goblinATK = goblinATK - 3;
                    playerHP = playerHP - goblinATK;
                    playerBlock--;

                    printf("(HERO BLOCKS 3 DMG and Receives %.1f DMG!)\n\n", goblinATK);

                }

                //Else, damage is null
                else {
                    playerDodge--;

                    printf("(GOBLIN Misses!)\n\n");

                }

            }

            //Else if goblin meets rock condition
            else if (goblinDie >= 4) {
                goblinATK = 5;

                printf("ROLL SUCCESSFUL!\n");
                
                //If player did not block and dogde
                if (playerBlock == 0 && playerDodge == 0) {
                    playerHP = playerHP - goblinATK;

                    printf("(HERO receives %.1f DMG!)\n\n", goblinATK);

                }

                //ELse if player did block
                else if (playerBlock == 1 && playerDodge == 0) {
                    goblinATK = goblinATK - 3;
                    playerHP = playerHP - goblinATK;
                    playerBlock--;

                    printf("(HERO BLOCKS 3 DMG and Receives %.1f DMG!)\n\n", goblinATK);

                }

                //Else, damage is null
                else {
                    playerDodge--;

                    printf("(GOBLIN Misses!)\n\n");

                }

            }

            //Else, roll failed
            else {
                printf("ROLL FAILED!\n\n");

            }
            
        }

        //Else, goblin ded
        else {
            printf("[GOBLIN is DED]\n\n");
            printf("[HERO WINS!]\n\n");
            end++;

        }
        
    }

}