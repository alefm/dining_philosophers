/********************************************************
*
* Author: Alef Martins
* Sistema Operacionais - UNIVALI
*
********************************************************/

#include <dining_philosophers.h>

int philosopher_state[N_PHILOSOPHERS] = { PHILOSOPHER_THINK, PHILOSOPHER_THINK, PHILOSOPHER_THINK, PHILOSOPHER_THINK, PHILOSOPHER_THINK };
static int phil_id[N_PHILOSOPHERS];
pthread_mutex_t forks[N_PHILOSOPHERS];
pthread_t philosopher[N_PHILOSOPHERS];

void philosopher_print_state(int state, int pos){

	switch(state){
		case PHILOSOPHER_WAIT:
			printf("Filósofo %d está esperando!\n", pos);
			break;
		case PHILOSOPHER_EAT:
			printf("Filósofo %d está comendo!\n", pos);
			break;
		case PHILOSOPHER_THINK:
			printf("Filósofo %d está pensando!\n", pos);
			break;
		default:
			break;
	}
}

void * philosopher_thread(void *arg){
	int pos = *((int *) arg);

	int left_phil = (pos + N_PHILOSOPHERS - 1) % N_PHILOSOPHERS;
	int right_phil = (pos + 1) % N_PHILOSOPHERS;

	int left_fork = left_phil;
	int right_fork = pos;

	philosopher_print_state(philosopher_state[pos], pos+1);

	sleep(MAX_WAIT_TIME);

	while(TRUE){

		philosopher_state[pos] = PHILOSOPHER_WAIT;

		pthread_mutex_lock(&forks[left_fork]);
		pthread_mutex_lock(&forks[right_fork]);

		philosopher_state[pos] = PHILOSOPHER_EAT;
		philosopher_print_state(philosopher_state[pos], pos+1);

		if(philosopher_state[left_phil] == PHILOSOPHER_EAT || philosopher_state[right_phil] == PHILOSOPHER_EAT){
		    printf("ERROR!\n");
		}
		sleep(random_wait_time());

		philosopher_state[pos] = PHILOSOPHER_THINK;
		philosopher_print_state(philosopher_state[pos], pos+1);

		pthread_mutex_unlock(&forks[left_fork]);
		pthread_mutex_unlock(&forks[right_fork]);

		sleep(random_wait_time());

	}
}

int random_wait_time(){
    return rand() % MAX_WAIT_TIME;
}

int main(int argc, char **argv) {
    srand(time(NULL));

	/* Init all forks mutex */
	for(int i = 0; i < N_PHILOSOPHERS; i++){
		pthread_mutex_init (&forks[i], NULL);
	}

	/* Create all philosophers threads */
	for(int i = 0; i < N_PHILOSOPHERS; i++){
		phil_id[i] = i;
		pthread_create(&philosopher[i], NULL, philosopher_thread, &phil_id[i]);
	}

	/* Join to main thread wait until another threads is working */
	for(int i = 0; i < N_PHILOSOPHERS; i++){
		pthread_join(philosopher[i], NULL);
	}

	return EXIT_SUCCESS;
}
