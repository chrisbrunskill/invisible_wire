 #include "pitches.h"
 int val = 0;
 int rst = 1;
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
  
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  val = analogRead(0);
  if (val < 700){
    Serial.println(val);
    fail();
    while (analogRead(0)<700) {}
  }
}

void fail() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
