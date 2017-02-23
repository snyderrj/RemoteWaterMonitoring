
#include <Adafruit_VC0706.h>
#include <SPI.h>
#include <SoftwareSerial.h>         

SoftwareSerial cameraconnection = SoftwareSerial(2, 3);

Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

void setup() {
  
  Serial.begin(9600, SERIAL_8N1);  
  // Try to locate the camera
  if(!cam.begin())
     Serial.println("Camera not found!\n");
  cam.setBaud9600();
  // Set the picture size - you can choose one of 640x480, 320x240 or 160x120 
  // Remember that bigger pictures take longer to transmit!
  
  cam.setImageSize(VC0706_640x480);        // biggest
  //cam.setImageSize(VC0706_320x240);        // medium
  //cam.setImageSize(VC0706_160x120);          // small
}

void loop() {
  int i = 0;
  while(true)
  {
    if(i == 0)
    {
      uint16_t jpglen = 0;
      while(jpglen == 0) {
        cam.takePicture();
      
        // Get the size of the image (frame) taken  
        jpglen = cam.frameLength();
        //Serial.println(jpglen);
      }
      int oldjpglen = jpglen;
      uint8_t bytesToRead;
      while (jpglen > 0) {
        // read 32 bytes at a time;
        //uint8_t *buffer;
        bytesToRead = min(16, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
        Serial.write(cam.readPicture(bytesToRead),bytesToRead);
        
        //Serial.write(buffer, bytesToRead);
        Serial.flush();
        delay(20);

        jpglen -= bytesToRead;
      }
      
      if (bytesToRead<32)
        {
          bytesToRead = 32-bytesToRead;
          while(bytesToRead>0)
          {
            Serial.write((byte) 0x00);
            bytesToRead = bytesToRead - 1;
            Serial.flush();
          }
        }
       //Serial.write(cam.readPicture(jpglen),jpglen);
    }
    i = 1;
  }
}
