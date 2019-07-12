#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void displayRules(); /*prototype*/
bool wincondtion(int secretletters, int lifes), correctAnswer(int count, int repeatingletters), correctformat(char* letter);  /*prototype*/
int repeatingcondition(int lifes, int repeatingletters), lenghtstring(char word[20]); /*prototype*/
char abecedario[60] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	char lista[49][30] = {{"awkward"},{"bagpipes"},{"banjo"},{"bungler"},{"croquet"},{"crypt"},{"dwarves"},{"fervid"},{"fishhook"},{"fjord"},{"gazebo"},{"gypsy"},{"haiku"},{"haphazard"},{"hyphen"},{"ivory"},{"jazzy"},{"jiffy"},{"jinx"},{"jukebox"},{"kayak"},{"kiosk"},{"klutz"},{"memento"},{"mystify"},{"numbskull"},{"ostracize"},{"oxygen"},{"pajama"},{"phlegm"},{"pixel"},{"polka"},{"quad"},{"quip"},{"rhythmic"},{"rogue"},{"sphinx"},{"squawk"},{"swivel"},{"toady"},{"twelfth"},{"unzip"},{"waxy"},{"wildebeest"},{"yacht"},{"zealous"},{"zigzag"},{"zippy"},{"zombie"}};
	int x, large, secretletters = 0, i, lifes = 5;
	char word[30], letter[100], repeatedletters[60];
	bool win = false, condition, wronganswer, guessCondition; 
	
	displayRules();
	
	srand(time(NULL));
	x = rand() % 50;
	//making the word which will be guest by the user through index
   for (i = 0; lista[x][i] != '\0'; i++)
		
      word[i] = lista[x][i];
      
	large = lenghtstring(word);
	char secretword[large];
	
	for (i=0;i<large;i++)
		if (word[i] == ' '){ //esto es para varias palabras juntas
			secretword[i] = ' ';
		}
		else{
			secretword[i] = '*';
			secretletters++; //important variable in future
		}
	
	printf("%s \n", secretword);
	
	while (win == false){
		int repeatingletters = 0;
		printf("Life counter: %i \n", lifes);	
		printf("input a letter prro: ");
		
		/*asking for the letter, we use gets because it is a string*/
		gets(letter);
		
		/*calling the function to check if the letter was input in the correct format*/
		condition = correctformat(letter);
		
		/*verifying the format*/
		if(condition == false){
			printf("\nsomething is wrong in your format, try it again \n");
			lifes--;
		}
		else{
			int count = 0;
			//once we have verified the format, we check if there is a match between the letter input and every letter in the word we have to guess
			for (i=0;i<large;i++){
				//condition to check the match
				if(letter[0]==word[i]){
					secretword[i] = letter[0];
					if (secretword[i] == repeatedletters[i]){
					//condition that will tell us if the input letter match with one of the words that the user has input
					repeatingletters++;
					}
					else{
						//this is to make a string calling repeated letters that help us to know in the statement before, if a letter is repeated
						repeatedletters[i] = secretword[i];
						count++;
					}
					
				}
					
		}
		
		
		guessCondition = correctAnswer(count, repeatingletters);
		
		//condition to check if the user input a correct answer and if it is correct or not, make a rest or a sum
		guessCondition = correctAnswer(count, repeatingletters);
		if (guessCondition == true){
			//secretletters is the counter to check if we have guest all the letters
			printf("\ngreat! you have guest a letter \n");
			secretletters -= count;
		}
		else{
			//once we know the answer is incorrect, we check if it is because is a repeated letter or the user only failed
			lifes = repeatingcondition(lifes, repeatingletters);

		}
			
		}
		//cleaning the terminal
		printf("\n\n\nPush a bottom to continue \n");
		getch();
		system("cls");
		printf("%s \n", secretword);
		printf("----------------------------------------------------------------------------------------\n");		

		//function to verify if the game has finished
		
		win = wincondition(secretletters, lifes);
		
	}

		

	return 0;
}
//function to display the rules
void displayRules(){

	printf("¡¡Welcome to the hangman_game!! \n");
	printf("These are the rules for the game: \n");
	printf("1. The purpose of this game is to enter a letter, trying to match with a letter of the secretword \n");
	printf("2. You win until you have matched all the letter of the secretword \n");
	printf("3. You lost if you lose your lifes \n");
	printf("4. You have 5 lifes, and you lose one life if you don't match the letter \n");
	printf("5. If you have matched a letter and you repeat this letter, you will lose a life \n");
	printf("6. You cannot enter nothing unless it is in the alphabet \n");
	printf("7. The word does not have capital letter, if you input one, you will lose a life \n");
	printf("8. Input only one letter, if you input more than one, you will lose a life \n \n");
	
	printf("Enojoy the game! \nPress any key to continue");
	
	getch();
	
	system("cls");
	
}


/*function to get the large of the word*/
int lenghtstring(char word[20])
{
	int letters=0;
	while (word[letters]!='\0') letters++;
	return letters;
}

/* function to verify if it is the correct format*/
bool correctformat(char* letter){
	/*strlen is used to get the len of the string*/
	int i, counter = 0, a = strlen(letter);
	/*condition to verify if it is only one letter*/
	if (a != 1){
		return false;
	}
	else{
		/*condition to verify if it is in the abecedario*/
		for (i=0;i<=52;i++){
			if(letter[0] == abecedario[i]){
				//we use a counter, because if the letter is in the abecedario, the counter will detect it.
				counter++;
			}
		}
		//This counter will tell us if the letter of the user was in the abecedario
		if (counter > 0){
			return true;
		}
		else{
			return false;
		}
	}
	
	
}
//function to verify if the answer is correct
bool correctAnswer(int count, int repeatingletters){
	
	if ((count>0) && (repeatingletters == 0)){
		return true;
		
	}		
	//secretletters is the counter to check if we have guest all the letters
		
}

//function to verify if the user is repeating letters
repeatingcondition(int lifes, int repeatingletters){
	if (repeatingletters==0){
	
		printf("\nwrong! try it again \n");
		//life is to check if we have lost or not
		return lifes - 1;
	}
	else{
		printf("\nyou are repeating letters \n");
		return lifes - 1;
	
	}
}

//function to verify if the user has won
wincondition(int secretletters, int lifes){
	//condtion to check if the user has won
		if (secretletters == 0){
			printf("congratulations! you have won");
			return true;
			
		}
		else{
			//condition to check if the user has lost the game
			if(lifes == 0){
				printf("Sorry, you have lost. Try it later");
				return true;
			}
			//condition to check if the game has not finished
			else{
				return false;
			}
		}
}

