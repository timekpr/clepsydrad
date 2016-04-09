// Copyright (c) 2014 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

// read conf file
// read log rotate file
#include "pamcheck.h"

int readConfFile (FILE *fp);

#include "c_socket.h"

int make_daemon ()
{
    FILE *fp= NULL;
    FILE *fp_pid= NULL;
    pid_t process_id = 0;
    pid_t sid = 0;
    process_id = fork();
    if (process_id < 0) {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }
    // PARENT PROCESS. Need to kill it.
    if (process_id > 0) {

        // Should moved to better place
        fp_pid = fopen ("/tmp/clepsydrad.pid", "w+");
        fprintf (fp_pid, "%d\n", process_id);
        fflush(fp_pid);
        fclose (fp_pid);

        printf("process_id of daemon process %d \n", process_id);
        // return success in exit status
        exit(0);
    }

    umask(0);
    sid = setsid();
    if(sid < 0)  {
        exit(1);
    }

    // Change the current working directory to root.
    chdir("/tmp");

    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fp = fopen ("/tmp/clepsydrad.log", "w+");

    char *p = NULL;
    int countToDie = 0;
    while (1)
    {
       //Dont block context switches, let the process sleep for some time
       sleep(1);
       // Temp code to cleanly die this process
       countToDie ++;
       if (countToDie > 15 )  {
           break;
       } else {
           // int pm = checkPamUser ();
           //fprintf(fp, " pam user check ... %d\n",  pm);
           int loggedC = getLoggedusers (fp);
           fprintf(fp, " pam cnt of logged users... %d\n",  loggedC);
           fflush(fp);
       }
       // Implement and call some function that does core work for this daemon.
    }
    fflush(fp);
    fprintf(fp, " First user in list is .. [%s] \n", getUserName (0));
    fprintf(fp, "list contains [%d] count of items...\n", list_count());
    delete_all (); // delete list
    fprintf(fp, "Quit clepsydrad, bye !...\n");
    fclose(fp);

    // remove pid file
    remove ("/tmp/clepsydrad.pid");
    return (0);

}

int main(void)
{
   return make_daemon ();
}

