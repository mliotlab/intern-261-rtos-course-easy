#ifndef DEADLOCK_DEMO_H
#define DEADLOCK_DEMO_H

void deadlock_demo_init(void);
void task_alpha(void *argument);
void task_beta(void *argument);

#endif /* DEADLOCK_DEMO_H */
