/*
 * elapsedTime.h
 *
 *  Created on: Nov 7, 2011
 *      Author: bob
 */

#ifndef ELAPSEDTIME_H_
#define ELAPSEDTIME_H_

#include <time.h>

double elapsedTimeInMilliSecs(struct timespec *when, struct timespec *now);

double elapsedTimeSince(struct timespec *when);

#endif /* ELAPSEDTIME_H_ */
