//FILE CREATED BY:- ANKESH CHANDRA
//COMPANY: SENSESEMI TECHNOLOGIES PVT. LTD.




#include <stdio.h>
#include <stdlib.h>

#include "SMM_MPS3.h"                   // MPS3 common header
#include "platform_base_address.h"
#include "SPI_CONFIG.h"

unsigned char buffer0[100];
unsigned char buffer1[100];
//volatile uint32_t status = 0; Will be programmed later, more statics in funtions for now!!


//Read-write control register 0------------------------------------------------------------------//
uint32_t ACCESS_CONTROL_REGISTER_O(uint32_t val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCR0;
			return status;
		}	else if(option == WRITE)	{
			*SSPCR0 = val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}
//Read-write control register 0------------------------------------------------------------------//

//Read-write control register 1------------------------------------------------------------------//
uint32_t ACCESS_CONTROL_REGISTER_1(uint32_t val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCR1;
			return status;
		}	else if(option == WRITE)	{
			*SSPCR1 = val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}
//Read-write control register 1------------------------------------------------------------------//

//Set & read pre-scaler register-----------------------------------------------------------------//
uint32_t ACCESS_PRESCALER_REG(uint32_t val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCPSR;
			return status;
		}	else if(option == WRITE)	{
			*SSPCPSR = val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}
//Set & read pre-scaler register-----------------------------------------------------------------//

//Read fifo status register-----------------------------------------------------------------//
uint32_t SPI_READ_FIFO_STATUS()	{
	uint32_t status = *SSPSR;
return status;
}
//Read fifo status register-----------------------------------------------------------------//

//Read/write interrupt mask set/clear register-----------------------------------------------//
uint32_t ACCESS_INTERRUPT_MASK_SET_CLEAR(uint32_t val, uint8_t action)	{
		if(action == READ)	{
			uint32_t status = *SSPIMSC;
			return status;
		}	else if(action == WRITE)	{
			*SSPIMSC = val;
			return SUCCESS;
		}	else {
			return UNKNOWN;
		}
}
//Read/write interrupt mask set/clear register-----------------------------------------------//

//Read raw interrupt status register--------------------------------------------------//
uint32_t READ_RAW_INTERRUPT_STATUS_REG()	{
	uint32_t status = *SSPRIS;
	return status;
}
//Read raw interrupt status register--------------------------------------------------//

//Read masked interrupt status register-----------------------------------------------//
uint32_t READ_MASKED_INTERRUPT_STATUS_REG()	{
	uint32_t status = *SSPMIS;
	return status;
}
//Read masked interrupt status register-----------------------------------------------//

//Clear all interrupts register -----------------------------------------------------//
void WRITE_INTERRUPT_CLEAR_REGISTER(uint32_t * val)	{
	*SSPICR = *val;
}
//Clear all interrupts register -----------------------------------------------------//

//DMA enable disable configuration register------------------------------------------//
uint32_t ACCESS_DMA_CONTROL_REGISTER(uint32_t * val, uint8_t action)	{
	if(action == READ)	{
		uint32_t status = *SSPDMACR;
		return status;
	}	else if(action == WRITE)	{
		*SSPDMACR = *val;
		return SUCCESS;
	}	else	{
		return UNKNOWN;
	}
}
//DMA enable disable configuration register------------------------------------------//

/*
uint32_t spi_read(unsigned int no_of_bytes)	{

	unsigned int loop, timeout;
	timeout = 10000;
	
	return 0;
}
*/

//----------------------------------------------SSPIMSC-------------------------------------------------//

uint8_t interrupt_mask_status_check_set(uint8_t set_clear, uint8_t bit)	{
	if(bit == SSPIMSC_SET_TXIM)	{
	
		if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TXIM) == CHECK_TXIM)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPIMSC_SET_TXIM),WRITE)) == SUCCESS)	{
			return FAIL; //Check cycle depth in physical tests!!
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TXIM) != CHECK_TXIM)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPIMSC_SET_TXIM),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
			}
			}
		} else if (bit == SSPIMSC_SET_RXIM) {
					if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RXIM) == CHECK_RXIM)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPIMSC_SET_RXIM),WRITE)) == SUCCESS)	{
			return FAIL;	//Check cycle depth in physical tests!!
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RXIM) != CHECK_RXIM)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPIMSC_SET_RXIM),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else if (bit == SSPIMSC_SET_RTIM)	{
			if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RTIM) == CHECK_RTIM)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPIMSC_SET_RTIM),WRITE)) == SUCCESS)	{
			return FAIL;	//Check cycle depth in physical tests!!
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RTIM) != CHECK_RTIM)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPIMSC_SET_RTIM),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else if (bit == SSPIMSC_SET_RORM)	{
			if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RORM) == CHECK_RORM)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPIMSC_SET_RORM),WRITE)) == SUCCESS)	{
			return FAIL;	//Check cycle depth in physical tests!!
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RORM) != CHECK_RORM)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPIMSC_SET_RORM),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else	{
				return UNKNOWN;
			}
			return UNKNOWN;
		}
	
//--------------------------------------------------SSPIMSC-----------------------------------------------//

//------------------------------------------------Data-Register-SSPDR-------------------------------------//
		
uint16_t READ_DATA_REG()	{
	uint16_t read_val = *SSPDR;
	return read_val;
}	

uint16_t WRITE_DATA_REG(uint16_t wr_val)	{
	*SSPDR = wr_val;
	return SUCCESS;
}	

//------------------------------------------------Data-Register-SSPDR-------------------------------------//
		
//-------------------------------Read-Peripheral-ID-Register-0--------------------------------------------//
		
	uint32_t READ_PERIPHERAL_ID_REGISTER_0()	{
	uint32_t status = *SSPPeriphID0;
	return status;
}
//-------------------------------Read-Peripheral-ID-Register-0--------------------------------------------//

//-------------------------------Read-Peripheral-ID-Register-1--------------------------------------------//

uint32_t READ_PERIPHERAL_ID_REGISTER_1()	{
	uint32_t status = *SSPPeriphID1;
	return status;
}
//-------------------------------Read-Peripheral-ID-Register-1--------------------------------------------//

//-------------------------------Read-Peripheral-ID-Register-2--------------------------------------------//

uint32_t READ_PERIPHERAL_ID_REGISTER_2()	{
	uint32_t status = *SSPPeriphID2;
	return status;
}
//-------------------------------Read-Peripheral-ID-Register-2--------------------------------------------//

//-------------------------------Read-Peripheral-ID-Register-3--------------------------------------------//

uint32_t READ_PERIPHERAL_ID_REGISTER_3()	{
	uint32_t status = *SSPPeriphID3;
	return status;
}
//-------------------------------Read-Peripheral-ID-Register-3--------------------------------------------//

//-------------------------------Read-Peripheral-Cell-ID-0------------------------------------------------//
		
	uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_0()	{
	uint32_t status = *SSPCellID0;
	return status;
}
//-------------------------------Read-Peripheral-Cell-ID-0------------------------------------------------//

//-------------------------------Read-Peripheral-Cell-ID-1------------------------------------------------//
		
	uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_1()	{
	uint32_t status = *SSPCellID1;
	return status;
}
//-------------------------------Read-Peripheral-Cell-ID-1------------------------------------------------//

//-------------------------------Read-Peripheral-Cell-ID-2------------------------------------------------//
		
	uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_2()	{
	uint32_t status = *SSPCellID2;
	return status;
}
//-------------------------------Read-Peripheral-Cell-ID-2------------------------------------------------//

//-------------------------------Read-Peripheral-Cell-ID-3------------------------------------------------//
		
	uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_3()	{
	uint32_t status = *SSPCellID3;
	return status;
}
//-------------------------------Read-Peripheral-Cell-ID-3------------------------------------------------//

//-------------------------------Read-Write-SSPTCR-Register-----------------------------------------------//

uint8_t ACCESS_TEST_CONTROL_REGISTER(uint8_t option)	{
		if(option == ENABLE_TEST_FIFO)	{
			*SSPTCR = ENABLE_TEST_FIFO;
			return SUCCESS;
		}	else if(option == EN_INTEGRATION_TEST)	{
			*SSPTCR = EN_INTEGRATION_TEST;
			return SUCCESS;
		}	else if(option == ENABLE_TEST_FIFO + EN_INTEGRATION_TEST)	{
			*SSPTCR = ENABLE_TEST_FIFO + EN_INTEGRATION_TEST;
			return SUCCESS;
		}	else if(option == DISABLE_TEST)	{
			*SSPTCR = DISABLE_TEST;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}

//-------------------------------Read-Write-SSPTCR-Register-----------------------------------------------//

//------------------------Read-Write-SSPITIP(Integration Test Input)-Register-----------------------------//
uint32_t hold_reg_itip = 0;
uint32_t ACCESS_INTEGRATION_TEST_INP_REG(uint8_t rw, uint8_t state, uint32_t val)	{
	if(rw == WRITE)	{
	if(state == CLEAR)	
		hold_reg_itip = 0x00000000;
	else if (state == SET)
		hold_reg_itip = hold_reg_itip + val;
	else
		return FAIL;
	*SSPITIP = hold_reg_itip;
	return SUCCESS;
	}
	if(rw == READ){
		uint32_t read = *SSPITIP;
		return read;
	}
	return UNKNOWN;
}

//------------------------Read-Write-SSPITIP(Integration Test Input)-Register-----------------------------//

//-----------------------Read-Write-SSPITOP(Integration Test Output)-Register-----------------------------//
uint32_t hold_reg_itop = 0;
uint32_t ACCESS_INTEGRATION_TEST_OUT_REG(uint8_t rw, uint8_t state, uint32_t val)	{
	if(rw == WRITE)	{
	if(state == CLEAR)	{
		hold_reg_itop = 0x00000000;
		return SUCCESS;
	}	else if (state == SET)
		hold_reg_itip = hold_reg_itip + val;
	else
		return FAIL;
	*SSPITOP = hold_reg_itip;
	return SUCCESS;
	}
	if(rw == READ)	{
		uint32_t read = *SSPITOP;
		return read;
	}
	return UNKNOWN;
}

//-----------------------Read-Write-SSPITOP(Integration Test Output)-Register-----------------------------//

//----------------------------------------Read-SSPTDR_Register--------------------------------------------//

uint16_t READ_TEST_DATA_REGISTER()	{
	uint16_t stat = *SSPTDR;
	return stat;
}

//----------------------------------------Read-SSPTDR_Register--------------------------------------------//
