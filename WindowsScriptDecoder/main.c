#include <stdio.h>
#define TABLE_SIZE 97

struct TableEntry
{
	char plainText;
	char ciphers[3];
} lookUpTable[TABLE_SIZE] = {
	{'a', {'#','x','p'}}, 
	{'b', {'A',')','i'}}, 
	{'c', {'4','(','.'}}, 
	{'d', {'\t','s','L'}}, 
	{'e', {'*','Y','!'}},
	{'f', {'D','3','$'}}, 
	{'g', {'?','g','N'}}, 
	{'h', {'w','m','P'}}, 
	{'i', {';','U','\t'}}, 
	{'j', {'U','S','V'}},
	{'k', {'i','|','s'}},
	{'l', {'a',':','5'}},
	{'m', {'c','_','a'}},
	{'n', {'P','e','K'}},
	{'o', {'g','F','X'}},
	{'p', {'Q','X',';'}},
	{'q', {'I','1','W'}},
	{'r', {'O','i','"'}},
	{'s', {'F','l','m'}},
	{'t', {'h','Z','M'}},
	{'u', {'|','H','%'}},
	{'v', {'6','\'','('}},
	{'w', {'p','\\','F'}},
	{'x', {'n','=','J'}},
	{'y', {'z','$','2'}},
	{'z', {'/','y','A'}},
	{'A', {'B','w','E'}},
	{'B', {'\'','J',','}},
	{'C', {'H','a','*'}},
	{'D', {'r',']','t'}},
	{'E', {'u','\"','\''}},
	{'F', {'1','K','7'}},
	{'G', {'7','o','D'}},
	{'H', {'M','N','y'}},
	{'I', {'R',';','Y'}},
	{'J', {'"','L','/'}},
	{'K', {'T','P','o'}},
	{'L', {'j','g','&'}},
	{'M', {'G','*','r'}},
	{'N', {'d','}','j'}},
	{'O', {'-','t','9'}},
	{'P', {' ','T','{'}},
	{'Q', {'Q','+','?'}},
	{'R', {'.','-','8'}},
	{'S', {'L',',','w'}},
	{'T', {']','0','g'}},
	{'U', {'~','n','S'}},
	{'V', {'l','k','G'}},
	{'W', {'o','f','4'}},
	{'X', {'y','5','x'}},
	{'Y', {'t','%',']'}},
	{'Z', {'C','!','0'}},
	{'1', {'N','9','c'}},
	{'2', {'E','p','3'}},
	{'3', {'k','E','+'}},
	{'4', {'b','h','h'}},
	{'5', {'Y','q','Q'}},
	{'6', {'x','O','f'}},
	{'7', {'^','\t','v'}},
	{'8', {'}','b','1'}},
	{'9', {'J','D','d'}},
	{'0', {'f','8','k'}},
	{'`', {'(','{','U'}},
	{'~', {',',' ','B'}},
	{'!', {'0','G','u'}},
	{'@', {'@','@','@'}},
	{'#', {')','V','`'}},
	{'$', {'[','B','q'}},
	{'%', {'8','j','^'}},
	{'^', {'$','c','l'}},
	{'&', {'3','/','I'}},
	{'*', {'5','4',')'}},
	{'(', {'X','I','b'}},
	{')', {':','A','}'}},
	{'_', {'+','?','H'}},
	{'-', {'\\','v','|'}},
	{'+', {'e','2','6'}},
	{'=', {'`','~',':'}},
	{',', {'9','[',' '}},
	{'.', {'V','r','z'}},
	{'/', {'s','C','/'}},
	{'<', {'<','<','<'}},
	{'>', {'>','>','>'}},
	{'?', {'S','^','~'}},
	{';', {'q','u','C'}},
	{'\'', {'=','&','\\'}},
	{':', {'m','#','T'}},
	{'\"', {'!','z','R'}},
	{'[', {'&','d','#'}},
	{']', {'%','R','['}},
	{'\\', {'v','M','Z'}},
	{'{', {'_','7','='}},
	{'}', {'Z','Q','O'}},
	{'|', {'K','`','_'}},
	{' ', {'2','.','-'}},
	{'\n', {'\n','\n','\n'}},
	{'\t', {'{','W','n'}}
};

int state;

char inputFilePath[256];
char outputFilePath[256];

int lookUp(int ch)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if ((int)(lookUpTable[i].ciphers[state]) == ch)
		{
			state = (state + 1) % 3;
			return (int)(lookUpTable[i].plainText);
		}
	}
	printf("Invalid character presented!\n");
	exit(1);
}

void decode(FILE* inputFile, FILE* outputFile)
{
	int inputChar = 0;
	while (~(inputChar = fgetc(inputFile)))
		fputc(lookUp(inputChar), outputFile);
}

int main()
{
	printf("Input the location of the script file: ");
	scanf("%s", inputFilePath);
	FILE* inputFile = fopen(inputFilePath, "r");
	printf("Input the location of the decoded script file: ");
	scanf("%s", outputFilePath);
	FILE* outputFile = fopen(outputFilePath, "w");

	if (!inputFile || !outputFile)
	{
		printf("Cannot open file!\n");
		exit(1);
	}

	decode(inputFile, outputFile);

	fclose(inputFile);
	fclose(outputFile);

	return 0;
}