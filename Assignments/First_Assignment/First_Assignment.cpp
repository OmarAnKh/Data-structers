#include <iostream>
#include <string>
using namespace std;

class seat
{
private:
    int seatNumber;
    bool reserved;

public:
    seat(int seat);
    ~seat();
    int getSeat();
    void setReserve(bool reservation);
    bool getReservation();
    void printInfo();
};

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
void reserve(flight &a);
void deleteReserve(flight &a);
void cancelAllReservations(flight &a);
void showAllSeats(flight a);

int main()
{
    int operation;
    flight trip;
    do
    {
        cout << endl;
        cout << "what is the operation you want to make:" << endl;
        cout << "1-Reserve a newly empty seat." << endl;
        cout << "2-Delete a reserved seat." << endl;
        cout << "3-Delete all reserved seats." << endl;
        cout << "4-Print out flight seats map." << endl;
        cout << "5-Quit" << endl;
        cin >> operation;
        switch (operation)
        {
        case 1:
            reserve(trip);
            break;
        case 2:
            deleteReserve(trip);
            break;
        case 3:
            cancelAllReservations(trip);
            break;
        case 4:
            showAllSeats(trip);
            break;
        default:
            break;
        }
    } while (operation != 5);
}

void reserve(flight &a)
{
    cout << "enter the seat number";
    int seatNum;
    cin >> seatNum;
    while (!a.isValid(seatNum))
    {
        cout << "please re-enter a valid seat number";
        cin >> seatNum;
    }
    while (!a.reserve(seatNum))
    {
        cout << "We are sorry the seat you are trying to reserve has already been taken try another one";
        cin >> seatNum;
        while (!a.isValid(seatNum))
        {
            cout << "please re-enter a valid seat number";
            cin >> seatNum;
        }
    }
}

void deleteReserve(flight &a)
{
    cout << "please enter the seat number you want to cancel the reservation for";
    int seatNum;
    cin >> seatNum;
    while (!a.isValid(seatNum))
    {

        cout << "please enter the seat number you want to cancel the reservation for";
        cin >> seatNum;
    }
    while (!a.cancelreservation(seatNum))
    {
        cout << "We are sorry the seat you are trying to cancel reservation for is not reserved";
        cin >> seatNum;
        while (!a.isValid(seatNum))
        {
            cout << "please re-enter a valid seat number";
            cin >> seatNum;
        }
    }
}

void cancelAllReservations(flight &a)
{
    a.cancelAllReservations();
}

void showAllSeats(flight a)
{
    int amountOfReservedSeats = a.seatsInfo();
    cout << "there is " << amountOfReservedSeats << " reserved seats";
}

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

seat::seat(int seat)
{
    this->seatNumber = seat;
    this->reserved = false;
}

seat::~seat()
{
}
int seat::getSeat()
{
    return this->seatNumber;
}
bool seat::getReservation()
{
    return this->reserved;
}
void seat::printInfo()
{
    string Reservation = (this->reserved) ? "reserved" : "empty";
    cout << "number: " << this->seatNumber << " "
         << "the seat is:" << Reservation
         << "     ";
}

void seat::setReserve(bool reservation)
{
    reserved = reservation;
}