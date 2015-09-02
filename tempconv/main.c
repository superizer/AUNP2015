#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double tempc(){
	printf("converted\n");
	return 0.0;
}

int main(int argc, char **argv){
	char input_unit, output_unit;
	double input_temp, output_temp;

	printf("input unit (f/c): "); scanf("%c",&input_unit);
	printf("output lunit (f/c): "); scanf("%c",&output_unit);
	printf("input temp : "); scanf("%c",&input_temp);

	printf("Convert %lf %c to %c\n", input_temp, input_unit, output_temp);

	/* tempc(); */
	return 0;
}
