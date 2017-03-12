#include <DS3231.h>
DS3231  rtc(SDA, SCL);

int ledPin = 13;
int pirPin = 3;
int pirCounter = 0;
int val;


void setup() {
  Serial.begin(250000);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  rtc.begin();

  rtc.setTime(12, 05, 15); 
  rtc.setDate(25, 11, 2016);

}

void loop() {
  val = digitalRead(pirPin);

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(4000);
    Serial.print("Motion Detected at: ");
  
     // Send date
    Serial.print(rtc.getDateStr());
    Serial.print(" -- ");

  // Send time
    Serial.println(rtc.getTimeStr());
  } else if (val == LOW) {
    digitalWrite(ledPin, LOW);
  }
}


