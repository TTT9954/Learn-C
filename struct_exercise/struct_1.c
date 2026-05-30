#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Contact { 
    char name[50]; 
    char phone[50]; 
} ; 

int check_exist(const struct Contact contacts[], int *count, char *phone)
{
    int is_exist = 0;
    for(int i = 0; i < *count; i++)
    {
        if(strcmp(contacts[i].phone, phone) == 0)
        {
            is_exist = 1;
            break;
        }
    }
    return is_exist;
}
void addContact(struct Contact contacts[], int *count) 
{ 
    int total = 0;
    int exist = 0;
    char phone[50];
    if (*count < 100) 
    { 
        total += *count;
        printf("Total: %d\n", total); 
        printf("Enter name: "); 
        scanf("%s", contacts[*count].name);
        printf("Enter phone number: "); 
        scanf("%s", phone);
        exist = check_exist(contacts, count, phone);
        if(!exist)
        {
            strcpy(contacts[*count].phone, phone);
            (*count)++;
            printf("Contact added successfully.\n"); 
        }
        else 
        {
            printf("This phone number already existed\n");
            printf("Contact added unsuccessfully.\n");
        }
    } 
    else 
    { 
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
} 
// Function to search for a contact by name 
void searchContact(const struct Contact contacts[], int count, const char *name) 
{ 
    int found = 0; 
    for(int i = 0; i < count; i++) 
    { 
        if(strcmp(contacts[i].name, name) == 0)
        { 
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone); 
            found = 1; 
            break; 
        } 
    } 
    if (!found) { printf("Contact not found.\n"); } 
} 

// void display(const struct Contact contacts[], int *count)
// {
//     int i = 0;
//     while(i < *count)
//     {
//         printf("Name: %s\n", contacts[i].name);
//         printf("Phone number: %s\n", contacts[i].phone);
//         i++;
//     }
// }

     