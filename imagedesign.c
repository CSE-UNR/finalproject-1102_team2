// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 250
#define MAXCOL 250

int Menu();
int EditMenu();
int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI, int *pixelI);
void DisplayImage(int rowindex, int colindex, char imsize[][MAXCOL], int pixel);
void dim(int rowindex, int colindex,char imsize[][MAXCOL], int everypix);
void brighten(int rowindex, int colindex,char imsize[][MAXCOL], int everypix);
void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int *colbegin, int *rowbegin);
int savefile(char imsize[][MAXCOL], int row, int colindex);

int main (){  

	char imsize[MAXROW][MAXCOL], 	newimsize[MAXROW][MAXCOL], userchoice, userchoice2, file[100]; 
	FILE *imagefp; 
	int rowindex, colindex, Cend, Cbegin, Rend, Rbegin, pixel; 
	
	do{
		userchoice = Menu();
		switch(userchoice){
			case 1:
				GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex, &pixel); 
				break;
			case 2:
				DisplayImage(rowindex, colindex, imsize, pixel);
				break;
			case 3:
				userchoice2 = EditMenu();
				switch(userchoice2){
					case 1:
						DisplayImage(rowindex, colindex, imsize, pixel);
						crop(rowindex, colindex, imsize, Cend, Rend, &Cbegin, &Rbegin);
				
						break;
					case 2:
						dim(rowindex, colindex, imsize, pixel); 
						savefile(imsize, rowindex, colindex);
						break;
					case 3:
						brighten(rowindex, colindex,imsize, pixel); 
						savefile(imsize, rowindex, colindex);
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
	int colMax = 0, row = 0, col = 0;
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
				colMax=col;
				col = 0; 		
			}else{ 
				col++; 
			}
		} 
		*colI = colMax;
		*rowI = row;
		printf("row size: %d", *rowI);
		printf("column size: %d", *colI);
					
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
		for(int col = 0; col < colindex;col++){  
			
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
			}
			printf("\n");
		
		}
	} 
void brighten(int rowindex, int colindex,char imsize[][MAXCOL], int everypix){ 

	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex;col++){
			if(imsize [row][col] == '0'){
				printf("."); 
				imsize [row][col] = '1';
				} 
			else if (imsize [row][col] == '1'){
				printf("o"); 
				imsize [row][col] = '2';
				} 
			else if (imsize [row][col] == '2'){
				printf("O");
				imsize [row][col] = '3'; 
				} 
			else if (imsize [row][col] == '3'){
				printf("0"); 
				imsize [row][col] = '4';
				} 
			else if (imsize [row][col] == '4'){
				printf("0"); 
				} 	
			}
		printf("\n");
		}			
	} 
void dim(int rowindex, int colindex,char imsize[][MAXCOL], int everypix){ 
	
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex; col++){
		
			if(imsize [row][col] == '0'){
				printf(" "); 
				} 
			else if (imsize [row][col] == '1'){
				printf(" "); 
				imsize [row][col] = '0';
				} 
			else if (imsize [row][col] == '2'){
				printf("."); 
				imsize [row][col] = '1';
				} 
			else if (imsize [row][col] == '3'){
				printf("o"); 
				imsize [row][col] = '2';
				} 
			else if (imsize [row][col] == '4'){
				printf("O"); 
				imsize [row][col] = '3';
				} 
		}
	printf("\n");	
	}
} 


void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int *colbegin, int *rowbegin){

	printf("The image you want to crop is %d x %d.\n", rowindex, colindex);
	printf("The row and column values start in the upper lefthand corner\n");
	printf("Which column do you want to be the new left side?");
	scanf("%d", colbegin);
	printf("Which column do you want to be the new right side?");
	scanf("%d",&colend);
	printf("Which row do you want to be the new top?");
	scanf("%d",rowbegin);
	printf("Which row do you want to be the new bottom?");
	scanf("%d",&rowend);
	 
	for(int row = *rowbegin; row < rowend; row++){ 
		for(int col = *colbegin;col < colend;col++){
		 
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
			}
			printf("\n"); 
		}
	printf("\n"); 
} 
int savefile(char imsize[][MAXCOL], int rowindex, int colindex){ 
	FILE *newimfp;
	char filename[100], choice;
	int col = 0;
	int row = 0;
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
				for(int row = 0; row < rowindex ; row++){ 
					for(int col = 0; col < colindex;col++){
						fprintf(newimfp, "%c", imsize[row][col]);	
				
					}
				
				fprintf(newimfp,"\n");
				}	
			} 
			
	printf("Image successfully loaded!\n\n");
	fclose(newimfp);
	} 
	
}





