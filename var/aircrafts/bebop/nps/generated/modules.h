/* This file has been generated from /home/djim/Documents/paparazzi/conf/airframes/bebop.xml */
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
#include "calibration/send_imu_mag_current.h"
#include "loggers/file_logger.h"

#define SEND_IMU_MAG_CURRENT_PERIOD 0.050000
#define SEND_IMU_MAG_CURRENT_FREQ 20.000000
#define FILE_LOGGER_PERIODIC_PERIOD 0.001953
#define FILE_LOGGER_PERIODIC_FREQ 512.000000

EXTERN_MODULES uint8_t calibration_send_imu_mag_current_status;
EXTERN_MODULES uint8_t loggers_file_logger_periodic_status;

#ifdef MODULES_C

static inline void modules_init(void) {
  calibration_send_imu_mag_current_status = MODULES_IDLE;
  loggers_file_logger_periodic_status = MODULES_IDLE;
}

static inline void modules_periodic_task(void) {
  static uint8_t i1; i1++; if (i1>=1) i1=0;
  static uint8_t i25; i25++; if (i25>=25) i25=0;

  if (calibration_send_imu_mag_current_status == MODULES_START) {
    calibration_send_imu_mag_current_status = MODULES_RUN;
  }
  if (calibration_send_imu_mag_current_status == MODULES_STOP) {
    calibration_send_imu_mag_current_status = MODULES_IDLE;
  }

  if (loggers_file_logger_periodic_status == MODULES_START) {
    file_logger_start();
    loggers_file_logger_periodic_status = MODULES_RUN;
  }
  if (loggers_file_logger_periodic_status == MODULES_STOP) {
    file_logger_stop();
    loggers_file_logger_periodic_status = MODULES_IDLE;
  }

  if (loggers_file_logger_periodic_status == MODULES_RUN) {
    file_logger_periodic();
  }
  if (i25 == 0 && calibration_send_imu_mag_current_status == MODULES_RUN) {
    send_imu_mag_current();
  }
}

static inline void modules_event_task(void) {
}

#endif // MODULES_C

#ifdef MODULES_DATALINK_C

#include "messages.h"
#include "generated/airframe.h"
static inline void modules_parse_datalink(uint8_t msg_id __attribute__ ((unused))) {
}

#endif // MODULES_DATALINK_C

#endif // MODULES_H
