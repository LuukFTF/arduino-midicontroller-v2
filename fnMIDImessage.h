
void MIDImessage(uint8_t status, uint8_t data1, uint8_t data2) {
  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);  
}
