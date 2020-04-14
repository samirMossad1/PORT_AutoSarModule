

#ifndef PORT_REGS_H_
#define PORT_REGS_H_



#define AVR


#ifdef AVR
/************************************************************************************
 *                  Hardware Registers (AVR)                                        *
 ************************************************************************************/


/*The Direction Register Of Port_A*/
#define PORT_A_DIRECTION_REGISTER_ADDRESS					((volatile uint8 *)(0x3A))

/*The Direction Register Of Port_B*/
#define PORT_B_DIRECTION_REGISTER_ADDRESS					((volatile uint8 *)(0x37))

/*The Direction Register Of Port_C*/
#define PORT_C_DIRECTION_REGISTER_ADDRESS					((volatile uint8 *)(0x34))

/*The Direction Register Of Port_D*/
#define PORT_D_DIRECTION_REGISTER_ADDRESS					((volatile uint8 *)(0x31))


/*The Data Register (Input/Output) Of Port_A*/
#define PORT_A_DATA_OUT_REGISTER_ADDRESS					((volatile uint8 *)(0x3B))

/*The Data Register (Input/Output) Of Port_B*/
#define PORT_B_DATA_OUT_REGISTER_ADDRESS					((volatile uint8 *)(0x38))

/*The Data Register (Input/Output) Of Port_C*/
#define PORT_C_DATA_OUT_REGISTER_ADDRESS					((volatile uint8 *)(0x35))

/*The Data Register (Input/Output) Of Port_D*/
#define PORT_D_DATA_OUT_REGISTER_ADDRESS					((volatile uint8 *)(0x32))


/*The Data Register (Input/Output) Of Port_A*/
#define PORT_A_DATA_IN_REGISTER_ADDRESS						((volatile uint8 *)(0x39))

/*The Data Register (Input/Output) Of Port_B*/
#define PORT_B_DATA_IN_REGISTER_ADDRESS						((volatile uint8 *)(0x36))

/*The Data Register (Input/Output) Of Port_C*/
#define PORT_C_DATA_IN_REGISTER_ADDRESS						((volatile uint8 *)(0x33))

/*The Data Register (Input/Output) Of Port_D*/
#define PORT_D_DATA_IN_REGISTER_ADDRESS						((volatile uint8 *)(0x30))

#endif

#endif
