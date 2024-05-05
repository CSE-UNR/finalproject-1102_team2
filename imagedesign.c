// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 100
#define MAXCOL 100

int Menu();
int EditMenu();
int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI);
void DisplayImage(int row, int col, char imsize[][col]);
int main (){  

	char imsize[MAXROW][MAXCOL]; 
	FILE *imagefp; 
	int rowindex;
	int colindex;
	char userchoice, userchoice2;
	
	
	do{
		userchoice = Menu();
		
		switch(userchoice){
			case 1:
				GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex); 
				break;
			case 2:
				DisplayImage(rowindex, colindex, imsize);
				break;
			case 3:
				userchoice2 = EditMenu();
				switch(userchoice2){
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 0:
						break;
				}
			case 0:
			printf("Goodbye!\n");
		}
	
	
	
	
	}while(userchoice != 0);
	
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

int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI){ 
	 
	char filename [20]; 
	
	int row = 0;
	int col = 0;
	printf("What is the name of the image file: ");
	scanf("%s", filename);
	imagefp = fopen (filename, "r"); 
	printf("\n");
	if (imagefp == NULL){ 
		printf("Can not load image\n"); 
		return 0;	
	}
	else{ 
	 
		while (fscanf(imagefp, "%c", &imsize[row][col]) == 1){
			if(imsize[row][col] == '\n'){
				row++; 
				
			}
			else{
				col++; 
				
			} 
		} 
		*colI = col;
		*rowI = row;
		//while (fscanf(imagefp, "%c", &imsize[MAXROW][col]) == 1){
		//col++;
		//*colI = col;
		//}
	
			//for (int row = 0; row < MAXROW; row++){ 
			//	for(int col = 0; col < MAXCOL; col++){ 
			//	fscanf(imagefp, "%d", &imsize[row][col]); 
			//	} 
			//}
		 
		 
		
		printf("Image successfully loaded!\n\n"); 
		fclose(imagefp);
	} 
}
 


int EditMenu(){
	int choice;

	printf("**EDITING**\n");
	printf("1: Crop\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	
	printf("\nChoose from one of the options above:");
	scanf("%d", &choice);
	
}

void DisplayImage(int rowindex, int colindex, char imsize[][MAXCOL]){
	
	
	
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex;col++){
		printf("%c", imsize[row][col]);
		}
	} 
	printf("\n");
}

void brighten(int rowindex, int colindex,int imsize[][MAXCOL]){ 
	for(int row = 0; row < rowindex;row++){ 
		for(int col = 0; col < colindex;col++){
			if (imsize[row][col] != 4){
				imsize[row][col] + 1; 
				}
			}
		}
	} 
void dim(int rowindex, int colindex,int imsize[][MAXCOL]){ 
	for(int row = 0; row < rowindex;row++){ 
		for(int col = 0; col < colindex;col++){
			if (imsize[row][col] != 0){
				imsize[row][col] - 1; 
				}
			}
		}
	} 



