#include <stdio.h>
#include <unistd.h>  // Para usar fork() e exec()
#include <sys/types.h>  // Para usar tipos como pid_t
#include <sys/wait.h>  // Para usar a função wait()

int main() {
    pid_t pid = fork();  // Cria o processo filho

    if (pid < 0) {
        // Caso ocorra erro no fork
        printf("Erro ao criar processo filho!\n");
        return 1;
    } else if (pid == 0) {
        // Código que será executado pelo processo filho
        printf("Eu sou o processo filho. Meu PID é %d\n", getpid());

        // Executa o comando "ls -l" no processo filho
        execlp("ls", "ls", "-l", NULL);  // Substitui o processo filho pelo comando "ls -l"

        // Se o exec falhar
        printf("Erro ao executar o comando!\n");
        return 1;
    } else {
        // Código que será executado pelo processo pai
        printf("Eu sou o processo pai. Meu PID é %d e o PID do meu filho é %d\n", getpid(), pid);
        wait(NULL);  // O pai aguarda o término do filho
        printf("O processo filho terminou.\n");
    }

    return 0;
}
