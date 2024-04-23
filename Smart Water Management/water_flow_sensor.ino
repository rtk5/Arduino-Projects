#include <WiFi.h>
#include <WebServer.h>

#define FLOW_SENSOR_PIN 2 // GPIO2 for flow sensor input

WebServer server(80);

volatile unsigned int pulseCount;
float flowRate;
float totalVolume;

const char* ssid = "Rithvik";
const char* password = "88888888";

unsigned long prevMillis = 0;
const long interval = 2000; // interval to update readings (in milliseconds)

void pulseCounter() {
  static unsigned long lastPulseTime = 0;
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastPulseTime > 30) {  // Debounce time increased to 30 milliseconds
    pulseCount++;
    lastPulseTime = currentMillis;
  }
}

void updateFlowRateAndVolume() {
  detachInterrupt(FLOW_SENSOR_PIN);
  flowRate = pulseCount / 7.5; // Adjust this according to your sensor
  totalVolume += (flowRate / 60.0) * (interval / 1000.0); // L/min * (min/interval) = L
  pulseCount = 0;
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, FALLING);
}

void handleRoot() {
  String message = "<!DOCTYPE html><html><head><title>Water Flow and Volume Sensor</title>";
  message += "<script>function updateValues() {";
  message += "var xhttp = new XMLHttpRequest();";
  message += "xhttp.onreadystatechange = function() {";
  message += "if (this.readyState == 4 && this.status == 200) {";
  message += "var response = this.responseText.split(',');";
  message += "document.getElementById('flowRate').innerHTML = response[0];";
  message += "document.getElementById('totalVolume').innerHTML = response[1];";
  message += "}};";
  message += "xhttp.open('GET', '/data', true);";
  message += "xhttp.send();";
  message += "}";
  message += "setInterval(updateValues, 1000);</script></head>";
  message += "<body onload='updateValues()'>";
  message += "<h1>Water Flow and Volume Sensor</h1>";
  message += "<p>Flow Rate: <span id='flowRate'></span> L/min</p>";
  message += "<p>Total Volume: <span id='totalVolume'></span> L</p>";
  message += "</body></html>";
  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(115200);
  pinMode(FLOW_SENSOR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, FALLING);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/data", HTTP_GET, []() {
    updateFlowRateAndVolume();
    String responseData = String(flowRate, 2) + "," + String(totalVolume, 2);
    server.send(200, "text/plain", responseData);
  });

  server.begin();
}

void loop() {
  server.handleClient();
  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis >= interval) {
    updateFlowRateAndVolume();
    prevMillis = currentMillis;
  }
}
