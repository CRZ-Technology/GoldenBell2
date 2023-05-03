//////////////////////////////////////////////////////////////////////////////////
// memory_map.h for Cosmos+ OpenSSD
// Copyright (c) 2017 Hanyang University ENC Lab.
// Contributed by Yong Ho Song <yhsong@enc.hanyang.ac.kr>
//				  Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
//				  Sangjin Lee <sjlee@enc.hanyang.ac.kr>
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
// Engineer: Jaewook Kwak <jwkwak@enc.hanyang.ac.kr>
//
// Project Name: Cosmos+ OpenSSD
// Design Name: Cosmos+ Firmware
// Module Name: Static Memory Allocator
// File Name: memory_map.h
//
// Version: v1.0.0
//
// Description:
//	 - allocate DRAM address space (0x0010_0000 ~ 0x3FFF_FFFF) to each module
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Revision History:
//
// * v1.0.0
//   - First draft
//////////////////////////////////////////////////////////////////////////////////

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "data_buffer.h"
#include "address_translation.h"
#include "request_allocation.h"
#include "request_schedule.h"
#include "request_transform.h"
#include "request_ipc.h"

#define DRAM_START_ADDR				        0x00100000

#define MEMORY_SEGMENTS_CORE0_START_ADDR	DRAM_START_ADDR
#define MEMORY_SEGMENTS_CORE0_END_ADDR		0x001FFFFF

#define MEMORY_SEGMENTS_CORE1_START_ADDR	0x00200000
#define MEMORY_SEGMENTS_CORE1_END_ADDR		0x002FFFFF


// Uncached & Unbuffered
//for data buffer
#define NVME_MANAGEMENT_START_ADDR		0x00300000
#define NVME_MANAGEMENT_END_ADDR		0x003FFFFF

#define IPC_CMD_ADDR                        0x400000
#define IPC_CMD_END_ADDR                    0x4FFFFF

#define IPC_STORAGE_CORE1_ADDR              0x500000

#define IPC_START_REQ_CORE1_ADDR            0x500004

#define IPC_START_RES_CORE1_ADDR            0x500008

#define RESERVED0_START_ADDR			0x0050000C
#define RESERVED0_END_ADDR				0x0FFFFFFF

#define FPGA_DUMMY_ADDR (0x10000000 - 0x1000) // Dummy 4KB address for FPGA dma operation.

#define DATA_BUFFER_BASE_ADDR 					0x10000000


// cached & buffered
// for buffers
#define DATA_BUFFER_MAP_ADDR		 		0x18000000
#define DATA_BUFFFER_HASH_TABLE_ADDR		(DATA_BUFFER_MAP_ADDR + sizeof(DATA_BUF_MAP))
// for request pool
#define REQ_POOL_ADDR 		(DATA_BUFFFER_HASH_TABLE_ADDR + sizeof(DATA_BUF_HASH_TABLE))
#define REQ_POOL_END_ADDR				    0x3FFFFFFF
#define DRAM_END_ADDR						0x3FFFFFFF

#endif /* MEMORY_MAP_H_ */
