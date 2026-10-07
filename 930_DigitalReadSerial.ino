
const int pushButton = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int buttonState = 0;
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor="led";
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.print("Current Color: ");
  Serial.println(currentcolor);
  //delay(1);  // delay in between reads for stability
  if (buttonState == HIGH && !ButtonPressed){
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }
  if (ledcolor == 0){
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  } 
  else if (ledcolor == 1) {
    currentcolor = "Red";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2) {
    currentcolor = "Green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3) {
    currentcolor = "Blue";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 4) {
    currentcolor = "Yellow";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5) {
    currentcolor = "Purple";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6) {
    currentcolor = "Cyan";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 7) {
    currentcolor = "White";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 8) {
    ledcolor = 0;
  }
  delay(100);
}
