
void MIDImessage2(uint8_t status, uint8_t data1, uint8_t data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);  
  
}
class clPotentiometer {
  private:
    int potPin;
    int potVal;
    int lastVal;
    int midiControllerChannel;
    int diff = 4;
  public:
    clPotentiometer(int potPin, int midiControllerChannel) {
      this->potPin = potPin;
      this->midiControllerChannel = midiControllerChannel;
      init();
      }
    void init(){
      update();
    }
    void update() {
      potVal = analogRead(potPin);
    }
    void getValue() {
      update();
      return(potVal);
    }
    void updateMidi(){
      int potValDiff = potVal - lastVal;
      
      if (abs(potValDiff) > diff) {
        MIDImessage2(177, midiControllerChannel, map(potVal, 0, 1023, 0, 127));
        lastVal = potVal;
      }
    }
  }

  
