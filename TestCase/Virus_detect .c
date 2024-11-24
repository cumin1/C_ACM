#include <stdio.h>
#include <string.h>

int detect(char *virus, char *detect_dna) {
    int len_S = strlen(virus);
    int len_T = strlen(detect_dna);

    for (int i = 0; i <= len_S - len_T; i++) {  // 注意这里调整了循环条件
        int flag = 1;
        for (int j = 0; j < len_T; j++) {
            if (virus[i + j] != detect_dna[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    return 0;
}

//int main() {
//    char virus_dna[4] = "baa";
//    char detect_dna[11] = "baabbbbaba";
//
//    char all_vrius[9] = {0};  // 分配足够的空间并初始化为0
//    for (int i = 0; i < sizeof(all_vrius) - 1; i++) {
//        all_vrius[i] = virus_dna[i % 3];
//    }
//
//    printf("%s\n", all_vrius);
//    for (int i = 0; i <= strlen(all_vrius) - 3; i++) {  // 确保子字符串长度足够
//        char str[4] = {all_vrius[i], all_vrius[i + 1], all_vrius[i + 2], '\0'};
//        if (detect(str, detect_dna)) {
//            printf("have virus\n");
//            break;
//        }
//    }
//
//    return 0;
//}