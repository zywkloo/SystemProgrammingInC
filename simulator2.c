#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
/*takes no parameters and returns a char *.
 * The function should generate a random license plate with the format "XXX ###" where X is a random character
 * from A to Z and # is a random digit from 0 to 9.*/

char* randomPlate(){
    char* plate;
    plate = (char*)malloc(8* sizeof(char));
    for(int i=0; i<3;++i){
        plate[i]= (char)(65+rand()%26);
    }
    plate[3]=' ';
    for(int j=4; j<7;++j){
        plate[j]= (char)(48+rand()%10);
    }
    plate[7]='\0';
    return plate;

}

/*takes no parameters and returns a char *.
 * The function should generate a random license plate with the format "XXX ###" where X is a random character
 * from A to Z and # is a random digit from 0 to 9.*/
Car* randomCar(){
    Car * newCar;
    newCar =(Car *) malloc(sizeof(Car));
    initializeCar(newCar, randomPlate(), (char)(rand()%2));
    return newCar;
}


int main() {
    static int seed = 2;
    srand(time(NULL) + seed* seed);
    Car* carArr[50];
    ParkingLot* lotArr[5];

    for (int i=0;i<50;i++){
        carArr[i]=randomCar();  // assign dynamically generated Car pointer to each array index
        printf("Car %s with permit %d\n",carArr[i]->plateNumber,carArr[i]->permit);  //display car info
    }

    printf("\n");
    for (int j=0;j<5;j++){
        lotArr[j] = (ParkingLot*) malloc(sizeof(ParkingLot)); //dynamic allocate new pointers for Parking lot
        initializeLot(lotArr[j], j+1, 5*(j+1), (double) (j+4), (double) (j+6)*2);  //init parking lots
        printLotInfo(*lotArr[j]);  //print Parking lot info
    }

    printf("\n");// Car enter one by one
    for (int i=0;i<50;i++){
        carEnters(lotArr[rand()%5],carArr[i] , 6+i/12, i%12 *5);  //random enter one of 5 parkingLots
    }

    printf("\n"); // After all cars entered print lot info
    for (int j=0;j<5;j++){
        printLotInfo(*lotArr[j]);
    }

    printf("\n");// Car enter one by one
    for (int i=0;i<50;i++){
        int LotNumber = carArr[i]->lotParkedIn;
        if ( LotNumber!=0) carLeaves(lotArr[LotNumber-1],carArr[i] , 11+i/12, i%12 *5);  //if a car parked, leave after 11:00
    }

    printf("\n");//  print revenues one by one
    for (int j=0;j<5;j++){
        printf("Total revenue of Lot %d is $%4.2f\n",j+1 ,lotArr[j]->revenue);
    }
    // free dynamical Car pointers
    for (int i=0;i<50;i++){
        free(carArr[i]);
    }
    // free dynamical Parking lot pointers
    for (int i=0;i<5;i++){
        free(lotArr[i]);
    }
}

