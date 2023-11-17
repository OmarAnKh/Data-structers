#include <iostream>
#include "seat.h"
using namespace std;

class flight
{
private:
    seat **seats;
    int first_three_rows;
    int rest_of_rows;

public:
    flight();
    bool isValid(int seatNum);
    bool reserve(int seatNum);
    bool cancelreservation(int seatNum);
    void cancelAllReservations();
    int seatsInfo();
};

flight::flight()
{
    first_three_rows = 3;
    rest_of_rows = 6;
    int counter = 11;
    seats = new seat *[9];
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            seats[i] = new seat[2]{counter, counter + 1};
            counter += 10;
        }
        else
        {
            seats[i] = new seat[4]{counter, counter + 1, counter + 2, counter + 3};
            counter += 10;
        }
    }
}

bool flight::isValid(int seatNum)
{
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            for (int j = 0; j < 2; j++)
            {
                if (seatNum == seats[i][j].getSeat())
                {
                    return 1;
                }
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (seatNum == seats[i][j].getSeat())
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool flight::reserve(int seatNum)
{
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            for (int j = 0; j < 2; j++)
            {
                if (seats[i][j].getSeat() == seatNum)
                {
                    if (seats[i][j].getReservation() == false)
                    {
                        seats[i][j].setReserve(true);
                        return 1;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (seats[i][j].getSeat() == seatNum)
                {
                    if (seats[i][j].getReservation() == false)
                    {
                        seats[i][j].setReserve(true);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

bool flight::cancelreservation(int seatNum)
{
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            for (int j = 0; j < 2; j++)
            {
                if (seats[i][j].getSeat() == seatNum)
                {
                    if (seats[i][j].getReservation() == true)
                    {
                        seats[i][j].setReserve(false);
                        return 1;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (seats[i][j].getSeat() == seatNum)
                {
                    if (seats[i][j].getReservation() == true)
                    {
                        seats[i][j].setReserve(false);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void flight::cancelAllReservations()
{
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            for (int j = 0; j < 2; j++)
            {
                if (seats[i][j].getReservation() == true)
                {
                    seats[i][j].setReserve(false);
                }
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (seats[i][j].getReservation() == true)
                {
                    seats[i][j].setReserve(false);
                }
            }
        }
    }
}

int flight::seatsInfo()
{
    int amountOfReserevedSeats = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i < first_three_rows)
        {
            cout << "\t\t\t\t ";
            for (int j = 0; j < 2; j++)
            {
                if (seats[i][j].getReservation() == true)
                {
                    amountOfReserevedSeats++;
                }
                seats[i][j].printInfo();
            }
            cout << "\n"
                 << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (seats[i][j].getReservation() == true)
                {
                    amountOfReserevedSeats++;
                }
                seats[i][j].printInfo();
            }
            cout << "\n"
                 << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    return amountOfReserevedSeats;
}