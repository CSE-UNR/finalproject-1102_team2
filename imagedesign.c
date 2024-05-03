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
<<<<<<< HEAD

	GetImage(imagefp, MAXROW, MAXCOL, imsize); 
	DisplayImage(MAXROW, MAXCOL, imsize);
=======
	int rowindex;
	int colindex;
	GetImage(imagefp, MAXROW, MAXCOL, imsize, &rowindex, &colindex); 
	DisplayImage(rowindex, colindex, imsize);
>>>>>>> 33fa4f9cb4e11ded3722060e1b62c40589177935
	
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

<<<<<<< HEAD
void DisplayImage(int row, int col, int imsize[][col]){
  
	for(int i = 0; i < row; i++){ 
		printf("%d", imsize[i][col]);
	}
}

int EditMenu(){

}



=======
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
>>>>>>> 33fa4f9cb4e11ded3722060e1b62c40589177935


