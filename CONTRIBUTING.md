# Contributing to PATK-Kernel

Thank you for your interest in **PATK-Kernel** (PanicAtTheKernel). 

We are building an uncompromising, crash-proof microkernel operating system natively targeting modern 64-bit architectures. Before writing code or submitting Pull Requests (PRs), you **must** understand and adhere to our architectural laws.

---

## The Iron Laws of PATK-Kernel

1. **Ring 0 Is Strictly Minimal:**
   - **NO HARDWARE DRIVERS IN RING 0.** GPU, Wi-Fi, Ethernet, and storage drivers belong strictly in user space (Ring 3). Any PR introducing hardware drivers into the kernel core will be rejected immediately.
   - File systems (VFS) and network protocol stacks live in Ring 3. 

2. **Freestanding Code Only:**
   - The kernel lives directly on the bare metal. Standard user-space C libraries (`glibc`, `musl`, etc.) do not exist here.
   - Never `#include <stdlib.h>`, `<stdio.h>`, or `<pthread.h>`.
   - All code must compile with `-ffreestanding -nostdinc`.

3. **Pure 64-Bit Modernization (Current Focus):**
   - We are actively migrating legacy 32-bit x86/i386 structures to pure `x86_64` Long Mode.
   - PRs must strictly use fixed-width integer types (`u32_t`, `u64_t`, or `uint32_t`, `uint64_t`) and maintain 16-byte stack alignment compliance with the System V AMD64 ABI.

4. **IPC Must Be Fast:**
   - Avoid unnecessary memory copying (copy-in/copy-out) between address spaces.
   - New syscalls and IPC routines must prioritize CPU register-bound message passing (`r8-r15`).

---

## Coding Style & Standards

- **Languages:** ANSI C (C99/C11 standards) and AT&T/NASM syntax x86 Assembly.
- **Indentation:** 8-character tabs (BSD/Kernel convention) or 4 spaces consistently per module.
- **License Compliance:** All new files must include the SPDX license identifier:
  ```c
  /* SPDX-License-Identifier: BSD-3-Clause */
  /* Copyright (c) 2026 PATK-OS Authors */
  ```

---

## Development Workflow

1. Fork the repository.
2. Create a descriptive feature branch: `git checkout -b feature/x86_64-paging`.
3. Ensure the core compiles cleanly without warnings:
   ```bash
   make
   ```
4. Test on QEMU before submitting:
   ```bash
   make qemu
   ```
5. Submit a detailed Pull Request explaining the architectural impact.

**Remember: Monoliths panic. Microkernels prevail.**