/*****************************************************************************
 * ijksdl_thread.c
 *****************************************************************************
 *
 * copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <errno.h>
#include <assert.h>
#include "ijkutil.h"
#include "ijksdl_stdinc.h"
#include "ijksdl_thread.h"

#if !defined(__APPLE__)
// using ios implement for autorelease
static void *SDL_RunThread(void *data) {
	SDL_Thread *thread = (SDL_Thread *)data;
	LOGI("SDL_RunThread: [%d] %s\n", (int )gettid(), thread->name);
	thread->retval = thread->func(thread->data);
	return NULL;
}

SDL_Thread *SDL_CreateThreadEx(SDL_Thread *thread, int (*fn)(void *),
		void *data, const char *name) {
	thread->func = fn;
	thread->data = data;
	strlcpy(thread->name, name, sizeof(thread->name) - 1);
	int retval = pthread_create(&thread->id, NULL, SDL_RunThread, thread);
	if (retval)
		return NULL;

	return thread;
}
#endif

int SDL_SetThreadPriority(SDL_ThreadPriority priority) {
	struct sched_param sched;
	int policy;
	pthread_t thread = pthread_self();

	if (pthread_getschedparam(thread, &policy, &sched) < 0) {
		LOGE("pthread_getschedparam() failed");
		return -1;
	}
	if (priority == SDL_THREAD_PRIORITY_LOW) {
		sched.sched_priority = sched_get_priority_min(policy);
	} else if (priority == SDL_THREAD_PRIORITY_HIGH) {
		sched.sched_priority = sched_get_priority_max(policy);
	} else {
		int min_priority = sched_get_priority_min(policy);
		int max_priority = sched_get_priority_max(policy);
		sched.sched_priority =
				(min_priority + (max_priority - min_priority) / 2);
	}
	if (pthread_setschedparam(thread, policy, &sched) < 0) {
		LOGE("pthread_setschedparam() failed");
		return -1;
	}
	return 0;
}

void SDL_WaitThread(SDL_Thread *thread, int *status) {
	assert(thread);
	if (!thread)
		return;

	pthread_join(thread->id, NULL);

	if (status)
		*status = thread->retval;
}
