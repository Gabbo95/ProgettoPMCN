#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
	int id;
	clock_t time_arrive;
	clock_t time_exit_queue;
}element;


int k=1;

int push(element *list_elements){
	element p;
	p.time_arrive=clock();
	p.id=k;
	k++;
	for(int i=0;i<50;i++){
		if(list_elements[i].id==0){
			list_elements[i]=p;
			return 1;
		}
	}
	return 0;
	
}

element pull(element *list_elements){
	if(list_elements[0].id==0){
		printf("WAIT!!! Queue full\n");
		element p;
		p.id=0;
		return p;
	}
	element current_element=list_elements[0];
	current_element.time_exit_queue = clock();
	for(int i=1;i<50;i++){
		if(list_elements[i-1].id!=0){
			list_elements[i-1]=list_elements[i];
		}
		else{
			break;
		}
		if(i==49){
			element p;
			p.id=0;
			list_elements[i]=p;
		}
	}
	return current_element;
}

void initializate(element *list_elements){
	for(int i=0;i<50;i++){
		element p;
		p.id=0;
		list_elements[i]=p;
	}
	return;
}

void print_elements(element *list_elements){
	for(int i=0;i<50;i++){
		if(list_elements[i].id!=0){
			printf("%d valore elemento\n",list_elements[i].id);
		}
	}
}

void main(void){
	int i;
	element list_elements[50];
	initializate(list_elements);
	while(i<5){
		push(list_elements);
		i++;
		printf("%d\n",i);
	}
	print_elements(list_elements);
	element q = pull(list_elements);
	printf("%d valore elemento tolto\n",q.id);
	print_elements(list_elements);
	return;
}
