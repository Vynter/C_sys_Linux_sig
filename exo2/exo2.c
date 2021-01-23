#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <error.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig){
  if(kill(getpid(), SIGTERM) == 0) {
    printf("le processus fils a était interempu\n");
    }else{
    printf("Erreur lors de l'exécution\n");
    }
}

int main(){
  pid_t child = fork();
  int status;
  if(child == -1){
    perror("Erreur lors du fork\n");
    return 1;
    }else{
      if(child == 0){
        printf("je suis le processus fils\n");
        signal(SIGUSR1, sigHandler);
        }else{
        wait(&status);
        sleep(5);
        kill(child, SIGUSR1);
        }
        }

  return 0;
  }
