#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 函数声明
void huatu(int dianshu, int huase);
void guize();
char getDianShuChar(int dianshu);
char getHuaSeChar(int huase);

// 主函数
int main() {
    // 初始化随机数种子
    srand((unsigned int)time(NULL));
    printf("===== 24点游戏开始 =====\n");
    printf("提示：每次抽牌前请按Enter键继续...\n");
    guize();
	getchar();
    return 0;
}

// 游戏规则函数：两人轮流抽牌，超过24点者输
void guize() {
    int tanyi_score = 0, zhouxuewen_score = 0;  // 使用指定名称作为变量名
    int round = 1;
    int dianshu, huase;
    char input[10];  // 用于接收用户输入
    char tanyi[20] = "tanyi";    // 玩家1名称变量
    char zhouxuewen[20] = "zhouxuewen";// 玩家2名称变量
    
    // 输入玩家名字（保持默认值，也可修改）
    printf("\n请输入玩家1的名字（默认: tanyi）: ");
    fgets(input, sizeof(input), stdin);
    if (strlen(input) > 1) {
        input[strcspn(input, "\n")] = '\0';
        strcpy(tanyi, input);
    }
    
    printf("请输入玩家2的名字（默认: zhouxuewen）: ");
    fgets(input, sizeof(input), stdin);
    if (strlen(input) > 1) {
        input[strcspn(input, "\n")] = '\0';
        strcpy(zhouxuewen, input);
    }
    
    while (1) {
        printf("\n\n===== 第%d轮 =====", round);
        
        // tanyi抽牌前等待Enter
        printf("\n%s准备抽牌，请按Enter键...", tanyi);
        fgets(input, sizeof(input), stdin);
        
        // tanyi抽牌
        dianshu = rand() % 13 + 1;
        huase = rand() % 4;
        huatu(dianshu, huase);
        tanyi_score += (dianshu > 10) ? 10 : dianshu;
        printf("%s当前总点数: %d\n", tanyi, tanyi_score);
        
        // 检查tanyi是否超过24点
        if (tanyi_score > 24) {
            printf("\n%s点数超过24点，%s获胜！\n", tanyi, zhouxuewen);
            break;
        }
        
        // zhouxuewen抽牌前等待Enter
        printf("\n%s准备抽牌，请按Enter键...", zhouxuewen);
        fgets(input, sizeof(input), stdin);
        
        // zhouxuewen抽牌
        dianshu = rand() % 13 + 1;
        huase = rand() % 4;
        huatu(dianshu, huase);
        zhouxuewen_score += (dianshu > 10) ? 10 : dianshu;
        printf("%s当前总点数: %d\n", zhouxuewen, zhouxuewen_score);
        
        // 检查zhouxuewen是否超过24点
        if (zhouxuewen_score >=24) {
            printf("\n%s点数超过24点，%s获胜！\n", zhouxuewen, tanyi);
            break;
        }
        
        round++;
    }
}

// 绘制卡牌函数：左上角和右下角显示点数和花色
void huatu(int dianshu, int huase) {
    char dsChar = getDianShuChar(dianshu);
    char hsChar = getHuaSeChar(huase);
    
    // 绘制5行7列的卡牌
    printf("\n------------------------\n");
    printf("|%c%c                     |\n", dsChar, hsChar);  // 左上角
    printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
	printf("|                       |\n");
    printf("|                     %c%c|\n", dsChar, hsChar);  // 右下角
    printf("-------------------------\n");
}

// 将点数转换为对应的字符
char getDianShuChar(int dianshu) {
    switch(dianshu) {
        case 1: return 'A';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        default: return '0' + dianshu;
    }
}

// 将花色转换为对应的ASCII字符
char getHuaSeChar(int huase) {
    switch(huase) {
        case 0: return 3;  // ♥ 红心
        case 1: return 4;  // ♦ 方块
        case 2: return 5;  // ♣ 梅花
        case 3: return 6;  // ♠ 黑桃
        default: return '?';
    }
}
