/* ********************** Max Altitude Launch ****************************
/ Uses an accelerometer to look for the maximum altitude then writes a digitlal
/ output. 
/ Kellen Schroeter 6.23.12
*/

int xPin = 5;                             // Pin for x out on Memsic2125
int xRaw;                                 // Value for the raw data
float xmG, xAccel;                        // Values for milli g & m/s^2 data
int enginePin = 10;                       // Pin for LED or transistor or w/e

void setup() {
  Serial.begin(9600);                     // Initialize serial @ 9600 baud
  pinMode(xPin, INPUT);                   // Memsic is input
}

void loop() {
  xRaw = pulseIn(xPin, HIGH);             // Measure Raw Data
  xmG = ((xRaw / 10) - 500) * 8;          // Convert to mili g's (@ room temp)
  xAccel = (xmG * 9.81) / 1000;           // Convert to m/s^2
  
  
  Serial.print("X Acceleration: ");       // Print "xxxxx"
  Serial.println(xAccel);                 // Print the acceleration in m/s^2
  
  if (xAccel <= 3) {                      // if the acceleration is < 3 then...
    analogWrite(enginePin, 255);          // turn engine on or w/e
    delay(1000);
    analogWrite(enginePin, 0);            // turn engine off or w/e
    delay(50);
  } else { delay(50);
  }
}
  
