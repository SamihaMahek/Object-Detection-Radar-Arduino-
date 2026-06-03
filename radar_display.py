import serial  # Tool to connect to the laptop's USB port
import time    # Tool to create simple time delays

# 1. SETUP: Connect to the Arduino
arduino_port = "COM3"  # Change this to your Arduino's USB port
baud_rate = 9600  # Communication speed (must match Arduino)

print("Connecting to Radar system...")
# Open the connection line
radar_connection = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Wait 2 seconds for hardware to turn on properly
print("Radar connected! Scanning started...\n")

# 2. RUNTIME LOOP: Read data coming from Arduino
while True:
    # Check if there is data waiting to be read
    if radar_connection.in_waiting > 0:

        # Read the raw data line until it hits the '.' character
        raw_text = radar_connection.read_until(b".").decode("utf-8").strip()

        # Check if the data has a comma (means it's a valid message)
        if "," in raw_text:
            # Remove the ending dot character
            clean_text = raw_text.replace(".", "")

            # Split the text at the comma into two separate values
            angle, distance = clean_text.split(",")

            # Print a clean display to the screen
            print(f"Angle: {angle}° ---> Obstacle Distance: {distance} cm")
