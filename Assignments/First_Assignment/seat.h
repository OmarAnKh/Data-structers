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
    cout<< "number: " << this->seatNumber << " "
        << "the seat is:" << Reservation
        << "     ";
}

void seat::setReserve(bool reservation)
{
    reserved = reservation;
}