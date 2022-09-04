
#include <zephyr/zephyr.h>
#include <zephyr/sys/printk.h>

void main(void)
{

    while (1)
    {
        printk("Hello World\n");
        k_msleep(1000);
    }
    

}
