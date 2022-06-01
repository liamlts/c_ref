#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEMS 5

struct stk{
	char symbol[5];
	int quantity;
	float price;
	struct stk *next;
};

struct stk *make_structure(void);
void fill_structure(struct stk *a, int c);
void show_structure(struct stk *a);
void save_structure(struct stk *a);
struct stk *read_structure();

int main(void)
{
	struct stk *first;
	struct stk *current;
	int x;
	FILE *stks = fopen("stocks.db", "r");

	for(x=0;x<ITEMS;x++){
		if(x == 0)
		{
			rewind(stks);
			//fseek(stks,sizeof(struct stk) * 1, SEEK_SET);
			fread(first, sizeof(struct stk), 1, stks);
			first->next = (struct stk *)malloc(sizeof(struct stk) * 1);
			show_structure(first);
			current = first;
		}
		else
		{
			fseek(stks,sizeof(struct stk)*(x), SEEK_SET);
			fread(current, sizeof(struct stk), 1, stks);
			current->next=(struct stk *)malloc(sizeof(struct stk) *1);
			//current = current->next;
		}
		current = current->next;
	}
	current->next = NULL;
	puts("Investment portfilio\n");
	printf("Symbol\tShares\tPrice\tValue\n");
	current = first;
	while(current){
		show_structure(current);
		current = current->next;
	}
	return 0;
}

struct stk *make_structure(void)
{
	struct stk *a;

	a = (struct stk *)malloc(sizeof(struct stk) *1);
	(a == NULL) ? exit(1) : printf("Alloaction successful\n");

	return a;
}

void fill_structure(struct stk *a, int c)
{
	printf("Item #%d/%d:\n", c, ITEMS);
	printf("Stock symbol: ");
	scanf("%s", a->symbol);
	printf("Number of shares: ");
	scanf("%d", &a->quantity);
	printf("Share price : ");
	scanf("%f", &a->price);
}

void show_structure(struct stk *a)
{
	printf("%-6s\t%5d\t%.2f\t%.2f\n",a->symbol, a->quantity, a->price, a->quantity*a->price);
}

void save_structure(struct stk *a)
{
	FILE *stks;
	stks = fopen("stocks.db", "a");

	if(!stks)
	{
		puts("Error creating file\n");
		exit(1);
	}
	fwrite(a, sizeof(struct stk), 1, stks);
	fclose(stks);
	printf("Wrote %s value to file\n", a->symbol);
}

struct stk *read_structure()
{
	FILE *stks = fopen("stocks.db", "r");
	(!stks) ? exit(1) : puts("File open successfully\n");
	struct stk *a;
	a = (struct stk *)malloc(sizeof(struct stk) * 1);
	(a == NULL) ? exit(1) : printf("Allocation success\n");

	fread(a, sizeof(struct stk), 1, stks);
	return a;
}

