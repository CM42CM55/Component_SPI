//FILE CREATED BY:- ANKESH CHANDRA
//COMPANY: SENSESEMI TECHNOLOGIES PVT. LTD.


#include "SPI_CONFIG.h"

uint32_t read_peripheral_id()	{
	uint32_t ID;
	ID = READ_PERIPHERAL_ID_REGISTER_0();
	ID = ID + (READ_PERIPHERAL_ID_REGISTER_1() << 8);
	ID = ID + (READ_PERIPHERAL_ID_REGISTER_2() << 16);
	ID = ID + (READ_PERIPHERAL_ID_REGISTER_3() << 24);
	return ID;
}

uint32_t read_peripheral_cell_id()	{
	uint32_t CELL_ID;
	CELL_ID = READ_PERIPHERAL_CELL_ID_REGISTER_0();
	CELL_ID = CELL_ID + (READ_PERIPHERAL_CELL_ID_REGISTER_1()	<<	8);
	CELL_ID = CELL_ID	+	(READ_PERIPHERAL_CELL_ID_REGISTER_2()	<<	16);
	CELL_ID	=	CELL_ID	+	(READ_PERIPHERAL_CELL_ID_REGISTER_3()	<<	24);
	return CELL_ID;
}

uint32_t hold_val;
uint8_t pl022_test_suite()	{
	printf("\nPeripheral ID: %d\nPeripheral_Cell ID: %d\n", read_peripheral_id(), read_peripheral_cell_id());
/* TO BE DONE AFTER DMA INTEGRATION
	if(ACCESS_TEST_CONTROL_REGISTER(DISABLE_TEST) == SUCCESS)	{
		//if(ACCESS_TEST_CONTROL_REGISTER(EN_INTEGRATION_TEST) == SUCCESS)	{
			//printf("\nIntegration Test Enable Done!\n");
		//}	else return UNKNOWN;
	}	else return UNKNOWN;
	if(ACCESS_INTEGRATION_TEST_INP_REG(WRITE, CLEAR, 0) == SUCCESS)	{
		if(ACCESS_INTEGRATION_TEST_INP_REG(WRITE, SET, (SET<<SSPITIP_SET_SSPTXDMACLR)) == SUCCESS)	{
			hold_val = ACCESS_INTEGRATION_TEST_INP_REG(READ, 0, 0);
			printf("\nIntegration Input Test Register Val: %d\n", hold_val);
			return SUCCESS;
		}	else return UNKNOWN;
	}	else return UNKNOWN;
	if(ACCESS_INTEGRATION_TEST_INP_REG(WRITE, SET, (hold_val + (SET<<SSPITIP_SET_SSPRXDMACLR))) == SUCCESS)	{
		hold_val = ACCESS_INTEGRATION_TEST_INP_REG(READ, 0, 0);
		printf("\nIntegration Input Test Register Val: %d\n", hold_val);
		return SUCCESS;
	}	else return UNKNOWN;
*/
	// NORMAL REGISTER READ WRITE
		if(ACCESS_CONTROL_REGISTER_O(0x00000314, WRITE) == SUCCESS)	{
			if(ACCESS_CONTROL_REGISTER_1(0x0000000B, WRITE) == SUCCESS)	{
				if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
					//CALL FUNCTION
					return SUCCESS;
				}
			}
		}
	return SUCCESS;
}

/*
void SPI_PERIPH_INIT_ADS_TRIAL()	{
	*SSPCR0 = 0x00000317;
	*SSPCR1 = 0x0000000B;
	*SSPCPSR = 0x00000003;
}
*/

uint8_t spi_motorola_config()	{

	
	
return 0;
}

uint32_t spi_read(unsigned int no_of_bytes)	{


	
	return 0;
}

	


