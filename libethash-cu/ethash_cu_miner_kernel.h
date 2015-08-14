#ifndef _ETHASH_CU_MINER_KERNEL_H_
#define _ETHASH_CU_MINER_KERNEL_H_

#include <stdint.h>

#define STATE_SIZE 12

typedef union
{
	uint64_t uint64s[16 / sizeof(uint64_t)];
	uint32_t uint32s[16 / sizeof(uint32_t)];
} hash16_t;


typedef union
{
	uint32_t uint32s[32 / sizeof(uint32_t)];
	uint64_t uint64s[32 / sizeof(uint64_t)];
} hash32_t;


typedef union
{
	uint32_t uint32s[64 / sizeof(uint32_t)];
	uint64_t uint64s[64 / sizeof(uint64_t)];
	uint4	 uint4s[64 / sizeof(uint4)];
} hash64_t;


typedef union
{
	uint32_t uint32s[128 / sizeof(uint32_t)];
	uint4	 uint4s[128 / sizeof(uint4)];
} hash128_t;

cudaError set_constants(
	uint32_t * dag_size,
	uint32_t * max_outputs
);

void run_ethash_search(
	uint32_t blocks,
	uint32_t threads,
	cudaStream_t stream,
	uint32_t* g_output,
	hash32_t const* g_header,
	uint64_t* g_state,
	hash128_t const* g_dag,
	uint64_t start_nonce,
	uint64_t target
);

#endif
