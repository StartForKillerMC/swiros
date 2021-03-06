/*
 * Copyright (c) 2010, Stefan Lankes, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ARCH_STDDEF_H__
#define __ARCH_STDDEF_H__

#ifdef __cplusplus
extern "C" {
#endif

#if __SIZEOF_POINTER__ == 4
#define CONFIG_X86_32
typedef unsigned long size_t;
typedef long ptrdiff_t;
#ifdef __KERNEL__
typedef long ssize_t;
typedef long off_t;
#endif
#elif __SIZEOF_POINTER__ == 8
#define CONFIG_X86_64
typedef unsigned long long size_t;
typedef long long ptrdiff_t;
#ifdef __KERNEL__
typedef long long ssize_t;
typedef long long off_t;
#endif
#else
#error unsupported architecture
#endif

typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned short wchar_t;

#ifndef _WINT_T
#define _WINT_T
typedef unsigned int wint_t;
#endif

/* This defines what the stack looks like after an ISR was running */
struct state {
#ifdef CONFIG_X86_32
	uint32_t ds;
	// es register
	uint32_t es;
	/// EDI register
	uint32_t edi;
	/// ESI register
	uint32_t esi;
	/// EBP register
	uint32_t ebp;
	/// ESP register
	uint32_t esp;
	/// EBX register 
	uint32_t ebx;
	/// EDX register
	uint32_t edx;
	/// ECX register
	uint32_t ecx;
	/// EAX register
	uint32_t eax;		/* pushed by 'pusha' */

	/// Interrupt number
	uint32_t int_no;
	
	// pushed by the processor automatically
	uint32_t error;
	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
	uint32_t useresp;
	uint32_t ss;
#elif defined(CONFIG_X86_64)
	/// R15 register
	uint64_t r15;
	/// R14 register
	uint64_t r14;
	/// R13 register
	uint64_t r13;
	/// R12 register
	uint64_t r12;
	/// R11 register
	uint64_t r11;
	/// R10 register
	uint64_t r10;
	/// R9 register
	uint64_t r9;
	/// R8 register
	uint64_t r8;
	/// RDI register
	uint64_t rdi;
	/// RSI register
	uint64_t rsi;
	/// RBP register
	uint64_t rbp;
	/// (pseudo) RSP register
	uint64_t rsp;
	/// RBX register
	uint64_t rbx;
	/// RDX register
	uint64_t rdx;
	/// RCX register
	uint64_t rcx;
	/// RAX register
	uint64_t rax;

	/// Interrupt number
	uint64_t int_no;

	// pushed by the processor automatically
	uint64_t error;
	uint64_t rip;
	uint64_t cs;
	uint64_t rflags;
	uint64_t userrsp;
	uint64_t ss;
#endif
};

#ifdef __cplusplus
}
#endif

#endif
