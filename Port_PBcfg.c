
#include "Port.h"



PortPin PortModulePinsList[MAXIMUM_NUMBER_OF_ALL_PINS]=
{
		{
				.PortPinId=PIN_0,
				.ParentPortId=PORT_A,
				.PortPinDirection=PORT_PIN_OUT,
				.PortPinInitialMode=PORT_PIN_MODE_DIO_ID,
				.PortPinLevelValue=PORT_PIN_LEVEL_HIGH,
				.PortPinMode=NULL_PTR,
				.boolPortPinDirectionChangeable=TRUE,
				.boolPortPinModeChangeable=FALSE,
				.u8PinNumberOfPinModes=0

		}
		,
		{
				.PortPinId=PIN_1,
				.ParentPortId=PORT_B,
				.PortPinDirection=PORT_PIN_IN,
				.PortPinInitialMode=PORT_PIN_MODE_DIO_ID,
				.PortPinLevelValue=PORT_PIN_LEVEL_HIGH,
				.PortPinMode=NULL_PTR,
				.boolPortPinDirectionChangeable=FALSE,
				.boolPortPinModeChangeable=FALSE,
				.u8PinNumberOfPinModes=0

		}


};

PortContainer PortModulePortsList[MAXIMUM_NUMBER_OF_ALL_PORTS]=
{
		{
				.PortPinRef=PortModulePinsList,
				.PortNumberOfPortPins=MAXIMUM_NUMBER_PORT_A_PINS
		}
		,
		{
				.PortPinRef=&PortModulePinsList[1],
				.PortNumberOfPortPins=MAXIMUM_NUMBER_PORT_B_PINS
		}
};


Port_ConfigType PortConfigStruct=
{
		.PortContainerRef=PortModulePortsList,
		.PortModuleNumberOfPorts=MAXIMUM_NUMBER_OF_ALL_PORTS
};
