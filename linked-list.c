#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start = NULL;

//2> Insert At Begin.
void insertAtBegin(int n)
{
    struct node *newnode;
    newnode=(struct node*)malloc (sizeof(struct node));
    newnode->data=n;
    newnode->next=start;
    start=newnode;
    return;
}

//3> Insert At Ending.
void InsertAtEnd(int n)
{
    struct node *temp;
     struct node *newnode;
     temp=start;
     newnode=(struct node*)malloc(sizeof(struct node));
     if (start==NULL)
     {
         newnode->data=n;
         newnode->next=start;
         start=newnode;
         return;
     }
     else
     {     temp = start;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newnode;
    }
     newnode->data=n;
     newnode->next=NULL;
     return;
}
//4> Insert Node After a Specific Node.

void IASN(int n,int sn)
{
    struct node *newnode,*temp=start;
    int f=0;
        while(temp!=NULL)
        {
            if (temp->data==sn)
            {
                f=1;
                break;
            }
            temp=temp->next;
        }
    if (f==1 )//|| (temp->next==NULL && temp->data == sn))
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=n;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else{
        printf("Node is not found.\n");
    }
    return;
}

//5> Insert Node befor specific node.
void NBSN(int n,int sn)
{
    struct node *newnode,*temp=start,*previous;
    int f=0;
     newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=n;
    while(temp!=NULL)
    {
        if(temp==start && temp->data==sn)
        {
            newnode->next=temp;
            start=newnode;
        }
       else if(temp->data==sn )
        {
            f=1;
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    if (f==1)
    {
        newnode->next=previous->next;
        previous->next=newnode;
    }
    else{
        printf("Node is not found.\n");
    }
    return;
}

//6> Delet node for begining..
void DeletAtBegining() 
{
    struct node *temp=start;
    start=start->next;
    printf("Your data %d is deleted",temp->data);
    free(temp);
    return;
}

//7> Delet node for ending.
void DeletAtEnding()
{
    struct node *preview,*temp=start;
    if (start->next==NULL)
    {
        printf("Your data %d is deleted.",start->data);
        free(start);
        start=NULL;
    }
    else{
    while(temp->next!=NULL)
    {
        
        preview=temp;
        temp=temp->next;
    }
    preview->next=NULL;
    printf("Your data %d is deleted",temp->data);
    free(temp);
}
    return;
}

//8> Delet After Specific Node.
void D_A_S_N(int sn)
{
    struct node *temp=start,*nextnode;
    int f=1;
    if (start->next==NULL)
    {
        printf("You have only single node.");
        return;
    }else{
        while(temp->next!=NULL)
        {
             nextnode=temp->next;
            if (temp->data == sn)
            {
                f = 1;
                break;
            }
            temp=temp->next;
        }
    }

     if (f==1){
        temp->next=nextnode->next;
        printf("Your data %d is delet.",nextnode->data);
        free(nextnode);
    }
    else{
    printf("Node is not found.");
    }
    return;

}

//9> Delet befor specific Node.
void D_B_S_N(int sn)
{
    struct node *temp=start,*preview,*ntemp;
    int f=0,count=0;
    if (start->next == NULL)
    {
        printf("You have only one node.");
        return;
    }else {
        while(temp!=NULL)
        {
            if  (temp->data==sn){
                f=2;
                break;
            
            }else if (ntemp->data == sn )
            {
                f = 1;
                break;
            }
            
            preview=temp;
            temp=temp->next;
            ntemp=temp->next;
        }
    }
    if (f==1)
    {

        preview->next=temp->next;
        printf("Delet your data %d before specific ndoe",temp->data);
        free(temp);
    }else if (f==2)
    {
        start=preview->next;
        printf("Your data %d is deleted",preview->data);
        free(preview);
    }else {
        printf("Node is not found.");
    }
    return;
}

//10> Delet a specific node.
void D_S_N(int sn)
{
    struct node *temp=start,*prev;
    int f=0,count=0;
    while(temp!=NULL)
    {
        count++;
        if (temp->data == sn)
        {
            f=1;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if (count==1)
    {
        start=temp->next;
        printf("Your data %d is delet.",temp->data);
        free(temp);
    }else if (f==1)
    {
        prev->next=temp->next;
        printf("Your data %d is delet.",temp->data);
        free(temp);
    }else{
        printf("Your node is not exist.");
    }
    return;
}

//11> Search a particular Node.
void S_A_P_N(int sn)
{
    struct node *temp=start;
    int f=0;
    while (temp!=NULL){
        if (temp->data == sn)
        {
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f==1)
    {
        printf("Your data %d is -> Here",temp->data);
    }else{
        printf("Data is not found.");
    }
    return;
}
//12-> Print total NO. of Nodes.
void T_N_O_N ()
{
    struct node *temp=start;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Total Number of Node is -> %d",count);
    return;
}

// //13> Arragne the data ascending to descending order.
// void shorting(){
// struct node *temp=start,*preview;
//     int count=0,a,b,c,i;
//     while (temp!=NULL)
//     {
//         count++;
//         temp=temp->next;
//     }
//     for (i=0;i<count;i++){
//         while(temp!=NULL){
//     preview=temp;
//     temp = temp->next;
//     a = preview->data;
//     b = temp->data;
//              if (a > b)    
//        {
//         c = a;
//         a = b;
//         b = c;
//        }
// }
//     }
// printf("Data sorted sucessfully.");
// return;
// }

//1> Display.
void display()
{
    struct node *temp;
    temp = start;
    if (start == NULL)
    {
        printf("File is empty !\n");
    }else{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
    return;
}
void main ()
{
    int n,ch;
        printf("0> Exit\n");
        printf("1> Display\n");
        printf("2> Insert At Begin\n");
        printf("3> Insert At End\n");
        printf("4> Node After Specific Node\n");
        printf("5> Node Before Specific Node\n");
        printf("6> Delet Node from begining.\n");
        printf("7> Delet Node from ending.\n");
        printf("8> Delet after specific Node\n");
        printf("9> Delet befor specific Node.\n");
        printf("10> Delet a specific Node.\n");
        printf("11> Search a particular Node\n");
        printf("12> Print total NO. of Nodes.\n");
        printf("13> Arrange the data Assending to desending.\n");
        
       
         while(1)
    {
        printf("\nEnter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                display();
                break;
            }
            case 2:
            {
                printf("Enter data to add in begining:");
                scanf("%d",&n);
                insertAtBegin(n);
                break;
            }
            case 3:
            {
                printf("Enter data insert at ending.\n");
                scanf("%d",&n);
                InsertAtEnd(n);
                break;
            }
            case 4:
            {
                int n,sn;
                if (start==NULL)
                {
                    printf("You hace no node . \n So plese creat a node .\n Enter the node data .\n");
                    scanf("%d",&n);
                    struct node *newnode;
                    newnode = (struct node*)malloc(sizeof(struct node));
                    newnode->data=n;
                    newnode->next = NULL;
                    start = newnode;
                    printf("Your first node created sucessfully.\n");
                    break;
                }
                printf("Enter the specific node data:");
                scanf("%d",&sn);
                printf("Enter the node data.");
                scanf("%d",&n);
                IASN(n,sn);
                break;
            }
            case 5:
            {
                if (start==NULL)
                {
                    printf("You have no node.\nCreat Your first node.\nEnter the node data.\n");
                    scanf("%d",&n);
                    struct node *newnode;
                    newnode=(struct node*)malloc(sizeof(struct node));
                    newnode->data=n;
                    start=newnode;
                    newnode->next=NULL;
                    printf("Your first node created sucessfully.\n");
                    break;
                }
                int n,sn;
                printf("Enter the specific node data:-\n");
                scanf("%d",&sn);
                printf("Enter the node data:-\n");
                scanf("%d",&n);
                NBSN(n,sn);
                break;
            }
            case 6:
            {
                if (start==NULL)
                {
                    printf("Memory is Empty.");
                    break;
                }
                DeletAtBegining();
                break;
            }
            case 7:
            {
                if (start==NULL)
                {
                    printf("Memory is empty.");
                    break;
                }
                DeletAtEnding();
                break;
            }
            case 8:
            {
                int sn;
                if (start==NULL)
                {
                    printf("Memory is empty!");
                    break;
                }
                printf("Enter the Specafic Node.");
                scanf("%d",&sn);
                D_A_S_N(sn);
                break;
            }
            case 9:
            {
                int sn;
                if (start==NULL)
                {
                    printf("File is empty:");
                    break;
                }else{
                printf("Enter the specific node ->");
                scanf("%d",&sn);
                D_B_S_N(sn);
                break;
                }
           }
           case 10:
           {
            int sn;
            if (start==NULL)
            {
                printf("Memory is empty.");
                break;
            }else{
                printf("Ente the specific data:");
                scanf("%d",&sn);
                D_S_N(sn);
            }
            break;
           }

           case 11:
           {
            int sn;
            if (start == NULL)
            {
                printf("Memory is empty.");
                break;
            }else{
                printf("Enter the data for searching.");
                scanf("%d",&sn);
            S_A_P_N(sn);
            break;
           }
        }
            case 12:
            {
                if (start==NULL){
                    printf("Memory is empty.");
                    break;
                }
                T_N_O_N();
                break;
            }
            // case 13:
            // {
            //     if (start==NULL)
            //     {
            //         printf("Memory is empty.");
            //         break;
            //     }
            //     shorting();
            //     break;
            // }
            case 0:
            {
                exit(0);
            }
        }
    }
} 