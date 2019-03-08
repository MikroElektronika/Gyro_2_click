#line 1 "D:/Clicks_git/G/GYRO_2_Click/SW/example/c/ARM/MSP/Click_Gyro2_MSP.c"
#line 1 "d:/clicks_git/g/gyro_2_click/sw/example/c/arm/msp/click_gyro2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/g/gyro_2_click/sw/example/c/arm/msp/click_gyro2_config.h"
#line 1 "d:/clicks_git/g/gyro_2_click/sw/example/c/arm/msp/click_gyro2_types.h"
#line 4 "d:/clicks_git/g/gyro_2_click/sw/example/c/arm/msp/click_gyro2_config.h"
const uint32_t _GYRO2_SPI_CFG[ 7 ] =
{
 _SPI_MASTER,
 64,
 _SPI_CLOCKSOURCE_SMCLK,
 _SPI_MSB_FIRST,
 _SPI_PHASE_DATA_CHANGE_FIRST_CAPTURE_NEXT,
 _SPI_CLK_IDLE_HIGH,
 _SPI_3PIN
};



const uint32_t _GYRO2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 56 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
extern uint8_t GYRO2_STATUS ;
extern uint8_t GYRO2_OUT_X_MSB ;
extern uint8_t GYRO2_OUT_X_LSB ;
extern uint8_t GYRO2_OUT_Y_MSB ;
extern uint8_t GYRO2_OUT_Y_LSB ;
extern uint8_t GYRO2_OUT_Z_MSB ;
extern uint8_t GYRO2_OUT_Z_LSB ;
extern uint8_t GYRO2_DR_STATUS ;
extern uint8_t GYRO2_F_STATUS ;
extern uint8_t GYRO2_F_SETUP ;
extern uint8_t GYRO2_F_EVENT ;
extern uint8_t GYRO2_INT_SRC_FLAG;
extern uint8_t GYRO2_WHO_AM_I ;
extern uint8_t GYRO2_CTRL_REG0 ;
extern uint8_t GYRO2_RT_CFG ;
extern uint8_t GYRO2_RT_SRC ;
extern uint8_t GYRO2_RT_THS ;
extern uint8_t GYRO2_RT_COUNT ;
extern uint8_t GYRO2_TEMP ;
extern uint8_t GYRO2_CTRL_REG1 ;
extern uint8_t GYRO2_CTRL_REG2 ;
extern uint8_t GYRO2_CTRL_REG3 ;
extern uint8_t GYRO2_ADDR0 ;
extern uint8_t GYRO2_ADDR1 ;

extern uint8_t GYRO2_DR_800Hz ;
extern uint8_t GYRO2_DR_400Hz ;
extern uint8_t GYRO2_DR_200Hz ;
extern uint8_t GYRO2_DR_100Hz ;
extern uint8_t GYRO2_DR_50Hz ;
extern uint8_t GYRO2_DR_25Hz ;
extern uint8_t GYRO2_DR_12_5Hz ;
extern uint8_t GYRO2_Standby ;
extern uint8_t GYRO2_Ready ;
extern uint8_t GYRO2_Active ;

extern uint8_t GYRO2_INT_CFG_FIFO_INT1 ;
extern uint8_t GYRO2_INT_CFG_FIFO_INT2 ;
extern uint8_t GYRO2_INT_EN_FIFO ;
extern uint8_t GYRO2_INT_DIS_FIFO ;
extern uint8_t GYRO2_INT_CFG_RT_INT1 ;
extern uint8_t GYRO2_INT_CFG_RT_INT2 ;
extern uint8_t GYRO2_INT_EN_RT ;
extern uint8_t GYRO2_DIS_EN_RT ;
extern uint8_t GYRO2_INT_CFG_DRDY_INT1 ;
extern uint8_t GYRO2_INT_CFG_DRDY_INT2 ;
extern uint8_t GYRO2_INT_EN_DRDY ;
extern uint8_t GYRO2_INT_DIS_DRDY ;
extern uint8_t GYRO2_IPOL_ACTIVE_HI ;
extern uint8_t GYRO2_IPOL_ACTIVE_LO ;
extern uint8_t GYRO2_PP_OD_OS ;
extern uint8_t GYRO2_PP_OD_PUSH_PULL ;

extern uint8_t GYRO2_RT_CFG_ELE ;
extern uint8_t GYRO2_RT_CFG_ZTEFE ;
extern uint8_t GYRO2_RT_CFG_YTEFE ;
extern uint8_t GYRO2_RT_CFG_XTEFE ;

extern uint8_t GYRO2_SCALE_0;
extern uint8_t GYRO2_SCALE_1;
extern uint8_t GYRO2_SCALE_2;
extern uint8_t GYRO2_SCALE_3;

extern uint8_t GYRO2_HI_PASS_OFF;
extern uint8_t GYRO2_HI_PASS_MOD0;
extern uint8_t GYRO2_HI_PASS_MOD1;
extern uint8_t GYRO2_HI_PASS_MOD2;
extern uint8_t GYRO2_HI_PASS_MOD3;

extern uint8_t GYRO2_LO_PASS_OFF;
extern uint8_t GYRO2_LO_PASS_MOD0;
extern uint8_t GYRO2_LO_PASS_MOD1;
extern uint8_t GYRO2_LO_PASS_MOD2;
#line 142 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);


void gyro2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 152 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_gpioDriverInit( const uint8_t*  gpioObj);
#line 161 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
uint8_t gyro2_singleRead(uint8_t rAddr);
#line 166 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_singleWrite(uint8_t wAddr, uint8_t rAddr);
#line 171 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
uint8_t gyro2_getID();
#line 177 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_getAxisraw(uint16_t *axisData);
#line 182 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_calcAxis(int16_t *axisData);
#line 187 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
uint8_t gyro2_intPin();
#line 192 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_swReset();
#line 197 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_setDR(uint8_t rate);
#line 202 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_setOpmode(uint8_t opmode);
#line 207 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_cfgInterrupt(uint8_t intCfg);
#line 212 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_interruptCfg(uint8_t intRoute, uint8_t intEn, uint8_t polarity_outdrvsetting);
#line 217 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
uint8_t gyro2_pwmPin();
#line 222 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_interruptEventgeneration(uint8_t cfg);
#line 227 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_sensitivity(uint8_t sSetting);
#line 232 "d:/clicks_git/g/gyro_2_click/sw/library/__gyro2_driver.h"
void gyro2_frSetup(uint8_t lowPass, uint8_t hiPass, uint8_t scaleSet);
#line 35 "D:/Clicks_git/G/GYRO_2_Click/SW/example/c/ARM/MSP/Click_Gyro2_MSP.c"
int16_t axisDatatmp[4];
char text[20];

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );


 mikrobus_i2cInit( _MIKROBUS1, &_GYRO2_I2C_CFG[0] );


 mikrobus_logInit( _MIKROBUS2, 9600 );

 Delay_ms( 100 );
}

void applicationInit()
{

 gyro2_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, GYRO2_ADDR1 );



 mikrobus_logWrite("+++ System Initialized +++",_LOG_LINE);
 Delay_ms(1000);

 if(gyro2_getID() == 0xD7)
 {
 mikrobus_logWrite("Gyro 2 click present",_LOG_LINE);
 gyro2_interruptEventgeneration(GYRO2_RT_CFG_ZTEFE | GYRO2_RT_CFG_YTEFE | GYRO2_RT_CFG_XTEFE);
 gyro2_sensitivity(10);
 gyro2_setOpmode(GYRO2_Active);
 gyro2_setDR(GYRO2_DR_100Hz);
 gyro2_interruptCfg( GYRO2_INT_CFG_FIFO_INT1, GYRO2_INT_EN_FIFO | GYRO2_INT_EN_DRDY, GYRO2_IPOL_ACTIVE_HI );
 gyro2_frSetup(GYRO2_LO_PASS_MOD2, GYRO2_HI_PASS_OFF, GYRO2_SCALE_3);
 }
 else
 {
 mikrobus_logWrite("error",_LOG_LINE);
 while(1);
 }
 Delay_ms(1000);
}

void applicationTask()
{
 if(gyro2_pwmPin())
 {
 gyro2_getAxisraw(&axisDatatmp[0]);
 gyro2_calcAxis(&axisDatatmp[0]);

 IntToStr( axisDatatmp[0], text);
 mikrobus_logWrite( "X: ",_LOG_TEXT);
 Ltrim(text);
 mikrobus_logWrite( text,_LOG_LINE);
 IntToStr( axisDatatmp[1], text);
 mikrobus_logWrite( "Y: ",_LOG_TEXT);
 Ltrim(text);
 mikrobus_logWrite( text,_LOG_LINE);
 IntToStr( axisDatatmp[2], text);
 mikrobus_logWrite( "Z: ",_LOG_TEXT);
 Ltrim(text);
 mikrobus_logWrite( text,_LOG_LINE);
 mikrobus_logWrite("---",_LOG_LINE);
 }
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
