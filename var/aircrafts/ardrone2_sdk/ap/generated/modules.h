/* This file has been generated from /home/djim/Documents/paparazzi/conf/airframes/ardrone2_sdk.xml */
/* Please DO NOT EDIT */

#ifndef MODULES_H
#define MODULES_H

#define MODULES_IDLE  0
#define MODULES_RUN   1
#define MODULES_START 2
#define MODULES_STOP  3

#define MODULES_FREQUENCY 512

#ifdef MODULES_C
#define EXTERN_MODULES
#else
#define EXTERN_MODULES extern
#endif
#include "std.h"
#include "core/sys_mon.h"

#define PERIODIC_REPORT_SYSMON_PERIOD 1.000000
#define PERIODIC_REPORT_SYSMON_FREQ 1.000000
#define PERIODIC_SYSMON_PERIOD 0.001953
#define PERIODIC_SYSMON_FREQ 512.000000


#ifdef MODULES_C

static inline void modules_init(void) {
  init_sysmon();
}

static inline void modules_periodic_task(void) {
  static uint8_t i1; i1++; if (i1>=1) i1=0;
  static uint16_t i512; i512++; if (i512>=512) i512=0;


  periodic_sysmon();
  if (i512 == 0) {
    periodic_report_sysmon();
  }
}

static inline void modules_event_task(void) {
  event_sysmon();
}

#endif // MODULES_C

#ifdef MODULES_DATALINK_C

#include "messages.h"
#include "generated/airframe.h"
static inline void modules_parse_datalink(uint8_t msg_id __attribute__ ((unused))) {
}

#endif // MODULES_DATALINK_C

#endif // MODULES_H
