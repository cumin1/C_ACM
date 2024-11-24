//#include <stdio.h>

//int main()
//{
//    //1.打开文件
//    FILE *fp = fopen("D:\\code_place\\Data_Struct\\FileReadWrite\\test.txt","w+");
//
//    if (fp==NULL)
//    {
//        perror("fopen error");
//        return -1;
//    }
    //2.操作文件(获取字符\字符串 写入字符\字符串)
//    int ch = getchar();
//    while (ch != '$')
//    {
//        fputc(ch, fp);
//        ch = getchar();
//    }

//    fputs("this is an example text",fp);
//    char str[25] = {0};
//    fgets(str, 24, fp);
//
//    printf("%s\n",str);

//    int ch;
//    while (ch != EOF)
//    {
//        ch = getc(fp);
//        printf("%c",ch);
//    }

//    char str[25] = {0};
//    fread(str,sizeof(char),sizeof(str),fp);
//
//    printf("%s\n",str);

//    char * name = "fuhao";
//    fprintf(fp,"i am %s", name);

//    fputs("we are in 2024",fp);
//
//    rewind(fp); // 使指针回到开始
//    char str1[10],str2[10],str3[10];
//    int year;
//    fscanf(fp,"%s %s %s %d",str1,str2,str3,&year);
//
//    printf("%s %s %s %d",str1,str2,str3,year);
//
//    //3.关闭文件
//    fclose(fp);
//
//    return 0;
//}