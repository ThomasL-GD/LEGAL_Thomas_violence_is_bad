#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand (time (NULL));
	
	int nPlayerLife = 100;
	int nAdvLife = 100;
	int nPlayerMP = 5;
	int nAdvMP = 5;
	// The -1 in poison variables means that they were never poisonned before.
	int nPlayerPoison = -1;
	int nAdvPoison = -1;
	int bPlayerDefend = 0;
	int bAdvDefend = 0;
	int nChoice = 0;
	int nRandom =0;
	
	for(int i = 0; i<50; i++){
		printf("\n");
	}
	
	while (nPlayerLife > 0 && nAdvLife > 0){
		
		nChoice = 0;
		bPlayerDefend = 0;
		if(nPlayerMP < 5){
			nPlayerMP += 1;
		}
		if(nPlayerPoison >= 1){
			
			// The player take 1 damage less than the enemy, if you want to know why, go check the line 141
			nRandom = (rand() % 7) + 6;
			nPlayerLife -= nRandom;
			nPlayerPoison -= 1;
			printf("You suffer from the poison, you take %d damage \n", nRandom);
			
		}
		
	
		// To ask again what the player wants to if he type smth else than the possible actions like if he type 5 for checking status or if he type 5489465 because he tries to break my game
		while(nChoice !=1 && nChoice != 2 && nChoice != 3 && nChoice != 4){
			
			printf("What do you want to do ? \n");
			
			printf("1) Attack \n");
			printf("2) Defend \n");
			printf("3) Poison spell : 5MP \n");
			printf("4) Antidote : 3MP \n");
			printf("5) Check your satus \n");
			printf("6) Observe the enemy \n");
			
			printf("Type your choice : ");
			scanf("%d",&nChoice);
			printf(" \n \n");
			
			
			if(nChoice == 5){
			
				printf("HP : %d/100\n", nPlayerLife);
				printf("MP : %d/5\n", nPlayerMP);
				
				if(nPlayerPoison >=3){
					printf("You feel hard poisonned. \n");
				}
				
				if(nPlayerPoison <= 2 && nPlayerPoison > 1){
					printf("You feel poisonned. \n");
				}
				
				if(nPlayerPoison == 1){
					printf("You feel a little poisonned. \n");
				}
				
				if(nPlayerPoison == 0){
					printf("You feel no longer poisonned. \n");
				}
				
				printf("\n");
			
			}
			
			if(nChoice == 6){
				
				if(nAdvLife >= 100){
					printf("The enemy seems to be in full health.\n");
				}
				
				if(nAdvLife >= 60 && nAdvLife < 100){
					printf("The enemy seems to be kinda healthy.\n");
				}
				
				if(nAdvLife >= 20 && nAdvLife < 60){
					printf("The enemy seems to be pretty damaged.\n");
				}
				
				if(nAdvLife < 20){
					printf("The enemy seems to be close to death.\n");
				}
				
				
				
				if(nAdvMP >= 5){
					printf("The enemy seems to be full of magic! \n");
				}
				
				if(nAdvMP >= 2 && nAdvMP < 5){
					printf("The enemy seems to have some magic left. \n");
				}
				
				if(nAdvMP < 2){
					printf("The enemy seems to be out of magic. \n");
				}
				
				
				
				if(nAdvPoison >= 3){
					printf("The enemy seems to be very poisonned. \n");
				}
				
				if(nAdvPoison == 2){
					printf("The enemy seems to be poisonned. \n");
				}
				
				if(nAdvPoison == 1 ){
					printf("The enemy seems to be just a bit poisonned. \n");
				}
				
				if(nAdvPoison == 0){
					printf("The enemy seems to be no longer poisonned. \n");
				}
				
				printf("\n");
			}
			
		}
		
		if(nChoice == 1){
			// Makes a random number between 16 and 25 so there's a bit more chances that the player makes more damage than the base damage (20) to make him feel more powerful => microflow ┌( ಠ‿ಠ)┘
			nRandom = (rand() % 10) + 16;
			
			if(bAdvDefend == 1){
				
				printf("You hit him right in his defense\n");
				nRandom = nRandom/4;
				
			}
			else{
				
				printf("You hit him ! \n");
				
			}
			
			printf("You made %d damage \n",nRandom);
			nAdvLife -= nRandom;
			
		}
		
		if(nChoice == 2){
			
			printf("You defend yourself for this turn.\n");
			bPlayerDefend = 1;
			
		}
		
		if(nChoice == 3){
			
			printf("You cast Poison...\n");
			
			if(nPlayerMP < 5){
				
				printf("But you don't have enough MP...\n");
				
			}
			else{
				
				nPlayerMP -= 5;
				
				if(nAdvPoison <= 0){
					
					printf("You poisonned the enemy\n");
					nAdvPoison = 3;
					
				}
				else{
					
					printf("But he was already poisonned...\n");
					nAdvPoison = 3;
					
				}
				
			}
			
		}
		
		if(nChoice == 4){
			
			printf("You cast Antidote...\n");
			
			if(nPlayerMP < 3){
				
				printf("But you don't have enough MP...\n");
				
			}
			else{
				
				nPlayerMP -= 3;
				
				if(nPlayerPoison == 0){
					
					printf("But you were not poisonned\n");
					nPlayerPoison = 0;
					
				}
				else{
					
					printf("You cure yourself from the poison\n");
					nPlayerPoison = 0;
					
				}
				
			}
			
		}
		printf("\n");
		
		
		// Enemy phase--------------------------------------------------------------------------
		
		
		if(nAdvLife > 0){
			printf("ENEMY PHASE : \n");
			
			bAdvDefend = 0;
			if(nAdvMP < 5){
				nAdvMP += 1;
			}
			if(nAdvPoison >= 1){
				
				nRandom = (rand() % 7) + 7;
				nAdvLife -= nRandom;
				nAdvPoison -= 1;
				printf("The enemy suffers from poison \n");
				
			}
			
			// Here, nChoice permits to reroll enemy's action if he tries to cast antidote or poison while he can't.
			nChoice = 0;
			while(nChoice == 0){
				nChoice = 1;
				nRandom = (rand() % 4) + 1;
				
				if(nRandom == 1){
					
					nRandom = (rand() % 9) + 16;
					printf("The enemy attacks you !\n");
			
					if(bPlayerDefend == 1){
						
						printf("He hits you in your defense\n");
						nRandom = nRandom/4;
						
					}
					
					printf("He makes %d damage to you\n \n",nRandom);
					nPlayerLife -= nRandom;
					nRandom = 0;
					
				}
				
				if(nRandom == 2){
					
					printf("The enemy defends. \n");
					bAdvDefend = 1;
					
				}
				
				if(nRandom == 3){
			
					if(nAdvMP < 5){
						
						nChoice = 0;
						
					}
					else{
						
						if(nPlayerPoison <= 0){
							
							printf("The enemy casts Poison\n");
							printf("You are now poisonned\n");
						
							nAdvMP -= 5;
							nPlayerPoison = 3;
							
						}
						else{
							
							nChoice = 0;
							
						}
						
					}
					
				}
				
				if(nRandom == 4){
			
					if(nAdvMP < 3){
						
						nChoice = 0;
						
					}
					else{
						
						
						if(nAdvPoison == 0){
							
							nChoice = 0;
							
						}
						else{
					
							printf("the enemy casts Antidote\n");	
							nAdvMP -= 3;
							nAdvPoison = 0;
							printf("the enemy is now cured from the poison\n");
							
						}
						
					}
					
				}
				
			}
			
			printf("\n \n");
			
		}
		else{
			
			printf("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n             YOU WON !!! \n \n      ^o^ Congratulations ! ^o^ ");
			
		}
		
		if(nPlayerLife <= 0){
			
			nPlayerLife = 0;
			while(nPlayerLife = 0){
				printf("You died.   ");
			}
			
		}
		
	}
	
	printf("\n \n \n \n \n \n \n \n \n \n \n \nGame design : Blue \nCoding : Blue \nArt : Blue \nStory : Blue \nHypo-theorico-philosopho-bilanguo-gamo-reflexion : Blue \nSpecial thanks : Family stuff and Blue \n \n \n \n");
	
}