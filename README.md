# Bus-Ticket-Booking-System
It is a project of my university written by C programming.

This code implements a simple bus ticket booking system in C. Here's a step-by-step explanation of how it works:

1. **Includes and Struct Definition**:
   - The code includes standard libraries: `stdio.h`, `stdlib.h`, and `string.h`.
   - It defines a `Booking` struct to store booking details: `name`, `seatNo`, `source`, and `destination`.

2. **Global Variables**:
   - An array `bookings` of 30 `Booking` structs to store up to 30 bookings.
   - An integer `bookedSeats` to keep track of the number of booked seats.

3. **Functions**:
   - **`registerUser`**: Registers a new user by appending their email and password to a file named `users.txt`.
   - **`loginUser`**: Logs in a user by checking their email and password against the entries in `users.txt`.
   - **`bookSeat`**: Books a seat by adding a new `Booking` to the `bookings` array.
   - **`viewReservations`**: Displays all current reservations.
   - **`editReservation`**: Edits an existing reservation based on the seat number.
   - **`printTicket`**: Prints the ticket details for a specific seat number.
   - **`welcome`**: Displays a welcome message.

4. **Main Function**:
   - Displays a welcome message.
   - Provides a menu for the user to register, log in, or exit.
   - If the user logs in successfully, they can book a seat, view reservations, edit a reservation, print a ticket, or log out.

Here is the main flow of the program:

- **Welcome Message**: The `welcome` function is called to display a welcome message.
- **Main Menu**: The user is presented with options to register, log in, or exit.
  - **Register**: Calls `registerUser` to register a new user.
  - **Login**: Calls `loginUser` to log in. If successful, the user is presented with a booking menu.
    - **Booking Menu**: The user can book a seat, view reservations, edit a reservation, print a ticket, or log out.
  - **Exit**: Exits the program.

The code ensures basic functionality for a bus ticket booking system, including user registration, login, booking, viewing, editing, and printing tickets.
