#include "elapsedTime.h"

/*
 * delta = end - start
 */
static void timespecDelta(struct timespec *start, struct timespec *end,	struct timespec *delta) {
	int secs, nsecs;

	secs = end->tv_sec - start->tv_sec;
	nsecs = end->tv_nsec - start->tv_nsec;

	if (nsecs < 0) {
		nsecs += 1000000000;
		secs--;
	}

	delta->tv_sec = secs;
	delta->tv_nsec = nsecs;
}

// Return elapsed time in milliseconds
double elapsedTimeInMilliSecs(struct timespec *when, struct timespec *now) {
	struct timespec delta;
	double value;

	timespecDelta(when, now, &delta);

	//                sec in milliseconds              nano sec in milliseconds
	value = ((double) delta.tv_sec * 1000) + ((double) delta.tv_nsec / 1000000.0);

	return (value);
}

double elapsedTimeSince(struct timespec *when) {
	struct timespec now;
	int status;
	double delta;

	status = clock_gettime( CLOCK_MONOTONIC_RAW, &now);
	//SetStatus(status, "clock_gettime");
	delta = (status) ? 0.0 : elapsedTimeInMilliSecs(when, &now);

	return (delta);
}
