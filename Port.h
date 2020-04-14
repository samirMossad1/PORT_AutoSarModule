
#ifndef PORT_H_
#define PORT_H_


/*PORT MODULE Vendor ID*/
#define PORT_VENDOR_ID					(0X00)

/*PORT Module ID*/
#define PORT_MODULE_ID					(0x00)

/*PORT Instance ID*/
#define PORT_INSTANCE_ID_0				(0x00)


/*
 * Module Version
 */
#define PORT_SW_MAJOR_RELEASE_VERSION           (1U)
#define PORT_SW_MINOR_RELEASE_VERSION           (0U)
#define PORT_SW_PATCH_RELEASE_VERSION           (0U)

/*
 * AUTOSAR Version
 */
#define PORT_AR_MAJOR_RELEASE_VERSION           (4U)
#define PORT_AR_MINOR_RELEASE_VERSION           (3U)
#define PORT_AR_PATCH_RELEASE_VERSION           (1U)




/*Include the general standard types*/
#include "Std_types.h"


/*
 * AUTOSAR version checking between PORT Module and Standard Types file
 * */

#if ((PORT_AR_MAJOR_RELEASE_VERSION!=STD_TYPES_AR_MAJOR_RELEASE_VERSION)\
        ||(PORT_AR_MINOR_RELEASE_VERSION!=STD_TYPES_AR_MINOR_RELEASE_VERSION)\
        ||(PORT_AR_PATCH_RELEASE_VERSION!=STD_TYPES_AR_PATCH_RELEASE_VERSION))

#error "The AutoSar versions of the PORT module and the Std_types file are not compatible"
#endif



/*Include the pre-compile configurations of the PORT Module*/
#include "Port_Cfg.h"



/*
 * AUTOSAR version checking between PORT Module Configurations and Standard Types file
 * */
#if ((PORT_CFG_AR_MAJOR_RELEASE_VERSION!=STD_TYPES_AR_MAJOR_RELEASE_VERSION)\
        ||(PORT_CFG_AR_MINOR_RELEASE_VERSION!=STD_TYPES_AR_MINOR_RELEASE_VERSION)\
        ||(PORT_CFG_AR_PATCH_RELEASE_VERSION!=STD_TYPES_AR_PATCH_RELEASE_VERSION))

#error "The Autosar versions of the PORT module pre-compile configurations and the Std_types files are not compatible"
#endif


/*
 * Software version checking between PORT Module and its Configurations
 * */

#if ((PORT_SW_MAJOR_RELEASE_VERSION!=PORT_CFG_SW_MAJOR_RELEASE_VERSION)\
        ||(PORT_SW_MINOR_RELEASE_VERSION!=PORT_CFG_SW_MINOR_RELEASE_VERSION)\
        ||(PORT_SW_PATCH_RELEASE_VERSION!=PORT_CFG_SW_PATCH_RELEASE_VERSION))

#error "The software versions of the  PORT module and configurations file are not compatible"
#endif


/*Include The PORT Module Hardware Registers*/
#include "Port_Regs.h"

/*Include The PORT Module Types*/
#include "Port_Types.h"



/************************************************************************************
 *                                 General Macros                                   *
 ************************************************************************************/

/*
 * PORT Module Status
 */

#define PORT_MODULE_INITALIZED           TRUE
#define PORT_MODULE_NOT_INITALIZED       FALSE



/*************************************************************************************
 *                           Service Id Macros                                       *
 *************************************************************************************/


/*Service ID for PORT Init Function*/
#define PORT_S_PORT_INIT_ID						(0X00)

/*Service ID for PORT Set Pin Direction Function*/
#define PORT_S_SET_PIN_DIRECTION_ID				(0X01)

/*Service ID for PORT Refresh Port Direction Function*/
#define PORT_S_REFRESH_PORT_DIRECTION_ID		(0X02)

/*Service ID for PORT Get Version Info Function*/
#define PORT_S_GET_VERSION_INFO_ID				(0X03)

/*Service ID for PORT Set Pin Mode Function*/
#define PORT_S_SET_PIN_MODE_ID					(0X04)


/*************************************************************************************
 *                      Development Errors IDs                                       *
 *************************************************************************************/

/*DET code to report an invalid pin*/
#define PORT_E_PARAM_PIN						(0x0A)

/*DET code to report invalid direction change*/
#define PORT_E_DIRECTION_UNCHANGEABLE			(0x0B)

/*DET code to report an uninitialized port module*/
#define PORT_E_INIT_FAILED						(0x0C)

/*DET code to report invalid mode*/
#define PORT_E_PARAM_INVALID_MODE				(0x0D)

/*DET code to report invalid mode change*/
#define PORT_E_MODE_UNCHANGEABLE				(0x0E)

/*DET code to report */
#define PORT_E_UNINIT							(0x0F)

/*DET code to report a null pointer*/
#define PORT_E_PARAM_POINTER					(0x10)





/*************************************************************************************
 *                     DIO Module Functions Prototypes                               *
 *************************************************************************************/



/*
 * Service Name: Port_Init
 *
 * Service ID:  0x00
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 * Parameters (in): -ConfigPtr
 *						Pointer to configuration set
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Initializes the Port Driver module.
 *
 **/
void Port_Init( const Port_ConfigType* ConfigPtr );



/*
 * Service Name: Port_RefreshPortDirection
 *
 * Service ID:  0x02
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 * Parameters (in): None
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Refreshes port direction.
 *
 **/
void Port_RefreshPortDirection( void );



/*Check if the SetPinDirection API enabled/disabled*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*
 * Service Name: Port_SetPinDirection
 *
 * Service ID:  0x01
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy:Reentrant
 *
 * Parameters (in): -Pin
 *					 Port Pin ID number
 *				    -Direction
 *					 Port Pin Direction
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Sets the port pin direction.
 *
 **/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif



/*Check if the SetPinMode API enabled/disabled*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*
 * Service Name: Port_SetPinMode
 *
 * Service ID:  0x04
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy:Reentrant
 *
 * Parameters (in): -Pin
 *					 Port Pin ID number
 *				    -Mode
 *					 New Port Pin mode to be set on port pin.
 *
 * Parameters (inout): None
 *
 * Parameters (out): None
 *
 * Return Value: None
 *
 * Description: Sets the port pin mode.
 *
 **/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif


/*Check if the VersionInfo enabled/disabled*/
#if (PORT_VERSION_INFO_API == STD_ON)
/*
 * Service Name: DIO_GetVersionInfo
 *
 * Service ID:  0x12
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Reentrant
 *
 * Parameters (in): None
 *
 * Parameters (inout): None
 *
 * Parameters (out): - versioninfo
 *                       Pointer to where to store the version information of this module.
 *
 * Return Value: None
 *
 * Description: Returns the version information.
 *
 **/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif





/*************************************************************************************
 *                                  Externed Variables                               *
 *************************************************************************************/


/*The Externed Post Build Configuration Structure*/
extern Port_ConfigType PortConfigStruct;



#endif
