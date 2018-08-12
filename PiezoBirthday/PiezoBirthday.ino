#define N_C6  1047
#define N_CS6 1109
#define N_D6  1175
#define N_DS6 1245
#define N_E6  1319
#define N_F6  1397
#define N_FS6 1480
#define N_G6  1568
#define N_GS6 1661
#define N_A6  1760
#define N_AS6 1865
#define N_B6  1976
#define N_C7  2093
#define N_CS7 2217
#define N_D7  2349
#define N_DS7 2489
#define N_E7  2637
#define N_F7  2794
#define N_FS7 2960
#define N_G7  3136
#define N_GS7 3322
#define N_A7  3520
#define N_AS7 3729
#define N_B7  3951

float notedurmult = 1.4; // note duration multiplier
#define pinpiezo 1 // pin for the piezo buzzer
#define pinbtn 0 // pin for the button

int melody[] = { // array with the notes of the melody
  N_G6, N_G6, N_A6, N_G6, N_C7, N_B6, N_G6, N_G6, N_A6, N_G6, N_D7, N_C7, N_G6, N_G6, N_G7, N_E7, N_C7, N_B6, N_A6, N_F7, N_F7, N_E7, N_C7, N_D7, N_C7
};

// array with the note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2
};

void setup(){
  tone(pinpiezo, 3000); // v
  delay(150);           // send start sound to let you know that the button can be pressed
  noTone(pinpiezo);     // ^
}

void playmusic(){
  for (int thisNote = 0; thisNote < 25; thisNote++) { // iterate through the arrays 25 times

    int noteDuration = 1000 / noteDurations[thisNote]; // get the correct note durations
    tone(pinpiezo, melody[thisNote], noteDuration); // start the sound with the specified frequency and duration on the specified piezo pin

    int pauseBetweenNotes = noteDuration * notedurmult; // multiply the note duration array with the specified duration
    delay(pauseBetweenNotes);                           // and then pause for this duration
    noTone(pinpiezo); // end the sound
  }
}

void loop() {
  if(digitalRead(pinbtn) == 1){
    playmusic(); // play melody if the button is pressed
    while(digitalRead(pinbtn) == 1){ // v
      delay(100);                    // v
      if(digitalRead(pinbtn) == 0){  // if the button is still pressed don't play the melody again
        break;                       // ^
      }                              // ^
    }
  }
  delay(20);
}
