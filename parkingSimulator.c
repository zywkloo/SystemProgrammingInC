#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char* plateNumber;
    char permit;
    Time enteringTime;
    int lotParkedIn;
} Car;

typedef struct  {
    int lotNumber;  //ParkingLot unique ID,
    double hourlyRate;  //a car owner would pay per hour to be parked in that lot,
    double maxCharge;   //the maximum amount that the car owner would pay to park the car for the day
    int capacity; // representing the maximum number of cars that can park in that lot,
    int currentCarCount;// indicating the number of cars currently parked in the lot, and finally a
    double revenue; // (a double) that keeps track of the amount of money taken in by that lot so far.
} ParkingLot;

// Sets the hours and minutes amount for the given time t based 
// on the specified hours h.  (e.g., 1.25 hours would be 1 hour 
// and 15 minutes)
void setHours(Time *t, double h) {
    t->hour = (int)h;
    t->minute = (int) ( (h - floor(h)) *60);

}

// Takes two Time objects (not pointers) and computes the difference 
// in time from t1 to t2 and then stores that difference in the diff 
// Time (which must be a pointer)
void difference(Time t1, Time t2, Time *diff) {
    double h1 = (double) t1.hour + t1.minute/60.0;
    double h2 = (double) t2.hour + t2.minute/60.0;
    setHours(diff,fabs(h1-h2));
}


// Initialize the car pointed to by c to have the given plate and 
// hasPermit status.  The car should have it’s lotParkedIn set to 
// 0 and enteringTime to be -1 hours and -1 minutes.
void initializeCar(Car *c, char *plate, char hasPermit) {
    c->plateNumber=plate;
    c->permit=hasPermit;
    c->enteringTime.hour= -1;
    c->enteringTime.minute= -1;
    c->lotParkedIn=0;

}


// Initialize the lot pointed to by p to have the given number, 
// capacity, hourly rate and max charge values.  The currentCarCount 
// and revenue should be at 0.
void initializeLot(ParkingLot *p, int num, int cap, double rate, double max) {
    p->lotNumber=num;
    p->capacity=cap;
    p->hourlyRate=rate;
    p->maxCharge=max;
    p->currentCarCount=0;
    p->revenue=0;


}

// Print out the parking lot parameters so that is displays as 
// follows:   Parking Lot #2 - rate = $3.00, capacity 6, current cars 5
void printLotInfo(ParkingLot p) {
    printf("Parking Lot #%d - rate = $%0.2lf, capacity %d, current cars %d.\n",
            p.lotNumber,p.hourlyRate,p.capacity,p.currentCarCount);
}


// Simulate a car entering the parking lot
// ...
void carEnters(ParkingLot * p, Car *c , int hour , int time){
    if (p->currentCarCount >= p->capacity) {
        printf("Car %s arrives at Lot %d at %d:%02d, but the lot is full.\n",c->plateNumber,p->lotNumber,hour,time);
        printf("Car %s cannot get in.\n",c->plateNumber);
    } else {
        c->enteringTime.hour=hour ;
        c->enteringTime.minute=time ;
        c->lotParkedIn = p->lotNumber;
        printf("Car %s enters Lot %d at %d:%02d.\n",c->plateNumber,p->lotNumber,hour,time);
        p->currentCarCount +=1;
    }
};

// Simulate a car leaving the parking lot
// ...
void carLeaves(ParkingLot * p, Car *c , int hour , int time){
    if (c->lotParkedIn != p->lotNumber){
        printf("Are you serious?Car %s didn't park at Lot %d .\n",c->plateNumber,p->lotNumber);
    } else {
        if (c->permit !=1 ) {
            //revenue calculation
            Time leaveTime = {hour, time};
            Time diff ={0,0};
            difference(leaveTime, c->enteringTime, &diff);
            double charge = ((diff.minute==0?0:1) + diff.hour) * (p->hourlyRate);
            charge = (charge > p->maxCharge) ? (p->maxCharge) : charge;
            p->revenue += charge;
            printf("Car %s leaves Lot %d at %d:%02d ",c->plateNumber,p->lotNumber,hour,time);
            printf("paid $%.2lf.\n",charge);
        } else {
            printf("Car %s leaves Lot %d at %d:%02d.\n",c->plateNumber,p->lotNumber,hour,time);
        }
        //clean Car status
        c->enteringTime.hour=-1 ;
        c->enteringTime.minute=-1 ;
        c->lotParkedIn = 0;
        p->currentCarCount -=1;

    }

};

int main() {
  Car  car1, car2, car3, car4, car5, car6, car7, car8, car9;
  ParkingLot p1, p2;

  // Set up 9 cars
  initializeCar(&car1, "ABC 123", 0);
  initializeCar(&car2, "ABC 124", 0);
  initializeCar(&car3, "ABD 314", 0);
  initializeCar(&car4, "ADE 901", 0); 
  initializeCar(&car5, "AFR 304", 0);
  initializeCar(&car6, "AGD 888", 0); 
  initializeCar(&car7, "AAA 111", 0);
  initializeCar(&car8, "ABB 001", 0); 
  initializeCar(&car9, "XYZ 678", 1);

  // Set up two parking lots
  initializeLot(&p1, 1, 4, 5.5, 20.0);
  initializeLot(&p2, 2, 6, 3.0, 12.0);

  printLotInfo(p1); 
  printLotInfo(p2);
  printf("\n"); 

  // Simulate cars entering the lots
  carEnters(&p1, &car1, 7, 15); 
  carEnters(&p1, &car2, 7, 25); 
  carEnters(&p2, &car3, 8,  0); 
  carEnters(&p2, &car4, 8, 10); 
  carEnters(&p1, &car5, 8, 15); 
  carEnters(&p1, &car6, 8, 20); 
  carEnters(&p1, &car7, 8, 30); 
  carEnters(&p2, &car7, 8, 32); 
  carEnters(&p2, &car8, 8, 50); 
  carEnters(&p2, &car9, 8, 55); 

  printf("\n");
  printLotInfo(p1);
  printLotInfo(p2);
  printf("\n"); 

  // Simulate cars leaving the lots
  carLeaves(&p2, &car4, 9, 0); 
  carLeaves(&p1, &car2, 9, 5); 
  carLeaves(&p1, &car6, 10, 0); 
  carLeaves(&p1, &car1, 10, 30); 
  carLeaves(&p2, &car8, 13, 0); 
  carLeaves(&p2, &car9, 15, 15); 
  carEnters(&p1, &car8, 17, 10); 
  carLeaves(&p1, &car5, 17, 50); 
  carLeaves(&p2, &car7, 18, 0); 
  carLeaves(&p2, &car3, 18, 15); 
  carLeaves(&p1, &car8, 20, 55);

  printf("\n");
  printLotInfo(p1);
  printLotInfo(p2);
  printf("\n"); 

  // Display the total revenue
  printf("Total revenue of Lot 1 is $%4.2f\n", p1.revenue); 
  printf("Total revenue of Lot 2 is $%4.2f\n", p2.revenue);
}

