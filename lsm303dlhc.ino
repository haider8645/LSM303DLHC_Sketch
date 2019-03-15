#include <LSM303.h>
#include <Wire.h>

LSM303 mag_acc_sensor;

void setup()
{
Serial.begin(115200);
Wire.setClock(400000);
Wire.begin();
delay(1000);

bool sensor_init = mag_acc_sensor.init();
if (sensor_init != 0)
{
LSM303::deviceType device = mag_acc_sensor.getDeviceType();
Serial.println("Detected Sensor Type: ");
Serial.println(device);


// 0x0C = 0b00001100
// DO = 011 (7.5 Hz ODR)
mag_acc_sensor.writeMagReg(LSM303::CRA_REG_M, 0x0C);

// 0x20 = 0b00100000
// GN = 001 (+/- 1.3 gauss full scale)
mag_acc_sensor.writeMagReg(LSM303::CRB_REG_M, 0x20);

// 0x00 = 0b00000000
// MD = 00 (continuous-conversion mode)
// MD = 01b, 0x01 (single conversion mode)
// MD = 10b, 0x02 (sleep mode)
mag_acc_sensor.writeMagReg(LSM303::MR_REG_M, 0x00);
}

}

void loop()
{
	
}
