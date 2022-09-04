
#include <zephyr/zephyr.h>
#include <zephyr/sys/printk.h>

#define MY_STACK_SIZE 512

static void thread1_handler(void *, void *, void *);
static void thread2_handler(void *, void *, void *);

K_THREAD_STACK_DEFINE(stack1, MY_STACK_SIZE);
struct k_thread thread1_data;

K_THREAD_STACK_DEFINE(stack2, MY_STACK_SIZE);
struct k_thread thread2_data;

void main(void)
{
    k_thread_create(&thread1_data, stack1,
                    K_THREAD_STACK_SIZEOF(stack1),
                    thread1_handler,
                    NULL, NULL, NULL,
                    4, 0, K_NO_WAIT);

    k_thread_create(&thread2_data, stack2,
                    K_THREAD_STACK_SIZEOF(stack2),
                    thread2_handler,
                    NULL, NULL, NULL,
                    2, 0, K_NO_WAIT);
}

/**
 * @brief task_handler function for thread 1
 *  - after spawning, thread1 begins executing this function
 * 
 * @param unused1 1st parameter
 * @param unused2 2nd parameter
 * @param unused3 3rd parameter
 */
static void thread1_handler(void *unused1, void *unused2, void *unused3)
{
    ARG_UNUSED(unused1);
    ARG_UNUSED(unused2);
    ARG_UNUSED(unused3);

    while (1)
    {
        printk("Thread 1\n");
        k_msleep(1000);
    }
}

/**
 * @brief task_handler function for thread 2
 *  - after spawning, thread2 begins executing this function
 * 
 * @param unused1 1st parameter
 * @param unused2 2nd parameter
 * @param unused3 3rd parameter
 */
static void thread2_handler(void *unused1, void *unused2, void *unused3)
{
    ARG_UNUSED(unused1);
    ARG_UNUSED(unused2);
    ARG_UNUSED(unused3);

    while (1)
    {
        printk("Thread 2\n");
        k_msleep(350);
    }
}