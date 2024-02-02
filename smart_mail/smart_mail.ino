#include <ESP8266WiFi.h>
#include <Servo.h>


// Define pin connections
#define IR_SENSOR_PIN D3
#define SERVO_PIN D4

// Wi-Fi credentials
const char* ssid = "Pooja";
const char* password = "pooja9880";

// Initialize objects
Servo mailboxServo;
WiFiServer server(80);

int mailCount = 0;

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected.");

  // Print IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started.");

  mailboxServo.attach(SERVO_PIN);
  pinMode(IR_SENSOR_PIN, INPUT);

  

  Serial.println("Smart Mailbox system initialized.");
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {
    Serial.println("New client connected.");
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // Close the connection after the response
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html><head><title>Smart Mailbox</title></head><body>");
    client.println("<h1>Smart Mailbox</h1>");
    client.println("<p>Number of mails: " + String(mailCount) + "</p>");
    client.println("</body></html>");
    client.stop();  // Close the connection
    Serial.println("Client disconnected.");
  }

  int mailStatus = digitalRead(IR_SENSOR_PIN);

  if (mailStatus == HIGH) {
    mailCount++;
    Serial.println("Mail detected!");
    openMailbox();
    delay(5000); // Wait for a few seconds
    closeMailbox();
    Serial.println("Mailbox closed.");
  }

  // Update LCD display with mail count
 
  // Print IP address on serial monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  delay(1000); // Delay between iterations
}

void openMailbox() {
  mailboxServo.write(0); // Open the mailbox
  delay(1000); // Wait for the servo to reach the desired position
}

void closeMailbox() {
  mailboxServo.write(90); // Close the mailbox
  delay(1000); // Wait for the servo to reach the desired position
}
