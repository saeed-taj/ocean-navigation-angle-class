#include <iostream>
#include <iomanip>  // For setprecision and fixed
using namespace std;

class Angle {

private:
    
    int degrees;
    float minutes;
    char direction; // 'N', 'S', 'E', 'W'

public:

    // Constructor with three arguments
    Angle(int deg = 0, float min = 0.0, char dir = 'N') : degrees(deg), minutes(min), direction(dir) {}

    // Member function to input angle values
    void getAngle() {
        
        do {
        
        cout << "Enter degrees between 0 to 180 : ";
        cin >> degrees;
        
        if (degrees < 0 || degrees > 180)
        cout << "Error : invalid input : Enter degrees from 0 to 180" << endl; 
        
        }
           while (degrees < 0 || degrees > 180);
        
        do {
        
        cout << "Enter minutes from 0 to 60 : ";
        cin >> minutes;
        
        if(minutes < 0 || minutes > 60)
        cout << "Error : Invalid : Enter minutes from 0 to 60 " << endl; 
      }
      while (minutes < 0 || minutes > 60);  
        
       
        do{
    
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
         
         direction = toupper(direction);  // to convert from lowercase to the uppercase 
        
        if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W')
        cout <<"Error : Invalid input : Enter correct direction" << endl;
        
        }

        while (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W');

    }

    // Member function to display angle in 179°59.9' E format
    void displayAngle() const {
        
        cout << degrees << '\xF8' << fixed << setprecision(1) << minutes << "' " << direction << endl;
    
    }

};

int main() {
    
    // Initialize an angle using the constructor
    Angle angle1(149, 34.8, 'W');
    
    cout << "Initialized angle: ";
    
    angle1.displayAngle();

    // Input and display angles in a loop
    
    char choice;
    
    do {
        Angle angle;
        angle.getAngle();
    
        cout << "Entered angle: ";
        angle.displayAngle();

        cout << "Do you want to enter another angle? (y/n): ";
        cin >> choice;
    }
    
     while (choice == 'y' || choice == 'Y');

    return 0;
}
