//////////////////////////////////////////////////////////////////////////////////
// nvme_main.c for Cosmos+ OpenSSD
// Copyright (c) 2016 Hanyang University ENC Lab.
// Contributed by Yong Ho Song <yhsong@enc.hanyang.ac.kr>
//				  Youngjin Jo <yjjo@enc.hanyang.ac.kr>
//				  Sangjin Lee <sjlee@enc.hanyang.ac.kr>
//				  Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
//				  Kibin Park <kbpark@enc.hanyang.ac.kr>
//
// This file is part of Cosmos+ OpenSSD.
//
// Cosmos+ OpenSSD is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// Cosmos+ OpenSSD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Cosmos+ OpenSSD; see the file COPYING.
// If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Company: ENC Lab. <http://enc.hanyang.ac.kr>
// Engineer: Sangjin Lee <sjlee@enc.hanyang.ac.kr>
//			 Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
//			 Kibin Park <kbpark@enc.hanyang.ac.kr>
//
// Project Name: Cosmos+ OpenSSD
// Design Name: Cosmos+ Firmware
// Module Name: NVMe Main
// File Name: nvme_main.c
//
// Version: v1.2.0
//
// Description:
//   - initializes FTL and NAND
//   - handles NVMe controller
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Revision History:
//
// * v1.2.0
//   - header file for buffer is changed from "ia_lru_buffer.h" to "lru_buffer.h"
//   - Low level scheduler execution is allowed when there is no i/o command
//
// * v1.1.0
//   - DMA status initialization is added
//
// * v1.0.0
//   - First draft
//////////////////////////////////////////////////////////////////////////////////

#include "xil_printf.h"
#include "debug.h"

#include "nvme.h"
#include "nvme_main.h"

#include "memory_map.h"
#include "nvme_api.h"
#include "xsdps.h"		/* SD device driver */
#include "request_ipc.h"

static const unsigned int storage_info_addr = IPC_STORAGE_CORE1_ADDR;
extern const unsigned int start_req_addr;
extern const unsigned int start_res_addr;
XSdPs SdInstance;

int nvme_main(void)
{
	XSdPs_Config *SdConfig;
	int Status;

	/*
	 * Initialize the host controller
	 */
	SdConfig = XSdPs_LookupConfig(XPAR_XSDPS_0_DEVICE_ID);
	if (NULL == SdConfig) {
		return XST_FAILURE;
	}

	Status = XSdPs_CfgInitialize(&SdInstance, SdConfig,
					SdConfig->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Status = XSdPs_CardInitialize(&SdInstance);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

    InitIpcQueue();

	*(unsigned int *)storage_info_addr = SdInstance.SectorCount;

    while(*(unsigned int *)start_req_addr == 0)
        ;

    *(unsigned int *)start_res_addr = 1;

	while(1)
	{
        ProcessNvmeSdReq();
	}

	return XST_SUCCESS;
}


