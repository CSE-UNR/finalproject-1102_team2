// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 500 
#define MAXCOL 500

int Menu();
int EditMenu();
void GetImage(FILE *imagefp, int maxrow, int colm, int imsize[][colm]);
void DisplayImage(int row, int col, int imsize[][col]
);
int main (){  

	int imsize[MAXROW][MAXCOL]; 
	FILE *imagefp = NULL; 

	GetImage(imagefp, MAXROW, MAXCOL, imsize); 
	DisplayImage(MAXROW, MAXCOL, imsize);
	
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
	 
	char filename [20]; 
	
	printf("Enter file name: ");
	scanf("%s", filename);
	imagefp = fopen (filename, "r"); 
	
	if (imagefp == NULL){ 
		printf("Can not load image\n"); 	
	}
	else{ 
		int row = 0, col = 0; 
		while (fscanf(imagefp, "%d", &imsize[row][col]) == 1){
		col++; 
		row++;
			
		}
		printf("Image successfully loaded!\n"); 
		fclose(imagefp);
	} 
	
} 

void DisplayImage(int row, int col, int imsize[][col]){
  
	for(int i = 0; i < row; i++){ 
		printf("%d", imsize[i][col]);
	}
}

int EditMenu(){

}





