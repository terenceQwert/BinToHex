#include <stdio.h>

int main(void){
	FILE *fptr, *fptw;
	int counter = 0;
	int c1;

	fptr = fopen (".\\Font\\glyphs.bin","rb");
	fptw = fopen (".\\Font\\glyphs.txt","w");

	while(1){
		c1 = fgetc(fptr);

		if(c1 == EOF){
			break;
		}

		fprintf(fptw, "0x%02X, ", c1);

		counter ++;
		if(counter == 16){
			fprintf(fptw, "\n");
			counter = 0;
		}
	}
	
	fclose(fptr);
	fclose(fptw);
	return 0;
}