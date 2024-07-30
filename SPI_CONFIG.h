#ifndef __SPI_CONFIG_H__
#define	__SPI_CONFIG_H__


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define SSPCR0_OF						0x00
#define SSPCR1_OF						0x04
#define SSPDR_OF						0x08
#define SSPSR_OF						0x0C
#define SSPCPSR_OF					0x10
#define SSPIMSC_OF					0x14
#define SSPRIS_OF						0x18
#define SSPMIS_OF						0x1C
#define SSPICR_OF						0x20
#define SSPDMACR_OF					0x24
#define SSPPeriphID0_OF			0xFE0
#define SSPPeriphID1_OF			0xFE4
#define SSPPeriphID2_OF			0xFE8
#define SSPPeriphID3_OF			0xFEC
#define SSPCellID0_OF				0xFF0
#define SSPCellID1_OF				0xFF4
#define SSPCellID2_OF				0xFF8
#define SSPCellID3_OF				0xFFC

#define SPI_BASE 					FPGA_SPI_SHIELD0_BASE_NS

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

#define READ 								251
#define WRITE 							252
#define SUCCESS							253
#define FAIL								254
#define UNKNOWN							255

#define SET									1
#define CLEAR								0

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
#define SSPIMSC_SET_RORIM   0
#define CHECK_RORIM         0x00000001


void SPI_PERIPH_INIT_ADS_TRIAL();
uint32_t ACCESS_CONTROL_REGISTER_O(uint32_t * val, uint8_t option);
uint32_t ACCESS_CONTROL_REGISTER_1(uint32_t * val, uint8_t option);
uint32_t ACCESS_PRESCALER_REG(uint32_t * val, uint8_t option);
uint32_t SPI_READ_FIFO_STATUS();
uint32_t ACCESS_INTERRUPT_MASK_SET_CLEAR(uint32_t val, uint8_t action);
uint32_t READ_RAW_INTERRUPT_STATUS_REG();
uint32_t READ_MASKED_INTERRUPT_STATUS_REG();
void WRITE_INTERRUPT_CLEAR_REGISTER(uint32_t * val);
uint32_t ACCESS_DMA_CONTROL_REGISTER(uint32_t * val, uint8_t action);
uint32_t spi_read(unsigned int no_of_bytes);


uint32_t READ_PERIPHERAL_ID_REGISTER_0();
uint32_t READ_PERIPHERAL_ID_REGISTER_1();
uint32_t READ_PERIPHERAL_ID_REGISTER_2();
uint32_t READ_PERIPHERAL_ID_REGISTER_3();

uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_0();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_1();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_2();
uint32_t READ_PERIPHERAL_CELL_ID_REGISTER_3();


#endif
