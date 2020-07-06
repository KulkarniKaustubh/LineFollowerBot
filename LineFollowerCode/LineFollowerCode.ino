int IR1 = A0;
int IR2 = A1;

void setup() {
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void goForward() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW); 
}

void goRight() {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);  
}

void goLeft() {
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void dontGoAnywhere() {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void loop() {
  int IR1_OUT = analogRead(IR1);
  int IR2_OUT = analogRead(IR2);

  Serial.print("ir1: ");
  Serial.println(IR1_OUT);
  Serial.print("ir2: ");
  Serial.println(IR2_OUT);
  
  if (IR1_OUT < 100 && IR2_OUT < 100) {
    goForward();
  }

  if (IR1_OUT > 100 && IR2_OUT < 100) {
    goLeft();
  }

  if (IR1_OUT < 100 && IR2_OUT > 100) {
    goRight();
  }

  if (IR1_OUT > 100 && IR2_OUT > 100) {
    dontGoAnywhere();
  }
  
  delay(500);
}
