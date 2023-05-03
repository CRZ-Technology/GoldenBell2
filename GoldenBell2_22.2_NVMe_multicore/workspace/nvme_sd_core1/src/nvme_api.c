/*
 * nvme_api.c
 *
 *  Created on: 2020. 1. 17.
 *      Author: ProDesk
 */

#include "xstatus.h"
#include "xil_types.h"
#include "xil_printf.h"
#include "string.h"
#include "stdlib.h"
#include "nvme.h"
#include "xsdps.h"		/* SD device driver */

int read_sd(u64 startLba, u64 DstAddr, u64 nlb)
{
	u64 sd_blk = startLba * (BYTES_PER_NVME_BLOCK / BYTES_PER_SD_BLOCK);
	u64 sd_nlb = nlb * (BYTES_PER_NVME_BLOCK / BYTES_PER_SD_BLOCK);

	XSdPs_ReadPolled(&SdInstance, sd_blk, sd_nlb, (u8 *)DstAddr);
}

int write_sd(u64 startLba, u64 SrcAddr, u64 nlb)
{
	u64 sd_blk = startLba * (BYTES_PER_NVME_BLOCK / BYTES_PER_SD_BLOCK);
	u64 sd_nlb = nlb * (BYTES_PER_NVME_BLOCK / BYTES_PER_SD_BLOCK);

	XSdPs_WritePolled(&SdInstance, sd_blk, sd_nlb,	(u8 *)SrcAddr);
}
