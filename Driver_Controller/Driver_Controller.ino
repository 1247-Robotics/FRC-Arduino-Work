const int button = 2;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Joystick.begin();
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH){
    Joystick.setButton(0,1);
  } else{
    Joystick.setButton(0,0);
  }
  delay(10);
}
