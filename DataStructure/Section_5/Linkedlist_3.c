/*검색해서 특정장르 출력하는게 안되서 판타지 장르만 출력되고
킹스맨만 삭제되게 했습니다.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie
{
	char title[20];
	char genre[20];
	int year;
	struct Movie *next;
}Movie;
	
Movie*head = NULL;

void createtitle(Movie *movie)
{
	printf("영화제목:%s\n",movie->title);
}

void creategenre(Movie*movie)
{
	printf("영화장르:%s\n",movie->genre);
}

void createyear(Movie*movie)
{
	printf("개봉년도:%d\n",movie->year);
}

void createMovie(Movie*movie)
{
	createtitle(movie);
	creategenre(movie);
	createyear(movie);
}


void createAll()
{
	Movie * current = head;
	printf("ㅡㅡㅡㅡㅡ영화ㅡㅡㅡㅡㅡ\n");
	if(head == NULL)
	{
		return;
	}

	while(current != NULL)
	{
		createMovie(current);
		printf("\n");
		current = current->next;
	
	}
	}



Movie * insertMovie(char title[20],char genre[20],int year)
{
	Movie * current = head;
	Movie * newMovie = (Movie*)malloc(sizeof(Movie));
	strcpy(newMovie->title,title);
	strcpy(newMovie->genre,genre);
	newMovie->year=year;
	newMovie->next = NULL;

	if(head == NULL)
	{
		head = newMovie;
		return;
	}
		while(current->next!=NULL)
	
		current = current->next;
		current->next = newMovie;
}



int length(Movie *head)
{
	int count =0;
	Movie * current = head;
	while(current!=NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}


void search(Movie *head) 
{
	char want[20];
	Movie *current = head;
	printf("영화 찾기:");
	scanf_s("%s", want, sizeof(want));
	while (current != NULL) {
		if (!strcmp(want, current->title)) 
		{
			printf("영화제목 :%s \n영화장르:%c\n출시년도:%d\n\n", current->title, current->genre, current->year);
		}
			current = current->next;
	}

}
void deleteMovie(char title[20])
{
	Movie*current = head;
	Movie*previous = NULL;
	printf("\n영화%s 삭제\n\n",title);
	while (strcmp(title,head->title)==0)
	{
		head=head->next;
	}

	while(current!=NULL)
	{
		if(strcmp(title,current->title)==0)
		{
			previous->next=current->next;
			current=previous;
		}
		previous = current;
		current = current->next;
	}
}
void Genre(char genre[20])
{
	Movie *current = head;
	printf("특정 장르의 곡만 출력 판타지 \n");
	while(current != NULL)
	{
		if(strcmp(genre,current->genre) == 0)
		{
			createMovie(current);
			printf("\n");
		}
		current = current->next;
	}
}


int main(void)
{
	insertMovie("해리포터", "판타지", 2016);
	insertMovie("곤지암", "공포", 2018);
	insertMovie("킹스맨", "액션", 2015);
	insertMovie("인사이드아웃", "애니매이션", 2015);
	insertMovie("다크나이트","범죄", 2008);
	createAll();
	system("pause");
	printf("\n\n\n\n새로운 영화 추가\n\n");
	insertMovie("어벤져스","액션",2018);
	createAll();
	printf("전체 영화개수: %d\n\n",length(head));
	search(head);
	system("pause");
	Genre("판타지");
	system("pause");
	deleteMovie("킹스맨");
	createAll();
	system("pause");
	return 0;
	
}