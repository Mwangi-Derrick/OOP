#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class with common attributes and methods
class User {
    protected:
        string userID;
        string password;
        string phone;
        string email;
        bool isLoggedIn;
    
    public:
        // Constructor
        User(string uuid, string pwd, string ph, string em) {
            userID = uuid;
            password = pwd;
            phone = ph;
            email = em;
            isLoggedIn = false;
        }
        
        // Virtual destructor for proper cleanup in inheritance
        virtual ~User() {}
        
        void login(string pwd) {
            if (pwd == password) {
                isLoggedIn = true;
                cout << userID << " logged in successfully!" << endl;
            } else {
                cout << "Invalid password!" << endl;
            }
        }
        
        void logout() {
            if (isLoggedIn) {
                isLoggedIn = false;
                cout << userID << " logged out." << endl;
            }
        }
        
        void updateProfile(string ph, string em) {
            phone = ph;
            email = em;
            cout << "Profile updated for " << userID << endl;
        }
        
        void displayInfo() {
            cout << "\nUser ID: " << userID << endl;
            cout << "Phone: " << phone << endl;
            cout << "Email: " << email << endl;
            cout << "Status: " << (isLoggedIn ? "Logged In" : "Logged Out") << endl;
        }
        
        // Getters
        string getUserID() { return userID; }
        bool getLoginStatus() { return isLoggedIn; }
};

// Ride class to represent a ride
class Ride {
    private:
        string rideID;
        string passengerID;
        string riderID;
        string pickup;
        string dropoff;
        double fare;
        string status; // "REQUESTED", "ACCEPTED", "COMPLETED", "CANCELLED"
    
    public:
        Ride(string rId, string pId, string pick, string drop, double f) {
            rideID = rId;
            passengerID = pId;
            riderID = "";
            pickup = pick;
            dropoff = drop;
            fare = f;
            status = "REQUESTED";
        }
        
        void displayRide() {
            cout << "\nRide ID: " << rideID << endl;
            cout << "Passenger: " << passengerID << endl;
            if (!riderID.empty()) cout << "Rider: " << riderID << endl;
            cout << "From: " << pickup << " To: " << dropoff << endl;
            cout << "Fare: $" << fare << endl;
            cout << "Status: " << status << endl;
        }
        
        // Getters and setters
        string getRideID() { return rideID; }
        string getStatus() { return status; }
        void setRider(string rId) { riderID = rId; }
        void acceptRide(string rId) { 
            riderID = rId; 
            status = "ACCEPTED";
        }
        void completeRide() { status = "COMPLETED"; }
        void cancelRide() { status = "CANCELLED"; }
};

// Passenger class inherits from User
class Passenger : public User {
    private:
        vector<Ride> myRides;
        double walletBalance;
    
    public:
        Passenger(string uuid, string pwd, string ph, string em) 
            : User(uuid, pwd, ph, em) {
            walletBalance = 0.0;
        }
        
        // Passenger specific methods
        void addFunds(double amount) {
            walletBalance += amount;
            cout << "Added $" << amount << " to wallet. New balance: $" << walletBalance << endl;
        }
        
        Ride requestRide(string rideId, string pickup, string dropoff, double fare) {
            if (!isLoggedIn) {
                cout << "Please login first!" << endl;
                return Ride("", "", "", "", 0);
            }
            
            if (walletBalance < fare) {
                cout << "Insufficient balance! Please add funds." << endl;
                return Ride("", "", "", "", 0);
            }
            
            Ride newRide(rideId, userID, pickup, dropoff, fare);
            myRides.push_back(newRide);
            walletBalance -= fare;
            
            cout << "Ride requested successfully!" << endl;
            newRide.displayRide();
            return newRide;
        }
        
        void cancelRide(string rideId) {
            for (auto &ride : myRides) {
                if (ride.getRideID() == rideId && ride.getStatus() == "REQUESTED") {
                    ride.cancelRide();
                    walletBalance += 50; // Refund (example amount)
                    cout << "Ride " << rideId << " cancelled. Refund processed." << endl;
                    return;
                }
            }
            cout << "Ride not found or cannot be cancelled!" << endl;
        }
        
        void viewMyRides() {
            cout << "\n=== " << userID << "'s Ride History ===" << endl;
            if (myRides.empty()) {
                cout << "No rides yet." << endl;
                return;
            }
            for (auto &ride : myRides) {
                ride.displayRide();
            }
        }
        
        double getBalance() { return walletBalance; }
};

// Rider class inherits from User
class Rider : public User {
    private:
        vector<Ride> assignedRides;
        string vehicleNumber;
        string vehicleModel;
        double rating;
        bool isAvailable;
    
    public:
        Rider(string uuid, string pwd, string ph, string em, string vNum, string vModel) 
            : User(uuid, pwd, ph, em) {
            vehicleNumber = vNum;
            vehicleModel = vModel;
            rating = 5.0;
            isAvailable = true;
        }
        
        // Rider specific methods
        void acceptRide(Ride &ride) {
            if (!isLoggedIn) {
                cout << "Please login first!" << endl;
                return;
            }
            
            if (!isAvailable) {
                cout << "You are currently not available for rides!" << endl;
                return;
            }
            
            ride.acceptRide(userID);
            assignedRides.push_back(ride);
            isAvailable = false;
            
            cout << "Ride " << ride.getRideID() << " accepted!" << endl;
        }
        
        void completeRide(Ride &ride) {
            if (ride.getStatus() == "ACCEPTED") {
                ride.completeRide();
                isAvailable = true;
                cout << "Ride " << ride.getRideID() << " completed!" << endl;
            }
        }
        
        void updateAvailability(bool available) {
            isAvailable = available;
            cout << "Availability set to: " << (available ? "Available" : "Not Available") << endl;
        }
        
        void viewEarnings() {
            double totalEarnings = assignedRides.size() * 50; // Example calculation
            cout << "\n=== Earnings for " << userID << " ===" << endl;
            cout << "Total Rides: " << assignedRides.size() << endl;
            cout << "Total Earnings: $" << totalEarnings << endl;
            cout << "Rating: " << rating << "/5.0" << endl;
        }
        
        void displayRiderInfo() {
            displayInfo();
            cout << "Vehicle: " << vehicleModel << " (" << vehicleNumber << ")" << endl;
            cout << "Availability: " << (isAvailable ? "Available" : "On a Ride") << endl;
        }
};

// Main function to demonstrate the system
int main() {
    // Create a passenger
    Passenger passenger("P001", "pass123", "555-0101", "john@email.com");
    passenger.login("pass123");
    passenger.addFunds(100);
    
    // Create a rider
    Rider rider("R001", "ride456", "555-0202", "jane@email.com", "ABC-123", "Toyota Camry");
    rider.login("ride456");
    rider.displayRiderInfo();
    
    cout << "\n=== Ride Booking Demo ===" << endl;
    
    // Passenger requests a ride
    Ride ride1 = passenger.requestRide("RIDE001", "Home", "Airport", 45.50);
    
    // Rider accepts the ride
    if (ride1.getRideID() != "") {
        rider.acceptRide(ride1);
        
        // Complete the ride
        rider.completeRide(ride1);
    }
    
    // View passenger's ride history
    passenger.viewMyRides();
    
    // View rider's earnings
    rider.viewEarnings();
    
    return 0;
}