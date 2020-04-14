
#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_


/*************************************************************************************
 *                              PORT Module TypeDefs                                  *
 *************************************************************************************/

#if (PORT_MAXIMUM_NUMBER_OF_PORTS <= 8)
typedef uint8 Port_PortType;
#else
typedef uint16 Port_PortType;
#endif

#if (PORT_MAXIMUM_NUMBER_OF_PINS <= 8)
typedef uint8 Port_PinType;
#else
typedef uint16 Port_PinType;
#endif

#if (PORT_MAXIMUM_NUMBER_OF_PIN_MODES <= 8)
typedef uint8 Port_PinModeType;
#else
typedef uint16 Port_PinModeType;
#endif

typedef uint8 EcucBooleanParamDef;
typedef uint16 EcucIntegerParamDef;




/*************************************************************************************
 *                               PORT Module Enumerations                             *
 *************************************************************************************/



typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT

}Port_PinDirectionType;

typedef enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAS,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI

}Port_PinMode;


typedef enum
{
	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW

}Port_PinLevel;


typedef struct
{
	volatile uint8*	PortDirectionRegisterAddress;
	volatile uint8*	PortDataOutputRegisterAddress;
	volatile uint8*	PortDataInputRegisterAddress;

}PortRegisterAdd;




/*************************************************************************************
 *                               PORT Module Structures                               *
 *************************************************************************************/

typedef struct
{
	Port_PinType		 	PortPinId;
	Port_PortType			ParentPortId;
	Port_PinDirectionType 	PortPinDirection;
	Port_PinModeType		PortPinInitialMode;
	Port_PinLevel			PortPinLevelValue;
	Port_PinModeType*		PortPinMode;
	EcucBooleanParamDef 	boolPortPinDirectionChangeable;
	EcucBooleanParamDef		boolPortPinModeChangeable;
	uint8					u8PinNumberOfPinModes;

}PortPin;

typedef struct
{
	PortPin*			PortPinRef;
	Port_PinType		PortNumberOfPortPins;

}PortContainer;



typedef struct
{

	PortContainer*	 		PortContainerRef;
	Port_PortType			PortModuleNumberOfPorts;


}Port_ConfigType;


#endif
