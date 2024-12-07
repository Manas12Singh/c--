#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <vector>

using namespace std;

class Communication
{
public:
    struct msg_buffer
    {
        long msg_type;
        char msg_text[100];
    } message;

    void pipe_communication(int fd[2])
    {
        pid_t pid_pipe = fork();
        if (pid_pipe == 0)
        {
            close(fd[0]);
            string pipe_msg = "Hello from pipe child";
            write(fd[1], pipe_msg.c_str(), pipe_msg.length() + 1);
            close(fd[1]);
            _exit(0);
        }
    }

    void message_queue_communication(int msgid)
    {
        pid_t pid_msg = fork();
        if (pid_msg == 0)
        {
            message.msg_type = 1;
            strcpy(message.msg_text, "Hello from message queue child");
            msgsnd(msgid, &message, sizeof(message), 0);
            _exit(0);
        }
    }

    void shared_memory_communication(char *shared_mem)
    {
        pid_t pid_shm = fork();
        if (pid_shm == 0)
        {
            strcpy(shared_mem, "Hello from shared memory child");
            _exit(0);
        }
    }
};

int main()
{
    Communication comm;

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    key_t key_msg = ftok("progfile", 65);
    int msgid = msgget(key_msg, 0666 | IPC_CREAT);

    key_t key_shm = ftok("shmfile", 65);
    int shmid = shmget(key_shm, 1024, 0666 | IPC_CREAT);
    char *shared_mem = (char *)shmat(shmid, (void *)0, 0);

    comm.pipe_communication(fd);
    comm.message_queue_communication(msgid);
    comm.shared_memory_communication(shared_mem);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    close(fd[1]);
    char read_pipe_msg[100];
    read(fd[0], read_pipe_msg, sizeof(read_pipe_msg));
    close(fd[0]);
    cout << "Parent received from pipe: " << read_pipe_msg << endl;

    msgrcv(msgid, &comm.message, sizeof(comm.message), 1, 0);
    cout << "Parent received from message queue: " << comm.message.msg_text << endl;
    msgctl(msgid, IPC_RMID, NULL);

    cout << "Parent received from shared memory: " << shared_mem << endl;
    shmdt(shared_mem);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
