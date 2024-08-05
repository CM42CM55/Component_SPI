//FILE CREATED BY:- ANKESH CHANDRA
//COMPANY: SENSESEMI TECHNOLOGIES PVT. LTD.


#include "SPI_CONFIG.h"

uint8_t looper=0;
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
	uint8_t return_val;
	// NORMAL REGISTER READ WRITE IN LOOP BACK
		if(ACCESS_CONTROL_REGISTER_O(0x00000317, WRITE) == SUCCESS)	{
			if(ACCESS_CONTROL_REGISTER_1(0x0000000B, WRITE) == SUCCESS)	{
				if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
					//CALL FUNCTION
					return_val = cycle_test();
					if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
							return return_val;
					else
					return SUCCESS;
				}
			}
		}
	// MOTOROLA FRAME FORMAT TEST --> PHYSICAL SETUP REQUIRED	
		if(ACCESS_CONTROL_REGISTER_O(0x00000317, WRITE) == SUCCESS)	{
			if(ACCESS_CONTROL_REGISTER_1(0x0000000B, WRITE) == SUCCESS)	{
				if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
					//CALL FUNCTION
					return_val = cycle_test();
					if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
							return return_val;
					else
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


//----------------------------------------------------Test Suite Functions----------------------------------------//

uint8_t spi_write_half_dup_test(uint8_t datum)	{

	if(((SPI_READ_FIFO_STATUS())&CHECK_BSY) == CHECK_BSY)	{
		return BUSY;
	} else	{
		if(((SPI_READ_FIFO_STATUS())&CHECK_TNF) == CHECK_TNF)	{
			if(WRITE_DATA_REG(datum) == SUCCESS)	{
				printf("\nWrite Complete!");
			} else return FAIL;
		} else return BUSY;
	} return SUCCESS;
}

uint8_t spi_read_half_dup_test()	{
	uint8_t datum;
	if(((SPI_READ_FIFO_STATUS())&CHECK_BSY) == CHECK_BSY)	{
		return BUSY;
	} else	{
		if(((SPI_READ_FIFO_STATUS())&CHECK_RNE) == CHECK_RNE)	{
			datum = READ_DATA_REG();
			return datum;
		}	else return RX_FIFO_FULL;
	}return SUCCESS;
}

uint8_t cycle_test()	{
	uint8_t datum = 0;
	for(looper=0;looper<8;looper++)	{
		datum = spi_write_half_dup_test(looper+100);
		if(datum==SUCCESS)	{
			continue;
		}	else return datum;
	}
	for(looper=0;looper<8;looper++)	{
		datum = spi_read_half_dup_test();
		if(datum == BUSY || datum == RX_FIFO_FULL)	
			return READ_HALTED;
		else
			printf("Read Data [%d]: %d\n", looper, datum);
	}
	return SUCCESS;
}

void call_func_for_main()	{
	
	uint8_t datum = pl022_test_suite();
	if(datum == SUCCESS)
		printf("\nHalf Duplex Loop Back Test Complete!\n");
	else
		printf("\nTest Failed! - Check code.\n");
}
	
//----------------------------------------------------Test Suite Functions----------------------------------------//

//--------------------------------------------------Motorola Frame Format-----------------------------------------//

uint8_t spi_m_config_master(uint8_t CPHA, uint8_t CPOL)	{
	uint8_t return_val;
	if(CPHA == LOW && CPOL == LOW)	{
		if(ACCESS_CONTROL_REGISTER_O(0x00000307, WRITE) == SUCCESS)	{
			if(ACCESS_CONTROL_REGISTER_1(0x0000000A, WRITE) == SUCCESS)	{
				if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
					//CALL FUNCTION
					if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
							return return_val;
					else
					return SUCCESS;
				}
			}
		}
	}	else if (CPHA == LOW && CPOL == HIGH)	{
			if(ACCESS_CONTROL_REGISTER_O(0x00000347, WRITE) == SUCCESS)	{
				if(ACCESS_CONTROL_REGISTER_1(0x0000000A, WRITE) == SUCCESS)	{
					if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
						//CALL FUNCTION
						if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
								return return_val;
						else
						return SUCCESS;
					}
				}
			}
	}	else if (CPHA == HIGH && CPOL == LOW)	{
			if(ACCESS_CONTROL_REGISTER_O(0x00000387, WRITE) == SUCCESS)	{
				if(ACCESS_CONTROL_REGISTER_1(0x0000000A, WRITE) == SUCCESS)	{
					if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
						//CALL FUNCTION
						if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
								return return_val;
						else
						return SUCCESS;
					}
				}
			}
	} else if (CPHA == HIGH && CPOL == HIGH)	{
			if(ACCESS_CONTROL_REGISTER_O(0x000003C7, WRITE) == SUCCESS)	{
				if(ACCESS_CONTROL_REGISTER_1(0x0000000A, WRITE) == SUCCESS)	{
					if(ACCESS_PRESCALER_REG(0x00000003, WRITE) == SUCCESS)	{
						//CALL FUNCTION
						if(return_val == BUSY || return_val == FAIL || return_val == RX_FIFO_FULL || return_val == READ_HALTED)
								return return_val;
						else
						return SUCCESS;
					}
				}
			}
	}

	
	
return 0;
}
