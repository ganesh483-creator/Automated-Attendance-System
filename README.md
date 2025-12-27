# Automated-Attendance-System
# Automated Attendance System Using ESP8266

## Abstract
This project presents an automated attendance system using the ESP8266 Wi-Fi module. 
The system detects the presence of individuals by identifying the MAC addresses of 
their mobile devices within a Wi-Fi range. The collected data is sent securely to 
Google Sheets, and a Python script is used to finalize attendance automatically. 
This approach eliminates manual attendance methods and provides a non-intrusive, 
cost-effective, and scalable solution suitable for classrooms, workplaces, and events.

## Objectives
- To automate the attendance process without manual intervention  
- To reduce human errors in attendance tracking  
- To design a cost-effective and energy-efficient system  

## Technologies Used
- ESP8266 Wi-Fi Module  
- Arduino Programming (Arduino IDE)  
- Python (Pandas Library)  
- Google Sheets (for data logging)  

## Working of the System
1. ESP8266 connects to a Wi-Fi network  
2. Scans nearby Wi-Fi devices and collects MAC addresses  
3. Sends the detected data to Google Sheets using HTTPS  
4. Python script processes the data and finalizes attendance  

## Features
- Fully automated attendance system  
- No biometric or manual input required  
- Scalable and easy to deploy  
- Suitable for real-time attendance tracking  

## Future Enhancements
- Attendance analytics and reports  
- Web or mobile dashboard integration  
- Alert notifications for absentees  

## Author
Ganesh Nashaboyina
