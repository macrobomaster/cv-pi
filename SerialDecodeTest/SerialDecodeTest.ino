byte msg = 0;   // for incoming serial data
unsigned int cv_x = 0;
unsigned int cv_y = 0;
boolean sign_x = 0;
boolean sign_y = 0;
int count = 0;


void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    msg = Serial.read();

      if ((msg & 192) == 0 && count == 0) {
        if ((msg & 32) == 1) {
          sign_x = 1;
        }
        else {
          sign_x = 0;
        }
        msg = msg<<3;
        cv_x = msg;
        cv_x = cv_x<<3;
        count++;
      }
      else if ((msg & 192) == 64 && count == 1) {
        cv_x += (msg & 63);
        count++;
      }
      else if ((msg & 192) == 128 && count == 2) {
        if ((msg & 32) == 1) {
          sign_y = 1;
        }
        else {
          sign_y = 0;
        }
        msg = msg<<3;
        cv_y = msg;
        cv_y = cv_y<<3;
        count++;
      }
      else if ((msg & 192) == 192 && count == 3) {
        cv_y += (msg&63);
        count = 0;
        
      }
      else
        count=0;
    // say what you got:
 
    Serial.print(msg);
    Serial.print(" ");
    Serial.print(cv_x);
    Serial.print(" ");
    Serial.print(cv_y);
    Serial.println(" ");
        
  
    

  }
}
