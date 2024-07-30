//FILE CREATED BY:- ANKESH CHANDRA
//COMPANY: SENSESEMI TECHNOLOGIES PVT. LTD.




#include <stdio.h>
#include <stdlib.h>

#include "SMM_MPS3.h"                   // MPS3 common header
#include "platform_base_address.h"
#include "SPI_CONFIG.h"

unsigned char buffer0[100];
unsigned char buffer1[100];


void SPI_PERIPH_INIT_ADS_TRIAL()	{
	*SSPCR0 = 0x00000317;
	*SSPCR1 = 0x0000000A;
	*SSPCPSR = 0x00000002;
}

uint32_t ACCESS_CONTROL_REGISTER_O(uint32_t * val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCR0;
			return status;
		}	else if(option == WRITE)	{
			*SSPCR0 = *val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}

uint32_t ACCESS_CONTROL_REGISTER_1(uint32_t * val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCR1;
			return status;
		}	else if(option == WRITE)	{
			*SSPCR1 = *val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}

uint32_t ACCESS_PRESCALER_REG(uint32_t * val, uint8_t option)	{
		if(option == READ)	{
			uint32_t status = *SSPCPSR;
			return status;
		}	else if(option == WRITE)	{
			*SSPCPSR = *val;
			return SUCCESS;
		}	else	{
			return UNKNOWN;
		}
}


uint32_t SPI_READ_FIFO_STATUS()	{
	uint32_t status = *SSPSR;
return status;
}

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

uint32_t READ_RAW_INTERRUPT_STATUS_REG()	{
	uint32_t status = *SSPRIS;
	return status;
}

uint32_t READ_MASKED_INTERRUPT_STATUS_REG()	{
	uint32_t status = *SSPMIS;
	return status;
}
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


uint32_t spi_read(unsigned int no_of_bytes)	{

	unsigned int loop, timeout;
	timeout = 10000;
	
	return 0;
}


//----------------------------------------------SSPIMSC-------------------------------------------------//

uint8_t interrupt_mask_status_check_set(uint8_t set_clear, uint8_t bit)	{
	if(bit == SSPSR_SET_BSY)	{
	
		if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_BSY) == CHECK_BSY)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPSR_SET_BSY),WRITE)) == SUCCESS)	{
			return FAIL;
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_BSY) != CHECK_BSY)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPSR_SET_BSY),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
			}
			}
		} else if (bit == SSPSR_SET_RFF) {
					if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RFF) == CHECK_RFF)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPSR_SET_RFF),WRITE)) == SUCCESS)	{
			return FAIL;
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RFF) != CHECK_RFF)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPSR_SET_RFF),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else if (bit == SSPSR_SET_RNE)	{
			if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RNE) == CHECK_RNE)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPSR_SET_RNE),WRITE)) == SUCCESS)	{
			return FAIL;
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_RNE) != CHECK_RNE)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPSR_SET_RNE),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else if (bit == SSPSR_SET_TNF)	{
			if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TNF) == CHECK_TNF)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPSR_SET_TNF),WRITE)) == SUCCESS)	{
			return FAIL;
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TNF) != CHECK_TNF)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPSR_SET_TNF),WRITE)) == SUCCESS)	{
			return SUCCESS;
				}	else {
					return FAIL;
				}
				}
			}
			}	else if (bit == SSPSR_SET_TFE)	{
			if(set_clear == CLEAR)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TFE) == CHECK_TFE)	{
		if((ACCESS_INTERRUPT_MASK_SET_CLEAR((CLEAR<<SSPSR_SET_TFE),WRITE)) == SUCCESS)	{
			return FAIL;
		}
		}
		}	else if(set_clear == SET)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR(0,READ)&CHECK_TFE) != CHECK_TFE)	{
			if((ACCESS_INTERRUPT_MASK_SET_CLEAR((SET<<SSPSR_SET_TFE),WRITE)) == SUCCESS)	{
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

		
	
