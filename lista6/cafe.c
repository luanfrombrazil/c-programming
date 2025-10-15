#include <stdio.h>

int cafe() {
    int um,dois,tres;
    scanf("%d\n%d\n%d", &um,&dois,&tres);
    int min_andar1, min_andar2,min_andar3;
    min_andar1 = (dois + tres*2)*2;
    min_andar2 = (tres + um)*2;
    min_andar3 = (um*2 + dois)*2;

    if (min_andar1 <= min_andar2 && min_andar1 <= min_andar3) {
        printf("%d",min_andar1);
    }else if (min_andar2 <= min_andar1 && min_andar2 <= min_andar3) {
        printf("%d",min_andar2);
    }else {
        printf("%d",min_andar3);
    }
    return 0;
}

int main() {
    return cafe();
} 