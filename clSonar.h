
void MIDImessage3(uint8_t status, uint8_t data1, uint8_t data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);  
}

class clSonar {
  private:
    int trigPin;
    int echoPin;
    int midiControllerChannel;
    float duration;
    float distance;
    float lastVal;
    float diff = 1;
  public:
  clSonar(int trigPin, int echoPin, int midiControllerChannel) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->midiControllerChannel = midiControllerChannel;
    init();
  }
  void init() {
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    update();
    }
  int update() {
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    
    duration = pulseIn(echoPin, HIGH); 
    distance = (duration*.0343)/2; 
   }
  int getValue() {
    update();
    return(distance);
  }

  int updateMidi() {
    getValue();
    
    int valDiff = distance  - lastVal;

    if (abs(valDiff) > diff && distance < 50) {
      int distanceMap = map(distance, 0, 50, 0, 127);
      MIDImessage3(177, midiControllerChannel, distanceMap);
//      Serial.print("Distance: "); 
//      Serial.println(distance);
      lastVal = distance;
    }
  }
};
