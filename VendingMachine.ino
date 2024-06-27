#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#include <DHT.h>
#include <EEPROM.h>

#define counterPin 18 
#define coinPin 19
#define buzzer1 40
#define buzzer2 49
#define waterlevel A0
#define relays 14
#define button1 39
#define DHTPIN 32
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const byte ROWS = 4;
const byte COLS = 4;
const byte rowPins[ROWS] = {A1, A2, A3, A4};
const byte colPins[COLS] = {A5, A6, A7, A8};

const int servos[] = {3, 2, 4, 44, 46};
Servo myservo[5];

struct ProductData {
    String ProductName;
    float ProductPrice;
    float ProductQuantity;
    bool isProductEmpty;
};

ProductData product[5];

struct exhaustFan {
    int pwmPin;
    int signalPin;
};

exhaustFan externalFans[4] = {
    {5, 10},
    {6, 11},
    {7, 12},
    {8, 13}
};

const int leds[] = {48, 50, 52, 47, 53};
int waterLed = 51;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 20, 4);

//Glabal Variables
int currentState = 0;
int change_products = 0;
int prodKey = -1;
int restartPicking = 0;
int beforeState = -1;
int changingInstruction = 0;
int checkStartPeso = 0;
int passwordSetter = 0;
String setPass = "";
String password = "2024";
bool login = false;
bool resetPass = false;
int showPeso = -1;
int showOnce = 0;
int deleteKey = -1;
//Millis
unsigned long idle_millis = 0;
unsigned long selected_millis = 0;
unsigned long peso_millis = 0;

volatile int TotalPeso = 0;  
unsigned long lastDebounceTime = 0; 
const unsigned long debounceDelay = 50; 
