/*
Example for Gyro2 Click

    Date          : okt 2018.
    Author        : Dusan Poluga

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initialize the GPIO and communication structures.
- Application Initialization - Initialize the communication interface and
                               configure the click board.  
- Application Task - Read the x,y,z and temperature data from the click board
                     and display the resoults on the serial port.
*/

#include "Click_Gyro2_types.h"
#include "Click_Gyro2_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN,  _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN,  _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT  );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT  );

    mikrobus_i2cInit( _MIKROBUS1, &_GYRO2_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    gyro2_i2cDriverInit( (T_GYRO2_P)&_MIKROBUS1_GPIO, (T_GYRO2_P)&_MIKROBUS1_I2C, GYRO2_ADDR1 );
    Delay_ms(3000);

    if(gyro2_getId() == 0xD7)
    {
        mikrobus_logWrite("Gyro 2 present", _LOG_LINE);
        gyro2_interruptEventgeneration(GYRO2_RT_CFG_ZTEFE | GYRO2_RT_CFG_YTEFE | GYRO2_RT_CFG_XTEFE);
        gyro2_sensitivity(10);
        gyro2_setOpmode(GYRO2_Active);
        gyro2_setDR(GYRO2_DR_100Hz);
        gyro2_interruptCfg( GYRO2_INT_CFG_FIFO_INT1, GYRO2_INT_EN_FIFO | GYRO2_INT_EN_DRDY, GYRO2_IPOL_ACTIVE_HI );
        gyro2_frSetup(GYRO2_LO_PASS_MOD2, GYRO2_HI_PASS_OFF, GYRO2_SCALE_3);
    }
    else 
    {
        mikrobus_logWrite("Error", _LOG_LINE);
        while(1);
    }
    Delay_ms(100);
}

void applicationTask()
{
    char text[10];
    int16_t axisData[3];
    char state;
    char temperature;

    gyro2_getAxisraw(&axisData[0]);
    gyro2_calcAxis(&axisData[0]);

    IntToStr(axisData[0],&text[0]);
    Ltrim(&text[0]);
    mikrobus_logWrite("x: ",_LOG_TEXT);
    mikrobus_logWrite(&text[0],_LOG_LINE);
    IntToStr(axisData[1],&text[0]);
    Ltrim(&text[0]);
    mikrobus_logWrite("y: ",_LOG_TEXT);
    mikrobus_logWrite(&text[0],_LOG_LINE);
    IntToStr(axisData[2],&text[0]);
    Ltrim(&text[0]);
    mikrobus_logWrite("z: ",_LOG_TEXT);
    mikrobus_logWrite(&text[0],_LOG_LINE);
    temperature=gyro2_readTemperature();
    ByteToStr(temperature,&text[0]);
    Ltrim(&text[0]);
    mikrobus_logWrite("Temperature: ",_LOG_TEXT);
    mikrobus_logWrite(&text[0],_LOG_TEXT);
    mikrobus_logWrite(" °C",_LOG_LINE);
    mikrobus_logWrite("++",_LOG_LINE);
    Delay_ms(200);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}