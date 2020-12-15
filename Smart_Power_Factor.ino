#include <WiFiEsp.h>
#include <PZEM004Tv30.h>

char ssid[] = "DAPR";
char pass[] = "dinan_99";

int status = WL_IDLE_STATUS;
PZEM004Tv30 pzem(11, 12);

void setup() {
Serial.begin(9600);
Serial1.begin(115200);
WiFi.init(&Serial1);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi Module Tidak Ada");
    while (true);
}
while ( status != WL_CONNECTED) {
    Serial.print("Mencoba Terhubung ke WiFi dengan SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  Serial.print("Kamu Telah Terhubung Ke WiFi: ");
  Serial.println(ssid);
  printWifiStatus();
}

void loop() {
float voltage = pzem.voltage();
if(voltage != NAN){
Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
} else {
Serial.println("Error reading voltage");
}
float current = pzem.current();
if(current != NAN){
Serial.print("Current: "); Serial.print(current); Serial.println("A");
} else {
Serial.println("Error reading current");
}
float power = pzem.power();
if(current != NAN){
Serial.print("Power: "); Serial.print(power); Serial.println("W");
} else {
Serial.println("Error reading power");
}
float energy = pzem.energy();
if(current != NAN){
Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
} else {
Serial.println("Error reading energy");
}
float frequency = pzem.frequency();
if(current != NAN){
Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
} else {
Serial.println("Error reading frequency");
}
float pf = pzem.pf();
if(current != NAN){
Serial.print("PF: "); Serial.println(pf);
} else {
Serial.println("Error reading power factor");
}
Serial.println();
delay(2000);
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("Alamat IP: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("Kekuatan Sinyal (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
