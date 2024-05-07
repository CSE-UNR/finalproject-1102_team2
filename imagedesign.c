// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 250
#define MAXCOL 250

int Menu();
int EditMenu();
int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI, int *pixelI);
void DisplayImage(int row, int col, char imsize[][col], int pixel);
void dim(int rowindex, int colindex,char imsize[][MAXCOL], int everypix);
void brighten(int rowindex, int colindex,char imsize[][MAXCOL], int everypix);
void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int colbegin, int rowbegin);
int savefile(char imsize[][MAXCOL], int row, int everypix);

int main (){  

	char imsize[MAXROW][MAXCOL], 	newimsize[MAXROW][MAXCOL]; 
	FILE *imagefp; 
	int rowindex, colindex, newC, newR, Cend, Cbegin, Rend, Rbegin;
	char userchoice, userchoice2;
	char file[100];
	int pixel;
	
	do{
		userchoice = Menu();
		
		switch(userchoice){
			case 1:
				GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex, &pixel); 
				break;
			case 2:
				DisplayImage(rowindex, colindex, imsize, pixel);
			//	printf("%d", rowindex);
				break;
			case 3:
				userchoice2 = EditMenu();
				switch(userchoice2){
					case 1:
						DisplayImage(rowindex, colindex, imsize, pixel);
						crop(rowindex, colindex, imsize, Cend, Rend, Cbegin, Rbegin );
						//newC = &Cend - &Cbegin;	
						//newR = &Rend - &Rbegin;
						
						
						break;
					case 2:
						dim(rowindex, colindex, imsize, pixel); 
						savefile(imsize, rowindex, pixel);
						break;
					case 3:
						brighten(rowindex, colindex,imsize, pixel); 
						savefile(imsize, rowindex, pixel);
						break;
				}	
				break;
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

int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI, int *pixelI){ 
	 
	char filename [20]; 
	int pixel = 0, row = 0, col = 0;
	printf("What is the name of the image file: ");
	scanf("%s", filename);
	imagefp = fopen (filename, "r"); 
	printf("\n");
	if (imagefp == NULL){ 
		printf("Can not load image\n"); 
		return 0;	
	}
	else{ 
	 
		while (fscanf(imagefp, "%c", &imsize[row][pixel]) == 1){
			if(imsize[row][pixel] == '\n'){
				row++; 	
				
			}else{ 
				pixel++; 
			}
			if(row < 1){
				col++; 	
			} 
		} 
		*colI = col;
		*rowI = row;
		*pixelI = pixel;			
		printf("Image successfully loaded!\n\n"); 
		fclose(imagefp);
	}  
	
}
 


int EditMenu(){
	int choice2;

	printf("**EDITING**\n");
	printf("1: Crop\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	
	printf("\nChoose from one of the options above:");
	scanf("%d", &choice2);
	
	return choice2;
	
}

void DisplayImage(int rowindex, int colindex, char imsize[][MAXCOL], int everypix){

	
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < everypix;col++){  
			
			if(imsize [row][col] == '0'){
				printf(" "); 
				} 
			else if (imsize [row][col] == '1'){
				printf("."); 
				} 
			else if (imsize [row][col] == '2'){
				printf("o"); 
				} 
			else if (imsize [row][col] == '3'){
				printf("O"); 
				} 
			else if (imsize [row][col] == '4'){
				printf("0"); 
				} 
			else if (imsize[row][col] == '\n'){ 
			printf("\n"); 
			}
		
		}
	} 
	printf("\n\n");
}

void brighten(int rowindex, int colindex,char imsize[][MAXCOL], int everypix){ 
//printf("%d,%d", rowindex, colindex);
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < everypix;col++){
			if(imsize [row][col] == '0'){
				printf("."); 
				} 
			else if (imsize [row][col] == '1'){
				printf("o"); 
				} 
			else if (imsize [row][col] == '2'){
				printf("O"); 
				} 
			else if (imsize [row][col] == '3'){
				printf("0"); 
				} 
			else if (imsize [row][col] == '4'){
				printf("0"); 
				} 
			else if (imsize[row][col] == '\n'){ 
			printf("\n"); 
			} 
			}
				}printf("\n");		
	} 
void dim(int rowindex, int colindex,char imsize[][MAXCOL], int everypix){ 
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < everypix;col++){
			if(imsize [row][col] == '0'){
				printf(" "); 
				} 
			else if (imsize [row][col] == '1'){
				printf(" "); 
				} 
			else if (imsize [row][col] == '2'){
				printf("."); 
				} 
			else if (imsize [row][col] == '3'){
				printf("o"); 
				} 
			else if (imsize [row][col] == '4'){
				printf("O"); 
				} 
			else if (imsize[row][col] == '\n'){ 
			printf("\n");  
				}
			}
		} printf("\n");
	} 


void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int colbegin, int rowbegin){


	printf("The image you want to crop is %d x %d.\n", rowindex, colindex);
	printf("The row and column values start in the upper lefthand corner\n");
	printf("Which column do you want to be the new left side?");
	scanf("%d", &colbegin);
	printf("Which column do you want to be the new right side?");
	scanf("%d",&colend);
	printf("Which row do you want to be the new top?");
	scanf("%d",&rowbegin);
	printf("Which row do you want to be the new bottom?");
	scanf("%d",&rowend);
	 
	int pixels;
	pixels = (colend - colbegin)*(rowend - rowbegin);
	for(rowbegin; rowbegin < rowend; rowbegin++){ 
		for(colbegin;colbegin < pixels ;colbegin++){
		 
			if(imsize [rowbegin][colbegin] == '0'){
				printf(" "); 
				} 
			else if (imsize [rowbegin][colbegin] == '1'){
				printf("."); 
				} 
			else if (imsize [rowbegin][colbegin] == '2'){
				printf("o"); 
				} 
			else if (imsize [rowbegin][colbegin] == '3'){
				printf("O"); 
				} 
			else if (imsize [rowbegin][colbegin] == '4'){
				printf("0"); 
				} 
			else if (imsize[rowbegin][colbegin] == '\n'){ 
			printf("\n"); 
			}
		}
	} 
} 
int savefile(char imsize[][MAXCOL], int rowI, int everypix){ 
	FILE *newimfp;
	char filename[100];
	char choice;
	int col = 0;
	printf("would you like to save the file (y/n)"); 
	scanf(" %c", &choice); 
	if(choice == 'n'){ 
		return 0; 
	} 
	else if(choice == 'y'){ 
		printf("What do you want to name the image file? (include the extension)"); 
		scanf("%s", filename); 
		newimfp = fopen(filename, "w");
		if (newimfp == NULL){ 
		printf("Can not load image\n"); 
		return 0;	
	}
		else{ 
			for(int row = 0; row < rowI ; row++){ 
				for(int col = 0; col < everypix;col++){
				fprintf(newimfp, "%d", imsize[row][everypix]);	
				
				}
			fprintf(newimfp,"\n");
			}	
		}
	printf("Image successfully loaded!\n\n");
	fclose(newimfp);
	} 
	
}






