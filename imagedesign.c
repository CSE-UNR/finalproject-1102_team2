// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h> 

int Menu();
void GetImage();

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

void GetImage(FILE *imagefp, int maxrow, int colm, int imsize[][colm]){ 
	 
	int filename [20]; 
	
	printf("Enter file name");
	scanf(" %s ", filename);
	imagefp = fopen (filename, "r"); 
	
	if (imagefp == NULL){ 
		printf("Can not load image\n");
	}
	else{ 
	int inx = 0; 
	while (fscanf(filename, "%d", &imsize[inx][
		printf("Image successfully loaded!\n"); 
	} 
	
}
