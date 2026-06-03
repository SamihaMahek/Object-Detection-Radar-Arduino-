// Define hardware hardware connection pins (Standard C Constants)
#define TRIG_PIN 10
#define ECHO_PIN 11
#define SERVO_PIN 12

void setup() {
    // Set pin modes using native C configurations
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(SERVO_PIN, OUTPUT);
    
    // Open a serial communication port line at 9600 baud rate
    Serial.begin(9600); 
}

// Custom C helper function to calculate object distance
long calculateDistance() {
    digitalWrite(TRIG_PIN, LOW); 
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2; // Physics math logic conversion
    return distance;
}

void loop() {
    int angle;
    long distance;

    // Standard C 'for' loop to sweep servo right (0 to 180 degrees)
    for(angle = 0; angle <= 180; angle += 2) {  
        // Generate a standard pulse width modulation (PWM) signal manually
        digitalWrite(SERVO_PIN, HIGH);
        delayMicroseconds(500 + (angle * 10)); 
        digitalWrite(SERVO_PIN, LOW);
        
        distance = calculateDistance();
        
        // Print the metrics to the data stream line
        Serial.print(angle);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
        delay(40);
    }
}
