/* This file has been generated by gen_flight_plan from /home/djim/Documents/paparazzi/conf/flight_plans/Team8/team8.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H

#include "std.h"
#include "generated/modules.h"
    #include "autopilot.h"
    #include "generated/modules.h"
#define FLIGHT_PLAN_NAME "Team8"
#define NAV_UTM_EAST0 594535
#define NAV_UTM_NORTH0 5760891
#define NAV_UTM_ZONE0 31
#define NAV_LAT0 519906340 /* 1e7deg */
#define NAV_LON0 43767889 /* 1e7deg */
#define NAV_ALT0 0 /* mm above msl */
#define NAV_MSL0 45110 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_CLIMB 2
#define WP_STDBY 3
#define WP_VariableWaypoint 4
#define WAYPOINTS { \
 {42.0, 42.0, 1},\
 {0.0, 0.0, 1},\
 {0.0, 5.0, 1},\
 {-2.0, -5.0, 1},\
 {0.5, 0.5, 1},\
};
#define WAYPOINTS_ENU { \
 {42.80, 41.21, 1.00}, /* ENU in meters  */ \
 {0.00, 0.00, 1.00}, /* ENU in meters  */ \
 {0.09, 5.00, 1.00}, /* ENU in meters  */ \
 {-2.09, -4.96, 1.00}, /* ENU in meters  */ \
 {0.51, 0.49, 1.00}, /* ENU in meters  */ \
};
#define WAYPOINTS_LLA { \
 {.lat=519910043, .lon=43774120, .alt=1000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=45.11m) */ \
 {.lat=519906339, .lon=43767889, .alt=1000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=45.11m) */ \
 {.lat=519906789, .lon=43767903, .alt=1000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=45.11m) */ \
 {.lat=519905893, .lon=43767585, .alt=1000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=45.11m) */ \
 {.lat=519906384, .lon=43767964, .alt=1000}, /* 1e7deg, 1e7deg, mm (above NAV_MSL0, local msl=45.11m) */ \
};
#define WAYPOINTS_LLA_WGS84 { \
 {.lat=519910043, .lon=43774120, .alt=46110}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=519906339, .lon=43767889, .alt=46110}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=519906789, .lon=43767903, .alt=46110}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=519905893, .lon=43767585, .alt=46110}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
 {.lat=519906384, .lon=43767964, .alt=46110}, /* 1e7deg, 1e7deg, mm (above WGS84 ref ellipsoid) */ \
};
#define NB_WAYPOINT 5
#define FP_BLOCKS { \
 { "Wait GPS" }, \
 { "Geo init" }, \
 { "Execute Script" }, \
 { "HOME" }, \
};
#define NB_BLOCK 4
#define GROUND_ALT 0.
#define GROUND_ALT_CM 0
#define SECURITY_HEIGHT 0.1
#define SECURITY_ALT 0.1
#define HOME_MODE_HEIGHT 1.
#define MAX_DIST_FROM_HOME 15.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // Wait GPS
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        if (! (NavKillThrottle())) {
          NextStage();
        } else {
          break;
        }
      Label(while_1)
      Stage(1)
        if (! (!(GpsFixValid()))) Goto(endwhile_2) else NextStageAndBreak();
        Stage(2)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // Geo init
    ; // pre_call
    switch(nav_stage) {
      Label(while_3)
      Stage(0)
        if (! (LessThan(NavBlockTime(),10))) Goto(endwhile_4) else NextStageAndBreak();
        Stage(1)
          Goto(while_3)
        Label(endwhile_4)
      Stage(2)
        if (! (NavSetGroundReferenceHere())) {
          NextStage();
        } else {
          break;
        }
      default:
      Stage(3)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(2) // Execute Script
    ; // pre_call
    switch(nav_stage) {
      Label(while_5)
      Stage(0)
        if (! (TRUE)) Goto(endwhile_6) else NextStageAndBreak();
        Stage(1)
          if (NavApproaching(4,CARROT)) NextStageAndBreakFrom(4) else {
            NavGotoWaypoint(4);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(4), 0.);
          }
          break;
        Label(while_7)
        Stage(2)
          if (! ((5>stage_time))) Goto(endwhile_8) else NextStageAndBreak();
          Stage(3)
            Goto(while_7)
          Label(endwhile_8)
        Stage(4)
          Goto(while_5)
        Label(endwhile_6)
      default:
      Stage(5)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(3) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H