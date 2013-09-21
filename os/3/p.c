void parsecmd(string cmd, char** argv){
        char *temp;
        temp=(char*)malloc((cmd.length()+1)*sizeof(char*));
        cmd.copy(temp,cmd.length(),0);
        //argv=(char**)malloc(10*sizeof(char*));
        for(int i=0;i<10;i++){
                argv[i]=(char*)malloc(50*sizeof(char*));
        }
        int i=0;
        while(*temp){
                while(*temp == ' ' ||
                                *temp == '\t'||
                                *temp == '\n'){
                        *temp ='\0';
                        temp++;
                }
                argv[i++]=temp;
                while(*temp != '\0' &&
                                *temp != '\t' &&
                                *temp != '\n' &&
                                *temp != ' ' )
                        temp++;

        }
        argv[i]=NULL;
