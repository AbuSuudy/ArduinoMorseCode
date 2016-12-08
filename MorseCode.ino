
int ledPin = 13;
int dotDelay = 200;

char* letters[] = {
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--.."    // Z
};

char* numbers [] = {
  "-----",   // 0
  ".----",   // 1
  "..---",   // 2
  "...--",   // 3
  "....-",   // 4
  ".....",   // 5
  "-....",   // 6
  "--...",   // 7
  "---..",   // 8
  "----."    // 9
};

void setup() {
  pinMode(ledPin, OUTPUT);

  /*
     Serial is used for communication between the Arduino
     board and a computer or other devices. Begin sets the
     data rate in bits per second (baud)
  */

  Serial.begin(9600);

}

void loop() {
  char ch;

  if (Serial.available()) {
    ch = Serial.read();

    Serial.print(ch);

    /*
       Asci minus A value to get index
       from array
    */

    if ( ch >= 'a' && ch <= 'z') {

      morseCodeSequence(letters[ch - 'a']);
    }
    else if ( ch >= 'A' && ch <= 'Z') {

      morseCodeSequence(letters[ch - 'A']);

    } else if ( ch >= '0' && ch <= '9') {

      morseCodeSequence(numbers[ch - '0']);

    } else if ( ch = ' ') {

      delay(dotDelay * 4);

    }
  } else {
    //new line after character is printed out
    Serial.println(" ");
  }
  Serial.println(" ");
}

void morseCodeSequence(char* sequence) {
  int i = 0;

  while ( sequence[i] != NULL) {
    dotOrDash( sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}


void dotOrDash( char character) {
  digitalWrite(ledPin, HIGH);
  if (character == '.') {
    delay(dotDelay);
  } else {  //else dash
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}

