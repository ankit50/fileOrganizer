#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<bits/types.h>
#define MAX_PATH 1024
typedef struct file{
    char *category;
    char *extension[10];
}FileCategory;
FileCategory fileCategory[]={                                
    {"documents", {".txt",".json", ".docx",NULL}},
    {"videos", {".mp4",".mkv", NULL}},  
    {"audios", {".mp3", NULL}},
    {"code", {".c",".cpp", ".js", NULL}},
    {"images", {".jpg", ".jpeg"}},  
    {"others", {NULL}},  
};
//function to get the category of file based on extension
char* getCategory(const char *ext){
    for(int i=0; i<sizeof(fileCategory)/sizeof(fileCategory[0]); i++){
        for(int j=0;(fileCategory[i].extension[j])!=NULL;j++){
            if(strcmp(ext, fileCategory[i].extension[j])==0){
                return fileCategory[i].category;
            }
        }
    }    
    return "others";
}
//function to organize files in given directory]
void organizeFiles(const char* directroyName){
    char categoryPathName[MAX_PATH];
    char oldPathName[MAX_PATH];
    char newPathName[MAX_PATH];
    struct dirent *entry;
    //1. Open the directory and check wheather it exists or not
    DIR *dir = opendir(directroyName);
    if(!dir){
        perror("ERROR: ");
        return;
    }
    //2. Read The content of opened directory and store it in entry
   while((entry = readdir(dir))!=NULL){
        //2.1 check if read content is file or not
        if( entry->d_type == DT_REG){
            //2.2 call getCategory by getting the file extension
            char *category = getCategory(strrchr(entry->d_name, '.'));
            //2.3 create the directory if doesn't exists
            snprintf(categoryPathName, sizeof(categoryPathName), "%s/%s", directroyName, category);    
            mkdir(categoryPathName, 0777);   
            snprintf(oldPathName, sizeof(oldPathName), "%s/%s", directroyName, entry->d_name);
            snprintf(newPathName, sizeof(newPathName), "%s/%s", categoryPathName, entry->d_name);
            rename(oldPathName, newPathName);
        }
    }
    closedir(dir);
}

void main(){
    organizeFiles("/home/ankit/Desktop/demo");
}