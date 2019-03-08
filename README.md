![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Gyro2 Click

- **CIC Prefix**  : GYRO2
- **Author**      : Dusan Poluga
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the Gyro2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2604/gyro-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library provides generic functions for working with the click board.

Key functions :

- ``` uint8_t gyro2_getId()  ``` - Function for reading the ID register of the click board.
- ``` void gyro2_getAxisraw(int16_t *axisData) ``` - Function for reading the raw axis data from the click board.
- ``` void gyro2_calcAxis(int16_t *axisData)  ``` - Function for calculating the axis data.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initialize the GPIO and communication structures.
- Application Initialization - Initialize the communication interface and
                               configure the click board.  
- Application Task - Read the x,y,z and temperature data from the click board
                     and display the resoults on the serial port.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2604/gyro-2-click) page.

Other mikroE Libraries used in the example:

- Conversions Library
- C_String Library
- UART Library
- I2C Library
- SPI Library

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
