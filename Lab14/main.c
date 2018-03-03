#include <stdio.h>
int n, flag = 0;
int whocalls = 0;
int bd[150];

void cbsort () {
    int aux;
    for (int i = n-1; i > 0; --i) {
        for (int j = 0; j < i ; ++j) {
            if (bd[j] > bd[j+1]) {
                aux = bd[j+1];
                bd[j+1] = bd[j];
                bd[j] = aux;
            }
        }
    }
}

void decrbsort () {
    int aux;
    for (int i = n-1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (bd[j] < bd[j+1]){
                aux = bd[j];
                bd[j] = bd[j+1];
                bd[j+1] = aux;
            }
        }
    }
}

int binarysearch (int search) {
    int beg = 0, end = n -1, mid;
    if (flag == 1) {
        while (beg <= end) {
            mid = (beg+end)/2;
            if (whocalls) {
                printf("%d ", mid);
            }
            if (bd[mid] == search) {
                if (whocalls) {
                    printf("\n");
                }
                return mid;
            }
            else if (bd[mid] > search) {
                end = mid -1;
            }
            else if (bd[mid] < search){
                beg = mid + 1;
            }
        }
    }
    else if (flag == -1) {
    	while (beg <= end) {
            mid = (beg+end)/2;
            if (whocalls) {
                printf("%d ", mid);
            }
    		if (bd[mid] == search) {
                if (whocalls) {
                    printf("\n");
                }
    			return mid;
    		}
    		if (bd[mid] > search) {
    			beg = mid -1;
    		}
    		if (bd[mid] < search) {
    			end = mid + 1;
    		}
    	}
    }
    if (whocalls) {
        printf("\n");
    }
    return -5;
}

void insertion (int insert) {
    int superflag;
    superflag = binarysearch(insert);
    if (superflag >= 0) {
        printf("Aluno ja matriculado na turma!\n");
        return;
    }
    if (superflag == -5) {
        bd[n] = insert;
        ++n;
        if (flag == 1) {
            cbsort();
        }
        else if (flag == -1) {
            decrbsort();
        }
    }
    else {
        bd[n] = insert;
        ++n;
    }
}

int main() {
    int search, insert, result = 0;
    int remove;
    char c;
    int pos = -5;
    int h;
    flag = 0;
    scanf("%d", &n);

    for (int i = 0; i < n ; ++i) {
        scanf("%d", &bd[i]);
    }

    scanf(" %c", &c);

    while (c != 's') {

        if (c == 'p') {
            for (int i = 0; i < n; ++i) {
                printf("%d ", bd[i]);
            }
            printf("\n");
        }

        if (c=='r') {
            scanf("%d", &remove);
            pos=-5;
            if (n < 1) {
                printf("Nao ha alunos cadastrados na turma!\n");
            }
            else {
                for ( h = 0; h < n && pos == -5; ++h) {
                    if (bd[h] == remove) {
                        pos = h;
                    }
                }
                if (pos != -5) {
                    for (int i = h; i < n ; ++i) {
                        //if (pos+1 == n) {
                          //  break;
                        //}
                        bd[pos] = bd[pos+1];
                    }
                    n = n -1;
                    if (flag == 1) {
                        cbsort();
                    }
                    else if (flag == -1){
                        decrbsort();
                    }
                }
                else {
                    printf("Aluno nao matriculado na turma!\n");
                }
            }

        }

        if (c == 'c') {
            cbsort();
            flag = 1;
        }

        if (c=='d') {
            decrbsort();
            flag = -1;
        }

        if (c == 'i') {
            scanf ("%d", &insert);
            if (n <= 149) {
                insertion(insert);
            }
            else printf("Limite de vagas excedido!\n");
        }

        if (c == 'b') {
            whocalls = 1;
            scanf("%d", &search);
            if (flag == 1 || flag == -1) {

                result = binarysearch(search);

                if (result == -5) {

                    printf("%d nao esta na lista!\n", search);
                } 

                else printf("%d esta na posicao: %d\n", search, result);
            }

            else {
                printf("Vetor nao ordenado!\n");
            }
            whocalls = 0;
        }
        scanf(" %c", &c);
    }
    return 0;
}