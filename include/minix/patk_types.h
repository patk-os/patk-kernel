/*
  PATK-OS
  License:BSD-Clause 3
  Created and written by Akın Alp Öztürk <akinalpozturk577@gmail.com>
  Created on 20.11.2026 20:50
  Edited by Akın Alp Öztürk <akinalpozturk577@gmail.com> on 20.11.2026 21:16
  Edited by Akın Alp Öztürk <akinalpozturk577@gmail.com> on 20.11.2026 21:22
  Editec by Akın Alp Öztürk <akinalpozturk577@gmail.com> on 20.11.2026 21:26
*/



#ifndef _PATK_TYPES_H
#define _PATK_TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t   u8_t;
typedef uint16_t  u16_t;
typedef uint32_t  u32_t;
typedef uint64_t  u64_t;

typedef int8_t    i8_t;
typedef int16_t   i16_t;
typedef int32_t   i32_t;
typedef int64_t   i64_t;

/* Multiboot & Kernel Param definitions */
#include <minix/type.h>
#include <machine/multiboot.h>
#include <minix/param.h>

#endif /* _PATK_TYPES_H */
