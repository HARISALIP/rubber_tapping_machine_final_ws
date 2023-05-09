
// Define the pins for the motors
const int MTR1_CW_PIN = 33;
const int MTR1_CCW_PIN = 32;

const int DC_MTR2_CW = 25;
const int DC_MTR2_CCW = 26;

const int BUTTN_1 =4;
const int BUTTN_2 =5;


void setup() {
  Serial.begin(115200);
  
  pinMode(MTR1_CW_PIN, OUTPUT);
  pinMode(MTR1_CCW_PIN, OUTPUT);
  
  pinMode(DC_MTR2_CW, OUTPUT);
  pinMode(DC_MTR2_CCW, OUTPUT);
  
  pinMode(BUTTN_1, INPUT_PULLUP);
  pinMode(BUTTN_2, INPUT_PULLUP);

  digitalWrite(MTR1_CW_PIN, HIGH);
  digitalWrite(MTR1_CCW_PIN, HIGH);
  
}

void loop() {
  
  if (digitalRead(BUTTN_1) == LOW) {
    Serial.println("BUTTON FIRST PRESSED");
    delay(1000);
    digitalWrite(MTR1_CW_PIN, LOW);
    delay(5000);
    digitalWrite(MTR1_CW_PIN, HIGH);
    delay(2000); 
    digitalWrite(MTR1_CCW_PIN, LOW);
    delay(5000);
    digitalWrite(MTR1_CCW_PIN, HIGH);
    delay(2000); 
    digitalWrite(DC_MTR2_CW, HIGH);
    delay (2000);
    digitalWrite(DC_MTR2_CW, LOW);
    
}

  if (digitalRead(BUTTN_2) == LOW) {
    
    Serial.println("BUTTON SECOND PRESSED");
    digitalWrite(DC_MTR2_CCW, HIGH);
    delay(5000);
    digitalWrite(DC_MTR2_CCW, LOW);
     
}

}
