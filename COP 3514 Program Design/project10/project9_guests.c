// Zahran Yahia Khan
// This program manages and tracks the guest list for a local restaurant.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};


struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);
struct guest *remove_guest(struct guest *list);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list);
                break;
      case 'p': print_list(new_list);
                break;
      case 'r': new_list = remove_guest(new_list);
                break;
      case 'q': clear_list(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct guest *add_guest(struct guest *list){
    char phone[PHONE_LEN + 1];

    struct guest *new_guest; 
    new_guest = malloc(sizeof(struct guest));

    // Checking if memory allocation for the new guest is successful
    if (new_guest == NULL) {
        printf("malloc failed in add_guest\n");
        return list;
    }

    // read phone number from the user
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);

    // checking whether the guest already exists
    struct guest *current = list;
    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            printf("guest already exists.");
            free(new_guest); // release memory for the new guest
            return list;     // return the original list without modification
        }
        current = current->next; // move to the next guest in the list
    }
        
    strcpy(new_guest->phone, phone);

    // Read last name, first name, and party size
    printf("Enter guest's last name: ");
    read_line(new_guest->last, NAME_LEN);

    printf("Enter guest's first name: ");
    read_line(new_guest->first, NAME_LEN);

    printf("Enter party size: ");
    scanf("%d", &(new_guest->party_size));
    while (getchar() != '\n') /* skips to the end of the line */
        ;

    new_guest->next = NULL; // The new guest will be the last in the list

    // If the list is empty, return new guest
    if (list == NULL) {
        return new_guest;
    }
    
    // If the list is not empty, the code enters this section.
    // Add the new guest to the end of the list
    struct guest *temp = list; // creating a temporary pointer 'temp' and initializing it with the head of the list

    // entering a loop that iterates through the list until it reaches the last guest (the one whose next pointer is NULL).
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // When the loop exits, temp points to the last guest in the list.

    temp->next = new_guest;
    // sets the next pointer of the last guest to point to the new guest, adding the new guest to the end of the list.

    return list; // Return the updated list

} 

void print_list(struct guest *list){
    struct guest *current;
    // Initializing a temporary pointer 'current' to the head of the guest list. 
    // This pointer will be used to traverse the list.
    // Moving the current pointer to the next guest in the list by updating it to point to the guest's next node
    for (current = list; current != NULL; current = current->next) {
        printf("%-15s%-20s%-20s%5d\n", current->phone, current->last, current->first, current->party_size);
    }
}

void clear_list(struct guest *list){
    struct guest *current = list;
    // Initializing a temporary pointer 'current' to the head of the guest list. 
    // This pointer will be used to traverse the list.
    struct guest *temp;
    //  a temporary pointer 'temp' to temporarily store the current node before freeing its memory

    while (current != NULL) {
        temp = current; // store the current node's address in temp
        current = current->next; // move to the next node in the list
        free(temp); // Free the memory allocated for the node that temp points to.
    }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}

struct guest *remove_guest(struct guest *list) {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];

    // read information for the guest to be removed
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);

    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN);

    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN);

    struct guest *cur = list;
    struct guest *prev = NULL;

    // search for the guest in the list
    while (cur != NULL){
        if (strcmp(cur->phone, phone) == 0 && strcmp(cur->last, last) == 0 &&
            strcmp(cur->first, first) == 0){
                // entered guest found, remove the node from the list
                if (prev == NULL) {
                    // the guest to be removed is in the first node in the list
                    list = list->next;
                } else {
                    // the guest to be removed is in some other node in the list
                    prev->next = cur->next;
                }
                free(cur); // free memory for the removed guest
                return list;
        }
        prev = cur;
        cur = cur->next;
    }

    // entered guest not found, that is, when the following condition becomes true
    // if (cur == NULL)
    
    printf("guest does not exist\n");
    return list;
}