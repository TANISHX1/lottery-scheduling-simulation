#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <termios.h>
#include <unistd.h>

#define NUM_RUNS 10 //no.of schedulers runs
//structure to create the linked list
typedef struct node
{
    char *job_name;
    int tickets;
    int wins;//no. of times job selected
    struct node *next;
}node_t;
 //to store the data of job
node_t* create_job(char *name,int tickets){
    node_t *new_job = (node_t *)malloc(sizeof(node_t));
    new_job->job_name = strdup(name);
    new_job-> wins =0;
    new_job->tickets = tickets;
    new_job->next = NULL;
    return new_job;
}
void append_job(node_t **head , char* name, int tickets){
    node_t *new_job =create_job(name,tickets);
    if(*head == NULL){
        *head = new_job;
    }else{
        node_t *temp = *head;
        while(temp->next !=NULL)
        {
          temp = temp->next; 
        }
          temp->next = new_job;
    }
}
int get_total_tickets(node_t *head){
    int total =0;
    while (head!=NULL)
    {
        total+= head->tickets;
        head = head->next;
    }
    return total;
}

void lottery_schedule(node_t *head,bool selection_print_flag){
    int total_tickets = get_total_tickets(head);
    if(total_tickets ==0){
        printf("NO TICKETS IN THE POOL>>: \n");
        return;
    }

    int winner = rand()%total_tickets, counter =0;
    
    node_t *current = head;
    while(current !=NULL){
        counter+=current->tickets;
        if(counter>winner){
            if(selection_print_flag)
            {
        printf(" Selected Job: %s (winning ticket # %d)\n",current->job_name,winner);
            }
           current->wins++;
            return;
        }
        current = current->next;

    }
}
//to print statics
void print_stats(node_t *head){
    printf("\n==Job Wins Statics(out of %d runs)===\n",NUM_RUNS);
    while(head!=NULL){
     
        printf("%s-> Wins: %d (%.2f%%)\n",head->job_name,head->wins,(head->wins*100.0)/NUM_RUNS);
    
        head = head->next;
    }
}

//free memory
void free_job_list(node_t *head){

    node_t *temp;
    while(head!= NULL){
        temp = head;
        head = head->next;
        free(temp->job_name);
        free(temp);
    }
}
void shorting(node_t **head){
    if(*head == NULL || (*head)->next ==NULL) return ;

    int flag;
    node_t **ptr = head;
    do{
        flag =0;
    
    
    while((*ptr)->next != NULL)
    {
        node_t *temp = *ptr;
        node_t *temp1 = temp->next;
        if(temp->wins > temp1->wins)
        {
            temp->next = temp1->next;
            temp1->next = temp;
            *ptr = temp1;
            flag =1;
        }
        ptr = &(*ptr)->next;

    }}while(flag);
}

int main(){
    restart:
    char decision;
    srand(time(NULL));
    int jobs,ticket_value = 10,flag=0,flag1=0,i;
   
    printf("Enter number of jobs:\t");
    scanf("%d",&jobs);
    printf("Press [1]: To see job selection per schedule  | [0]: To Skip :\t");
    scanf("%d",&flag);
    printf("Press [1]: To short the Wins Statics | [0]: To Skip :\t");
    scanf("%d",&flag1);
    char upd[20];
    node_t *job_list = NULL;
 for( i=0;i<jobs;i++)
    {
        snprintf(upd,sizeof(upd),"Job_%c",65+i);//it is to create names like Job_A,job_B,Job_c and so on.
        ticket_value = rand()%(10*jobs);
        append_job(&job_list,upd,ticket_value);
    }
/*append_job(&job_list,"Job_B",20);
append_job(&job_list,"Job_C",30);
append_job(&job_list,"Job_D",40);*/
for(i=0;i<NUM_RUNS;i++)
{
    lottery_schedule(job_list,flag);
   // printf("---------------------------------\n");
}
if(flag1)
{for ( i=0;i<jobs;i++)
{
   shorting(&job_list);
}}
print_stats(job_list);
free_job_list(job_list);

printf("Press [Y]:To Run Again [N]: To Exit\t");
scanf(" %c",&decision);
if(decision =='Y')
{
    goto restart;
}
else{
return 0;
}
}