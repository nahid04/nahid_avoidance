#define echopin  12 // echo pin// nahid_avoidance_code_27_2_18
#define trigpin 11 // Trigger pin
#define E1 10  // Enable Pin for motor 1
#define E2 5  // Enable Pin for motor 2
 
#define I1 9  // Control pin 1 for motor 1
#define I2 8  // Control pin 2 for motor 1
#define I3 7  // Control pin 1 for motor 2
#define I4 6  // Control pin 2 for motor 2

int maximumRange = 100;
long duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
}

void loop ()
{

  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds (10);
    digitalWrite(trigpin, LOW);
    
    duration = pulseIn (echopin,HIGH,50000);
    distance = ((duration *340)/2000);
    delay (100);
    Serial.print("Distance: ");
    Serial.println(distance);
  }
  
  if (distance >= 31){
     
    analogWrite(E1, 255); // Run in full speed
    analogWrite(E2, 255); // Run in full speed
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
 
    delay (1000);
  }
  
  else if (distance >=10 && distance <= 30) {
     
    analogWrite(E1, 255); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay (100);
  }
 else if (distance < 10){

      
    analogWrite(E1, 255); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
   delay (50);
   
     
 }

}
