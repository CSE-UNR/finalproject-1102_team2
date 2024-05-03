// Tyler Johnson
// Ayla Velasquez 

#include <stdio.h>
#define MAXROW 500 
#define MAXCOL 500

int Menu();
void GetImage(FILE *imagefp, int maxrow, int colm, int imsize[][colm], int *rowI, int *colI);
void DisplayImage(int rowindex, int col,int imsize[][col]
);
int main (){  

	int imsize[MAXROW][MAXCOL]; 
	FILE *imagefp = NULL; 
	int rowindex;
	int colindex;
	GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex); 
	DisplayImage(rowindex, colindex, imsize);
	
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

void GetImage(FILE *imagefp, int maxrow, int colm, int imsize[][colm],int *rowI, int *colI){ 
	 
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
		*rowI = row;
		*colI = col;
		printf("Image successfully loaded!\n"); 
		fclose(imagefp);
	} 
	
} 

void DisplayImage(int rowindex, int colindex, int imsize[][MAXCOL]){
	
	
	for(int row = 0; row < rowindex; row++){ 
		for(int col = 0; col < colindex;col++){
		char pixel;
		switch (imsize[row][col]){ 
			case 0: 
				pixel = ' '; 
				break; 
			case 1: 
				pixel = '.';
				break;  
			case 2: 
				pixel = 'o'; 
				break; 
			case 3: 
				pixel =  'O'; 
				break; 
			case 4: 
				pixel = '0'; 
				break; 
			} 
			printf("%c", pixel);
			
		printf("%d\n", imsize[row][col]);
	}
	} 
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



