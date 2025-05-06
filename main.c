    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    typedef struct{
        char *task;
        int completed; // 1 = true, 0 = false
    } Task;
 
    Task *tasks = NULL; // 0 bytes are used
    int length = 0;





    //-------------------------------------------------
    // functions
    void addTask(const char *task){ 
        tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task));
        tasks[length].task = (char *)malloc(strlen(task) + 1);
        tasks[length].completed = 0;
        // Copies the C string pointed by source into the array pointed by destination, 
        // including the terminating null character (and stopping at that point).
        strcpy(tasks[length].task, task);
        length++;
        // print in C
        printf("task added");
    }   

    void listTask(){ 
        char status;

        for ( int i = 0; i < length; i++){
            if(tasks[i].completed == 1){
                status = 'd'; // done
            } else {
                status = 'n'; // not done
            }
            // print to console
            printf("%d. %s [%c]\n", i + 1, tasks[i].task, status);
        }

    }
    void markCompleted(int index){ 
        if ( index <= length && index > 0) {
            tasks[index - 1].completed = 1; // true
            printf("Task marked as completed\n");
        } else {
            printf("Invalid index\n");
        }

    }
    void deleteTask( int index,const char* task){ 
        if ( index <= length && index > 0) {
            tasks[index - 1].completed = 1; // true
            index = index - 1;

            // free memory
            free(tasks[index].task);

            for(int i = index; i < length - 1; i++){
                tasks[i] = tasks[i + 1];
            }
            length--;
            // reallocate tasks memory
            tasks = (Task *)realloc(tasks, (length * sizeof(Task)));
        } else {
            printf("Invalid index\n");
        }

    }

    void editTask(int index,const char* task){
        if ( index <= length && index > 0) {
            index = index - 1;
            char *editedTask = (char * )realloc(tasks[index].task, strlen(task) + 1);
        
            if(editedTask != NULL){
                tasks[index].task = editedTask;
                strcpy(tasks[index].task, task);
                printf("Task updated successfully");

            } else {
                printf("Memory Allocation failed");
            }
        } else {
            printf("Invalid index\n");
        }
    }
        
    int main(){ // return integer
        int running = 1;
        int choice;
        int indexInput;

        char taskInput[100];
            printf("\nOptions\n");
            printf("1. Add a task\n");
            printf("2. List all tasks\n");
            printf("3. Mark as complete\n");
            printf("4. Edit a task\n");
            printf("5. Delete a task\n");
            printf("6. Exit\n");

        while (running){
            printf("Enter choice(1,2,3,4,5,6): ");
            scanf("%d", &choice); // take input from user

            // switch statement
            switch(choice){
                case 1: // add a task
                    printf("Enter task: ");
                    getchar(); // get character
                    fgets(taskInput, sizeof(taskInput), stdin);
                    // taskInput[strcspn(taskInput, "\n")] = '\0';
                    addTask(taskInput);
                break;

                case 2:
                    listTask();
                break;

                case 3:
                    printf("Enter index: "); // ask user
                    scanf("%d", &indexInput); // scan user input with index provided by user
                    markCompleted(indexInput); // plug index into completed
                break;
                
                case 4:
                    printf("Enter index: "); // ask user
                    scanf("%d", &indexInput);
                    printf("Enter edited task: ");
                    getchar();
                    fgets(taskInput, sizeof(taskInput), stdin);
                    // taskInput[strcspn(taskInput, "\n")] = '\0';

                    editTask(indexInput, taskInput);
                break;
                
                case 5:
                printf("Enter index: ");
                scanf("%d", &indexInput);

                deleteTask(indexInput,taskInput);
                break;

                case 6:
                running = 0;
                break;

                default:

                    printf("Invalid choice\n");
                    break;
            }

            
        }

            free(tasks);
            
            return 0;
        } 

    

    // 1 kb = 1024 bytes
