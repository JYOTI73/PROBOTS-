#define BT Serial1

#define PICO_USB_BAUD 115200
#define BLUETOOTH_BAUD 115200

#define LED_SUCCESS_PIN_NO 11
#define BUZZER_PIN_NO 26

#define SWITCH_TOP_PIN_NO 27
#define SWITCH_MIDDLE_PIN_NO 22
#define SWITCH_BOTTOM_PIN_NO 21

#define MOTOR_LEFT_A_PIN_NO 16
#define MOTOR_LEFT_B_PIN_NO 17
#define MOTOR_STANDBY_PIN_NO 18
#define MOTOR_RIGHT_A_PIN_NO 19
#define MOTOR_RIGHT_B_PIN_NO 20

#define IR_LEFT_PIN_NO 13  // LEFT SENSOR
#define IR_RIGHT_PIN_NO 12 // RIGHT SENCOR

#define IR_ON_PIN_NO 10

#define IR_01_PIN_NO 9
#define IR_02_PIN_NO 8
#define IR_03_PIN_NO 7
#define IR_04_PIN_NO 6
#define IR_05_PIN_NO 5
#define IR_06_PIN_NO 4
#define IR_07_PIN_NO 3
#define IR_08_PIN_NO 2

#define BATTERY_VOLTAGE_CHECK_PIN_NO A2
#define ANALOG_REFERENCE_VOLTAGE 3.3
#define ANALOG_READ_RESOLUTION 12
#define R7_OHM_POSITIVE 10000.0
#define R8_OHM_GROUND 5100.0
#define BATTERY_LOW_VOLTAGE_CUTOFF 7.0 //6.9

#define ANALOG_WRITE_RESOLUTION 16
#define MOTOR_DRIVER_ENABLE 1
#define MOTOR_DRIVER_STANDBY 0

const float voltageDividerRatio = (R7_OHM_POSITIVE + R8_OHM_GROUND) / R8_OHM_GROUND;
const float adcCountToVolt = ANALOG_REFERENCE_VOLTAGE / (pow(2, ANALOG_READ_RESOLUTION) - 1) * voltageDividerRatio;
// Vin=count*3.3/(pow2(ANALOGREADRESOLUTION)-1)*voltageDividerRatio;

const int photoDiodePins[8] = {IR_02_PIN_NO, IR_03_PIN_NO, IR_04_PIN_NO, IR_05_PIN_NO, IR_06_PIN_NO, IR_07_PIN_NO, IR_08_PIN_NO};
// r2/(r1+r2)

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED_SUCCESS_PIN_NO, OUTPUT);
    pinMode(BUZZER_PIN_NO, OUTPUT);

    pinMode(SWITCH_TOP_PIN_NO, INPUT_PULLUP);
    pinMode(SWITCH_MIDDLE_PIN_NO, INPUT_PULLUP);
    pinMode(SWITCH_BOTTOM_PIN_NO, INPUT_PULLUP);

    pinMode(MOTOR_LEFT_A_PIN_NO, OUTPUT);
    pinMode(MOTOR_LEFT_B_PIN_NO, OUTPUT);
    pinMode(MOTOR_LEFT_A_PIN_NO, OUTPUT);

    pinMode(MOTOR_STANDBY_PIN_NO, OUTPUT);

    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    pinMode(MOTOR_RIGHT_B_PIN_NO, OUTPUT);

    pinMode(IR_LEFT_PIN_NO, INPUT);
    pinMode(IR_RIGHT_PIN_NO, INPUT);

    pinMode(IR_ON_PIN_NO, OUTPUT); // CONTROL PIN

    // pinMode(IR_D1_PIN_NO,INPUT);
    // pinMode(IR_D2_PIN_NO,INPUT);
    // pinMode(IR_D3_PIN_NO,INPUT);
    // pinMode(IR_D4_PIN_NO,INPUT);

    // pinMode(IR_D5_PIN_NO,INPUT);
    // pinMode(IR_D6_PIN_NO,INPUT);
    // pinMode(IR_D7_PIN_NO,INPUT);
    // pinMode(IR_D8_PIN_NO,INPUT);

    pinMode(BATTERY_VOLTAGE_CHECK_PIN_NO, INPUT);
    analogReadResolution(ANALOG_READ_RESOLUTION); // For Battery Voltage Check

    // analogWriteResolution(ANALOG_WRITE_RESOLUTION); //For Motor PWM
    analogWriteResolution(8); // For Motor PWM 2^8 is 0 to 255

    BT.begin(BLUETOOTH_BAUD);
    delay(100);

    blink_n_beep(3, 500);
    BT.println("\r\n========= RESET =========");

    motionForward(255);
    delay(1000);
    motionStop();
    delay(2000);

    motionReverse(255);
    delay(1000);
    motionStop();
    delay(2000);
}

//////////////////////////////////////////////////
int i = 0;
//////////////////////////////////////////////////
void loop()
{
    BT.print("\r\n");
    BT.print(i);
    batteryVoltageCheck(); // DO NOT REMOVE: To save LiPo from permanent dammage!

    delay(1000);
    i++;
} /////////////////////////////////////////////////
void motionForward(int speed)
{
    analogWrite(MOTOR_LEFT_A_PIN_NO, speed);
    pinMode(MOTOR_LEFT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO, LOW);

    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    analogWrite(MOTOR_RIGHT_B_PIN_NO, speed);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}
//////////////////////////////////////////////////////////////////
void motionReverse(int speed)
{
    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    analogWrite(MOTOR_RIGHT_B_PIN_NO, speed);

    analogWrite(MOTOR_RIGHT_A_PIN_NO, speed);
    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}
////////////////////////////////////////////////////////////////////////////////
void motionStop(void)
{
    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    pinMode(MOTOR_RIGHT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_B_PIN_NO, LOW);

    pinMode(MOTOR_LEFT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    pinMode(MOTOR_LEFT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_B_PIN_NO, LOW);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_STANDBY);
}
//////////////////////////////////////////////////////////////////////////////////

float batteryVoltageCheck(void)
{
    //
    // Voltage Divider formula:

    // Vout = Vin * R2/(R1+R2)
    // Vin = Vout *(R1+R2)/R2;
    //

    int adcCount = analogRead(BATTERY_VOLTAGE_CHECK_PIN_NO);
    float voltageOfBattery;
    voltageOfBattery = adcCount * adcCountToVolt;
    BT.print("\r\n adcCount = ");
    BT.print(adcCount);
    BT.print("\r\n voltageDividerRatio = ");
    BT.print(voltageDividerRatio);
    BT.print("\r\n adcCountToVolt = ");
    BT.print("adcCountToVolt");

    BT.print("\r\n Battery Voltage = ");
    BT.print(voltageOfBattery);
    if (voltageOfBattery < BATTERY_LOW_VOLTAGE_CUTOFF)
    {
        digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_STANDBY); // STOP MOTORS
        digitalWrite(IR_ON_PIN_NO, LOW);                          // HIGH = ON
        BT.print("\r\n adcCount = ");
        BT.print(adcCount);
        BT.print("\r\n voltageDividerRatio = ");
        BT.print(voltageDividerRatio);
        BT.print("\r\n adcCountToVolt = ");
        BT.print("adcCountToVolt");
        BT.print("\r\n Battery Voltage = ");
        BT.print(voltageOfBattery);
        hang();
    }
    return voltageOfBattery;
}
////////////////////////////////////////////////////////////
void blink(int n, int timePeriod)
{
    while (n > 0)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
        delay(timePeriod / 2);

        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED_SUCCESS_PIN_NO, LOW);
        delay(timePeriod / 2);
        n--;
    }
}
////////////////////////////////////////////////////////////
void beep(int n, int timePeriod)
{
    while (n > 0)
    {
        digitalWrite(BUZZER_PIN_NO, HIGH);
        delay(timePeriod / 2);

        digitalWrite(BUZZER_PIN_NO, LOW);
        delay(timePeriod / 2);
        n--;
    }
}
///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
void blink_n_beep(int n, int timePeriod)
{
    while (n > 0)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
        digitalWrite(BUZZER_PIN_NO, HIGH);
        delay(timePeriod / 2);

        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED_SUCCESS_PIN_NO, LOW);
        digitalWrite(BUZZER_PIN_NO, LOW);
        delay(timePeriod / 2);
        n--;
    }
}
/////////////////////////////////////////////////////////////
void hang(void)
{
    int t = 0;
    BT.println("\r\n######### HANG ########");

    digitalWrite(BUZZER_PIN_NO, HIGH);
    delay(2000);
    digitalWrite(BUZZER_PIN_NO, LOW);

    while (1)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LED_SUCCESS_PIN_NO, LOW);
        delay(200);
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
        delay(200);
        if (t % 100)
        {
            BT.print("H");
        }
        t++;
    }
}
