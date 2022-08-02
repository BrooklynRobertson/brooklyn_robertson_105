// brooklyn_robertson_105.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Task1.h"


class Yacht {
   
private:
    int serialNumber;
    int yachtCount{ 0 };
    Location latitude, longitude;
    

public:

    Yacht(int serialNumber) {
        Yacht::serialNumber = serialNumber;
    };

std::string get_pos() {

    }
    void display(Location latitude, Location longitude) {
        std::cout << "Yacht serial number: " << serialNumber <<
            "\t Yacht Location: ";

    }
};

class Location : public Yacht {
private:
    //member variables
    int degrees;
    float minutes;
    char direction;

    ////lat and long vactors to store
    //std::vector<std::string> latitude;
    //std::vector<std::string> longitude;

public:
    Location latitude, longitude;
    Location(int degrees, float minutes, char direction) {
        degrees = this->degrees;
        minutes = this->minutes;
        direction = this->direction;
    };
    //get latitude & longitude position (degree, minutes and direction) from user
        void getpos() {
        std::cout << "Please enter degrees: (between 0-180)\n";
        std::cin >> degrees;

        std::cout << "Please enter minutes: (0-60)\n";
        std::cin >> minutes;
        if (degrees < 90 || degrees == 0) {
            std::cout << "Please enter 'N' for North or 'S' for South: \n";
            std::cin >> direction;

            latitude.push_back(std::to_string(degrees));//add to latitude vector
            latitude.push_back("\xF8");//add degree character
            latitude.push_back(std::to_string(minutes)); //add minutes to lat vector
            latitude.push_back("\x27");//add apostrophe character

            //figure out whether to use N or S
            switch (toupper(direction)) {
            case 'N':
                latitude.push_back(" N");
                break;
            case 'S':
                latitude.push_back(" S");
                break;
            default:
                latitude.push_back(std::to_string(direction));//if all else fails, add what user said.
                break;
            }
        }
        else {
            std::cout << "Latitude must be 0 - 89\xF8..... \n";
        }

        /*if (degrees < 0  || degrees > 180) {
            std::cout << "number must be or be between 0 and 180!\n";
        }
        else {
            if (degrees == 0 || degrees <= 90) {
                latitude = degrees;
            else if (degrees == 180 || degrees > 90) {
                longitude = degrees;
            }
            }
        }*/
        /*std::cout << "Please enter direction: ('N','S','E' or 'W')\n";
        std::cin >> direction;
        switch (std::tolower(direction)) {
        case 'n':
            compassDirection = Direction::N;
            break;
        case 's':
            compassDirection = Direction::S;
        case 'e':
            compassDirection = Direction::E;
            break;
        case 'w':
            compassDirection = Direction::W;
            break;
        default:
            break;
        }*/
        std::cout << "Coordinates recorded.....\n";
    }

};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
