/* This file has been generated from /home/djim/Documents/paparazzi/conf/airframes/ardrone2_sdk.xml */
/* Please DO NOT EDIT */

#ifndef AIRFRAME_H
#define AIRFRAME_H

#define AIRFRAME_NAME "ardrone2_sdk"
#define AC_ID 200
#define MD5SUM ((uint8_t*)"\017\002\223\255\154\376\127\026\057\004\345\214\366\172\264\225")

#define COMMAND_PITCH 0
#define COMMAND_ROLL 1
#define COMMAND_YAW 2
#define COMMAND_THRUST 3
#define COMMANDS_NB 4
#define COMMANDS_FAILSAFE {0,0,0,0}


#define SERVOS_DEFAULT_NB -4611686018427387903
#include "subsystems/actuators/actuators_default.h"


#define SECTION_STABILIZATION_RATE 1
#define STABILIZATION_RATE_SP_MAX_P 10000
#define STABILIZATION_RATE_SP_MAX_Q 10000
#define STABILIZATION_RATE_SP_MAX_R 10000
#define STABILIZATION_RATE_DEADBAND_P 20
#define STABILIZATION_RATE_DEADBAND_Q 20
#define STABILIZATION_RATE_DEADBAND_R 200
#define STABILIZATION_RATE_REF_TAU 4
#define STABILIZATION_RATE_GAIN_P 400
#define STABILIZATION_RATE_GAIN_Q 400
#define STABILIZATION_RATE_GAIN_R 350
#define STABILIZATION_RATE_IGAIN_P 75
#define STABILIZATION_RATE_IGAIN_Q 75
#define STABILIZATION_RATE_IGAIN_R 50
#define STABILIZATION_RATE_DDGAIN_P 300
#define STABILIZATION_RATE_DDGAIN_Q 300
#define STABILIZATION_RATE_DDGAIN_R 300

#define SECTION_STABILIZATION_ATTITUDE 1
#define STABILIZATION_ATTITUDE_SP_MAX_PHI 0.523598775
#define STABILIZATION_ATTITUDE_SP_MAX_THETA 0.523598775
#define STABILIZATION_ATTITUDE_SP_MAX_R 1.570796325
#define STABILIZATION_ATTITUDE_DEADBAND_A 0
#define STABILIZATION_ATTITUDE_DEADBAND_E 0
#define STABILIZATION_ATTITUDE_DEADBAND_R 250

#define SECTION_GUIDANCE_V 1
#define GUIDANCE_V_HOVER_KP 425
#define GUIDANCE_V_HOVER_KD 200
#define GUIDANCE_V_HOVER_KI 125
#define GUIDANCE_V_NOMINAL_HOVER_THROTTLE 0.5
#define GUIDANCE_V_ADAPT_THROTTLE_ENABLED FALSE

#define SECTION_GUIDANCE_H 1
#define GUIDANCE_H_MAX_BANK 0.523598775
#define GUIDANCE_H_PGAIN 7
#define GUIDANCE_H_DGAIN 2
#define GUIDANCE_H_IGAIN 0

#define SECTION_AUTOPILOT 1
#define MODE_STARTUP AP_MODE_NAV
#define MODE_MANUAL AP_MODE_RC_DIRECT
#define MODE_AUTO1 AP_MODE_HOVER_Z_HOLD
#define MODE_AUTO2 AP_MODE_NAV

#define SECTION_BAT 1
#define CATASTROPHIC_BAT_LEVEL .2
#define CRITIC_BAT_LEVEL 1.9
#define LOW_BAT_LEVEL 2.5
#define MAX_BAT_LEVEL 10.0

#define SECTION_IMU 1
#define IMU_ACCEL_X_NEUTRAL 2072
#define IMU_ACCEL_Y_NEUTRAL 2040
#define IMU_ACCEL_Z_NEUTRAL 2047
#define IMU_ACCEL_X_SENS 19.1079036954
#define IMU_ACCEL_X_SENS_NUM 27802
#define IMU_ACCEL_X_SENS_DEN 1455
#define IMU_ACCEL_Y_SENS 19.5393623518
#define IMU_ACCEL_Y_SENS_NUM 30032
#define IMU_ACCEL_Y_SENS_DEN 1537
#define IMU_ACCEL_Z_SENS 19.6539180847
#define IMU_ACCEL_Z_SENS_NUM 21069
#define IMU_ACCEL_Z_SENS_DEN 1072
#define IMU_ACCEL_X_SIGN 1
#define IMU_ACCEL_Y_SIGN -1
#define IMU_ACCEL_Z_SIGN -1
#define IMU_GYRO_P_SENS_NUM 4359
#define IMU_GYRO_P_SENS_DEN 1000
#define IMU_GYRO_Q_SENS_NUM 4359
#define IMU_GYRO_Q_SENS_DEN 1000
#define IMU_GYRO_R_SENS_NUM 4359
#define IMU_GYRO_R_SENS_DEN 1000
#define IMU_GYRO_P_SIGN 1
#define IMU_GYRO_Q_SIGN -1
#define IMU_GYRO_R_SIGN -1
#define IMU_MAG_X_NEUTRAL 118
#define IMU_MAG_Y_NEUTRAL -65
#define IMU_MAG_Z_NEUTRAL 110
#define IMU_MAG_X_SENS 14.6416865144
#define IMU_MAG_X_SENS_NUM 6252
#define IMU_MAG_X_SENS_DEN 427
#define IMU_MAG_Y_SENS 14.5167340835
#define IMU_MAG_Y_SENS_NUM 39471
#define IMU_MAG_Y_SENS_DEN 2719
#define IMU_MAG_Z_SENS 15.1670335124
#define IMU_MAG_Z_SENS_NUM 62018
#define IMU_MAG_Z_SENS_DEN 4089
#define IMU_MAG_X_SIGN -1
#define IMU_MAG_Y_SIGN 1
#define IMU_MAG_Z_SIGN -1
#define IMU_BODY_TO_IMU_PHI 0.
#define IMU_BODY_TO_IMU_THETA 0.
#define IMU_BODY_TO_IMU_PSI 0.


#endif // AIRFRAME_H