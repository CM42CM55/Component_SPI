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

uint8_t pl022_test_suite()	{
	printf("\nPeripheral ID: %d\nPeripheral_Cell ID: %d\n", read_peripheral_id(), read_peripheral_cell_id());
	if(ACCESS_TEST_CONTROL_REGISTER(DISABLE_TEST) == SUCCESS)	{
		if(ACCESS_TEST_CONTROL_REGISTER(EN_INTEGRATION_TEST) == SUCCESS)	{
			printf("\nIntegration Test Enable Done!\n");
		}
	}
	
	return SUCCESS;
}
	


