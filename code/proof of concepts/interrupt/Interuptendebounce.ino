const int knopPin = 2;
const int ledPin = 17;

bool isSchakelaarAan = false;

long laatsteDebounceTijd = 0;
long debounceVertraging = 200;

void setup() {
  pinMode(knopPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(knopPin), toggleSchakelaar, FALLING);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (isSchakelaarAan) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void toggleSchakelaar() {
  long huidigeTijd = millis();

  if (huidigeTijd - laatsteDebounceTijd < debounceVertraging) {
    return;
  }

  isSchakelaarAan = !isSchakelaarAan;

  laatsteDebounceTijd = huidigeTijd;
}
