#include <LiquidCrystal.h>

#define TANK_DRIVE 0
#define ARCADE_DRIVE 1

#define JOYSTICK 0
#define XBOX 1

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int driveModeButton = 2;
const int controllerButton = 3;

int driveMode = TANK_DRIVE;
int controller = JOYSTICK;

void setup() {
  // put your setup code here, to run once:
  Joystick.begin();
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" Team 1247 GO!! ");
  
  pinMode(driveModeButton, INPUT);
  pinMode(controllerButton, INPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  driveMode = digitalRead(driveModeButton);
  controller = digitalRead(controllerButton);
  
  if (driveMode == ARCADE_DRIVE){
    Joystick.setButton(0,1);
    lcd.setCursor(0, 0);
    lcd.print("  Arcade Drive  ");
  } else{
    Joystick.setButton(0,0);
    lcd.setCursor(0, 0);
    lcd.print("   Tank Drive   ");
  }
  
  if (controller == XBOX){
    Joystick.setButton(1,1);
    lcd.setCursor(0, 1);
    lcd.print(" XBOX Controller");
  } else{
    Joystick.setButton(1,0);
    lcd.setCursor(0, 1);
    lcd.print("    Joystick    ");
  }
  delay(10);
}
