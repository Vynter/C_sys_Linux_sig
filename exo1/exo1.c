#include <stdio.h>
#include <error.h>
#include <signal.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    perror("Veuillez saisir le Pid");
    return 0;
    }else{
      int processK;
      sscanf(argv[1], "%d", &processK);
      if(kill(processK, SIGKILL) == 0) {
        printf("Le processus a bel et bien était interempug \n");
        }else{
        printf("erreur lors de l'exécution \n");
        }
  }

  return 0;    
}
