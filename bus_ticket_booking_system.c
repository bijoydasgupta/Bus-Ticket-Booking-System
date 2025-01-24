#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Booking
{
    char name[50];
    int seatNo;
    char source[50];
    char destination[50];
};

struct Booking bookings[30];
int bookedSeats = 0;

// Function for registration
void registerUser()
{
    FILE *file = fopen("users.txt", "a");
    if (file == NULL)
    {
        printf("\tError opening file!\n");
        return;
    }

    char email[50];
    char password[50];

    printf("\tEnter email: ");
    scanf("%s", email);
    printf("\tEnter password: ");
    scanf("%s", password);

    fprintf(file, "%s,%s\n", email, password);
    fclose(file);

    printf("\tRegistration successful!\n");
}

// Function for user login
int loginUser()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("\tError opening file!\n");
        return 0;
    }

    char email[50];
    char password[50];
    char storedEmail[50];
    char storedPassword[50];

    printf("\tEnter email: ");
    scanf("%s", email);
    printf("\tEnter password: ");
    scanf("%s", password);

    while (fscanf(file, "%[^,],%s\n", storedEmail, storedPassword) != EOF)
    {
        if (strcmp(email, storedEmail) == 0 && strcmp(password, storedPassword) == 0)
        {
            printf("\tLogin successful!\n");
            fclose(file);
            return 1;
        }
    }

    printf("\tInvalid email or password.\n");
    fclose(file);
    return 0;
}

void bookSeat()
{
    if (bookedSeats >= 30)
    {
        printf("\tNo more seats available.\n");
        return;
    }

    struct Booking newBooking;

    printf("\tEnter name: ");
    scanf("%s", newBooking.name);
    fflush(stdin);
    printf("\tEnter seat number: ");
    scanf("%d", &newBooking.seatNo);
    fflush(stdin);
    printf("\tEnter Source: ");
    scanf("%s", &newBooking.source);
    fflush(stdin);
    printf("\tEnter Destination: ");
    scanf("%s", &newBooking.destination);

    bookings[bookedSeats++] = newBooking;
    printf("\tSeat booked successfully.\n");
}

void viewReservations()
{
    if (bookedSeats == 0)
    {
        printf("\tNo reservations made yet.\n");
        return;
    }

    printf("\n\tAll reservations:\n\n");
    printf("\tSeat No.        Name        Source      Destination\n");
    printf("\t----------------------------------------------------\n");
    int i = 0;
    while (i < bookedSeats)
    {
        printf("\n\t  %d            %s          %s         %s", bookings[i].seatNo, bookings[i].name, bookings[i].source, bookings[i].destination);

        ++i;
    }
    printf("\n");
}

void editReservation()
{
    int seatToEdit;
    printf("\tEnter seat number to edit: ");
    scanf("%d", &seatToEdit);

    int found = 0;
    int i = 0;
    while (i < bookedSeats)
    {
        if (bookings[i].seatNo == seatToEdit)
        {
            printf("\tEnter new name: ");
            scanf("%s", bookings[i].name);
            printf("\tEnter new source: ");
            scanf("%s", bookings[i].source);
            printf("\tEnter new distination: ");
            scanf("%s", bookings[i].destination);
            printf("\tReservation edited successfully.\n");
            found = 1;
            break;
        }
        ++i;
    }

    if (found == 0)
    {
        printf("\tReservation is not found.\n");
    }
}

void printTicket()
{
    int seatToPrint;
    printf("\tEnter seat number to print ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    int i = 0;
    while (i < bookedSeats)
    {
        if (bookings[i].seatNo == seatToPrint)
        {
            printf("\n\tTicket for \nSeat No. %d", bookings[i].seatNo);
            printf("\n\tPassenger Name: %s", bookings[i].name);
            printf("\n\tPassenger Source: %s", bookings[i].source);
            printf("\n\tPassenger Destination: %s", bookings[i].destination);
            found = 1;
            break;
        }
        ++i;
    }

    if (found == 0)
    {
        printf("\tReservation is not found.\n");
    }
}

void welcome()
{
    system("color 0A");
    printf("\n\n");
    printf("\t\t\t\t*********************************************************\n\n");
    printf("\t\t\t\t   *    << Welcome to Online UIU Bus Counter >>    *\n\n");
    printf("\t\t\t\t**********************************************************\n");
}
int main()
{
    welcome();
    int choice;
    int isLoggedIn = 0;

    do
    {
        printf("\n\n\t\t\t\t\t\t  1. Register\n\t\t\t\t\t\t  2. Login\n\t\t\t\t\t\t  3. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            isLoggedIn = loginUser();
            if (isLoggedIn)
            {
                int bookingChoice;
                do
                {
                    printf("\n\t\t\t\t\t\t  Mini Bus Booking System\n");
                    printf("\t\t\t\t\t\t  1. Book a seat\n");
                    printf("\t\t\t\t\t\t  2. View reservations\n");
                    printf("\t\t\t\t\t\t  3. Edit a reservation\n");
                    printf("\t\t\t\t\t\t  4. Print a ticket\n");
                    printf("\t\t\t\t\t\t  5. Logout\n");
                    printf("\t  Enter your choice: ");
                    scanf("%d", &bookingChoice);

                    switch (bookingChoice)
                    {
                    case 1:
                        bookSeat();
                        break;
                    case 2:
                        viewReservations();
                        break;
                    case 3:
                        editReservation();
                        break;
                    case 4:
                        printTicket();
                        break;
                    case 5:
                        printf("\tLogged out...\n");
                        isLoggedIn = 0;
                        break;
                    default:
                        printf("\tInvalid choice. Please enter a valid option.\n");
                    }
                } while (isLoggedIn && bookingChoice != 5);
            }
            break;
        case 3:
            printf("\tExited\n");
            break;
        default:
            printf("\tInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
