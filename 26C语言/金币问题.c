//
// Created by Jianglai on 2026/10/29.
//

#include <stdio.h>

int calculateCoins_daily(int n) {
    int total = 0;
    int salary = 1;          // 当前每天发的金币数
    int days_at_salary = 0;  // 当前日薪已经持续的天数

    for (int day = 1; day <= n; day++) {
        total += salary;
        days_at_salary++;

        // 如果当前日薪持续的天数等于日薪本身，说明该升级了
        if (days_at_salary == salary) {
            salary++;
            days_at_salary = 0;
        }
    }

    return total;
}

int main() {
    int test_days[] = {6, 7, 10, 100, 1000};
    for (int i = 0; i < 5; i++) {
        printf("%d\n", test_days[i]);
        printf("    %d天共发%d枚金币\n", test_days[i], calculateCoins_daily(test_days[i]));
    }
    return 0;
}