#include<stdio.h>
#include<string.h>
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
void main(){
    char s[10] = ".mp4";
   char *ptr = getCategory(&s[0]);
   printf("%s\n", ptr);

}