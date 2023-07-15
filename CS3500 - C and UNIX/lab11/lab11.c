#include <errno.h>
#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stockName
{
    char acronym[80];
    char name[80];
} stockName;

void find(char *name) {

    ENTRY item;
    ENTRY *found_item;

    item.key = name;
    found_item = hsearch(item, FIND);
    if (found_item != NULL)
	printf(" %s\n", (char *)found_item->data);
    else
	printf("Key was not found\n");
}


int main(int argc, char *argv[]) {

    FILE *fp;
    
    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
	printf("File did not open correctly.\n");
	return 1;
    }
    int i = 0;
    int lineCount = 0;
    char lineGet[100];
    
    while (fgetc(fp) != EOF) {
    	fseek(fp, -1l, SEEK_CUR);
    	fgets(lineGet, 100, fp);
    	lineCount++;
    }
    rewind(fp);
    
    stockName stockNames[lineCount];
    while (i < lineCount) {  

   	char buf[100];
	char AcroTemp[10];
	fgets(buf, 100, fp);
	
	char *Name = (char *) malloc(sizeof(char)*80);
	char *Acro = (char *) malloc(sizeof(char)*10);
	//sscanf(buf, "%s %s", Acro, Name);
	
	int j = 0;
	char *token = strtok(buf, ",");
	//printf("%s\n", token);
	strcpy(Acro, token);
	token = strtok(NULL, ",");
        strcpy(Name, token);
    	strcpy(stockNames[i].acronym, Acro);
    	strcpy(stockNames[i].name, Name);
    	i++;
        free(Name);
        free(Acro);
    }
    fclose(fp);
    ENTRY item;
    ENTRY *found_item;
    
    int count = lineCount;
    
    if (hcreate(count) == 0) {
	printf("Error on hcreate, %s\n", strerror(errno));
	exit(1);
    }
    
    for (i = 0; i < count; i++) {
	item.key = (void*)stockNames[i].acronym;
	item.data = (void*)stockNames[i].name;
        hsearch(item, ENTER);
    }
    if (hsearch(item, ENTER) == NULL) {
	printf("Error on hsearch, %s\n", strerror(errno));
	exit(1);
    }

    char stockAcro[10];
    printf("Input a stock symbol: ");
    gets(stockAcro);
    while(strcmp(stockAcro, "QUIT")) {
        find(stockAcro);
	printf("Input a stock symbol: ");
        gets(stockAcro);
    }

    return 0;
}
