//FILE CREATED BY:- ANKESH CHANDRA
//COMPANY: SENSESEMI TECHNOLOGIES PVT. LTD.

#ifndef __SPI_CONFIG_H__
#define	__SPI_CONFIG_H__


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//----------------------------------------Register-Offsets-------------------------------------//

#define SSPCR0_OF							0x00
#define SSPCR1_OF							0x04
#define SSPDR_OF							0x08
#define SSPSR_OF							0x0C
#define SSPCPSR_OF						0x10
#define SSPIMSC_OF						0x14
#define SSPRIS_OF							0x18
#define SSPMIS_OF							0x1C
#define SSPICR_OF							0x20
#define SSPDMACR_OF						0x24
#define SSPPeriphID0_OF				0xFE0
#define SSPPeriphID1_OF				0xFE4
#define SSPPeriphID2_OF				0xFE8
#define SSPPeriphID3_OF				0xFEC
#define SSPCellID0_OF					0xFF0
#define SSPCellID1_OF					0xFF4
#define SSPCellID2_OF					0xFF8
#define SSPCellID3_OF					0xFFC
#define SSPTCR_OF							0x080
#define SSPITIP_OF						0x084
#define SSPITOP_OF						0x088
#define SSPTDR_OF							0x08C

//----------------------------------------Register-Offsets-------------------------------------//

#define SPI_BASE 						FPGA_SPI_SHIELD0_BASE_NS

//--------------------------------------Operational-Register-Bases------------------------------------//

#define SSPCR0							((volatile unsigned int *)(SPI_BASE		+	SSPCR0_OF))
#define SSPCR1							((volatile unsigned int *)(SPI_BASE		+	SSPCR1_OF))
#define SSPDR								((volatile unsigned int *)(SPI_BASE		+	SSPDR_OF))
#define SSPSR								((volatile unsigned int *)(SPI_BASE		+	SSPSR_OF))
#define SSPCPSR							((volatile unsigned int *)(SPI_BASE		+	SSPCPSR_OF))
#define SSPIMSC							((volatile unsigned int *)(SPI_BASE		+	SSPIMSC_OF))
#define SSPRIS							((volatile unsigned int *)(SPI_BASE		+	SSPRIS_OF))
#define SSPMIS							((volatile unsigned int *)(SPI_BASE		+	SSPMIS_OF))
#define SSPICR							((volatile unsigned int *)(SPI_BASE		+	SSPICR_OF))
#define SSPDMACR						((volatile unsigned int *)(SPI_BASE		+	SSPDMACR_OF))
#define SSPPeriphID0				((volatile unsigned int *)(SPI_BASE		+	SSPPeriphID0_OF))
#define SSPPeriphID1				((volatile unsigned int *)(SPI_BASE		+	SSPPeriphID1_OF))
#define SSPPeriphID2				((volatile unsigned int *)(SPI_BASE		+	SSPPeriphID2_OF))
#define SSPPeriphID3				((volatile unsigned int *)(SPI_BASE		+	SSPPeriphID3_OF))
#define SSPCellID0					((volatile unsigned int *)(SPI_BASE		+	SSPCellID0_OF))
#define SSPCellID1					((volatile unsigned int *)(SPI_BASE		+	SSPCellID1_OF))
#define SSPCellID2					((volatile unsigned int *)(SPI_BASE		+	SSPCellID2_OF))
#define SSPCellID3					((volatile unsigned int *)(SPI_BASE		+	SSPCellID3_OF))

//--------------------------------------Operational-Register-Bases------------------------------------//


//-----------------------------------------PrimeCell-SSP-Test-Registers-------------------------------//

#define SSPTCR							((volatile unsigned int	*)(SPI_BASE		+	SSPTCR_OF))
#define SSPITIP							((volatile unsigned int *)(SPI_BASE		+	SSPITIP_OF))
#define SSPITOP							((volatile unsigned int	*)(SPI_BASE		+	SSPITOP_OF))
#define SSPTDR							((volatile unsigned int	*)(SPI_BASE		+	SSPTDR_OF))	

//-----------------------------------------PrimeCell-SSP-Test-Registers-------------------------------//


//-----------------------------------------Program-Vars-----------------------------------------------//

#define HIGH								246
#define LOW									247
#define READ_HALTED					248
#define RX_FIFO_FULL				249
#define BUSY								250
#define READ 								251
#define WRITE 							252
#define SUCCESS							253
#define FAIL								254
#define UNKNOWN							255

#define SET									1
#define CLEAR								0

#define SSPCR0_SET_SCR			8
#define SSPCR0_SET_SPH			7
#define SSPCR0_SET_SPO			6
#define SSPCR0_SET_FRF1			5
#define SSPCR0_SET_FRF0			4
#define SSPCR0_SET_DSS			0

#define SSPCR1_SET_SOD			3
#define SSPCR1_SET_MS				2
#define	SSPCR1_SET_SSE			1
#define SSPCR1_SET_LBM			0



#define SSPSR_SET_BSY				4
#define CHECK_BSY						0x00000010
#define SSPSR_SET_RFF				3
#define CHECK_RFF						0x00000008
#define SSPSR_SET_RNE				2
#define CHECK_RNE						0x00000004
#define SSPSR_SET_TNF				1
#define	CHECK_TNF						0x00000002
#define SSPSR_SET_TFE				0
#define	CHECK_TFE						0x00000001


#define SSPIMSC_SET_TXIM    3
#define CHECK_TXIM          0x00000008
#define SSPIMSC_SET_RXIM    2
#define CHECK_RXIM          0x00000004
#define SSPIMSC_SET_RTIM    1
#define CHECK_RTIM          0x00000002
#define SSPIMSC_SET_RORM   	0
#define CHECK_RORM         	0x00000001

//Test Enable Register

#define ENABLE_TEST_FIFO		0x00000002
#define EN_INTEGRATION_TEST	0x00000001
#define DISABLE_TEST				0x00000000

//Test Enable Register

//Integration Test Input Register

#define SSPITIP_SET_SSPTXDMACLR					4
#define	SSPITIP_SET_SSPRXDMACLR					3
#define	SSPITIP_SET_SSPCLKIN						2
#define	SSPITIP_SET_SSPFSSIN						1
#define	SSPITIP_SET_SSPRXD							0

//Integration Test Output Register

#define SSPITOP_SET_SSPTXDMASREQ				13
#define SSPITOP_SET_SSPTXDMABREQ				12
#define	SSPITOP_SET_SSPRXDMASREQ				11
#define SSPITOP_SET_SSPRXDMABREQ				10
#define SSPITOP_SET_SSPINTR							9
#define SSPITOP_SET_SSPTXINTR						8
#define SSPITOP_SET_SSPRXINTR						7
#define SSPITOP_SET_SSPRTINTR						6
#define SSPITOP_SET_SSPRORINTR					5
#define SSPITOP_SET_nSSPOE							4
#define SSPITOP_SET_nSSPCTLOE						3
#define SSPITOP_SET_SSPCLKOUT						2
#define SSPITOP_SET_SSPFSSOUT						1
#define SSPITOP_SET_SSPTXD							0

//Integration Test Output Register


//-----------------------------------------Program-Vars-----------------------------------------------//

//--------------------------------------API-Function-Declarations-------------------------------------//

void SPI_PERIPH_INIT_ADS_TRIAL();
uint32_t ACCESS_CONTROL_REGISTER_O(uint32_t val, uint8_t option);
uint32_t ACCESS_CONTROL_REGISTER_1(uint32_t val, uint8_t option);
uint32_t ACCESS_PRESCALER_REG(uint32_t val, uint8_t option);
uint32_t SPI_READ_FIFO_STATUS();
uint32_t ACCESS_INTERRUPT_MASK_SET_CLEAR(uint32_t val, uint8_t action);
uint32_t READ_RAW_INTERRUPT_STATUS_REG();
uint32_t READ_MASKED_INTERRUPT_STATUS_REG();
void WRITE_INTERRUPT_CLEAR_REGISTER(uint32_t * val);
uint32_t ACCESS_DMA_CONTROL_REGISTER(uint32_t * val, uint8_t action);

uint32_t READ_PERIPHERAL_ID_REGISTER_0();
uint32_t READ_PERIPHERAL_ID_REGISTER_1();
uint32_t READ_PERIPHERAL_ID_REGISTER_2();
uint32_t READ_PERIPHERAL_ID_REGISTER_3();

uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_0();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_1();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_2();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_3();

uint8_t ACCESS_TEST_CONTROL_REGISTER(uint8_t option);
uint32_t ACCESS_INTEGRATION_TEST_INP_REG(uint8_t rw, uint8_t state, uint32_t val);
uint32_t ACCESS_INTEGRATION_TEST_OUT_REG(uint8_t rw, uint8_t state, uint32_t val);
uint16_t READ_TEST_DATA_REGISTER();

uint8_t WRITE_DATA_REG(uint8_t datum);
uint8_t READ_DATA_REG();

//spi_op.c
uint32_t read_peripheral_id();
uint32_t read_peripheral_cell_id();
uint8_t pl022_test_suite();
uint8_t spi_motorola_config();
uint8_t spi_write_half_dup_test(uint8_t datum);
uint8_t spi_read_half_dup_test();
uint8_t cycle_test();
void call_func_for_main();

//--------------------------------------API-Function-Declarations-------------------------------------//
//
#endif