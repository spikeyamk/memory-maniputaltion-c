#include "foo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT_WING 	0
#define RIGHT_WING	1	
#define LOGIC_LOW	0
#define LOGIC_HIGH	1

void PrintArgs(int argc, char* argv[]){
	printf("argc: %d\n", argc);

	for(int i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
}

void DecBinHexPrint(int input){
	char* output;

	printf("DEC: %d\n", input);

	output = DecToBin(input);
	printf("BIN: %s\n", output);
	free(output);

	printf("HEX: %X\n", input);
}

void StrRev(char* input){
	int start_index = 0;
	int end_index = strlen(input) - 1;
	
	for(char buffer; start_index < end_index; start_index++, end_index--){ 
		buffer = input[start_index];
		input[start_index] = input[end_index]; 
		input[end_index] = buffer;
	}
}

char* DecToBin(int input){
	char *bin_number;
	int i;
	int check = input;
	
	for(i = 0; check > 0; i++){
		check = check / 2;
	}

	bin_number = malloc(i*sizeof(char));

	for(i = 0; input > 0; i++){
		if(input % 2){
			bin_number[i] = '1';	
		}
		else{
			bin_number[i] = '0';
		}
		input = input / 2;
	}

	bin_number[i] = '\0';
	StrRev(bin_number);
	return bin_number;
}

int IntBitSet(int* input, int bit_pos, int logic_value){
	int number = *input;

	if(logic_value == 1){
		number = number | (1 << bit_pos);
	}
	else if(logic_value == 0){
		number = number & (~(1 << bit_pos));
	}
	else{
		return 1;
	}

	*input = number;
	return 0;
}

int IntRangeBitSet(int* input, int start_pos, int end_pos, int logic_value){
	int number = *input;
	int key = 0;	
	
	for(int i = end_pos; i >= start_pos; i--){
		key += 1 << i;
	}	

	if(logic_value == 1){
		number = number | key;
	}
	else if(logic_value == 0){
		number = number & (~key);
	}
	else{
		return 1;
	}

	*input = number;
	return 0;
}

void foomain(int argc, char* argv[]) {
	int number = atoi(argv[1]);
	int end_pos = (8*sizeof(int)) - 2;

	PrintArgs(argc, argv);

	DecBinHexPrint(number);

	IntRangeBitSet(&number, 8, end_pos, LOGIC_HIGH);
	DecBinHexPrint(number);

	IntBitSet(&number, 3, LOGIC_HIGH);
	DecBinHexPrint(number);
	IntBitSet(&number, 6, LOGIC_LOW);
	DecBinHexPrint(number);
}
















































