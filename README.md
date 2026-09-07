# Movie Ticket Booking System – LLD

A console-based Movie Ticket Booking System developed in C++ to demonstrate Object-Oriented Programming (OOP), SOLID principles, and Low-Level Design (LLD) concepts.

The system supports movie and show selection, seat booking, multiple payment methods, ticket generation, and booking cancellation.

## Features

- Display currently playing movies
- Display available shows with screen and start time
- Display seat layout and availability
- Select one or multiple seats
- Automatic seat-price calculation
- UPI, Card, and Cash payments
- Failed payment releases selected seats
- Automatic unique booking ID generation
- Ticket generation
- Booking cancellation
- Input validation and failure handling

## Technologies Used

- Language: C++
- Design: OOP and Low-Level Design
- Compiler: g++
- Interface: Console / Menu Driven

## Concepts Used

- Encapsulation
- Abstraction
- Inheritance
- Runtime and Compile-time Polymorphism
- Static Members
- Composition, Aggregation and Association
- SOLID Principles followed

## Project Structure

Movie-Ticket-Booking-System/

- Movie.cpp
- Seat.cpp
- Screen.cpp
- Cinema.cpp
- ShowSeat.cpp
- Show.cpp
- Customer.cpp
- Payment.cpp
- UpiPayment.cpp
- CardPayment.cpp
- CashPayment.cpp
- Booking.cpp
- PriceCalculator.cpp
- Ticket.cpp
- TicketPrinter.cpp
- BookingService.cpp
- main.cpp
- README.md

## How to Run

```bash
g++ main.cpp
./a.exe
