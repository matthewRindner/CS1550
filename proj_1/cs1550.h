#ifndef _LINUX_CS1550_H
#define _LINUX_CS1550_H

#include <linux/list.h>
static LIST_HEAD(sem_list);


/**
 * A generic semaphore, providing serialized signaling and
 * waiting based upon a user-supplied integer value.
 */
struct cs1550_sem
{
	/* Current value. If nonpositive, wait() will block */
	long value;

	/* Sequential numeric ID of the semaphore */
	long sem_id;

	/* Per-semaphore lock, serializes access to value */
	spinlock_t lock;

	//list of waiting process
	struct list_head waiting_tasks;

	//points to the next and prev semaphores
	struct list_head list;
};

struct list_head
{
	struct list_head *next, *prev;
};

struct cs1550_task
{
	struct list_head *list;
	struct task_struct *waiting_tasks
}


#endif
