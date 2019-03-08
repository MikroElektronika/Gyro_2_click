/*
    __gyro2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __gyro2_driver.h
@brief    Gyro2 Driver
@mainpage Gyro2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   GYRO2
@brief      Gyro2 Click Driver
@{

| Global Library Prefix | **GYRO2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Dusan Poluga**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _GYRO2_H_
#define _GYRO2_H_

/** 
 * @macro T_GYRO2_P
 * @brief Driver Abstract type 
 */
#define T_GYRO2_P    const uint8_t*

/** @defgroup GYRO2_COMPILE Compilation Config */              /** @{ */

   #define   __GYRO2_DRV_SPI__                            /**<     @macro __GYRO2_DRV_SPI__  @brief SPI driver selector */
   #define   __GYRO2_DRV_I2C__                            /**<     @macro __GYRO2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __GYRO2_DRV_UART__                           /**<     @macro __GYRO2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup GYRO2_VAR Variables */                           /** @{ */

extern const uint8_t GYRO2_ADDR0;
extern const uint8_t GYRO2_ADDR1;

extern const uint8_t GYRO2_STATUS    ;
extern const uint8_t GYRO2_OUT_X_MSB ;
extern const uint8_t GYRO2_OUT_X_LSB ;
extern const uint8_t GYRO2_OUT_Y_MSB ;             
extern const uint8_t GYRO2_OUT_Y_LSB ;
extern const uint8_t GYRO2_OUT_Z_MSB ;
extern const uint8_t GYRO2_OUT_Z_LSB ;
extern const uint8_t GYRO2_DR_STATUS ;
extern const uint8_t GYRO2_F_STATUS  ;
extern const uint8_t GYRO2_F_SETUP   ;
extern const uint8_t GYRO2_F_EVENT   ;
extern const uint8_t GYRO2_INT_SRC_FLAG ;
extern const uint8_t GYRO2_WHO_AM_I     ;
extern const uint8_t GYRO2_CTRL_REG0    ;
/* bits start */
extern const uint8_t GYRO2_SCALE_0 ;
extern const uint8_t GYRO2_SCALE_1 ;
extern const uint8_t GYRO2_SCALE_2 ;
extern const uint8_t GYRO2_SCALE_3 ;

extern const uint8_t GYRO2_HI_PASS_OFF  ;
extern const uint8_t GYRO2_HI_PASS_MOD0 ;
extern const uint8_t GYRO2_HI_PASS_MOD1 ;
extern const uint8_t GYRO2_HI_PASS_MOD2 ;
extern const uint8_t GYRO2_HI_PASS_MOD3 ;

extern const uint8_t GYRO2_LO_PASS_OFF  ;
extern const uint8_t GYRO2_LO_PASS_MOD0 ;
extern const uint8_t GYRO2_LO_PASS_MOD1 ;
extern const uint8_t GYRO2_LO_PASS_MOD2 ;
/* bits end */

extern const uint8_t GYRO2_RT_CFG       ;
/* bits start */
extern const uint8_t GYRO2_RT_CFG_ELE   ;
extern const uint8_t GYRO2_RT_CFG_ZTEFE ;
extern const uint8_t GYRO2_RT_CFG_YTEFE ;
extern const uint8_t GYRO2_RT_CFG_XTEFE ;

/* bits end */

extern const uint8_t GYRO2_RT_SRC       ;
extern const uint8_t GYRO2_RT_THS       ;
extern const uint8_t GYRO2_RT_COUNT     ;
extern const uint8_t GYRO2_TEMP         ;

/* reg */
extern const uint8_t GYRO2_CTRL_REG1    ;
/* bits */
extern const uint8_t GYRO2_DR_800Hz     ;
extern const uint8_t GYRO2_DR_400Hz     ;
extern const uint8_t GYRO2_DR_200Hz     ;
extern const uint8_t GYRO2_DR_100Hz     ;
extern const uint8_t GYRO2_DR_50Hz      ;
extern const uint8_t GYRO2_DR_25Hz      ;
extern const uint8_t GYRO2_DR_12_5Hz    ;
extern const uint8_t GYRO2_Standby      ;
extern const uint8_t GYRO2_Ready        ;
extern const uint8_t GYRO2_Active       ;
/*reg*/

extern const uint8_t GYRO2_CTRL_REG2    ;
/*----------- bits ------------*/
extern const uint8_t GYRO2_INT_CFG_FIFO_INT1 ;
extern const uint8_t GYRO2_INT_CFG_FIFO_INT2 ;
extern const uint8_t GYRO2_INT_EN_FIFO       ;
extern const uint8_t GYRO2_INT_DIS_FIFO      ;
extern const uint8_t GYRO2_INT_CFG_RT_INT1   ;
extern const uint8_t GYRO2_INT_CFG_RT_INT2   ;
extern const uint8_t GYRO2_INT_EN_RT         ;
extern const uint8_t GYRO2_DIS_EN_RT         ;
extern const uint8_t GYRO2_INT_CFG_DRDY_INT1 ;
extern const uint8_t GYRO2_INT_CFG_DRDY_INT2 ;
extern const uint8_t GYRO2_INT_EN_DRDY       ;
extern const uint8_t GYRO2_INT_DIS_DRDY      ;
extern const uint8_t GYRO2_IPOL_ACTIVE_HI    ;
extern const uint8_t GYRO2_IPOL_ACTIVE_LO    ;
extern const uint8_t GYRO2_PP_OD_OS          ;
extern const uint8_t GYRO2_PP_OD_PUSH_PULL   ;
extern const uint8_t GYRO2_CTRL_REG3         ;


                                                                       /** @} */
/** @defgroup GYRO2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup GYRO2_INIT Driver Initialization */              /** @{ */

#ifdef   __GYRO2_DRV_SPI__
void gyro2_spiDriverInit(T_GYRO2_P gpioObj, T_GYRO2_P spiObj);
#endif
#ifdef   __GYRO2_DRV_I2C__
void gyro2_i2cDriverInit(T_GYRO2_P gpioObj, T_GYRO2_P i2cObj, uint8_t slave);
#endif
                                                                       /** @} */
/** @defgroup GYRO2_FUNC Driver Functions */                   /** @{ */

/**
 * Function for setting the chip select pin.
 */
void gyro2_scsSet(uint8_t val);

/**
 * Function for setting the hw reset pin.
 */
void gyro2_rstSet(uint8_t val);

/**
 * Function for setting the communication interface.
 *  0 - I2C inteface enabled
 *  1 - SPI interface enabled 
 */
void gyro2_csSet(uint8_t val);

/**
 * Function for setting the ready pin.
 */
void gyro2_rdySet(uint8_t val);

/**
 * Function for reading the state of the ready pin.
 */
uint8_t gyro2_rdyGet();

/**
 * Function for reading the state of the interrupt pin.
 */
uint8_t gyro2_intGet();

/**
 * Function for hardware reset of the device.
 */
void gyro2_hwReset();

/** 
  Function for tringgering a software reset of the click board.
  */
void gyro2_swReset();

/** 
 * Function for single byte writes.
 */
void gyro2_writeReg(uint8_t rAddr, uint8_t rData);


/** 
 * Function for single byte reads.
 */
uint8_t gyro2_readReg(uint8_t rAddr);


/**
    Function will return the ID from the ID register
  */
uint8_t gyro2_getId();

/**
  Function will read the X, Y and Z axis registers.
  Data that is read is storred the 3 16bit array.
  */
void gyro2_getAxisraw(int16_t *axisData);

/**
  Function for calculating raw axis data.
  */
void gyro2_calcAxis(int16_t *axisData);

/**
   Function for setting the operation mode of the click board.
  */
void gyro2_setOpmode(uint8_t opmode);

/**
  Function for setting the data rate.
*/
void gyro2_setDR(uint8_t rate);

/**
  Function for configuring Interrupt register
  */
void gyro2_cfgInterrupt(uint8_t intCfg);

/**
   Function for configuring interrupts and output modes of the interrupt pins.
   */
void gyro2_interruptCfg(uint8_t intRoute, uint8_t intEn, uint8_t polarity_outdrvsetting);


/**
   Function for setting the sensitivity.
 */
void gyro2_sensitivity(uint8_t sSetting);

/**
   Function for enabling interrupt event generation
   */
void gyro2_interruptEventgeneration(uint8_t cfg);

/**
  Function for configuring Interrupt register
  */
void gyro2_cfgInterrupt(uint8_t intCfg);

/**
   Function for setting filters and the full scale of the measurement.
  */
void gyro2_frSetup(uint8_t lowPass, uint8_t hiPass, uint8_t scaleSet);

/**
 * Function for readign the temperature register.
 */
uint8_t gyro2_readTemperature();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Gyro2_STM.c
    @example Click_Gyro2_TIVA.c
    @example Click_Gyro2_CEC.c
    @example Click_Gyro2_KINETIS.c
    @example Click_Gyro2_MSP.c
    @example Click_Gyro2_PIC.c
    @example Click_Gyro2_PIC32.c
    @example Click_Gyro2_DSPIC.c
    @example Click_Gyro2_AVR.c
    @example Click_Gyro2_FT90x.c
    @example Click_Gyro2_STM.mbas
    @example Click_Gyro2_TIVA.mbas
    @example Click_Gyro2_CEC.mbas
    @example Click_Gyro2_KINETIS.mbas
    @example Click_Gyro2_MSP.mbas
    @example Click_Gyro2_PIC.mbas
    @example Click_Gyro2_PIC32.mbas
    @example Click_Gyro2_DSPIC.mbas
    @example Click_Gyro2_AVR.mbas
    @example Click_Gyro2_FT90x.mbas
    @example Click_Gyro2_STM.mpas
    @example Click_Gyro2_TIVA.mpas
    @example Click_Gyro2_CEC.mpas
    @example Click_Gyro2_KINETIS.mpas
    @example Click_Gyro2_MSP.mpas
    @example Click_Gyro2_PIC.mpas
    @example Click_Gyro2_PIC32.mpas
    @example Click_Gyro2_DSPIC.mpas
    @example Click_Gyro2_AVR.mpas
    @example Click_Gyro2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __gyro2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */

