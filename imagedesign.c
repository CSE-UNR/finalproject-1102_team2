// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 100
#define MAXCOL 100

int Menu();
int EditMenu();
int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI);
void DisplayImage(int row, int col, char imsize[][col]);
void dim(int rowindex, int colindex,char imsize[][MAXCOL]);
void brighten(int rowindex, int colindex,char imsize[][MAXCOL]);
void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int colbegin, int rowbegin);
void savefile(int rowindex, int colindex, char imsize[][MAXCOL], char newimage[][MAXCOL]);

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
				GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex); 
				break;
			case 2:
				DisplayImage(rowindex, colindex, imsize);
				printf("%d", rowindex);
				break;
			case 3:
				userchoice2 = EditMenu();
				switch(userchoice2){
					case 1:
						crop(rowindex, colindex, imsize, Cend, Rend, Cbegin, Rbegin );
						//newC = &Cend - &Cbegin;	
						//newR = &Rend - &Rbegin;
						printf("%d\n", newR);
						
						break;
					case 2:
						dim(rowindex, colindex, imsize);
						break;
					case 3:
						brighten(rowindex, colindex,imsize);
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

int GetImage(FILE *imagefp, int maxrow, int colm, char imsize[][colm], int *rowI, int *colI){ 
	 
	char filename [20]; 
	int pixel = 0;
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
			else if (row < 1){
				col++; 	
			} 
			else{ 
			pixel++; 
			}
		} 
		*colI = col;
		*rowI = row;				
		printf("Image successfully loaded!\n\n"); 
		fclose(imagefp);
	}  
	return pixel;
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

void DisplayImage(int rowindex, int colindex, char imsize[][MAXCOL]){
	
	
	
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
			else if (imsize[row][col] == '\n'){ 
			printf("\n"); 
			}
		
		}
	} 
	printf("\n\n");
}

void brighten(int rowindex, int colindex,char imsize[][MAXCOL]){ 
printf("%d,%d", rowindex, colindex);
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex;col++){ 
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
				}		
	} 
void dim(int rowindex, int colindex,char imsize[][MAXCOL]){ 
	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex;col++){ 
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
		}
	} 


void crop(int rowindex, int colindex, char imsize[][MAXCOL], int colend, int rowend, int colbegin, int rowbegin){


	for(int row = 0; row < rowindex ; row++){ 
		for(int col = 0; col < colindex ;col++){ 
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
	
	for(rowbegin; rowbegin < rowend; rowbegin++){ 
		for(colbegin;colbegin < colend;colbegin++){ 
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
void savefile(int rowindex, int colindex, char imsize[][MAXCOL], char newimage[][MAXCOL]){


}






