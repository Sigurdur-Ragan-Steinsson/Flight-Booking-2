#include <iostream>
#include <string>


using namespace std; 

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
private:
  int id;
  int capacity;
  int reserved;
  float percentOver;
  float maxCapacity;
};

FlightBooking::FlightBooking(int inputId, int inputCapacity, int inputReserved)
{
  id = inputId;
  capacity = inputCapacity;
  percentOver = 1.05;
  maxCapacity = percentOver * capacity;
  
  if((inputReserved < maxCapacity) && (inputReserved > 0))
    reserved = inputReserved;
  else if (inputReserved >= maxCapacity)
  {
    reserved = maxCapacity;
    reserved++;}
    
  else
    reserved = 0;
    
}

void FlightBooking::printStatus()
{
  //cout << "reserved = " << reserved << endl;
  cout << "Flight " << id << " : " << reserved <<  "/" <<  capacity << "(" << (reserved * 1.0) / capacity * 100 << "%)" << "seats taken";
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
  if(reserved + number_of_seats <= maxCapacity){
    reserved += number_of_seats;
    return true;
  }
  else{
    cout << "Cannot perform this operation" << endl;
    return false;
    }
  // try to add reservations and return 'true' on success
  // keep the limits in mind
}
bool FlightBooking::cancelReservations(int number_of_seats)
{
  //max and min may be different, (ex. max reserve iirc is 110% of capacity) so go back, check and then fix
  if(reserved - number_of_seats >= 0){
    reserved -= number_of_seats;
    return true;
  }
  else{
    cout << "Cannot perform this operation" << endl;
    return false;
    }
  // try to canel reservations and return 'true' on success
  // keep the limits in mind
}
int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;
  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;
  FlightBooking booking(1, capacity, reserved);
  std::string command = "";
  while (command != "quit")
  {
    booking.printStatus();
    cout << endl;
    std::cout << "What would you like to do?: ";
    getline(cin,command);
    if(command.find("add") < command.length()){
      booking.reserveSeats(stoi(command.substr(command.find(' '))));
    }
    if(command.find("cancel") < command.length()){
      booking.cancelReservations(stoi(command.substr(command.find(' '))));
    }
    // handle the command
  }
  return 0;
}