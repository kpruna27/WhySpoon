import processing.serial.*; // add the serial library
Serial myPort; // define a serial port object to monitor


void setup() {
  size(600, 750); // set the window size
  println(Serial.list()); // list all available serial ports
  myPort = new Serial(this, Serial.list()[0], 9600); // define input port
  myPort.clear(); // clear the port of any initial junk
  
  fill(0,0,0);
  rect(100,100,400,560);
  
  fill(255,255,255);
  rect(120,100,360,540);
  
  
}

void draw(){
  
  if (myPort.available () > 0) {
    String inString = myPort.readStringUntil('\n');
    if (inString != null) {
      inString = trim(inString);
      String[] reading = splitTokens(inString, "\t"); 
      if (reading.length == 2){
        int a1 = int(reading[0]);
        int a2 = int(reading[1]);
        
        int y = a2*50;
        //fill(0,255,0);
        //rect(120,y+200,360,300-y);
        println(y);
        
        
        
        
      
    
   
   }
  }
 }
}

        
        
