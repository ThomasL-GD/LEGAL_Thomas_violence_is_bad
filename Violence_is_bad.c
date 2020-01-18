#include <stdio.h>

int main(){
	
	int nPlayerLife = 100;
	int nAdvLife = 100;
	int nPlayerMP = 5;
	int nAdvMP = 5;
	// The -1 in poison variables means that they were never poisonned before.
	int nPlayerPoison = -1;
	int nAdvPoison = -1;
	int nChoice = 0;
	
	while (nPlayerLife > 0 && nAdvLife > 0){
	
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
				
				
				// For MP and Poison, if we would have learnt the random numbers, I would have created a small percentage of chances to fail to analyse the enemy and give a wrong information to the player.
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
		
	}
	
}