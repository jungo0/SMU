/*�˻��ؼ� Ư���帣 ����ϴ°� �ȵǼ� ��Ÿ�� �帣�� ��µǰ�
ŷ���Ǹ� �����ǰ� �߽��ϴ�.*/
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
	printf("��ȭ����:%s\n",movie->title);
}

void creategenre(Movie*movie)
{
	printf("��ȭ�帣:%s\n",movie->genre);
}

void createyear(Movie*movie)
{
	printf("�����⵵:%d\n",movie->year);
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
	printf("�ѤѤѤѤѿ�ȭ�ѤѤѤѤ�\n");
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
	printf("��ȭ ã��:");
	scanf_s("%s", want, sizeof(want));
	while (current != NULL) {
		if (!strcmp(want, current->title)) 
		{
			printf("��ȭ���� :%s \n��ȭ�帣:%c\n��ó⵵:%d\n\n", current->title, current->genre, current->year);
		}
			current = current->next;
	}

}
void deleteMovie(char title[20])
{
	Movie*current = head;
	Movie*previous = NULL;
	printf("\n��ȭ%s ����\n\n",title);
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
	printf("Ư�� �帣�� � ��� ��Ÿ�� \n");
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
	insertMovie("�ظ�����", "��Ÿ��", 2016);
	insertMovie("������", "����", 2018);
	insertMovie("ŷ����", "�׼�", 2015);
	insertMovie("�λ��̵�ƿ�", "�ִϸ��̼�", 2015);
	insertMovie("��ũ����Ʈ","����", 2008);
	createAll();
	system("pause");
	printf("\n\n\n\n���ο� ��ȭ �߰�\n\n");
	insertMovie("�����","�׼�",2018);
	createAll();
	printf("��ü ��ȭ����: %d\n\n",length(head));
	search(head);
	system("pause");
	Genre("��Ÿ��");
	system("pause");
	deleteMovie("ŷ����");
	createAll();
	system("pause");
	return 0;
	
}