#include<stdio.h>
#include<stdlib.h>

// Define a queue type structure. //
typedef struct node{
    int element;
    struct node *next;
}queue;

// Initialise a queue instant. //
queue *head = NULL;

void insert( int item ){
    // First check if head is null. //
    /* cause if it is then, you have to initialise it. */
    if( head == NULL ){
        head = ( queue * )malloc( sizeof( queue ) );
        head -> element = item;
        head -> next = NULL;
    }
    else{
        /* In this case we have to traverse the whole list,
        untill we reach the last node where we have to insert the
        element. So to traverse the whole list we initialise the
        variable temp pointer. */
        queue *temp;
        temp = head;
        
        // But first let us insert an element randomly to an address. //
        queue *var;
        var = ( queue * )malloc( sizeof( queue ) );
        var -> element = item;
        var -> next = NULL;
        // element is ready to be inserted in linked list. //
        
        // To traverse, initialise the while loop. //
        /* But we will need to store the previous pointer to
        change the value of last pointer's next. Because at last temp
        -> next will mean NULL -> next which is not accessible. */
        queue *prev;
        
        while( temp != NULL ){
            prev = temp;
            temp = temp -> next;
        }
        // Now prev pointer has the address of last element. //
        // Just make prev's next to the address of newly created element. //
        prev -> next = var;
        // Element is inserted. //
    }
    printf( "Element is inserted.\n" );
} // End of insert() function. //

void pop(){
    /* This is the simplest function. 
    You first have to check if queue is empty.
    If not, then store head's value in a temp variable,
    change head's value to head -> next and free the 
    temp value. */
    if( head == NULL ){
        printf("The queue is empty.\n");
    }
    else{
        queue *temp;
        temp = head;
        
        // But the element that is popped must be reported. //
        int elem = head -> element;
        
        head = head -> next;
        free( temp );
        
        printf("The element at first position %d is popped out.\n", elem);
    }
} // End of pop() function. //

void display(){
    /* First we will check if queue is empty or not. */
    if( head == NULL ){
        printf("Empty queue.\n");
    }
    else{
        /* Now we must initialise a temp variable to traverse the whole list. */
        queue *temp;
        temp = head;
        while( temp != NULL ){
            printf("%d\n", temp -> element);
            temp = temp -> next;
        }
    }
} // End of display() function. //

void main(){
    /* To make a menu driven program initialise
    a variable ch = 1. */
    int ch = 1;
    
    while( ch == 1 ){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. exit\n");
        
        // Initialise a choice variable. //
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if( choice == 1 ){
            // Ask user for an element. //
            int elem;
            printf("Enter element: ");
            scanf("%d", &elem);
            
            // Now simply make a call to insert() function. //
            insert( elem );
        }
        else if( choice == 2 ){
            // Here simply call pop() function. //
            pop();
        }
        else if( choice == 3 ){
            // Call display() function. //
            display();
        }
        else if( choice == 4 ){
            // Change ch = 0 to halt the while loop. //
            ch = 0;
        }
        else{
            printf("Invalid choice.\n");
        }
    }
}