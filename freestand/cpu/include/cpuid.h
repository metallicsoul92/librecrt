/* freestand/cpu/include/cpuid.h */

#ifndef _CPUID_H
#define _CPUID_H

#include <stdint.h>

/**
 * @brief Structure to store the result of the CPUID instruction.
 *
 * This structure holds the values returned by the CPUID instruction
 * in the `eax`, `ebx`, `ecx`, and `edx` registers.
 */
typedef struct {
    uint32_t eax; /**< Value from EAX register */
    uint32_t ebx; /**< Value from EBX register */
    uint32_t ecx; /**< Value from ECX register */
    uint32_t edx; /**< Value from EDX register */
} cpuid_t;

/**
 * @brief Executes the CPUID instruction with the given function and subfunction.
 *
 * This function retrieves information about the processor using the CPUID instruction,
 * and stores the results in the provided `cpuid_t` structure.
 *
 * @param function The main function code to pass to the CPUID instruction (loaded into EAX).
 * @param subfunction The subfunction code to pass to the CPUID instruction (loaded into ECX).
 * @param result Pointer to a cpuid_t structure to store the results.
 */
static inline void cpuid(uint32_t function, uint32_t subfunction, cpuid_t *result) {
    __asm__ volatile(
        "cpuid"
        : "=a" (result->eax), "=b" (result->ebx), "=c" (result->ecx), "=d" (result->edx)
        : "a" (function), "c" (subfunction)
    );
}

/* CPUID Feature Flags (Function 01h, EDX Register) */
#define CPUID_FLAG_FPU        (1 << 0)  /**< Floating Point Unit on-chip */
#define CPUID_FLAG_VME        (1 << 1)  /**< Virtual Mode Extension */
#define CPUID_FLAG_DE         (1 << 2)  /**< Debugging Extension */
#define CPUID_FLAG_PSE        (1 << 3)  /**< Page Size Extension */
#define CPUID_FLAG_TSC        (1 << 4)  /**< Time Stamp Counter */
#define CPUID_FLAG_MSR        (1 << 5)  /**< Model-Specific Registers */
#define CPUID_FLAG_PAE        (1 << 6)  /**< Physical Address Extension */
#define CPUID_FLAG_MCE        (1 << 7)  /**< Machine Check Exception */
#define CPUID_FLAG_CX8        (1 << 8)  /**< CMPXCHG8 Instruction */
#define CPUID_FLAG_APIC       (1 << 9)  /**< On-chip APIC Hardware */
#define CPUID_FLAG_SEP        (1 << 11) /**< SYSENTER/SYSEXIT */
#define CPUID_FLAG_MTRR       (1 << 12) /**< Memory Type Range Registers */
#define CPUID_FLAG_PGE        (1 << 13) /**< Page Global Enable */
#define CPUID_FLAG_MCA        (1 << 14) /**< Machine Check Architecture */
#define CPUID_FLAG_CMOV       (1 << 15) /**< Conditional Move Instruction */
#define CPUID_FLAG_PAT        (1 << 16) /**< Page Attribute Table */
#define CPUID_FLAG_PSE36      (1 << 17) /**< 36-bit Page Size Extension */
#define CPUID_FLAG_PSN        (1 << 18) /**< Processor Serial Number */
#define CPUID_FLAG_CLFSH      (1 << 19) /**< CLFLUSH Instruction */
#define CPUID_FLAG_DS         (1 << 21) /**< Debug Store */
#define CPUID_FLAG_ACPI       (1 << 22) /**< Thermal Monitor and Clock Control */
#define CPUID_FLAG_MMX        (1 << 23) /**< MMX Technology */
#define CPUID_FLAG_FXSR       (1 << 24) /**< FXSAVE/FXRSTOR */
#define CPUID_FLAG_SSE        (1 << 25) /**< SSE Instructions */
#define CPUID_FLAG_SSE2       (1 << 26) /**< SSE2 Instructions */
#define CPUID_FLAG_SS         (1 << 27) /**< Self Snoop */
#define CPUID_FLAG_HTT        (1 << 28) /**< Hyper-Threading Technology */
#define CPUID_FLAG_TM         (1 << 29) /**< Thermal Monitor */
#define CPUID_FLAG_PBE        (1 << 31) /**< Pending Break Enable */

#endif /* _CPUID_H */
