// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h> 

int Menu();

int main (){ 
	



return 0;
} 

int Menu(){
	int choice;

	printf("**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	
	printf("\nChoose from one of the options above:");
	scanf("%d", &choice);
	
	return choice;
}

void GetImage(){ 
	FILE *imagefp;
	imagefp = fopen ("image.txt", "w"); 
	
	if (imagefp == NULL){ 
		printf("Can not open file\n");
	}
	else{ 
		
	
	
	}
}
