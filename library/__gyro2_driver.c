/*
    __gyro2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__gyro2_driver.h"
#include "__gyro2_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __GYRO2_DRV_I2C__
static uint8_t _slaveAddress;
#endif
static uint8_t GYRO2_INTERFACE_SELECT;
static uint8_t GYRO2_I2C_SELECT = 1;
static uint8_t GYRO2_SPI_SELECT = 2;

const uint8_t GYRO2_ADDR0 = 0x20;
const uint8_t GYRO2_ADDR1 = 0x21;


const uint8_t GYRO2_STATUS        = 0x00;
const uint8_t GYRO2_OUT_X_MSB     = 0x01;
const uint8_t GYRO2_OUT_X_LSB     = 0x02;
const uint8_t GYRO2_OUT_Y_MSB     = 0x03;             
const uint8_t GYRO2_OUT_Y_LSB     = 0x04;
const uint8_t GYRO2_OUT_Z_MSB     = 0x05;
const uint8_t GYRO2_OUT_Z_LSB     = 0x06;
const uint8_t GYRO2_DR_STATUS     = 0x07;
const uint8_t GYRO2_F_STATUS      = 0x08;
const uint8_t GYRO2_F_SETUP       = 0x09;
const uint8_t GYRO2_F_EVENT       = 0x0A;
const uint8_t GYRO2_INT_SRC_FLAG  = 0x0B;
const uint8_t GYRO2_WHO_AM_I      = 0x0C;
const uint8_t GYRO2_CTRL_REG0     = 0x0D;
/* bits start */
const uint8_t GYRO2_SCALE_0 = 0;
const uint8_t GYRO2_SCALE_1 = 1;
const uint8_t GYRO2_SCALE_2 = 2;
const uint8_t GYRO2_SCALE_3 = 3;

const uint8_t GYRO2_HI_PASS_OFF  = 0;
const uint8_t GYRO2_HI_PASS_MOD0 = 0x04;
const uint8_t GYRO2_HI_PASS_MOD1 = 0x0C;
const uint8_t GYRO2_HI_PASS_MOD2 = 0x14;
const uint8_t GYRO2_HI_PASS_MOD3 = 0x1C;

const uint8_t GYRO2_LO_PASS_OFF  = 0;
const uint8_t GYRO2_LO_PASS_MOD0 = 0x20;
const uint8_t GYRO2_LO_PASS_MOD1 = 0x60;
const uint8_t GYRO2_LO_PASS_MOD2 = 0xE0;
/* bits end */

const uint8_t GYRO2_RT_CFG        = 0x0E;
/* bits start */
const uint8_t GYRO2_RT_CFG_ELE   = 0x08;
const uint8_t GYRO2_RT_CFG_ZTEFE = 0x04;
const uint8_t GYRO2_RT_CFG_YTEFE = 0x02;
const uint8_t GYRO2_RT_CFG_XTEFE = 0x01;

/* bits end */

const uint8_t GYRO2_RT_SRC        = 0x0F;
const uint8_t GYRO2_RT_THS        = 0x10;
const uint8_t GYRO2_RT_COUNT      = 0x11;
const uint8_t GYRO2_TEMP          = 0x12;

/* reg */
const uint8_t GYRO2_CTRL_REG1     = 0x13;
/* bits */
const uint8_t GYRO2_DR_800Hz      = 0;
const uint8_t GYRO2_DR_400Hz      = 1;
const uint8_t GYRO2_DR_200Hz      = 2;
const uint8_t GYRO2_DR_100Hz      = 3;
const uint8_t GYRO2_DR_50Hz       = 4;
const uint8_t GYRO2_DR_25Hz       = 5;
const uint8_t GYRO2_DR_12_5Hz     = 6;
const uint8_t GYRO2_Standby       = 0;
const uint8_t GYRO2_Ready         = 1;
const uint8_t GYRO2_Active        = 3;
/*reg*/

const uint8_t GYRO2_CTRL_REG2     = 0x14;
/*----------- bits ------------*/
const uint8_t GYRO2_INT_CFG_FIFO_INT1 = 0x80;
const uint8_t GYRO2_INT_CFG_FIFO_INT2 = 0x00;
const uint8_t GYRO2_INT_EN_FIFO       = 0x40;
const uint8_t GYRO2_INT_DIS_FIFO      = 0x00;
const uint8_t GYRO2_INT_CFG_RT_INT1   = 0x20;
const uint8_t GYRO2_INT_CFG_RT_INT2   = 0x00;
const uint8_t GYRO2_INT_EN_RT         = 0x10;
const uint8_t GYRO2_DIS_EN_RT         = 0x00;
const uint8_t GYRO2_INT_CFG_DRDY_INT1 = 0x08;
const uint8_t GYRO2_INT_CFG_DRDY_INT2 = 0x00;
const uint8_t GYRO2_INT_EN_DRDY       = 0x04;
const uint8_t GYRO2_INT_DIS_DRDY      = 0x00;
const uint8_t GYRO2_IPOL_ACTIVE_HI    = 0x02;
const uint8_t GYRO2_IPOL_ACTIVE_LO    = 0x00;
const uint8_t GYRO2_PP_OD_OS          = 0x01;
const uint8_t GYRO2_PP_OD_PUSH_PULL   = 0x00;
/* ------end bits---------- */
const uint8_t GYRO2_CTRL_REG3     = 0x15;

static uint8_t _tmp_ctrl_reg0;
static uint8_t _tmp_ctrl_reg1;
static uint8_t _tmp_ctrl_reg2;
static uint8_t _tmp_ctrl_reg3;

//0x16 - 0xFF reserved


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __GYRO2_DRV_SPI__

void gyro2_spiDriverInit(T_GYRO2_P gpioObj, T_GYRO2_P spiObj)
{
    GYRO2_INTERFACE_SELECT = GYRO2_SPI_SELECT;
    _tmp_ctrl_reg0 = 0;
    _tmp_ctrl_reg1 = 0;
    _tmp_ctrl_reg2 = 0;
    _tmp_ctrl_reg3 = 0;


    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
    hal_gpio_rstSet(1);                                                         //HW reset
    hal_gpio_anSet(1);                                                          //SPI CS pin
    hal_gpio_csSet(1);                                                          //interface select pin 1 for SPI
}

#endif
#ifdef   __GYRO2_DRV_I2C__

void gyro2_i2cDriverInit(T_GYRO2_P gpioObj, T_GYRO2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    GYRO2_INTERFACE_SELECT = GYRO2_I2C_SELECT;
    _tmp_ctrl_reg0 = 0;
    _tmp_ctrl_reg1 = 0;
    _tmp_ctrl_reg2 = 0;
    _tmp_ctrl_reg3 = 0;

    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
    hal_gpio_rstSet(1);                                                         //HW reset
    hal_gpio_anSet(1);                                                          //SPI CS pin
    hal_gpio_csSet(0);                                                          //interface select pin 0 for I2C
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */
void gyro2_scsSet(uint8_t val)
{
    hal_gpio_anSet(val);
}

void gyro2_rstSet(uint8_t val)
{
    hal_gpio_rstSet(val);
}

void gyro2_csSet(uint8_t val)
{
    hal_gpio_csSet(val);
}

void gyro2_rdySet(uint8_t val)
{
    hal_gpio_pwmSet(val);
}

uint8_t gyro2_rdyGet()
{
    return hal_gpio_pwmGet();
}

uint8_t gyro2_intGet()
{
    return hal_gpio_intGet();
}

void gyro2_hwReset()
{
    hal_gpio_rstSet(0);
    Delay_10ms();
    hal_gpio_rstSet(1);
    Delay_10ms();
}

void gyro2_writeReg(uint8_t rAddr, uint8_t rData)
{
    uint8_t tempBuff[3];
    tempBuff[0] = rAddr;
    tempBuff[1] = rData;

    if(GYRO2_INTERFACE_SELECT == GYRO2_SPI_SELECT)
    {
        hal_gpio_anSet(0);
        hal_spiTransfer(&tempBuff[0],&tempBuff[0],2);
        hal_gpio_anSet(1);
    }
    else
    {
        hal_i2cStart();
        hal_i2cWrite(_slaveAddress,&tempBuff[0],2,END_MODE_STOP);
    }
}

uint8_t gyro2_readReg(uint8_t rAddr)
{
    uint8_t tempBuff[3];
    tempBuff[0] = rAddr;

    if(GYRO2_INTERFACE_SELECT == GYRO2_SPI_SELECT)
    {
        tempBuff[0] |= 0x80;
        hal_gpio_anSet(0);
        hal_spiTransfer(&tempBuff[0],&tempBuff[0],2);
        hal_gpio_anSet(1);
        return tempBuff[1];
    }
    else
    {
        hal_i2cStart();
        hal_i2cWrite(_slaveAddress,&tempBuff[0],1,END_MODE_RESTART);
        hal_i2cRead(_slaveAddress,&tempBuff[0],1,END_MODE_STOP);
        return tempBuff[0];
    }
}

uint8_t gyro2_getId()
{
    return gyro2_readReg(GYRO2_WHO_AM_I);
}

void gyro2_getAxisraw(int16_t *axisData)
{
    uint8_t reg_data[7];
    uint8_t addrData[7];
    uint8_t addOne;

    addrData[0] = GYRO2_OUT_X_MSB;
    if(GYRO2_INTERFACE_SELECT == GYRO2_SPI_SELECT)
    {
      addrData[0] |= 0x80;
      hal_gpio_anSet(0);
      hal_spiTransfer(&addrData[0],&reg_data[0],7);
      hal_gpio_anSet(1);
      addOne = 1;
    }
    else 
    {
        addOne = 0;
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, &addrData[0], 1, END_MODE_RESTART );
        hal_i2cRead( _slaveAddress, &reg_data[0], 6, END_MODE_STOP );
    }
    axisData[0] = (uint16_t)(reg_data[0+addOne]<<8) | reg_data[1+addOne];
    axisData[1] = (uint16_t)(reg_data[2+addOne]<<8) | reg_data[3+addOne];
    axisData[2] = (uint16_t)(reg_data[4+addOne]<<8) | reg_data[5+addOne];
}

void gyro2_calcAxis(int16_t *axisData)
{
   axisData[0] = ( axisData[0] * 0.015625 / 88 * 3.0 );
   axisData[1] = ( axisData[1] * 0.015625 / 88 * 3.0 );
   axisData[2] = ( axisData[2] * 0.015625 / 88 * 3.0 );
}

uint8_t gyro2_readTemperature()
{
    return gyro2_readReg(GYRO2_TEMP);
}

void gyro2_swReset()
{
    _tmp_ctrl_reg1 = gyro2_readReg(GYRO2_CTRL_REG1);
    _tmp_ctrl_reg1 |= 1<<6;
    gyro2_writeReg(GYRO2_CTRL_REG1,_tmp_ctrl_reg1);
}

void gyro2_setDR(uint8_t rate)
{
    if(rate>7) rate = 7;
    _tmp_ctrl_reg1 = gyro2_readReg(GYRO2_CTRL_REG1);
    _tmp_ctrl_reg1 &= ~(7<<2); //clear the DR bitfield before setting
    _tmp_ctrl_reg1 |= (rate<<2);
    gyro2_writeReg(GYRO2_CTRL_REG1, _tmp_ctrl_reg1);
}

void gyro2_setOpmode(uint8_t opmode)
{
    if(opmode>3) opmode = 3;
    _tmp_ctrl_reg1 = gyro2_readReg(GYRO2_CTRL_REG1);
    _tmp_ctrl_reg1 &= ~3; //clear the DR bitfield before setting
    _tmp_ctrl_reg1 |= opmode;
    gyro2_writeReg(GYRO2_CTRL_REG1, _tmp_ctrl_reg1);
}

/* Interrupt register start */
void gyro2_interruptCfg(uint8_t intRoute, uint8_t intEn, uint8_t polarity_outdrvsetting)
{
   // Test if the parameter IntPin has the bit set/reset and place 1 or 0 on the correct bitfield.
   // interrupt enable
   _tmp_ctrl_reg2 = (intEn & 1<<2) ? ( _tmp_ctrl_reg2 | 4 ) : ( _tmp_ctrl_reg2 & 0xFB );
   _tmp_ctrl_reg2 = (intEn & 1<<4) ? ( _tmp_ctrl_reg2 | 16 ) : ( _tmp_ctrl_reg2 & 0xEF );
   _tmp_ctrl_reg2 = (intEn & 1<<6) ? ( _tmp_ctrl_reg2 | 64 ) : ( _tmp_ctrl_reg2 & 0xBF );
   // logic polarity and push pull output driver
   _tmp_ctrl_reg2 = (polarity_outdrvsetting & 1) ? ( _tmp_ctrl_reg2 | 1 ) : ( _tmp_ctrl_reg2 & 0xFE );
   _tmp_ctrl_reg2 = (polarity_outdrvsetting & 1<<1) ? ( _tmp_ctrl_reg2 | 2 ) : ( _tmp_ctrl_reg2 & 0xFD );
   // CFG route
    _tmp_ctrl_reg2 = (intRoute & 1<<3) ? ( _tmp_ctrl_reg2 | 8 )  : ( _tmp_ctrl_reg2 & 0xF7 );
    _tmp_ctrl_reg2 = (intRoute & 1<<5) ? ( _tmp_ctrl_reg2 | 32 ) : ( _tmp_ctrl_reg2 & 0xDF );
    _tmp_ctrl_reg2 = (intRoute & 1<<7) ? ( _tmp_ctrl_reg2 | 128 ) : ( _tmp_ctrl_reg2 & 0x7F );
    
    gyro2_writeReg(GYRO2_CTRL_REG2, _tmp_ctrl_reg2);
}

void gyro2_interruptEventgeneration(uint8_t cfg)
{
   uint8_t tmp;
   tmp = ( cfg & 0x0F );
   gyro2_writeReg( GYRO2_RT_CFG, tmp );
}

void gyro2_sensitivity(uint8_t sSetting)
{
   uint8_t tmp;
   tmp = ( sSetting & 0x7F );
   gyro2_writeReg( GYRO2_RT_THS, tmp );
}
/* Interrupt register end */

/* filter and range setup*/
void gyro2_frSetup(uint8_t lowPass, uint8_t hiPass, uint8_t scaleSet)
{
   uint8_t tmp;
   tmp =  ( lowPass & 0xC0 );
   tmp |= ( hiPass &  0x1C );
   tmp |= ( scaleSet  & 0x03 );
   gyro2_writeReg(GYRO2_CTRL_REG0, tmp );
}
/* -------------------------------------------------------------------------- */
/*
  __gyro2_driver.c

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
