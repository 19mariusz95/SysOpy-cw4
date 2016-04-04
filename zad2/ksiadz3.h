//
// Created by student on 04/04/16.
//

#ifndef ZAD2_KSIADZ3_H
#define ZAD2_KSIADZ3_H

pid_t get_catcher_pid() {
    char line[100];
    FILE *cmd = popen("pidof catcher", "r");
    if (cmd == NULL) {
        printf("Error while searching for catcher process\n");
        exit(1);
    }
    fgets(line, 100, cmd);
    unsigned long p = strtoul(line, NULL, 10);
    if (p == ULONG_MAX || p == 0) {
        printf("Error while searching for catcher process\n");
        exit(1);
    }
    pclose(cmd);
    return (pid_t) p;
}

int send_signal(int p, int signal, union sigval s) {
    int result = sigqueue(p, signal, s);
    if (result != 0)
        printf("Error");
    return result;
}

#endif //ZAD2_KSIADZ3_H
