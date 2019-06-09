from serial import Serial
import time

print("Starting.")
port = "/dev/cu.usbmodem14201"      #port for Arduino.
ser = Serial(port, 9600)
time.sleep(2)                       #wait for Arduino.
sendedBytes =  ser.write("90,90,90".encode())
print(sendedBytes)
print(ser.readline())               #wait and read string from Arduino.
print("Done.")
