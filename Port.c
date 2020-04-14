/************************************************************************************
 *                                 Required Includes                                *
 ************************************************************************************/

/*Include the Development Error Tracer Module to report DET Errors*/
#include "Det.h"

/*Include The PORT Module Header File*/
#include "Port.h"




/*************************************************************************************
 *                               Global Static Variables                             *
 *************************************************************************************/

STATIC boolean				boolPortModuleInitStatus=FALSE;
STATIC PortPin*				PortPinsRef=NULL_PTR;
STATIC PortContainer*		PortContainersRef=NULL_PTR;




/*************************************************************************************
 *                           Helper Functions Prototypes                             *
 *************************************************************************************/

STATIC void get_PortRegisterAddress( Port_PortType portId ,PortRegisterAdd* PortRegisterAddress);
STATIC void port_adjustPin(Port_PinType PortPinId,Port_PinDirectionType Direction,PortRegisterAdd* registerStruct);





/*************************************************************************************
 *                           Functions Implementation                                *
 *************************************************************************************/

void Port_Init( const Port_ConfigType* ConfigPtr )
{

	Port_PortType  			portCounter;
	Port_PinType   			pinCounter;
	Port_PinType			pinId=0;
	PortRegisterAdd		    registerStruct;
	boolean 				boolDevError=FALSE;


#if ( PORT_DEV_ERROR_DETECT == STD_ON)

	if(NULL_PTR == ConfigPtr)
	{

		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_PORT_INIT_ID,
				PORT_E_PARAM_POINTER );

		boolDevError=TRUE;

	}
	else
	{

	}

#endif

	if(FALSE == boolDevError)
	{

		PortContainersRef=ConfigPtr->PortContainerRef;
		PortPinsRef=PortContainersRef->PortPinRef;

		boolPortModuleInitStatus=PORT_MODULE_INITALIZED;


		for(portCounter=0;portCounter<ConfigPtr->PortModuleNumberOfPorts;portCounter++)
		{

			get_PortRegisterAddress(portCounter,&registerStruct);

			for(pinCounter=0;pinCounter<PortContainersRef[portCounter].PortNumberOfPortPins;pinCounter++)
			{

				port_adjustPin(pinId,PortPinsRef[pinId].PortPinDirection,&registerStruct);

				pinId++;

			}
		}


	}
	else
	{

	}

}

/********************************************************************************************************************/

void Port_RefreshPortDirection( void )
{
	Port_PortType  			portCounter;
	Port_PinType   			pinCounter;
	PortRegisterAdd		    registerStruct;
	Port_PinType			pinId=0;


	for(portCounter=0;portCounter<MAXIMUM_NUMBER_OF_ALL_PORTS;portCounter++)
	{

		get_PortRegisterAddress(portCounter,&registerStruct);

		for(pinCounter=0;pinCounter<PortContainersRef[portCounter].PortNumberOfPortPins;pinCounter++)
		{

			if( FALSE == PortPinsRef[pinId].boolPortPinDirectionChangeable )
			{
				port_adjustPin(pinId,PortPinsRef[pinId].PortPinDirection,&registerStruct);
			}
			else
			{

			}

			pinId++;

		}
	}
}



/********************************************************************************************************************/

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{

	PortRegisterAdd		registerStruct;


	boolean boolDevError=FALSE;

#if ( PORT_DEV_ERROR_DETECT == STD_ON)

	if(Pin >= MAXIMUM_NUMBER_OF_ALL_PINS)
	{
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_SET_PIN_DIRECTION_ID,
				PORT_E_PARAM_PIN );

		boolDevError=TRUE;

	}
	else
	{

	}

	if(PortPinsRef[Pin].boolPortPinDirectionChangeable == FALSE)
	{

		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_SET_PIN_DIRECTION_ID,
				PORT_E_DIRECTION_UNCHANGEABLE );

		boolDevError=TRUE;

	}
	else
	{

	}

#endif

	if(FALSE == boolDevError)
	{

		get_PortRegisterAddress(PortPinsRef[Pin].ParentPortId,&registerStruct);

		port_adjustPin(Pin,Direction,&registerStruct);

	}
	else
	{

	}
}
#endif



/********************************************************************************************************************/

#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

	boolean boolDevError=FALSE;

#if ( PORT_DEV_ERROR_DETECT == STD_ON)

	if(Pin >= MAXIMUM_NUMBER_OF_ALL_PINS)
	{
		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_SET_PIN_MODE_ID,
				PORT_E_PARAM_PIN );

		boolDevError=TRUE;

	}
	else
	{

	}

	if(PortPinsRef[Pin].boolPortPinModeChangeable == FALSE)
	{

		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_SET_PIN_MODE_ID,
				PORT_E_MODE_UNCHANGEABLE );

		boolDevError=TRUE;

	}
	else
	{

	}

#endif

	if(FALSE == boolDevError)
	{
		/*Hardware Dependent Code*/


	}
	else
	{


	}


}
#endif


/********************************************************************************************************************/

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
	boolean boolDevError=FALSE;

#if ( PORT_DEV_ERROR_DETECT == STD_ON)

	if(NULL_PTR == versioninfo)
	{

		Det_ReportError(PORT_MODULE_ID,
				PORT_INSTANCE_ID_0,
				PORT_S_GET_VERSION_INFO_ID,
				PORT_E_PARAM_POINTER );

		boolDevError=TRUE;

	}
	else
	{

	}

#endif

	if(FALSE == boolDevError)
	{
		versioninfo->moduleID=			(uint16)PORT_MODULE_ID;
		versioninfo->vendorID=			(uint16)PORT_VENDOR_ID;
		versioninfo->sw_major_version=	(uint8)PORT_SW_MAJOR_RELEASE_VERSION;
		versioninfo->sw_minor_version=	(uint8)PORT_SW_MINOR_RELEASE_VERSION;
		versioninfo->sw_patch_version=	(uint8)PORT_SW_PATCH_RELEASE_VERSION;
	}
	else
	{

	}

}
#endif


/********************************************************************************************************************/



/************************************************************************************
 *                             Helper Functions                                     *
 ************************************************************************************/


void get_PortRegisterAddress( Port_PortType portId ,PortRegisterAdd* PortRegisterAddress)
{

	switch(portId)
	{

	case PORT_A :
		PortRegisterAddress->PortDirectionRegisterAddress=PORT_A_DIRECTION_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataInputRegisterAddress=PORT_A_DATA_IN_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataOutputRegisterAddress=PORT_A_DATA_OUT_REGISTER_ADDRESS;
		break;

	case PORT_B :
		PortRegisterAddress->PortDirectionRegisterAddress=PORT_B_DIRECTION_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataInputRegisterAddress=PORT_B_DATA_IN_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataOutputRegisterAddress=PORT_B_DATA_OUT_REGISTER_ADDRESS;
		break;

	case PORT_C :
		PortRegisterAddress->PortDirectionRegisterAddress=PORT_C_DIRECTION_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataInputRegisterAddress=PORT_C_DATA_IN_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataOutputRegisterAddress=PORT_C_DATA_OUT_REGISTER_ADDRESS;
		break;

	case PORT_D :
		PortRegisterAddress->PortDirectionRegisterAddress=PORT_D_DIRECTION_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataInputRegisterAddress=PORT_D_DATA_IN_REGISTER_ADDRESS;
		PortRegisterAddress->PortDataOutputRegisterAddress=PORT_D_DATA_OUT_REGISTER_ADDRESS;
		break;


	}

}

/********************************************************************************************************************/

void port_adjustPin(Port_PinType PinId,Port_PinDirectionType Direction,PortRegisterAdd* registerStructRef)
{

	if( PORT_PIN_IN == Direction )
	{

		CLEAR_BIT((*(registerStructRef->PortDataOutputRegisterAddress)),PortPinsRef[PinId].PortPinId);

		__INPUT_BIT((*(registerStructRef->PortDirectionRegisterAddress)),PortPinsRef[PinId].PortPinId);

	}
	else if ( PORT_PIN_OUT == Direction )
	{

		/*Set Initial Level Value*/
		if(PortPinsRef[PinId].PortPinLevelValue == PORT_PIN_LEVEL_HIGH)
		{
			SET_BIT((*(registerStructRef->PortDataOutputRegisterAddress)),PortPinsRef[PinId].PortPinId);
		}
		else if(PortPinsRef[PinId].PortPinLevelValue == PORT_PIN_LEVEL_LOW)
		{
			CLEAR_BIT((*(registerStructRef->PortDataOutputRegisterAddress)),PortPinsRef[PinId].PortPinId);
		}
		else
		{

		}

		__OUTPUT_BIT((*(registerStructRef->PortDirectionRegisterAddress)),PortPinsRef[PinId].PortPinId);
	}
	else
	{

	}


}
/********************************************************************************************************************/

