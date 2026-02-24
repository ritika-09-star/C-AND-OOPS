#include <iostream>
using namespace std;

class Hotel
{
public:
    virtual void bookRoom() = 0;
    virtual void generateBill() = 0;
    virtual ~Hotel() {}
};

class RoomBooking : public Hotel
{
private:
    string guestName;
    int roomNumber;
    int roomTypeChoice;
    int numberOfRooms;
    int numberOfPeople;
    int days;
    float roomRate;
    float extraServiceCharges;
    float totalBill;

    // Room Counters
    static int singleRoomCounter;
    static int standardRoomCounter;
    static int deluxeRoomCounter;
    static int suiteRoomCounter;
    static int presidentialRoomCounter;

    // Room Availability
    static int singleAvailable;
    static int standardAvailable;
    static int deluxeAvailable;
    static int suiteAvailable;
    static int presidentialAvailable;

public:
    void bookRoom()
    {
        cout << "=====================================\n";
        cout << "        GRAND PALACE HOTEL\n";
        cout << "=====================================\n";

        cout << "Enter Guest Name: ";
        cin >> guestName;

        while (true)
        {
            cout << "\nSelect Room Type:\n";
            cout << "1. Single (800 per day)\n";
            cout << "2. Standard (1000 per day)\n";
            cout << "3. Deluxe (2000 per day)\n";
            cout << "4. Suite (3500 per day)\n";
            cout << "5. Presidential (5000 per day)\n";
            cout << "Enter Choice (1-5): ";
            cin >> roomTypeChoice;

            if (roomTypeChoice >= 1 && roomTypeChoice <= 5)
                break;
            else
                cout << "Invalid choice! Please enter between 1 and 5.\n";
        }

        bool available = true;

        switch (roomTypeChoice)
        {
        case 1:
            if (singleAvailable > 0)
            {
                roomRate = 800;
                roomNumber = singleRoomCounter++;
                singleAvailable--;
            }
            else
            {
                cout << "Single Rooms are not available!\n";
                available = false;
            }
            break;

        case 2:
            if (standardAvailable > 0)
            {
                roomRate = 1000;
                roomNumber = standardRoomCounter++;
                standardAvailable--;
            }
            else
            {
                cout << "Standard Rooms are not available!\n";
                available = false;
            }
            break;

        case 3:
            if (deluxeAvailable > 0)
            {
                roomRate = 2000;
                roomNumber = deluxeRoomCounter++;
                deluxeAvailable--;
            }
            else
            {
                cout << "Deluxe Rooms are not available!\n";
                available = false;
            }
            break;

        case 4:
            if (suiteAvailable > 0)
            {
                roomRate = 3500;
                roomNumber = suiteRoomCounter++;
                suiteAvailable--;
            }
            else
            {
                cout << "Suite Rooms are not available!\n";
                available = false;
            }
            break;

        case 5:
            if (presidentialAvailable > 0)
            {
                roomRate = 5000;
                roomNumber = presidentialRoomCounter++;
                presidentialAvailable--;
            }
            else
            {
                cout << "Presidential Room is not available!\n";
                available = false;
            }
            break;
        }

        if (!available)
            return;

        cout << "Room Number: " << roomNumber << endl;

        cout << "Enter Number of Rooms: ";
        cin >> numberOfRooms;

        cout << "Enter Number of People: ";
        cin >> numberOfPeople;

        cout << "Enter Number of Days: ";
        cin >> days;

        cout << "Enter Extra Service Charges: ";
        cin >> extraServiceCharges;

        cout << "\nRoom Booked Successfully!\n";
    }

    void generateBill()
    {
        totalBill = (roomRate * numberOfRooms * days) + extraServiceCharges;

        cout << "\n=====================================\n";
        cout << "        GRAND PALACE HOTEL\n";
        cout << "=====================================\n";

        cout << "\n========== HOTEL BILL ==========\n";
        cout << "Guest Name: " << guestName << endl;
        cout << "Room Number: " << roomNumber << endl;

        cout << "Room Type: ";
        if (roomTypeChoice == 1) cout << "Single\n";
        else if (roomTypeChoice == 2) cout << "Standard\n";
        else if (roomTypeChoice == 3) cout << "Deluxe\n";
        else if (roomTypeChoice == 4) cout << "Suite\n";
        else if (roomTypeChoice == 5) cout << "Presidential\n";

        cout << "Number of Rooms: " << numberOfRooms << endl;
        cout << "Number of People: " << numberOfPeople << endl;
        cout << "Days Stayed: " << days << endl;
        cout << "Room Charges: " << roomRate * numberOfRooms * days << endl;
        cout << "Extra Charges: " << extraServiceCharges << endl;
        cout << "Total Bill: " << totalBill << endl;
        cout << "=====================================\n";
    }
};

// Static Member Initialization
int RoomBooking::singleRoomCounter = 302;
int RoomBooking::standardRoomCounter = 421;
int RoomBooking::deluxeRoomCounter = 153;
int RoomBooking::suiteRoomCounter = 309;
int RoomBooking::presidentialRoomCounter = 251;

int RoomBooking::singleAvailable = 5;
int RoomBooking::standardAvailable = 5;
int RoomBooking::deluxeAvailable = 3;
int RoomBooking::suiteAvailable = 0;
int RoomBooking::presidentialAvailable = 1;

int main()
{
    Hotel* booking;
    RoomBooking rb;

    booking = &rb;

    booking->bookRoom();
    booking->generateBill();

    return 0;
}
