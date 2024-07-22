# posttest4-praktikum-iot-unmul
## POSTTEST 4 IOT

## NAMA DAN ANGGOTA KELOMPOK 
1. 2109106096 - Filipus Manik
2. 2109106106 - Muhammad Arif
3. 2209106003 - Muhammad Rifan Fathoni

## Deskripsi
Membuat Project IoT yang dapat dikontrol dan dimonitor dengan menggunakan satu platform IoT yang telah dipelajari yaitu TELEGRAM BOT

## Metode IOT 
### Metode Alat Monitoring Kekeruhan Air
1. Pemasangan Sensor:

- Sensor pH: Dipasang di dalam air untuk mengukur tingkat keasaman atau alkalinitas air.
- Sensor Turbidity: Juga ditempatkan di dalam air untuk mendeteksi tingkat kekeruhan, yang mengindikasikan jumlah partikel tersuspensi dalam air.

2. Pengumpulan Data:

Kedua sensor mengirimkan data analog ke mikrokontroler (seperti Arduino atau ESP32) yang telah diprogram untuk membaca dan mengolah data tersebut.

3. Pengiriman Data:

Data yang telah diolah oleh mikrokontroler dikirimkan ke broker MQTT secara nirkabel. MQTT adalah protokol pesan yang ringan dan ideal untuk komunikasi IoT.

4. Visualisasi Data:

Data yang diterima oleh broker MQTT kemudian ditampilkan secara real-time di aplikasi yang dibuat dengan Kodular. Aplikasi ini memvisualisasikan hasil pengukuran dalam bentuk grafik atau indikator lainnya.

5. Indikator LED:

Berdasarkan data yang diterima, mikrokontroler akan mengaktifkan LED indikator: LED merah untuk kondisi air yang kritis, LED kuning untuk kondisi waspada, dan LED hijau untuk kondisi aman.

## Komponen yang digunakan
1. 4 buah lampu LED
2. 1 buah bread board
3. 1 buah esp8266
4. 3 buah Jumper female to male
5. 1 Buah Jumper male to male
6. 4 Buah Resistor
7. 1 Buah DHT11

## Board Schematic

![Board Schematic](https://github.com/Kuuhaku456/posttest3-praktikum-iot-unmul/blob/main/Gambar_Real_Sketsa.jpg)

## Link video 
[Lampiran Video](https://drive.google.com/file/d/1igVZu2edogFl3B3rgP7S3eKV7EmxxCEB/view?usp=sharing)
