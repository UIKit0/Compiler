#ifndef QUADRUPLES_H_
#define QUADRUPLES_H_


#include "semantics.h"


typedef struct node2{
	int start;
	Statement *stmt;
	struct node2 *next;
}	loop_stack;

typedef struct node3{
	Expression *expression;
	struct node3 *next;
}switch_stack;


extern unsigned int quadNext ;


int NEXTQUAD();
void GENQUAD(char *op,char *x,char *y,char *z);
quad_node * EMPTYLIST();
quad_node * MAKELIST(int x);
quad_node *MERGE(quad_node *l1,quad_node *l2);
void BACKPATCH(FILE *fp,quad_node *L,char *z);
Type PARAMTYPE(char *I,int n);
char *PARAMMODE(char *I,int n);
int ISFUNCTION(char *I);
Type FUNCRESULT(char *I);
switch_stack *SwitchPop(switch_stack *top);
switch_stack *makeSwitchStack(Expression *expr);
switch_stack *SwitchPush(switch_stack *top,Expression *expr);
loop_stack *LoopPop(loop_stack *top);
loop_stack *makeLoopStack(Statement *stmt,int start);
loop_stack *LoopPush(loop_stack *top,int start,Statement *stmt);
int getLoopStart(loop_stack *top);
void print_stack(loop_stack *top);
quad_node *sort_list(quad_node *head);
void print_list(quad_node *first);
char *replace_str(char *str, char *orig, char *rep);

#endif
