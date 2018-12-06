#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    printf("%d tomer\n" , argc);
    int for_debug = 0;
    if(argc == 3){
        char* path1 = argv[1], *path2 = argv[2];
        int file1, file2;
        size_t read1,read2;
        char buffer_1[BUFFER_SIZE], buffer_2[BUFFER_SIZE];
        int go_on = 1;
        
        if(argc != 3){
            fprintf( stderr, "Error! input vars do not match expectation, expected 2 vars (paths)\n");
            exit(1);
        }
        
        file1 = open(argv[1], O_RDONLY);
        file2 = open(argv[2], O_RDONLY);
        
        if(file1 < 1 || file2 < 1){
            fprintf( stderr, "Error! can't open one of the following paths: %s or %s\n", path1, path2);
            exit(1);
        }
        
        
        if(path1 == path2){
            return 2;
        }
        
        while(go_on){
            read1 = read(file1, buffer_1 , BUFFER_SIZE);
            read2 = read(file2, buffer_2 , BUFFER_SIZE);
            
            if(read1 != read2){
                go_on = 0;
            }
            else{
                if(read1 == 0)
                    break;
                else{
                    const char* p1 = buffer_1;
                    const char* p2 = buffer_2;
                    
                    while(read1-- > 0){
                        *p1++;
                        *p2++;
                        if(*p1 != *p2)
                            go_on = 0;
                    }
                }
            }
        }
        
        if(go_on){
            printf("The content of these two files are the same! \n");
            exit(2);
        }
        else{
            fprintf( stderr, "These files doen't have the same content\n");
            exit(1);            
        }
        /*
        //FILE *file1 , *in2;
        //in1 = fopen( path1, " r " ); 
        //in2 = fopen( path2, " r " );
        
        
        printf("Before catch\n");
        if (!in1 || !in2) 
        {
            printf("Failed to open text file\n");
            //exit(1);
        }
        */
    }
    /*else{
        return 1;
    }*/
}