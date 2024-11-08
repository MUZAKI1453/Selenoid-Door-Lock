const int relayPin = 4;
String command = ""; // Menyimpan perintah dari Serial Monitor

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Pengunci Pintu Otomatis");
  Serial.println("'ON' UNTUK MENGUNCI DAN 'OFF' UNTUK MEMBUKA");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n'); // Baca input hingga '\n'
    command.trim(); // Menghilangkan spasi atau karakter baru di akhir input
  }

  if (command == "ON") {
    digitalWrite(relayPin, LOW); // Aktifkan relay untuk mengunci
    Serial.println("Selenoid terkunci.");
    command = ""; // Reset command setelah eksekusi
  } 
  else if (command == "OFF") {
    digitalWrite(relayPin, HIGH); // Nonaktifkan relay untuk membuka
    Serial.println("Selenoid terbuka.");
    command = ""; // Reset command setelah eksekusi
  } 
  else if (command != "") {
    Serial.println("Perintah tidak dikenal");
    command = ""; // Reset command setelah eksekusi
  }
}
