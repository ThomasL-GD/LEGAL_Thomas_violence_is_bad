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
		if(nPlayerPoison >= 1){
			
			nRandom = (rand() % 7) + 7;
			nPlayerLife -= nRandom;
			nPlayerPoison -= 1;
			printf("The enemy suffers from poison \n");
			
		}
		
	
		// To ask again what the player wants to if he type smth else than the possible actions like if he type 5 for checking status or if he type 5489465 because he tries to break my game
		while(nChoice !=1 && nChoice != 2 && nChoice != 3 && nChoice != 4){
			
			printf("What do you want to do ? \n");
			
			printf("1) Attack \n");
			printf("2) Defend \n");
			printf("3) Poison spell : 5MP \n");
			printf("4) Antidote : 2MP \n");
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
					printf("The enemy seems to out of magic. \n");
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
		printf("\n");
		
		
		// Enemy phase--------------------------------------------------------------------------
		
		
		if(nAdvLife > 0){
			printf("ENEMY PHASE : \n");
			
			bAdvDefend = 0;
			
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
				nRandom = (rand() % 2) + 1;
				
				if(nRandom == 1){
					
					nRandom = (rand() % 9) + 16;
					printf("The enemy attacks you !\n");
			
					if(bPlayerDefend == 1){
						
						printf("He hits you in your defense\n");
						nRandom = nRandom/4;
						
					}
					
					printf("He makes %d damage to you\n \n",nRandom);
					nPlayerLife -= nRandom;
					
				}
				
				if(nRandom == 2){
					
					printf("The enemy defends. \n");
					bAdvDefend = 1;
					
				}
			}
			
			printf("\n \n");
			
		}
		else{
			
			printf("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n             YOU WON !!! \n \n      ^o^ Congratulations ! ^o^ ");
			
		}
	}
	
	printf("\n \n \n \n \n \n \n \n \n \n \n \nGame design : Blue \nCoding : Blue \nArt : Blue \nStory : Blue \nHypo-theorico-philosopho-bilanguo-gamo-reflexion : Blue \nSpecial thanks : Family stuff and Blue \n \n \n \n");
	
}