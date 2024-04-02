#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Book{
	char bookTitle[50];
	int yearPublished;
};

int count = 0;

struct Book* addBook(struct Book*);
struct Book* displayAll(struct Book*);
struct Book* searchTitle(struct Book*);
struct Book* searchYear(struct Book*);

int main(){
	struct Book* books = malloc(sizeof(struct Book*) * 50);
	int userInput;
	do{
		printf("\n\n[1] Add book\n[2] Display all\n[3] Search Title\n[4] Search Year\nInput: ");
		scanf("%d", &userInput);
		printf("count: %d\n", count);
		
		switch(userInput){
			case 1 : 
				addBook(books);
				break;
			case 2 :
				displayAll(books);
				break;
			case 3 : 
				searchTitle(books);
				break;
			case 4 :
				searchYear(books);
				break;
			case 0 :
				exit(1);
		}
		
	}while (exit != 1);
	
}

struct Book* addBook(struct Book* books){
	char bookTitle[50];
	int bookYear;
	
	printf("Enter book title: ");
	scanf("%s", &bookTitle);
	
	strcpy(books[count].bookTitle, bookTitle);
	
	printf("Enter year published: ");
	scanf("%d", &books[count].yearPublished);
	
	count++;
}

struct Book* displayAll(struct Book* books){
	int x = 0;
	
	while(x != count){
		printf("\nBook Title: %s\n", books[x].bookTitle);
		printf("Year Published: %d\n", books[x].yearPublished);
		x++;
	}
}

struct Book* searchTitle(struct Book* books){
	char bookSearch[50];
	int x = 0;
	
	printf("Search title: ");
	scanf("%s", &bookSearch);
	
	while(x != count){
		int result = strcmp(bookSearch, books[x].bookTitle);
		if(result == 0){
			printf("\nBook Title: %s\n", books[x].bookTitle);
			printf("Year Published: %d\n", books[x].yearPublished);
			break;
		}
		x++;
	}
}

struct Book* searchYear(struct Book* books){
	int x = 0;
	int bookYear = 0;
	
	printf("Search year publish: ");
	scanf("%d", &bookYear);
	
	while (x != count){
		if(bookYear == books[x].yearPublished){
			printf("\nBook Title: %s\n", books[x].bookTitle);
			printf("Year Published: %d\n", books[x].yearPublished);
		}
		x++;
	}
}
