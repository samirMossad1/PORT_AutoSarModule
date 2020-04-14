

#ifndef  PORT_CFG_H
#define PORT_CFG_H


/*
 * Module's Configurations Version
 * */

#define PORT_CFG_SW_MAJOR_RELEASE_VERSION           (1U)
#define PORT_CFG_SW_MINOR_RELEASE_VERSION           (0U)
#define PORT_CFG_SW_PATCH_RELEASE_VERSION           (0U)


/*
 * AUTOSAR Version
 * */

#define PORT_CFG_AR_MAJOR_RELEASE_VERSION           (4U)
#define PORT_CFG_AR_MINOR_RELEASE_VERSION           (3U)
#define PORT_CFG_AR_PATCH_RELEASE_VERSION           (1U)




/************************************************************************************
 *                General Macros (Hardware Dependent)                               *
 ************************************************************************************/

/*To configure the direction of an output pin*/
#define __OUTPUT_BIT(REG,BIT) (REG|=(1<<BIT))

/*To configure the direction of an input pin*/
#define __INPUT_BIT(REG,BIT) (REG&=(~(1<<BIT)))




/************************************************************************************
 *                Pre-Compile Module Configurations                                 *
 ************************************************************************************/


/*To turn on/off the development errors*/
#define  PORT_DEV_ERROR_DETECT				(STD_ON)

/*To turn on/off the SetPinDireciton API*/
#define	 PORT_SET_PIN_DIRECTION_API			(STD_ON)

/*To turn on/off the SetPinMode API*/
#define	 PORT_SET_PIN_MODE_API				(STD_ON)

/*To turn on/off the VersionInfo API*/
#define	 PORT_VERSION_INFO_API				(STD_ON)

/*To define the maximum number of configured pins*/
#define	MAXIMUM_NUMBER_OF_ALL_PINS			(0x02)

/*To define the maximum number of configured ports*/
#define	MAXIMUM_NUMBER_OF_ALL_PORTS			(0x02)

/*To define the maximum number of configured pins in port A*/
#define MAXIMUM_NUMBER_PORT_A_PINS			(0x01)

/*To define the maximum number of configured pins in port B*/
#define MAXIMUM_NUMBER_PORT_B_PINS			(0x01)

/*To define the maximum number of configured pins in port C*/
#define MAXIMUM_NUMBER_PORT_C_PINS			(0x01)

/*To define the maximum number of configured pins in port D*/
#define MAXIMUM_NUMBER_PORT_D_PINS			(0x01)


/*Different Modes of any pin (HARDWARE DEPENDENT)*/
#define PORT_PIN_MODE_ADC_ID				(0x00)
#define PORT_PIN_MODE_CAS_ID				(0x01)
#define PORT_PIN_MODE_DIO_ID				(0x02)
#define PORT_PIN_MODE_DIO_GPT_ID			(0x03)
#define PORT_PIN_MODE_DIO_WDG_ID			(0x04)
#define PORT_PIN_MODE_FLEXRAY_ID			(0x05)
#define PORT_PIN_MODE_ICU_ID				(0x06)
#define PORT_PIN_MODE_LIN_ID				(0x07)
#define PORT_PIN_MODE_MEM_ID				(0x08)
#define PORT_PIN_MODE_PWM_ID				(0x09)
#define PORT_PIN_MODE_SPI_ID				(0x0A)





#endif
