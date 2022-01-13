#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>
#include <linux/stddef.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/cs1550.h>

static DEFINE_RWLOCK(lock);


/**
 * Creates a new semaphore. The long integer value is used to
 * initialize the semaphore's value.
 *
 * The initial `value` must be greater than or equal to zero.
 *
 * On success, returns the identifier of the created
 * semaphore, which can be used with up() and down().
 *
 * On failure, returns -EINVAL or -ENOMEM, depending on the
 * failure condition.
 */
SYSCALL_DEFINE1(cs1550_create, long, value)
{
	if(value >= 0)
	{
		//initailize the new semaphore to the value and its pointers
		//append on global list
		struct cs1550_sem *sem->sem_id = value;
		INIT_LIST_HEAD(&sem->list);

		sem->value += 1;

		//add new entry directly after head of list
		list_add(&sem->list, &sem_list
	}

	return sem->sem_id;
}

/**
 * Performs the down() operation on an existing semaphore
 * using the semaphore identifier obtained from a previous call
 * to cs1550_create().
 *
 * This decrements the value of the semaphore, and *may cause* the
 * calling process to sleep (if the semaphore's value goes below 0)
 * until up() is called on the semaphore by another process.
 *
 * Returns 0 when successful, or -EINVAL or -ENOMEM if an error
 * occurred.
 */
SYSCALL_DEFINE1(cs1550_down, long, sem_id)
{
	/*
	value -= 1
	if(value < 0){
		add process to list
		sleep()
		}
	*/
	struct cs1550_sem *sem;
	sem->sem_id = sem_id
	//lock to read through semaphore list
	read_lock(rwlock_t *sem_id);
	write_lock(rwlock_t *sem_id);
		//search through list
	list_for_each_entry(sem, &sem_list, list)
	{
		//idk how to use this
	}
	//protection with critical section
	spin_lock_init(spinlock_t);
	spin_lock(spin_lock_t *sem_id)
	sem->value--
	//if value is positve, put process to sleep temperaralyn and continue
	if(sem->value < 0)
	{
		struct cs1550_task *new_task = (struct cs1550_task *)kmalloc(sizeof(struct cs1550_task), GFP_ATOMIC);
		//traversal
		new_task->task = current;
		new_task->next = NULL;
		//if list has other stuff in it, append to end, else, the the beginning
		if(!list_empty(&sem->waiting_tasks))
		{
			list_add_tail(&new_task->list, &sem->waiting_tasks);
		}
		else
		{
			list_add(struct list_head *new, struct list_head *head)
		}
		//put process to sleep, unlock spinlock, call the sheduler
		set_current_state(TASK_INTERRUPTIBLE);
		spin_unlock(spin_lock *t)
		//end of mutual exclusion
		schedule()
	}
	else
	{
		spink_unlock(spin_lock *t)

	}
	//end of critical section R/W
	read_unlock(rwlock_t *sem_id);
	write_unlock(rwlock_t *sem_id);

	return 0;
}

/**
 * Performs the up() operation on an existing semaphore
 * using the semaphore identifier obtained from a previous call
 * to cs1550_create().
 *
 * This increments the value of the semaphore, and *may cause* the
 * calling process to wake up a process waiting on the semaphore,
 * if such a process exists in the queue.
 *
 * Returns 0 when successful, or -EINVAL if the semaphore ID is
 * invalid.
 */
SYSCALL_DEFINE1(cs1550_up, long, sem_id)
{
	struct cs1550_sem *sem;
	sem->sem_id = sem_id
	//lock to read through semaphore list
	read_lock(rwlock_t *sem_id);
	write_lock(rwlock_t *sem_id);
		//search through list
	list_for_each_entry(sem, &sem_list, list)
	{
		//idk how to use this
	}
	//protection with critical section
	spin_lock_init(spinlock_t);
	spin_lock(spin_lock_t *sem_id);
	sem->value++;
	//if value is positve, put process to sleep temperaralyn and continue
	if(sem->value <= 0)
	{
		struct cs1550_task *new_task;
		//if list has other stuff in it, append to end, else, the the beginning
		if(list_empty(&sem->sem_id))
		{
			//taverse to end

		}

		//traversal
		new_task->task = current;
		new_task->next = NULL;

		kfree(new_task);
		wake_up_process(new_task);

	}
	//end of critical section R/W
	read_unlock(rwlock_t *sem_id);
	write_unlock(rwlock_t *sem_id);

	return 0;

}

/**
 * Removes an already-created semaphore from the system-wide
 * semaphore list using the identifier obtained from a previous
 * call to cs1550_create().
 *
 * Returns 0 when successful or -EINVAL if the semaphore ID is
 * invalid or the semaphore's process queue is not empty.
 */
SYSCALL_DEFINE1(cs1550_close, long, sem_id)
{
	read_lock(rwlock_t *sem_id);
	write_lock(rwlock_t *sem_id);

	list_for_each_entry(sem, &sem_list, list)
	{
		if(cs1550_sem->sem_id =
	}
	//enter critical section
	spin_lock_init(spinlock_t);
	spin_lock(spin_lock_t *)

	//if the list is empty, remove semaphore, unlock, and free its memory
	if(list_empty(&sem->waiting_tasks))
	{
		list_del(struct list_head *sem)
		//critical section over
		spink_unlock(spin_lock *t)
		task_struct->curr = (struct cs1550_task *)kfree(sizeof(struct cs1550_task), GFP_NOWAIT);
	}
	else
	{
		//end of critical section R/W
		read_unlock(rwlock_t *sem_id);
		write_unlock(rwlock_t *sem_id);
	}
	return 0;
}
