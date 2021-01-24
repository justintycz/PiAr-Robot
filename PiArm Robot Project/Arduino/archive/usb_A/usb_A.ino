void setup() {
	Serial.begin(9600);
	
	Serial.println("OFF");
}

void loop() {
	if(Serial.available()) {
		
		// Read Data
		String command = Serial.readString();
		
		if(command == "1") {
			Serial.println("ON");
		}
		else if(command == "0") {
			Serial.println("OFF");
		}
	}
}