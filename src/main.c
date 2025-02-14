#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS   1000U

/* Get the prefix of these aliases */
#define LED0            DT_ALIAS(led0)
#define LED1            DT_ALIAS(led1)
#define LED2            DT_ALIAS(led2)
#define LED3            DT_ALIAS(led3)

/* get the port, pin, and prop for these led pins from DT */
static const struct gpio_dt_spec led_0 = GPIO_DT_SPEC_GET(LED0, gpios);
static const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED1, gpios);
static const struct gpio_dt_spec led_2 = GPIO_DT_SPEC_GET(LED2, gpios);
static const struct gpio_dt_spec led_3 = GPIO_DT_SPEC_GET(LED3, gpios);

int main(void)
{
        /* 
         * Configure the led pin by assigning the discovered property
         * unto it.
         */
        if (gpio_pin_configure_dt(&led_0, GPIO_OUTPUT_ACTIVE) < 0) {
                return 0;
        }
                
        if (gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_ACTIVE) < 0) {
                return 0;
        }

        if (gpio_pin_configure_dt(&led_2, GPIO_OUTPUT_ACTIVE) < 0) {
                return 0;
        }

        if (gpio_pin_configure_dt(&led_3, GPIO_OUTPUT_ACTIVE) < 0) {
                return 0;
        }

        (void)gpio_pin_set_dt(&led_0, 1);
        (void)gpio_pin_set_dt(&led_1, 0);
        (void)gpio_pin_set_dt(&led_2, 1);
        (void)gpio_pin_set_dt(&led_3, 0);

        while (1) {
                if (gpio_pin_toggle_dt(&led_0) < 0) {
                        return 0;
                }                

                if (gpio_pin_toggle_dt(&led_1) < 0) {
                        return 0;
                }                

                if (gpio_pin_toggle_dt(&led_2) < 0) {
                        return 0;
                }                

                if (gpio_pin_toggle_dt(&led_3) < 0) {
                        return 0;
                }                

                k_msleep(SLEEP_TIME_MS);
        }
        return 0;
}

