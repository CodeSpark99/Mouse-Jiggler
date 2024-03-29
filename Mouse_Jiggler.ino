struct {
 uint8_t buttons;
 int8_t x;
 int8_t y;
} mouseReport;
uint8_t nullReport[4] = { 0, 0, 0, 0 };
void setup();
void loop();
void setup() 
{
 Serial.begin(9600);
 delay(200);
}
void loop() 
{
 int ind;
 delay(1500);
 mouseReport.buttons = 0;
 mouseReport.x = 0;
 mouseReport.y = 0;
 int xr_val = random(-1280, 1279);
 int yr_val = random(-720, 719);
 mouseReport.x = map(xr_val, -1280, 1279, -10, 10);
 mouseReport.y = map(yr_val, -720, 719, -10, 10);
 for (ind=0; ind<20; ind++) {
	Serial.write((uint8_t *)&mouseReport, 4);
	Serial.write((uint8_t *)&nullReport, 4);
 }
}
