#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
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
    struct dirent *entry;
    //1. Open the directory and check wheather it exists or not
    DIR *dir = opendir(directroyName);
    if(!dir){
        perror("ERROR: ");
        return;
    }
    //2. Read The content of opended directtory and store it in entry
   while((entry = readdir(dir))!=NULL){
        //2.1 check if read content is file or not
        // if(entry->d_type == DT_REG){

        // }
        if( entry->d_type == DT_REG){
            printf("FIle found");
        }
    }



}

void main(){
//     char s[10] = ".mp4";
//    char *ptr = getCategory(&s[0]);
//    printf("%s\n", ptr);
organizeFiles("/home/ankit/Desktop/C_File_Script");

}