// Define the trigger and echo pins for two ultrasonic sensors
int trigPin1 = 6;  // Trigger for sensor 1
int echoPin1 = 7;  // Echo for sensor 1
int trigPin2 = 8;  // Trigger for sensor 2
int echoPin2 = 9;  // Echo for sensor 2

long duration1, cm1, duration2, cm2;

void setup() {
  Serial.begin(9600);
  
  // Set the trigger and echo pins as INPUT/OUTPUT
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // Sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  
  // Measure the duration of the echo pulse for sensor 1
  duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculate the distance in centimeters for sensor 1
  cm1 = (duration1 / 2) / 29.1;  // Divide by 29.1 or multiply by 0.0343

  // Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);

  // Measure the duration of the echo pulse for sensor 2
  duration2 = pulseIn(echoPin2, HIGH);
  
  // Calculate the distance in centimeters for sensor 2
  cm2 = (duration2 / 2) / 29.1;  // Divide by 29.1 or multiply by 0.0343

  // Logic based on the distance readings from both sensors
  if (cm1 <= 20 && cm2 <= 20) {
    Serial.println("Vdn");  // Move down
    delay(300);
  }

  if (cm1 >= 20 && cm1 <= 50 && cm2 >= 20 && cm2 <= 50) {
    Serial.println("Vup");  // Move up
    delay(300);
  }

  if (cm1 <= 10 && cm2 >= 30) {
    Serial.println("back");  // Move back
    delay(300);
  }

  if (cm1 >= 30 && cm2 <= 10) {
    Serial.println("next");  // Move forward
    delay(300);
  }
}
