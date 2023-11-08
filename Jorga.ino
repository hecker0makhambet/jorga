const int trigPin = 12; // Trigger Pin of the distance sensor
const int echoPin = 13; // Echo Pin of the distance sensor
const int gas_pin = 2; // Digital pin of the gas leak sensor
#define flame_pin A1 // Analog pin of the open flame sensor
// It detects the fire by its infrared sensor
#define gas_pin_a A2 // Analog pin of the gas leak sensor
// It detects the leak of gas
#define passivePin 8 // Pin of the passive buzzer
// Passive buzzer should signal if the flame is detected or there is a gas leak
#define buzz_pin 7 // Pin of the active buzzer
// Active buzzer should signal if some object gets close
long duration, cm;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz_pin, OUTPUT);
  
  pinMode(flame_pin, INPUT);
  pinMode(passivePin, OUTPUT);
  
  pinMode(gas_pin, INPUT);
  pinMode(gas_pin_a, INPUT);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;

  Serial.print("The distance to the object is: ");
  Serial.print(cm); // Printing the values
  Serial.println(" sm.");
  if(cm < 30){ // If object is close
    digitalWrite(buzz_pin, HIGH); // Play a signal
  }else{ // Else
    digitalWrite(buzz_pin, LOW); // Mute
  }


  int value = analogRead(flame_pin); // Reading the signal of open flame sensor
  int range = map(value,  0, 1024, 0, 3); // Formatting the value
  Serial.print(value); // Print the value(in the IDE)
  switch (range) {
  case 0: // If the value is zero
    Serial.println(" - ** Close  Fire **"); // The fire is close
    tone(passivePin, 1000); // Play the appropriate sound
    break;
  case 1: // If the value is one
    Serial.println(" - **  Distant Fire **"); // The fire is detected, but it is in a distance
    tone(passivePin, 500); // Play the appropriate sound
    break;
  case 2: // If the value is 2
    Serial.println(" - No  Fire"); // There is no fire
    noTone(passivePin); // Mute the sound
    break;
  }
  delay(1);
  delay(250);

  
  int gas_value = analogRead(gas_pin_a); // Reading the analog value from the gas sensor
  int digital = digitalRead(gas_pin); // Reading the digital value from the gas sensor
  Serial.println(String(gas_value) + " - " + String(digital)); // Printing the values(in the IDE)
  if(gas_value > 100){ // If the concentration of gas is high and gas leak is detected
    tone(passivePin, 250, 200); // Play an appropriate sound
  }
}
