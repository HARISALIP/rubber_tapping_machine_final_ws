
// Define the pins for the motors
const int MOTOR1_CLOCKWISE_PIN = 33;
const int MOTOR1_COUNTERCLOCKWISE_PIN = 32;
const int DC_MTR2_CW = 25;
const int DC_MTR2_CW_CCW = 27;

const int BUTTN_1 =4;
const int BUTTN_2 =5;


void setup() {
//  Serial.begin(115200);
  pinMode(MOTOR1_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR1_COUNTERCLOCKWISE_PIN, OUTPUT);
  pinMode(DC_MTR2_CW, OUTPUT);
  pinMode(DC_MTR2_CW_CCW, OUTPUT);
  pinMode(BUTTN_1, INPUT_PULLUP);
  pinMode(BUTTN_2, INPUT_PULLUP);

  digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
  digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, HIGH);
  
}

void loop() {
  
  if (digitalRead(BUTTN_1) == LOW) {
    delay(1000);
    digitalWrite(MOTOR1_CLOCKWISE_PIN, LOW);
    delay(5000);
    digitalWrite(MOTOR1_CLOCKWISE_PIN, HIGH);
    delay(2000); 
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN, LOW);
    delay(5000);
    digitalWrite(MOTOR1_COUNTERCLOCKWISE_PIN_PIN, HIGH);
    delay(2000); 
    digitalWrite(DC_MTR2_CW, HIGH);
    delay (2000)
    digitalWrite(DC_MTR2_CW, LOW);
}
  if (digitalRead(BUTTN_2) == LOW) {
    digitalWrite(DC_MTR2_CCW, HIGH);
    delay(5000);
    digitalWrite(DC_MTR2_CCW, LOW);
     
}
}
