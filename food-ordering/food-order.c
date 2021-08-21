#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    char foodname[50];
    int price;
    int qty;
    struct node *link;
};
struct node *headc = NULL,*heada = NULL;

void mainmenu()
{
    int c;
    printf("\n------------KARAVALI FOOD FORT-----------\n");
    printf("\n------------Main Menu-----------\n");
    printf("\n 1. Admin \n 2. Customer \n 3. Exit");
    printf("\nEnter Choice:\t ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:admin_menu();
        break;
    case 2: customer_menu();
        break;
    case 3: exit(1);
        break;
    default: printf("Invalid choice");
        break;
    }
}

void admin_menu()
{
    printf("\n------------Admin Menu-----------\n");
    int c;
    printf("\n 1. View Menu Items. \n 2.View Orders \n 3.Add Menu items \n 4. Delete Menu items \n 5. Main menu \n ");
    printf("\nEnter Choice:\t ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:displaymenu();
        break;
    case 2:displayorder();
        break;
    case 3:add_items();
        break;
    case 4:delete_items();
        break;
    case 5: mainmenu();
        break;
    default: printf("Invalid choice");
        break;
    }
}

void add_items()
{
    int i,n;
    printf("How many items you want to add ?\t ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("\n----------Item %d-------------------\n",i);
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=heada;
    printf("\n------------Add food Item-----------\n");
    printf("\nEnter item Number: ");
    scanf("%d",&newnode->data);
    printf("\nEnter item Name: ");
    scanf("%s",&newnode->foodname);
    printf("\nEnter item price: ");
    scanf("%d",&newnode->price);
    newnode->qty=0;
    newnode->link=NULL;
    if(temp==NULL)
    {
        heada=newnode;
    }else{
    while(temp->link != NULL)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    }
    }
    admin_menu();
}
void delete_items()
{
    printf("\n------------Delete food Item-----------\n");
    struct node *temp=heada,*temp2;
    if(temp==NULL)
        printf("\n--------Empty Menu--------");
    else{
        displaymenu2();
        int p,i;
        printf("Enter Position  to delete: ");
        scanf("%d",&p);
        if(p==1)
        {
           heada=heada->link;
           temp->link=NULL;
           free(temp);
        }
        else
        {

        for(i=1;i<p-1;i++)
        {
            temp=temp->link;
        }
        temp2=temp->link->link;
        temp->link=temp2;
        }
    }
    displaymenu();
    admin_menu();
}
void displaymenu2()
{
    struct node *temp=heada;
    if(temp==NULL)
        printf("\n--------Empty Menu--------");
    else{
        int i=1;
        printf("\n Sl no.\t Item ID \t Item \t\t Price\n");
        printf("-----------------------------------------\n");
        while(temp!=NULL)
        {
            printf("%d \t %d \t %s \t\t %d\n",i++,temp->data,temp->foodname,temp->price);
            temp=temp->link;
        }
    }
}

void displaymenu()
{
    struct node *temp=heada;
    if(temp==NULL)
        printf("\n--------Empty Menu--------");
    else{
        int i=1;
        printf("\n Sl no.\t Item ID \t Item \t\t Price\n");
        printf("-----------------------------------------\n");
        while(temp!=NULL)
        {
            printf("%d \t %d \t %s \t\t %d\n",i++,temp->data,temp->foodname,temp->price);
            temp=temp->link;
        }
    }
    admin_menu();
}

void customer_menu()
{
    printf("\n------------Customer Menu-----------\n");
    int c;
    printf("\n 1. View Menu. \n 2.View My Orders \n 3. Order food  \n 4. Delete order \n 5. Main menu \n ");
    printf("\nEnter Choice:\t ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:printf("\n------------KARAVALI FOOD FORT - MENU -----------\n");
        displaymenu_c();
        break;
    case 2:displayorder();
        break;
    case 3:orderfood();
        break;
    case 4:delete_order();
        break;
    case 5: mainmenu();
        break;
    default: printf("Invalid choice");
        break;
    }
}

void delete_order()
{
    int c;
    printf("\n------------Delete food Item-----------\n");
    struct node *temp=headc,*temp2;
    if(temp==NULL)
        printf("\n--------Empty Menu--------");
    else{
        printf("1. Cancel Order \t 2. Cancel item \n");
        scanf("%d",&c);
        if(c==1)
        {
            headc=NULL;
            free(headc);
            printf("--------------Order Cancled----------------------");
        }
        else
        {
        int p,i;
        printf("Enter Serial Number  to delete: ");
        scanf("%d",&p);
        if(p==1)
        {
           headc=headc->link;
           temp->link=NULL;
           free(temp);
        }
        else
        {

        for(i=1;i<p-1;i++)
        {
            temp=temp->link;
        }
        temp2=temp->link->link;
        temp->link=temp2;
        }
        }
    }
    displaymenu_c();
    customer_menu();
}
void displaymenu_c()
{
    struct node *temp=heada;
    if(temp==NULL)
        printf("\n--------Empty Menu--------");
    else{
        int i=1;
        printf("\n Sl no.\t Item ID \t Item \t\t Price\n");
        printf("-----------------------------------------\n");
        while(temp!=NULL)
        {
            printf("%d \t %d \t %s \t\t %d\n",i++,temp->data,temp->foodname,temp->price);
            temp=temp->link;
        }
    }
    customer_menu();
}


void orderfood()
{
    struct node *newnode,*temp=heada,*temp2=headc;
    int i,c,q;
    char ch;
    displaymenu2();
    while(1)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nSelect the food serial number to order: ");
    scanf("%d",&c);
    printf("\nEnter quantity: ");
    scanf("%d",&q);
        if(c==1)
        {
           newnode->data = temp->data;
           strcpy(newnode->foodname,temp->foodname);
           newnode->price = temp->price;
           newnode->qty=q;
        }
        else
        {
        for(i=1;i<=c-1;i++)
        {
            temp=temp->link;
        }
            newnode->data = temp->data;
           strcpy(newnode->foodname,temp->foodname);
           newnode->price = temp->price;
           newnode->qty=q;
        }
        newnode->link=NULL;
        if(temp2==NULL)
        {
        headc=newnode;
        }else{
        while(temp2->link != NULL)
        {
        temp2=temp2->link;
        }
        temp2->link=newnode;
        }
        printf("Do you want to add one more item ?(y/n): ");
        ch=getch();
        if(ch == 'n' || ch == 'N')
        {
            break;
        }
    }
    customer_menu();
}

void displayorder()
{
    int i,t,gt=0,up,n;
    struct node *temp=headc;
    if(temp==NULL)
        printf("\n--------My Orders--------");
    else{
        int i=1;
        printf("\n Sl no.\t Item ID \t Item \t Unit_Price \t Quantity \t Total\n");
        printf("------------------------------------------------------------------\n");
        while(temp!=NULL)
        {
            t=0;
            up=temp->price;
            n=temp->qty;

            for(i=0;i<n;i++)
            {
                t+=up;
            }
            gt+=t;
            printf("%d \t %d \t %s \t %d \t %d \t %d\n",++i,temp->data,temp->foodname,temp->price,temp->qty,t);

            temp=temp->link;
        }
        printf("\nGrand Total: %d",gt);
    }
    customer_menu();
}
void main()
{
    mainmenu();
    getch();

}
