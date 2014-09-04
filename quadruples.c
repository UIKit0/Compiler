#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "parser.h"

extern FILE *fp;

int NEXTQUAD(){
	return quadNext;
}

void GENQUAD(char *op,char *x,char *y,char *z){

	char quad[50];
	int i;


	//file opened no need to search every time
	printf("printing| %d: %s,%s,%s,%s | in fp = %d\n",quadNext,op,x,y,z,fileno(fp));
	fprintf(fp,"%d: %s,%s,%s,%s\n",quadNext,op,x,y,z);
	quadNext++;

}

quad_node * EMPTYLIST(){
	quad_node *new = NULL ;
	return new ;
}

quad_node * MAKELIST(int x){
	quad_node * new = (quad_node *)malloc(sizeof(quad_node));
	new->quad_num = x ;
	new->next = NULL ;
	return new;
}

quad_node *MERGE(quad_node *l1,quad_node *l2){
	quad_node *temp = l1;
	
	if(l1 == NULL)	return l2;
	else if(l2 == NULL)  return l1;
	else {
		while(temp->next != NULL)	temp=(temp->next);
		temp->next=l2;
	
		return l1;
	}
}

void BACKPATCH(FILE *fp,quad_node *L,char *z){
	//first finding the quads and replacing
	int cur = 1,i,result;
	int quad_number;
	FILE *fp2;
	
	printf("entered BACKPATCH: fp = %d\n",fileno(fp));
	
	if(L != NULL){		//if list is empty no need to backpatch
	
		quad_node *sorted_list = sort_list(L);
	
		fclose(fp);
		fp = fopen("quads.txt","r"); 		//reopen the file to get to the beginning
		fp2 = fopen("quads2.txt","w"); 
		printf("entered BACKPATCH: fp2 =  %d\n",fp2);
	
		char line[256];
		char * buffer;
		char * pch;
		printf("BACKPATCH 1\n");
	
		while(sorted_list != NULL){		//while there are more quads to be backpatched
			quad_number = sorted_list->quad_num;
			printf("entered BACKPATCH loop: quad to be backpatched is %d with string %s\n",quad_number,z);
			printf("BACKPATCH 2\n");
			
			if(cur == quad_number){			//if current quad must be backpatched
				printf("BACKPATCH 2a\n");
				fgets(line, 256, fp);
				
				
				
				printf("BACKPATCH 2b\n");
				buffer =(char*)malloc(sizeof(char) * strlen(line));
				
				fclose(fp2);
				fp2 = fopen("quads2.txt","a");
				
				printf("BACKPATCH 2c\n");
				strcpy(buffer, line);		//this command creates seg fault when loops -> first stmt in block_list!!

				fclose(fp2);
				fp2 = fopen("quads2.txt","a");

				printf("BACKPATCH 2d\n");
				buffer = replace_str(buffer, "*", z);
			
				printf("BACKPATCH 2f\n");
				fputs(buffer,fp2);
				
				cur++;
			}
			else if(cur < quad_number ){				//if file pointer before "wanted" quadruple
				fgets(line, 256, fp);
				fputs(line,fp2);
				//puts(line);
				cur++;
			}
			else {							//if file pointer after "backpatched" quadruple 
				sorted_list = sorted_list -> next;
			}
			
			printf("BACKPATCH 3\n");
		}
	
		while(cur < quadNext){
			printf("BACKPATCH : antigrafei apla 1 grammi apo to palio sto kainourgio\n");
			fgets(line, 256, fp);
			fputs(line,fp2);
			cur++;
			}
		printf("BACKPATCH 4\n");
		result = rename("quads2.txt","quads.txt");
		printf("BACKPATCH after rename:  fp = %d and fp2 = %d",fp,fp2);
		if(result == 0 )	printf("BACKPATCH: RENAME SUCCESSFULL\n");
		printf("BACKPATCH 4b\n");
		fclose(fp);
		printf("BACKPATCH 4c\n");
		printf("leaving BACKPATCH 4c:  fp2 = %d\n",fp2);
		fclose(fp2);
	
		printf("BACKPATCH 5\n");
		//afterwards going till the end of the file and waiting there
		fp = fopen("quads.txt","a+");
		printf("BACKPATCH exiting : fp = %d\n",fileno(fp));
	}
	printf("BACKPATCH exiting 3: fp = %d\n",fileno(fp));
	
}

Type PARAMTYPE(char *I,int n){
	SymbolEntry *tempArg = lookupEntry(I,LOOKUP_ALL_SCOPES,0)->u.eFunction.firstArgument;
	int param_count = n;
	
	
	while(param_count > 1){
		tempArg = tempArg->u.eParameter.next;
		param_count--;
	}
	return tempArg->u.eParameter.type;
}

char *PARAMMODE(char *I,int n){
	SymbolEntry *tempArg = lookupEntry(I,LOOKUP_ALL_SCOPES,0)->u.eFunction.firstArgument;
	int param_count = n;
	
	while(param_count > 1){
		tempArg = tempArg->u.eParameter.next;
		param_count--;
	}
	if(tempArg->u.eParameter.mode == PASS_BY_VALUE) return "V" ;
	else if(tempArg->u.eParameter.mode == PASS_BY_REFERENCE) return "R" ;
}

int ISFUNCTION(char *I){		//returns 1 if it is function,0 else
	SymbolEntry *temp = lookupEntry(I,LOOKUP_ALL_SCOPES,0);
	
	if(temp->u.eFunction.resultType == typeVoid )  return 0;
	else return 1;
}

Type FUNCRESULT(char *I){
	SymbolEntry *temp = lookupEntry(I,LOOKUP_ALL_SCOPES,0);
	
	return temp->u.eFunction.resultType;
}

 


switch_stack *SwitchPop(switch_stack *top){
	switch_stack *temp = top;
	
	if(temp == NULL){	
		printf("cannot pop since the stack is empty\n");
		return NULL;
	}
	else{
		temp = temp->next;
		return temp;
	}

}

switch_stack *makeSwitchStack(Expression *expr){
	switch_stack *temp = (switch_stack *)malloc(sizeof(switch_stack));
	
	temp->expression = expr;
	temp->next = NULL;
	
	return temp;
}

switch_stack *SwitchPush(switch_stack *top,Expression *expr){
	switch_stack *temp ;
	
	temp = (switch_stack *)malloc(sizeof(switch_stack));
	temp->expression = expr;
	temp->next = top;
	return temp;
}

loop_stack *LoopPop(loop_stack *top){
	loop_stack *temp = top;
	
	if(temp == NULL){	
		printf("cannot pop since the stack is empty\n");
		return NULL;
	}
	else{
		temp = temp->next;
		return temp;
	}

}

loop_stack *makeLoopStack(Statement *stmt,int start){
	loop_stack *temp = (loop_stack *)malloc(sizeof(loop_stack));
	
	temp->start = start;
	temp->stmt = stmt;
	temp->next = NULL;
	
	return temp;
}

loop_stack *LoopPush(loop_stack *top,int start,Statement *stmt){
	loop_stack *temp ;
	
	temp = (loop_stack *)malloc(sizeof(loop_stack));
	temp->start = start;
	temp->stmt = stmt;
	temp->next = top;
	return temp;
}

int getLoopStart(loop_stack *top){
	
	if(top == NULL)	{
		printf("The stack is empty there are no start numbers to return\n");
		return 0;
	}
	else {
		return (top->start);
	}	

}

/*
Statement *getLoopPointer(loop_start *top){
	
	if(top == NULL){
		printf("The stack is empty there are no statement pointers to return");
		return NULL;
	}
	else {
		return (top->stmt);
	}

}*/

void print_stack(loop_stack *top){
	
	
	while(top!=NULL){
		printf("%d ",top->start);
		top=top->next;
	}
	printf("\n");
}





quad_node *sort_list(quad_node *head) {

    quad_node *tmpPtr = head;
    quad_node *tmpNxt = head->next;

    int tmp;

    while(tmpNxt != NULL){
           while(tmpNxt != tmpPtr){
                    if(tmpNxt->quad_num < tmpPtr->quad_num){
                            tmp = tmpPtr->quad_num;
                            tmpPtr->quad_num = tmpNxt->quad_num;
                            tmpNxt->quad_num = tmp;
                    }
                    tmpPtr = tmpPtr->next;
            }
            tmpPtr = head;
            tmpNxt = tmpNxt->next;
    }
         return tmpPtr ; // Place holder
} 


void print_list(quad_node *first){
	
	printf("mpike print list\n");
	while(first!=NULL){
		printf("print list 1\n");
		printf("%d  ",first->quad_num);
		printf("print list 2\n");
		first=first->next;
	}
	printf("\n");
	printf("vgike print list\n");
}


char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}
