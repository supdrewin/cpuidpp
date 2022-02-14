/// CPUID++ - C++ wrappers for X86 cpu model detection.
/// Copyright (C) 2022  Supdrewin
///
/// This library is free software: you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by the Free
/// Software Foundation, either version 3 of the License, or (at your option)
/// any later version.
///
/// This library is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
/// more details.
///
/// You should have received a copy of the GNU General Public License along with
/// this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

namespace cpuid {

namespace feature {

enum LEAF_1_ECX : unsigned {
  SSE3 = 1u << 0, // SSE3, MXCSR, CR4.OSXMMEXCPT, #XF,
                  // if FPU=1 then also FISTTP

  PCLMULQDQ = 1u << 1,

  PCLMUL = PCLMULQDQ, // for gcc compat

  DTES64 = 1u << 2, // 64-bit Debug Trace and EMON Store MSRs

  MONITOR = 1u << 3, // MONITOR_FILTER_LINE_SIZE MSR

  DSCPL = 1u << 4, //	CPL-qualified Debug Store

  VMX = 1u << 5,

  SMX = 1u << 6, //	CR4.SMXE, GETSEC

  EIST = 1u << 7, // Enhanced SpeedStep Technology

  TM2 = 1u << 8, //	MISC_ENABLE.TM2E
                 // THERM_INTERRUPT and THERM_STATUS MSRs
                 // xAPIC thermal LVT entry
                 // THERM2_CONTROL MSR

  SSSE3 = 1u << 9,

  CNXID = 1u << 10, // context ID: the L1 data cache can be set to adaptive
                    // or shared mode MISC_ENABLE.L1DCCM

  //? gcc
  SDBG = 1u << 11, // DEBUG_INTERFACE MSR for silicon debug

  FMA = 1u << 12,

  CMPXCHG16B = 1u << 13,

  xTPR = 1u << 14, // MISC_ENABLE.ETPRD

  PDCM = 1u << 15, // Performance Debug Capability MSR

  // bit 16 reserved

  PCID = 1u << 17, //	CR4.PCIDE

  DCA = 1u << 18, // Direct Cache Access (that is, the ability to
                  // prefetch data from MMIO)

  SSE41 = 1u << 19, // SSE4.1, MXCSR, CR4.OSXMMEXCPT, #XF

  SSE4_1 = SSE41, // for gcc compat

  SSE42 = 1u << 20,

  SEE4_2 = SSE42, // for gcc compat

  x2APIC = 1u << 21, //	x2APIC, APIC_BASE.EXTD, MSRs 0000_0800h...0000_0BFFh
                     // 64-bit ICR (+030h but not +031h), no DFR (+00Eh),
                     // SELF_IPI (+040h)

  MOVBE = 1u << 22,

  POPCNT = 1u << 23,

  TSCDeadline = 1u << 24, // local APIC supports one-shot operation
                          // using TSC deadline value

  AESNI = 1u << 25,

  AES = AESNI, // for gcc compat

  XSAVE = 1u << 26, // CR4.OSXSAVE, XCRn, XGETBV, XSETBV, XSAVE(OPT), XRSTOR

  OSXSAVE = 1u << 27, // non-privileged read-only copy of
                      // current CR4.OSXSAVE value

  AVX = 1u << 28,

  F16C = 1u << 29, //	VCVTPH2PS and VCVTPS2PH

  RDRND = 1u << 30,

  //? gcc
  HV = 1u << 31, // hypervisor present (and intercepting this bit,
                 // to advertise its presence)
};

enum LEAF_1_EDX : unsigned {
  FPU = 1u << 0,

  VME = 1u << 1, // CR4.VME/PVI, EFLAGS.VIP/VIF, TSS32.IRB

  DE = 1u << 2, // CR4.DE, DR7.RW=10b, #UD on MOV from/to DR4/5

  PSE = 1u << 3, // PDE.PS, PDE/PTE.res, CR4.PSE, #PF(1xxxb)

  TSC = 1u << 4, //	TSC, RDTSC, CR4.TSD (doesn't imply MSR=1)

  MSR = 1u << 5, //	MSRs, RDMSR/WRMSR

  PAE = 1u << 6, //	64-bit PDPTE/PDE/PTEs, CR4.PAE

  MCE = 1u << 7, //	MCAR/MCTR MSRs, CR4.MCE, #MC

  CX8 = 1u << 8, // Some processors do support CMPXCHG8B,
                 // but don't report it by default.

  CMPXCHG8B = CX8, // for gcc compat

  APIC = 1u << 9, // If the APIC has been disabled, then the APIC
                  // feature flag will read as 0.
                  // Early AMD K5 processors (SSA5) inadvertently
                  // used this bit to report PGE support.

  // bit 10	reserved

  SEP = 1u << 11, // SYSENTER/SYSEXIT, SEP_* MSRs
                  // The Intel P6 processor does not support SEP, but
                  // inadvertently reports it.

  MTRR = 1u << 12, //	MTRR* MSRs

  PGE = 1u << 13, // PDE/PTE.G, CR4.PGE

  MCA = 1u << 14,

  CMOV = 1u << 15, // CMOVcc, if FPU=1 then also FCMOVcc/F(U)COMI(P)

  PAT = 1u << 16, // PAT MSR, PDE/PTE.PAT

  PSE36 = 1u << 17, // 4 MB PDE bits 16...13, CR4.PSE

  PSN = 1u << 18, // If the PSN has been disabled, then the PSN feature flag
                  // will read as 0. In addition the value for the maximum
                  // supported standard level (reported by standard level
                  // 0000_0000h, register EAX) will be lower.

  CLFSH = 1u << 19, // CLFLUSH

  // bit 20	reserved

  DS = 1u << 21, //	Debug Trace and EMON Store MSRs

  ACPI = 1u << 22, //	THERM_CONTROL MSR

  MMX = 1u << 23,

  FXSR = 1u << 24, //	FXSAVE/FXRSTOR, CR4.OSFXSR

  FXSAVE = FXSR, // for gcc compat

  SSE = 1u << 25,

  SSE2 = 1u << 26,

  SS = 1u << 27, //	selfsnoop

  HTT = 1u << 28, // Hyper-Threading Technology, PAUSE

  TM = 1u << 29, // THERM_INTERRUPT and THERM_STATUS MSRs
                 // xAPIC thermal LVT entry

  //? gcc
  IA64 = 1u << 30, //	IA-64, JMPE Jv, JMPE Ev

  PBE = 1u << 31, // Pending Break Event
};

} // namespace feature

auto check_feature(feature::LEAF_1_ECX) -> bool;

auto check_feature(feature::LEAF_1_EDX) -> bool;

} // namespace cpuid
