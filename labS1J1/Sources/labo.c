#include <stdio.h>
#include "labo.h"


		//help me god :(
		//it feels like hell
		//I don't even know what I'm writing down
		//Should probably put a picture of a coconut
		//If it worked with TF2, it should work with my code
		//Save me Emotional Support Nuggets!
		//I will now go to sleep
		//ZZZzzz...
		//Never mind
		//Can't sleep in a bunch of grabage code
		//This is not a joke
		//This is a cry for help
		//No esta Taco
		//Ooh a penny
		//You know what they say:
		//A penny a day keps the doct...
		//Wait, that's the wrong one
		//I forgor
		//Go Charmander!
		//Fix my code!
		//(Charmander noises)
		//(It was not very effective)
		//There's no more hope left
		//We are all doomed
		//I just want to pop the bubble algorithm
		//Like a buble wrap
		//With a big hammer
		//Bang! Bang! Bang!
		//Who's the king now!?
		//ME!
		//There's nothing you bubbles can do against me!
		//(Except this code)
		//Do bubble warps taste something?
		//Probably plastic
		//Let's ask the crowd
		//Do you guys think that bubble wraps taste like plastic?
		//(Crowd screaming yes)
		//You heard the voices folks!
		//They are in your head
		//This is making me crazy
		//Crazy?
		//I was crazy once
		//They locked me in a room
		//A rubber room
		//A rubber room with rats
		//Rats made me crazy
		//Crazy?
		//I was crazy once
		//They locked me in a room
		//A rubber room
		//A rubber room with rats
		//Rats made me crazy
		//Crazy?
		//Ok, I'm not doing it a third time
		//Unless you guys want me too
		//The crowd is gone...
		//I'm alone once again
		//Alone with this code
		//I need a hero
		//I'm holding out for a hero 'til the end of the night
		//He's gotta be strong, and he's gotta be fast
		//And he's gotta be fresh from the fight


		//I don't know who's that ^ guy but I bet he dosen't know how to correctly read instructions!

/*
* Faire une fonction qui retourne un sous-tableau de character de celui passer.
*/


char* sousTexte(char* texte, int from, int to) {

	static char mot[1025];
	for (int i = from; i < (to); i++) {

		mot[i-from] = texte[i];
	}
		return mot;
}

/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {

	for (int i = 0; i < 256; i++) {

		s->characters[i] = text[i];
		if (s->characters[i] == NULL) {

			s->length = i-1;
			
			return s->characters;

		}
	}

}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {

	static char back[256];
	int x = s->length;
	for (int i = 0; i < s->length; i++) {

		back[i] = s->characters[i];
		if (back[i] == s->characters[x]) {
			
			x--;

		}
		else{
		
			return 0;
		
		}

	}
	return 1;

	// Voir avec le prof ( lignecount impossible, Verifier bon chemin)
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {

	int count = 0;
	for (int i = 0; i < 256; i++) {

		if (elements[i] == NULL) {

			count = i;
			break;
		}
	}

	for (int i = 0; i < count-1; i++) {

		if (elements[i] > elements[i + 1]) {

			n = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = n;
			i = -1;
		}
	}
	return elements;
}